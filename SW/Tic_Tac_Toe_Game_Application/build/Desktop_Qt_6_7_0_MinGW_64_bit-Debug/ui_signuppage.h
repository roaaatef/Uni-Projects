/********************************************************************************
** Form generated from reading UI file 'signuppage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPPAGE_H
#define UI_SIGNUPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpPage
{
public:
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLabel *emailLabel;
    QLabel *passwordLabel;
    QLabel *loginLabel;
    QPushButton *loginButton;
    QPushButton *signupButton;
    QLineEdit *passwordLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *usernameLineEdit;
    QLabel *statusLabel;

    void setupUi(QWidget *SignUpPage)
    {
        if (SignUpPage->objectName().isEmpty())
            SignUpPage->setObjectName("SignUpPage");
        SignUpPage->resize(600, 600);
        groupBox = new QGroupBox(SignUpPage);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(125, 125, 350, 350));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        usernameLabel = new QLabel(groupBox);
        usernameLabel->setObjectName("usernameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        emailLabel = new QLabel(groupBox);
        emailLabel->setObjectName("emailLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, emailLabel);

        passwordLabel = new QLabel(groupBox);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, passwordLabel);

        loginLabel = new QLabel(groupBox);
        loginLabel->setObjectName("loginLabel");

        formLayout->setWidget(7, QFormLayout::SpanningRole, loginLabel);

        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName("loginButton");

        formLayout->setWidget(8, QFormLayout::LabelRole, loginButton);

        signupButton = new QPushButton(groupBox);
        signupButton->setObjectName("signupButton");

        formLayout->setWidget(9, QFormLayout::FieldRole, signupButton);

        passwordLineEdit = new QLineEdit(groupBox);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(5, QFormLayout::SpanningRole, passwordLineEdit);

        emailLineEdit = new QLineEdit(groupBox);
        emailLineEdit->setObjectName("emailLineEdit");

        formLayout->setWidget(3, QFormLayout::SpanningRole, emailLineEdit);

        usernameLineEdit = new QLineEdit(groupBox);
        usernameLineEdit->setObjectName("usernameLineEdit");

        formLayout->setWidget(1, QFormLayout::SpanningRole, usernameLineEdit);

        statusLabel = new QLabel(groupBox);
        statusLabel->setObjectName("statusLabel");

        formLayout->setWidget(6, QFormLayout::SpanningRole, statusLabel);


        retranslateUi(SignUpPage);

        QMetaObject::connectSlotsByName(SignUpPage);
    } // setupUi

    void retranslateUi(QWidget *SignUpPage)
    {
        SignUpPage->setWindowTitle(QCoreApplication::translate("SignUpPage", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SignUpPage", "Sign Up", nullptr));
        usernameLabel->setText(QCoreApplication::translate("SignUpPage", "Username", nullptr));
        emailLabel->setText(QCoreApplication::translate("SignUpPage", "Email", nullptr));
        passwordLabel->setText(QCoreApplication::translate("SignUpPage", "Password", nullptr));
        loginLabel->setText(QCoreApplication::translate("SignUpPage", "Already have an account?", nullptr));
        loginButton->setText(QCoreApplication::translate("SignUpPage", "Login", nullptr));
        signupButton->setText(QCoreApplication::translate("SignUpPage", "Sign up", nullptr));
        statusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignUpPage: public Ui_SignUpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPPAGE_H
