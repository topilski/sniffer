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

#pragma once

#include <common/serializer/json_serializer.h>

#include <common/types.h>

#define UNKNOWN_SSI 0

namespace sniffer {

class EntryInfo : public common::serializer::JsonSerializer<EntryInfo> {
 public:
  EntryInfo();
  explicit EntryInfo(const std::string& mac_address, common::time64_t ts, int8_t ssi = UNKNOWN_SSI);

  bool Equals(const EntryInfo& ent) const;
  bool IsValid() const;

  std::string GetMacAddress() const;

  common::time64_t GetTimestamp() const;
  void SetTimestamp(common::time64_t ts);

  int8_t GetSSI() const;

 protected:
  virtual common::Error DoDeSerialize(json_object* serialized) override;
  virtual common::Error SerializeFields(json_object* deserialized) const override;

 private:
  std::string mac_address_;
  common::time64_t timestamp_;
  int8_t ssi_;
};

inline bool operator==(const EntryInfo& left, const EntryInfo& right) {
  return left.Equals(right);
}
}
