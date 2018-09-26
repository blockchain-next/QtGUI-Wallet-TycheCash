// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <QString>

#include "TycheCashCore/Currency.h"

namespace WalletGui {

class CurrencyAdapter {

public:
  static CurrencyAdapter& instance();

  const TycheCash::Currency& getCurrency();
  QString getCurrencyDisplayName() const;
  QString getCurrencyName() const;
  QString getCurrencyTicker() const;
  quint64 getMinimumFee() const;
  quintptr getNumberOfDecimalPlaces() const;
  QString formatAmount(quint64 _amount) const;
  quint64 parseAmount(const QString& _amountString) const;
  bool validateAddress(const QString& _address) const;

private:
  TycheCash::Currency m_currency;

  CurrencyAdapter();
  ~CurrencyAdapter();
};

}
