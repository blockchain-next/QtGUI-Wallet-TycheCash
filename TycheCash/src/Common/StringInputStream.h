// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <string>
#include "IInputStream.h"

namespace Common {

class StringInputStream : public IInputStream {
public:
  StringInputStream(const std::string& in);
  size_t readSome(void* data, size_t size) override;

private:
  const std::string& in;
  size_t offset;
};

}