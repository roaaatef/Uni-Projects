#include "playernamespage.h"
#include "ui_playernamespage.h"
#include <QtSql>
#include <QMessageBox>

PlayerNamesPage::PlayerNamesPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayerNamesPage)
{
    ui->setupUi(this);

    connect(ui->startGameButton, &QPushButton::clicked, this, &PlayerNamesPage::handleStartGame);
    connect(ui->homeBottom, &QPushButton::clicked, this, &PlayerNamesPage::handleHome);
}

PlayerNamesPage::~PlayerNamesPage()
{
    delete ui;
}

void PlayerNamesPage::setGameMode(const QString &gameMode) {
    if (gameMode == "1 Player") {
        ui->player2LineEdit->setDisabled(true);
        ui->player2LineEdit->setText("AI");
    } else {
        ui->player2LineEdit->setEnabled(true);
        ui->player2LineEdit->clear();
    }
    gamemode=gameMode;
}

void PlayerNamesPage::handleStartGame() {
    if (ui->player1LineEdit->text().isEmpty() || ui->player2LineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Players Names", "Please fill in all fields.");
    } else {
        QString player1Name = ui->player1LineEdit->text();
        QString player2Name = ui->player2LineEdit->text();
        emit startGame(player1Name, player2Name, gamemode);
        ui->player1LineEdit->clear();
        (ui->player1LineEdit->text()=="AI")? ui->player2LineEdit->setText("AI"):ui->player2LineEdit->clear();
    }
}

void PlayerNamesPage::handleHome() {
    emit HomeRequested();
    ui->player1LineEdit->clear();
    (ui->player1LineEdit->text()=="AI")? ui->player2LineEdit->setText("AI"):ui->player2LineEdit->clear();
}
