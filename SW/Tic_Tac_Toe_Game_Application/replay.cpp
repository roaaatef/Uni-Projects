#include "replay.h"
#include "ui_replay.h"

#include "Global.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QVector>
#include <QPair>
#include <QThread>


Replay::Replay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Replay)
{
    ui->setupUi(this);
    connect(ui->profile, &QPushButton::clicked, this, &Replay::handleProfile);
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QString buttonName = "pushButton_" + QString::number(row) +"_"+ QString::number(col);
            boxes[row][col] = findChild<QPushButton*>(buttonName);
        }
    }
}

Replay::~Replay()
{
    delete ui;
}

void Replay::start(const int gameid){
    ID = gameid;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            boxes[i][j]->setText(" ");
        }
    }
    i=0;
    QVector<QPair<int,int>> movereplay = getGameHistory(ID);
    printhistory(movereplay);
}

QVector<QPair<int,int>> Replay::getGameHistory(const int gameid) {

    QVector<QPair<int, int>> moves; // Pair of game_id and moves

    QSqlDatabase game_db = QSqlDatabase::addDatabase("QSQLITE");
    game_db.setDatabaseName("C:/Users/DELL/Downloads/Tic_Tac_Toe_Game_Application/Tic_Tac_Toe_Game_Application/Game_db.db");
    if (game_db.open()) {
        QSqlQuery query;
        query.prepare("SELECT moves FROM Game_H WHERE ID = :gameid");
        query.bindValue(":gameid", gameid);
        if (!query.exec()) {
            QMessageBox::critical(nullptr,"Error","Error! couldn't get the moves");
        } else {
            while (query.next()) {
                QString history = query.value(0).toString();
                QJsonDocument jsonDoc = QJsonDocument::fromJson(history.toUtf8());
                QJsonArray jsonArray = jsonDoc.array();
                for (const QJsonValue& value : jsonArray) {
                    QJsonObject jsonObj = value.toObject();
                    int row = jsonObj["row"].toInt();
                    int col = jsonObj["col"].toInt();
                    moves.append(qMakePair(row, col));
                }
            }
        }
        return moves;
    }
    else {
        // Handle database connection failure.
        qDebug()<<"Database not connected";
        return {{NULL,NULL}};
    }
}

void Replay::delay(int n)
{
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Replay::printhistory (QVector<QPair<int,int>> retrievedMoves){
     int size = retrievedMoves.size();
     QPair<int,int> move = retrievedMoves[i];
    if (i % 2 == 0 ){
        boxes[move.first][move.second]->setText("X");
        i++;
        if (i>=size){
            QMessageBox::information(nullptr,"Game over","No more moves");
        }
    }
    else {
        boxes[move.first][move.second]->setText("O");
        i++;
        if (i>=size){
            QMessageBox::information(nullptr,"Game over","No more moves");
        }
    }
}
    // for (const auto& move : retrievedMoves) {
    //     if (i % 2 == 0){
    //         boxes[move.first][move.second]->setText("O");
    //         i++;
    //         delay(1);
    //     }
    //     else{
    //         boxes[move.first][move.second]->setText("X");
    //         i++;
    //         delay(1);
    //     }
    // }
    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         boxes[i][j]->setText(" ");
    //     }
    // }


void Replay::on_againButton_clicked()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            boxes[i][j]->setText(" ");
        }
    }
    i=0;
    QVector<QPair<int,int>> movereplay = getGameHistory(ID);
    printhistory(movereplay);
}

void Replay::handleProfile(){
    emit profileRequested();
}

void Replay::on_next_clicked()
{
    QVector<QPair<int,int>> movereplay = getGameHistory(ID);
    printhistory(movereplay);
}

