/*
 *
 * migrations
 * ledger-core
 *
 * Created by Pierre Pollastri on 25/04/2017.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#pragma once

#include <soci.h>
#include <iostream>

#include <core/utils/Exception.hpp>

namespace ledger {
    namespace core {
        /// Get the current database migration version.
        template <typename T>
        int getDatabaseMigrationVersion(soci::session& sql) {
            int version = -1;

            try {
                soci::statement st = (sql.prepare << "SELECT version FROM __database_meta__ WHERE id = :id", soci::use(T::COIN_ID), soci::into(version));
                st.execute();
                st.fetch();
            } catch (...) {
                // if we cannot find the version, it stays set to -1
            }

            return version;
        }

        template <int version, typename T>
        void migrate(soci::session& sql) {
            std::cerr << "No specified migration for version " << version << std::endl;
            throw make_exception(api::ErrorCode::RUNTIME_ERROR, "No specified migration for version {}", version);
        }

        template <int version, typename T>
        void migrate(soci::session& sql, int currentVersion) {
        };

        template <int version, typename T>
        void rollback(soci::session&) {
        }

        /// Migration system.
        ///
        /// The T type variable is expected to be a trait that has some constants:
        ///
        ///   - T::COIN_ID: coin ID numeric value. Keep in mind that this value must be unique for
        ///     all coins as it serves as a namespace value.
        ///
        ///     See <https://github.com/satoshilabs/slips/blob/master/slip-0044.md> to correctly
        ///     implement this function.
        ///   - T::CURRENT_VERSION: current version of the migration system.
        template <int version, typename T>
        struct Migration final {
          /// Advance the migration system up to version.
          static void forward(soci::session& sql, int currentVersion) {
              if (currentVersion < version) {
                  Migration<version - 1, T>::forward(sql, currentVersion);
                  migrate<version, T>(sql);

                  if (version == 1) {
                      sql << "INSERT INTO __database_meta__ (id, version)"
                          "VALUES (:id, 1)",
                          soci::use(T::COIN_ID);
                  } else {
                      sql << "UPDATE __database_meta__ SET version = :version where id = :id", soci::use(version), soci::use(T::COIN_ID);
                  }
              }
          }

          /// Rollback from migrationNumber.
          static void backward(soci::session& sql, int currentVersion) {
              if (currentVersion == version) {
                  // we’re in sync with the database; perform the rollback normally
                  rollback<version, T>(sql);

                  if (currentVersion >= 0) {
                      // after rolling back this migration, we won’t have anything left, so we only
                      // update the version for > 0
                      if (currentVersion != 0) {
                          auto prevVersion = version - 1;
                          sql << "UPDATE __database_meta__ SET id = :id, version = :version", soci::use(T::COIN_ID), soci::use(prevVersion);
                      }

                      Migration<version - 1, T>::backward(sql, currentVersion - 1);
                  }
              } else if (currentVersion < version) {
                  // we’re trying to rollback a migration that hasn’t been applied; try the previous
                  // rollback
                  Migration<version - 1, T>::backward(sql, currentVersion);
              } else {
                  // we’re trying to rollback a migration but we have missed some others; apply the
                  // next ones first
                  throw make_exception(api::ErrorCode::RUNTIME_ERROR, "Missing rollback migrations: {} to {}", version + 1, currentVersion);
              }
          }
        };

        template <typename T>
        struct Migration<0, T> final {
           static void forward(soci::session&, int) {
           }

           static void backward(soci::session&, int) {
           }
        };

        // default migrations

        /// Init migrations system.
        void setupMigrations(soci::session& sql);

        /// De-init migrations system.
        void unsetupMigrations(soci::session& sql);

        /// The Core tag type.
        struct CoreMigration {
            static int constexpr COIN_ID = -1;
            static uint32_t constexpr CURRENT_VERSION = 1;
        };

        // migrations
        template <> void migrate<1, CoreMigration>(soci::session& sql);
        template <> void rollback<1, CoreMigration>(soci::session& sql);
    }
}