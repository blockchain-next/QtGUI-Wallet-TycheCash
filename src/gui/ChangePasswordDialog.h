// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma  once

#include <QDialog>

namespace Ui {
class ChangePasswordDialog;
}

namespace WalletGui {

class ChangePasswordDialog : public QDialog {
  Q_OBJECT
  Q_DISABLE_COPY(ChangePasswordDialog)

public:
  ChangePasswordDialog(QWidget* _parent);
  ~ChangePasswordDialog();

  QString getNewPassword() const;
  QString getOldPassword() const;

private:
  QScopedPointer<Ui::ChangePasswordDialog> m_ui;

  Q_SLOT void checkPassword(const QString& _password);
};

}
