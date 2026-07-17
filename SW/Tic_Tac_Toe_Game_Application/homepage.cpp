#include "homepage.h"
#include "ui_homepage.h"
#include "Global.h"
#include <QtSql>
#include <QMessageBox>

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);

    connect(ui->profileButton, &QPushButton::clicked, this, &HomePage::handleProfile);
    connect(ui->infoButton, &QPushButton::clicked, this, &HomePage::handleInfo);

    connect(ui->twoPlayersButton, &QPushButton::clicked, this, &HomePage::handleTwoPlayers);
    connect(ui->onePlayerVsAIButton, &QPushButton::clicked, this, &HomePage::handleOnePlayerVsAI);
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::handleTwoPlayers() {
    emit gameModeChosen("2 Players");
}

void HomePage::handleOnePlayerVsAI() {
    emit gameModeChosen("1 Player");
}

void HomePage::handleProfile(){
    emit profileRequested();
}
void HomePage::handleInfo(){
    emit infoRequested();
}
