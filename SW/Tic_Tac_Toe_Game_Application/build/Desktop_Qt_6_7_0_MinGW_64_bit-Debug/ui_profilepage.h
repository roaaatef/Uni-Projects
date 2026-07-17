/********************************************************************************
** Form generated from reading UI file 'profilepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEPAGE_H
#define UI_PROFILEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfilePage
{
public:
    QLabel *profileLabel;
    QPushButton *loadHistoryButton;
    QPushButton *homeButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *usernameLabel;
    QLabel *emailLabel;
    QTableView *historyTableView;
    QLabel *label;
    QPushButton *logoutButton;

    void setupUi(QWidget *ProfilePage)
    {
        if (ProfilePage->objectName().isEmpty())
            ProfilePage->setObjectName("ProfilePage");
        ProfilePage->resize(600, 600);
        profileLabel = new QLabel(ProfilePage);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(250, 30, 91, 20));
        loadHistoryButton = new QPushButton(ProfilePage);
        loadHistoryButton->setObjectName("loadHistoryButton");
        loadHistoryButton->setGeometry(QRect(230, 109, 96, 29));
        homeButton = new QPushButton(ProfilePage);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(70, 550, 93, 29));
        layoutWidget = new QWidget(ProfilePage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(91, 57, 401, 49));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(layoutWidget);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout->addWidget(usernameLabel);

        emailLabel = new QLabel(layoutWidget);
        emailLabel->setObjectName("emailLabel");

        verticalLayout->addWidget(emailLabel);

        historyTableView = new QTableView(ProfilePage);
        historyTableView->setObjectName("historyTableView");
        historyTableView->setGeometry(QRect(41, 158, 511, 311));
        label = new QLabel(ProfilePage);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 470, 291, 20));
        logoutButton = new QPushButton(ProfilePage);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(390, 550, 93, 29));

        retranslateUi(ProfilePage);

        QMetaObject::connectSlotsByName(ProfilePage);
    } // setupUi

    void retranslateUi(QWidget *ProfilePage)
    {
        ProfilePage->setWindowTitle(QCoreApplication::translate("ProfilePage", "Form", nullptr));
        profileLabel->setText(QCoreApplication::translate("ProfilePage", "Profile", nullptr));
        loadHistoryButton->setText(QCoreApplication::translate("ProfilePage", "Show History", nullptr));
        homeButton->setText(QCoreApplication::translate("ProfilePage", "Back", nullptr));
        usernameLabel->setText(QString());
        emailLabel->setText(QString());
        label->setText(QCoreApplication::translate("ProfilePage", "Click on Replay to view the game moves", nullptr));
        logoutButton->setText(QCoreApplication::translate("ProfilePage", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfilePage: public Ui_ProfilePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEPAGE_H
