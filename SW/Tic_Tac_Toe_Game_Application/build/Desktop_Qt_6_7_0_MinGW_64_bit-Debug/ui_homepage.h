/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QPushButton *onePlayerVsAIButton;
    QPushButton *twoPlayersButton;
    QPushButton *profileButton;
    QPushButton *infoButton;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName("HomePage");
        HomePage->resize(600, 600);
        onePlayerVsAIButton = new QPushButton(HomePage);
        onePlayerVsAIButton->setObjectName("onePlayerVsAIButton");
        onePlayerVsAIButton->setGeometry(QRect(225, 410, 150, 30));
        twoPlayersButton = new QPushButton(HomePage);
        twoPlayersButton->setObjectName("twoPlayersButton");
        twoPlayersButton->setGeometry(QRect(225, 450, 150, 30));
        profileButton = new QPushButton(HomePage);
        profileButton->setObjectName("profileButton");
        profileButton->setGeometry(QRect(30, 90, 200, 29));
        infoButton = new QPushButton(HomePage);
        infoButton->setObjectName("infoButton");
        infoButton->setGeometry(QRect(372, 90, 200, 29));

        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QCoreApplication::translate("HomePage", "Form", nullptr));
        onePlayerVsAIButton->setText(QCoreApplication::translate("HomePage", "1 Player", nullptr));
        twoPlayersButton->setText(QCoreApplication::translate("HomePage", "2 Players", nullptr));
        profileButton->setText(QCoreApplication::translate("HomePage", "Profile", nullptr));
        infoButton->setText(QCoreApplication::translate("HomePage", "info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
