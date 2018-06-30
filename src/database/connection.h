/*  Copyright (C) 2014-2018 FastoGT. All right reserved.
    This file is part of sniffer.
    sniffer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    sniffer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with sniffer.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cassandra.h>

#include <vector>
#include <functional>

#include <common/error.h>

namespace database {

class Connection {
 public:
  typedef std::function<void(CassFuture* result)> exec_func_t;
  Connection();
  ~Connection();

  common::Error Connect(const std::vector<std::string>& hosts) WARN_UNUSED_RESULT;
  common::Error Disconnect() WARN_UNUSED_RESULT;

  common::Error Execute(const std::string& query, size_t parameter_count, exec_func_t succsess_cb) WARN_UNUSED_RESULT;

  bool IsConnected() const;

 private:
  CassCluster* cluster_;
  CassFuture* connect_future_;
  CassSession* session_;
};
}