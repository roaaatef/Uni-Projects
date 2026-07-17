/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePage
{
public:
    QLabel *player1nameLabel;
    QLabel *player2nameLabel;
    QPushButton *homeButton;
    QPushButton *pushButton_0_2;
    QPushButton *pushButton_1_0;
    QPushButton *pushButton_2_1;
    QPushButton *pushButton_1_1;
    QPushButton *pushButton_1_2;
    QPushButton *pushButton_0_0;
    QPushButton *pushButton_0_1;
    QPushButton *pushButton_2_2;
    QPushButton *pushButton_2_0;

    void setupUi(QWidget *GamePage)
    {
        if (GamePage->objectName().isEmpty())
            GamePage->setObjectName("GamePage");
        GamePage->resize(600, 600);
        player1nameLabel = new QLabel(GamePage);
        player1nameLabel->setObjectName("player1nameLabel");
        player1nameLabel->setGeometry(QRect(110, 30, 111, 20));
        player2nameLabel = new QLabel(GamePage);
        player2nameLabel->setObjectName("player2nameLabel");
        player2nameLabel->setGeometry(QRect(372, 30, 131, 20));
        homeButton = new QPushButton(GamePage);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(250, 530, 93, 29));
        pushButton_0_2 = new QPushButton(GamePage);
        pushButton_0_2->setObjectName("pushButton_0_2");
        pushButton_0_2->setGeometry(QRect(350, 100, 133, 133));
        QFont font;
        font.setPointSize(48);
        pushButton_0_2->setFont(font);
        pushButton_1_0 = new QPushButton(GamePage);
        pushButton_1_0->setObjectName("pushButton_1_0");
        pushButton_1_0->setGeometry(QRect(90, 230, 133, 133));
        pushButton_1_0->setFont(font);
        pushButton_2_1 = new QPushButton(GamePage);
        pushButton_2_1->setObjectName("pushButton_2_1");
        pushButton_2_1->setGeometry(QRect(220, 360, 133, 133));
        pushButton_2_1->setFont(font);
        pushButton_1_1 = new QPushButton(GamePage);
        pushButton_1_1->setObjectName("pushButton_1_1");
        pushButton_1_1->setGeometry(QRect(220, 230, 133, 133));
        pushButton_1_1->setFont(font);
        pushButton_1_2 = new QPushButton(GamePage);
        pushButton_1_2->setObjectName("pushButton_1_2");
        pushButton_1_2->setGeometry(QRect(350, 230, 133, 133));
        pushButton_1_2->setFont(font);
        pushButton_0_0 = new QPushButton(GamePage);
        pushButton_0_0->setObjectName("pushButton_0_0");
        pushButton_0_0->setGeometry(QRect(90, 100, 133, 133));
        pushButton_0_0->setFont(font);
        pushButton_0_1 = new QPushButton(GamePage);
        pushButton_0_1->setObjectName("pushButton_0_1");
        pushButton_0_1->setGeometry(QRect(220, 100, 133, 133));
        pushButton_0_1->setFont(font);
        pushButton_2_2 = new QPushButton(GamePage);
        pushButton_2_2->setObjectName("pushButton_2_2");
        pushButton_2_2->setGeometry(QRect(350, 360, 133, 133));
        pushButton_2_2->setFont(font);
        pushButton_2_0 = new QPushButton(GamePage);
        pushButton_2_0->setObjectName("pushButton_2_0");
        pushButton_2_0->setGeometry(QRect(90, 360, 133, 133));
        pushButton_2_0->setFont(font);

        retranslateUi(GamePage);

        QMetaObject::connectSlotsByName(GamePage);
    } // setupUi

    void retranslateUi(QWidget *GamePage)
    {
        GamePage->setWindowTitle(QCoreApplication::translate("GamePage", "Form", nullptr));
        player1nameLabel->setText(QCoreApplication::translate("GamePage", "TextLabel", nullptr));
        player2nameLabel->setText(QCoreApplication::translate("GamePage", "TextLabel", nullptr));
        homeButton->setText(QCoreApplication::translate("GamePage", "Quit", nullptr));
        pushButton_0_2->setText(QString());
        pushButton_1_0->setText(QString());
        pushButton_2_1->setText(QString());
        pushButton_1_1->setText(QString());
        pushButton_1_2->setText(QString());
        pushButton_0_0->setText(QString());
        pushButton_0_1->setText(QString());
        pushButton_2_2->setText(QString());
        pushButton_2_0->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GamePage: public Ui_GamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
