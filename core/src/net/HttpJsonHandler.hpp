/*
 *
 * HttpJsonHandler
 * ledger-core
 *
 * Created by Pierre Pollastri on 15/02/2017.
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
#ifndef LEDGER_CORE_HTTPJSONHANDLER_HPP
#define LEDGER_CORE_HTTPJSONHANDLER_HPP

#include <rapidjson/reader.h>
#include "HttpClient.hpp"

namespace ledger {
    namespace core {
        template <typename T, class Handler>
        class HttpJsonHandler : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, Handler> {
        public:
            HttpJsonHandler(const std::shared_ptr<api::HttpUrlConnection>& connection) {
                _connection = connection;
            };
            virtual T build() = 0;
            virtual ~HttpJsonHandler() {

            }
            virtual std::string getStatusText() const {
                return _connection->getStatusText();
            }
            virtual int32_t getStatusCode() const {
                return _connection->getStatusCode();
            }
            virtual std::unordered_map<std::string, std::string> getHttpHeaders() const {
                return _connection->getHeaders();
            };
        private:
            mutable std::shared_ptr<api::HttpUrlConnection> _connection;
        };
    }
}


#endif //LEDGER_CORE_HTTPJSONHANDLER_HPP
