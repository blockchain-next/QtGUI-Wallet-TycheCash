// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <QDialog>

namespace Ui {
class AboutDialog;
}

namespace WalletGui {

class AboutDialog : public QDialog {
  Q_OBJECT
  Q_DISABLE_COPY(AboutDialog)

public:
  AboutDialog(QWidget* _parent);
  ~AboutDialog();

private:
  QScopedPointer<Ui::AboutDialog> m_ui;
};

}
