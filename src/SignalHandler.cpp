// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <csignal>

#include "SignalHandler.h"

namespace WalletGui {

SignalHandler& SignalHandler::instance() {
  static SignalHandler inst;
  return inst;
}

SignalHandler::SignalHandler() : QObject() {
}

SignalHandler::~SignalHandler() {
}

void SignalHandler::init() {
  std::signal(SIGINT, SignalHandler::sigHandler);
  std::signal(SIGTERM, SignalHandler::sigHandler);
}

void SignalHandler::sigHandler(int _signal) {
  Q_EMIT SignalHandler::instance().quitSignal();
}

}
