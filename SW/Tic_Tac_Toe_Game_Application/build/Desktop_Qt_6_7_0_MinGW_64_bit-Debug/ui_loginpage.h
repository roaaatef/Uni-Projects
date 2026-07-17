/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *emailLineEdit;
    QPushButton *signupButton;
    QLabel *signupLabel;
    QLabel *statusLabel;
    QLabel *emailLabel;
    QLabel *passwordLabel;
    QPushButton *loginButton;
    QLineEdit *passwordLineEdit;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(600, 600);
        groupBox = new QGroupBox(LoginPage);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(125, 120, 350, 350));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        emailLineEdit = new QLineEdit(groupBox);
        emailLineEdit->setObjectName("emailLineEdit");

        gridLayout->addWidget(emailLineEdit, 1, 0, 1, 1);

        signupButton = new QPushButton(groupBox);
        signupButton->setObjectName("signupButton");

        gridLayout->addWidget(signupButton, 8, 0, 1, 1);

        signupLabel = new QLabel(groupBox);
        signupLabel->setObjectName("signupLabel");

        gridLayout->addWidget(signupLabel, 7, 0, 1, 2);

        statusLabel = new QLabel(groupBox);
        statusLabel->setObjectName("statusLabel");

        gridLayout->addWidget(statusLabel, 5, 0, 1, 3);

        emailLabel = new QLabel(groupBox);
        emailLabel->setObjectName("emailLabel");

        gridLayout->addWidget(emailLabel, 0, 0, 1, 2);

        passwordLabel = new QLabel(groupBox);
        passwordLabel->setObjectName("passwordLabel");

        gridLayout->addWidget(passwordLabel, 3, 0, 1, 2);

        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName("loginButton");

        gridLayout->addWidget(loginButton, 10, 2, 1, 1);

        passwordLineEdit = new QLineEdit(groupBox);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 4, 0, 1, 1);


        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LoginPage", "Login", nullptr));
        signupButton->setText(QCoreApplication::translate("LoginPage", "Sign Up", nullptr));
        signupLabel->setText(QCoreApplication::translate("LoginPage", "New to TicTacToe?", nullptr));
        statusLabel->setText(QString());
        emailLabel->setText(QCoreApplication::translate("LoginPage", "Email", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginPage", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginPage", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
