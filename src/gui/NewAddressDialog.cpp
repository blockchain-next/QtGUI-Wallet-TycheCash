// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "NewAddressDialog.h"

#include "ui_newaddressdialog.h"

namespace WalletGui {

NewAddressDialog::NewAddressDialog(QWidget* _parent) : QDialog(_parent), m_ui(new Ui::NewAddressDialog) {
  m_ui->setupUi(this);
}

NewAddressDialog::~NewAddressDialog() {
}

QString NewAddressDialog::getAddress() const {
  return m_ui->m_addressEdit->text();
}


QString NewAddressDialog::getLabel() const {
  return m_ui->m_labelEdit->text();
}

}
