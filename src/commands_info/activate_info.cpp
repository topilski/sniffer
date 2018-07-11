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

#include "commands_info/activate_info.h"

namespace sniffer {
namespace commands_info {

ActivateInfo::ActivateInfo() : LicenseInfo() {}

ActivateInfo::ActivateInfo(const std::string& license) : LicenseInfo(license) {}

}  // namespace server
}  // namespace iptv_cloud