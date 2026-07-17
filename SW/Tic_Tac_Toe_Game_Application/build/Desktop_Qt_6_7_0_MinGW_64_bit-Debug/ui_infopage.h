/********************************************************************************
** Form generated from reading UI file 'infopage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOPAGE_H
#define UI_INFOPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoPage
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLabel *objectiveLabel;
    QLabel *componentsLabel;
    QLabel *symbolsLabel;
    QLabel *turnsLabel;
    QLabel *rulesLabel;
    QPushButton *homeButton;

    void setupUi(QWidget *InfoPage)
    {
        if (InfoPage->objectName().isEmpty())
            InfoPage->setObjectName("InfoPage");
        InfoPage->resize(600, 600);
        widget = new QWidget(InfoPage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 40, 472, 513));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName("nameLabel");

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        objectiveLabel = new QLabel(widget);
        objectiveLabel->setObjectName("objectiveLabel");

        gridLayout->addWidget(objectiveLabel, 1, 0, 1, 1);

        componentsLabel = new QLabel(widget);
        componentsLabel->setObjectName("componentsLabel");

        gridLayout->addWidget(componentsLabel, 2, 0, 1, 1);

        symbolsLabel = new QLabel(widget);
        symbolsLabel->setObjectName("symbolsLabel");

        gridLayout->addWidget(symbolsLabel, 3, 0, 1, 1);

        turnsLabel = new QLabel(widget);
        turnsLabel->setObjectName("turnsLabel");

        gridLayout->addWidget(turnsLabel, 4, 0, 1, 1);

        rulesLabel = new QLabel(widget);
        rulesLabel->setObjectName("rulesLabel");

        gridLayout->addWidget(rulesLabel, 5, 0, 1, 1);

        homeButton = new QPushButton(widget);
        homeButton->setObjectName("homeButton");

        gridLayout->addWidget(homeButton, 6, 0, 1, 1);


        retranslateUi(InfoPage);

        QMetaObject::connectSlotsByName(InfoPage);
    } // setupUi

    void retranslateUi(QWidget *InfoPage)
    {
        InfoPage->setWindowTitle(QCoreApplication::translate("InfoPage", "Form", nullptr));
        nameLabel->setText(QCoreApplication::translate("InfoPage", "Tic Tac Toe Game", nullptr));
        objectiveLabel->setText(QCoreApplication::translate("InfoPage", "Objective: \n"
" The objective of Tic Tac Toe is to be the first player to create a line \n"
" (horizontal, vertical, or diagonal) of three of your symbols (X or O)\n"
" on the game board", nullptr));
        componentsLabel->setText(QCoreApplication::translate("InfoPage", "Game Components:\n"
" Game Board: The game board consists of a 3x3 grid where players\n"
" will place their symbols ", nullptr));
        symbolsLabel->setText(QCoreApplication::translate("InfoPage", "Symbols:\n"
" Players use two distinct symbols, typically X and O", nullptr));
        turnsLabel->setText(QCoreApplication::translate("InfoPage", "Turns: \n"
" Players take turns placing their symbols on empty spaces of the board", nullptr));
        rulesLabel->setText(QCoreApplication::translate("InfoPage", "Game Rules:\n"
" 1) Players alternate turns, starting with one player placing their symbol \n"
" (X or O) on an empty space of the board\n"
"\n"
" 2) The game continues until a player achieves a line of three of their\n"
" symbols in a row (horizontal, vertical, or diagonal) or until all spaces \n"
" on the board are filled \n"
"\n"
" 3)If all spaces are filled without a line of three symbols, the game ends\n"
" in a draw.  ", nullptr));
        homeButton->setText(QCoreApplication::translate("InfoPage", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoPage: public Ui_InfoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOPAGE_H
