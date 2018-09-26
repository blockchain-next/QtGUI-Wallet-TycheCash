// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <QObject>

namespace WalletGui {

class SignalHandler : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(SignalHandler)

public:
  static SignalHandler& instance();

  void init();

private:
  SignalHandler();
  ~SignalHandler();

  static void sigHandler(int _signal);

Q_SIGNALS:
  void quitSignal();
};

}
