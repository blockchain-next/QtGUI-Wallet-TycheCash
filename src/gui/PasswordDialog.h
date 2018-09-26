// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <QDialog>

namespace Ui {
class PasswordDialog;
}

namespace WalletGui {

class PasswordDialog : public QDialog {
  Q_OBJECT
  Q_DISABLE_COPY(PasswordDialog)

public:
  PasswordDialog(bool _error, QWidget* _parent);
  ~PasswordDialog();

  QString getPassword() const;

private:
  QScopedPointer<Ui::PasswordDialog> m_ui;
};

}
