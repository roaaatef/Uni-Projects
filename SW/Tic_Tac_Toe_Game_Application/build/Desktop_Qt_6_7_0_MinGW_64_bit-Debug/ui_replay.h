/********************************************************************************
** Form generated from reading UI file 'replay.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAY_H
#define UI_REPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Replay
{
public:
    QPushButton *pushButton_0_2;
    QPushButton *pushButton_1_1;
    QPushButton *pushButton_2_1;
    QPushButton *pushButton_0_0;
    QPushButton *pushButton_1_2;
    QPushButton *pushButton_0_1;
    QPushButton *pushButton_2_0;
    QPushButton *pushButton_2_2;
    QPushButton *againButton;
    QPushButton *pushButton_1_0;
    QPushButton *profile;
    QPushButton *next;

    void setupUi(QWidget *Replay)
    {
        if (Replay->objectName().isEmpty())
            Replay->setObjectName("Replay");
        Replay->resize(600, 600);
        pushButton_0_2 = new QPushButton(Replay);
        pushButton_0_2->setObjectName("pushButton_0_2");
        pushButton_0_2->setGeometry(QRect(370, 120, 133, 133));
        QFont font;
        font.setPointSize(48);
        pushButton_0_2->setFont(font);
        pushButton_1_1 = new QPushButton(Replay);
        pushButton_1_1->setObjectName("pushButton_1_1");
        pushButton_1_1->setGeometry(QRect(240, 250, 133, 133));
        pushButton_1_1->setFont(font);
        pushButton_2_1 = new QPushButton(Replay);
        pushButton_2_1->setObjectName("pushButton_2_1");
        pushButton_2_1->setGeometry(QRect(240, 380, 133, 133));
        pushButton_2_1->setFont(font);
        pushButton_0_0 = new QPushButton(Replay);
        pushButton_0_0->setObjectName("pushButton_0_0");
        pushButton_0_0->setGeometry(QRect(110, 120, 133, 133));
        pushButton_0_0->setFont(font);
        pushButton_1_2 = new QPushButton(Replay);
        pushButton_1_2->setObjectName("pushButton_1_2");
        pushButton_1_2->setGeometry(QRect(370, 250, 133, 133));
        pushButton_1_2->setFont(font);
        pushButton_0_1 = new QPushButton(Replay);
        pushButton_0_1->setObjectName("pushButton_0_1");
        pushButton_0_1->setGeometry(QRect(240, 120, 133, 133));
        pushButton_0_1->setFont(font);
        pushButton_2_0 = new QPushButton(Replay);
        pushButton_2_0->setObjectName("pushButton_2_0");
        pushButton_2_0->setGeometry(QRect(110, 380, 133, 133));
        pushButton_2_0->setFont(font);
        pushButton_2_2 = new QPushButton(Replay);
        pushButton_2_2->setObjectName("pushButton_2_2");
        pushButton_2_2->setGeometry(QRect(370, 380, 133, 133));
        pushButton_2_2->setFont(font);
        againButton = new QPushButton(Replay);
        againButton->setObjectName("againButton");
        againButton->setGeometry(QRect(120, 540, 93, 29));
        pushButton_1_0 = new QPushButton(Replay);
        pushButton_1_0->setObjectName("pushButton_1_0");
        pushButton_1_0->setGeometry(QRect(110, 250, 133, 133));
        pushButton_1_0->setFont(font);
        profile = new QPushButton(Replay);
        profile->setObjectName("profile");
        profile->setGeometry(QRect(410, 540, 93, 29));
        next = new QPushButton(Replay);
        next->setObjectName("next");
        next->setGeometry(QRect(260, 540, 93, 29));
        pushButton_0_0->raise();
        pushButton_1_0->raise();
        pushButton_2_0->raise();
        pushButton_0_1->raise();
        pushButton_0_2->raise();
        pushButton_1_1->raise();
        pushButton_2_1->raise();
        pushButton_1_2->raise();
        pushButton_2_2->raise();
        againButton->raise();
        profile->raise();
        next->raise();

        retranslateUi(Replay);

        QMetaObject::connectSlotsByName(Replay);
    } // setupUi

    void retranslateUi(QWidget *Replay)
    {
        Replay->setWindowTitle(QCoreApplication::translate("Replay", "Form", nullptr));
        pushButton_0_2->setText(QString());
        pushButton_1_1->setText(QString());
        pushButton_2_1->setText(QString());
        pushButton_0_0->setText(QString());
        pushButton_1_2->setText(QString());
        pushButton_0_1->setText(QString());
        pushButton_2_0->setText(QString());
        pushButton_2_2->setText(QString());
        againButton->setText(QCoreApplication::translate("Replay", "Replay again", nullptr));
        pushButton_1_0->setText(QString());
        profile->setText(QCoreApplication::translate("Replay", "Back", nullptr));
        next->setText(QCoreApplication::translate("Replay", "Next move", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Replay: public Ui_Replay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAY_H
