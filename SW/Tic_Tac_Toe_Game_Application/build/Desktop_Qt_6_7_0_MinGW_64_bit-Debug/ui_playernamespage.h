/********************************************************************************
** Form generated from reading UI file 'playernamespage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERNAMESPAGE_H
#define UI_PLAYERNAMESPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerNamesPage
{
public:
    QGroupBox *player1groupBox;
    QFormLayout *formLayout;
    QLineEdit *player1LineEdit;
    QPushButton *homeBottom;
    QPushButton *startGameButton;
    QGroupBox *player2groupBox_2;
    QFormLayout *formLayout_2;
    QLineEdit *player2LineEdit;

    void setupUi(QWidget *PlayerNamesPage)
    {
        if (PlayerNamesPage->objectName().isEmpty())
            PlayerNamesPage->setObjectName("PlayerNamesPage");
        PlayerNamesPage->resize(600, 600);
        player1groupBox = new QGroupBox(PlayerNamesPage);
        player1groupBox->setObjectName("player1groupBox");
        player1groupBox->setGeometry(QRect(150, 180, 300, 100));
        formLayout = new QFormLayout(player1groupBox);
        formLayout->setObjectName("formLayout");
        player1LineEdit = new QLineEdit(player1groupBox);
        player1LineEdit->setObjectName("player1LineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, player1LineEdit);

        homeBottom = new QPushButton(PlayerNamesPage);
        homeBottom->setObjectName("homeBottom");
        homeBottom->setGeometry(QRect(40, 40, 93, 29));
        startGameButton = new QPushButton(PlayerNamesPage);
        startGameButton->setObjectName("startGameButton");
        startGameButton->setGeometry(QRect(250, 510, 100, 29));
        player2groupBox_2 = new QGroupBox(PlayerNamesPage);
        player2groupBox_2->setObjectName("player2groupBox_2");
        player2groupBox_2->setGeometry(QRect(150, 310, 300, 100));
        formLayout_2 = new QFormLayout(player2groupBox_2);
        formLayout_2->setObjectName("formLayout_2");
        player2LineEdit = new QLineEdit(player2groupBox_2);
        player2LineEdit->setObjectName("player2LineEdit");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, player2LineEdit);


        retranslateUi(PlayerNamesPage);

        QMetaObject::connectSlotsByName(PlayerNamesPage);
    } // setupUi

    void retranslateUi(QWidget *PlayerNamesPage)
    {
        PlayerNamesPage->setWindowTitle(QCoreApplication::translate("PlayerNamesPage", "Form", nullptr));
        player1groupBox->setTitle(QCoreApplication::translate("PlayerNamesPage", "Player 1: X", nullptr));
        homeBottom->setText(QCoreApplication::translate("PlayerNamesPage", "Home", nullptr));
        startGameButton->setText(QCoreApplication::translate("PlayerNamesPage", "Start Game!", nullptr));
        player2groupBox_2->setTitle(QCoreApplication::translate("PlayerNamesPage", "Player 2: O ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerNamesPage: public Ui_PlayerNamesPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERNAMESPAGE_H
