#include "gamepage.h"
#include "ui_gamepage.h"
#include "Global.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QVector>
#include <QPair>

GamePage::GamePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePage)
    ,board{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},currentPlayer(1)
{
    ui->setupUi(this);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QString buttonName = "pushButton_" + QString::number(row) +"_"+ QString::number(col);
            boxes[row][col] = findChild<QPushButton*>(buttonName);
        }
    }

    connect(ui->homeButton, &QPushButton::clicked, this, &GamePage::handleHome);

    QObject::connect(ui->pushButton_0_0,&QPushButton::clicked,this,&GamePage::on_pb_0_0_clicked);
    QObject::connect(ui->pushButton_0_1,&QPushButton::clicked,this,&GamePage::on_pb_0_1_clicked);
    QObject::connect(ui->pushButton_0_2,&QPushButton::clicked,this,&GamePage::on_pb_0_2_clicked);
    QObject::connect(ui->pushButton_1_0,&QPushButton::clicked,this,&GamePage::on_pb_1_0_clicked);
    QObject::connect(ui->pushButton_1_1,&QPushButton::clicked,this,&GamePage::on_pb_1_1_clicked);
    QObject::connect(ui->pushButton_1_2,&QPushButton::clicked,this,&GamePage::on_pb_1_2_clicked);
    QObject::connect(ui->pushButton_2_0,&QPushButton::clicked,this,&GamePage::on_pb_2_0_clicked);
    QObject::connect(ui->pushButton_2_1,&QPushButton::clicked,this,&GamePage::on_pb_2_1_clicked);
    QObject::connect(ui->pushButton_2_2,&QPushButton::clicked,this,&GamePage::on_pb_2_2_clicked);

    QObject::connect(this,&GamePage::MoveMade,this,&GamePage::handleMove);
}

GamePage::~GamePage()
{
    delete ui;
}

void GamePage::handleHome(){
    emit homeRequested();
    resetGame();
}

void GamePage::setGameMode(const QString &player1Name, const QString &player2Name, const QString &gamemode){
    GameMode= gamemode;
    ui->player1nameLabel->setText("player 1: "+player1Name);
    ui->player2nameLabel->setText("player 2: "+player2Name);
    player_1=player1Name;
    player_2=(player2Name=="AI")? "AI":player2Name;
}

void GamePage::on_pb_0_0_clicked(){ emit MoveMade(0, 0);}
void GamePage::on_pb_0_1_clicked(){ emit MoveMade(0, 1);}
void GamePage::on_pb_0_2_clicked(){ emit MoveMade(0, 2);}
void GamePage::on_pb_1_0_clicked(){ emit MoveMade(1, 0);}
void GamePage::on_pb_1_1_clicked(){ emit MoveMade(1, 1);}
void GamePage::on_pb_1_2_clicked(){ emit MoveMade(1, 2);}
void GamePage::on_pb_2_0_clicked(){ emit MoveMade(2, 0);}
void GamePage::on_pb_2_1_clicked(){ emit MoveMade(2, 1);}
void GamePage::on_pb_2_2_clicked(){ emit MoveMade(2, 2);}

void GamePage::handleMove(int row, int col){

    // Update board and UI
    if (board[row][col] == 0) {
        board[row][col] = currentPlayer;
        if (currentPlayer == 1){
            boxes[row][col]->setText("X");
            moves.append(QPair<int, int>(row,col));
            check();
            if (currentPlayer == 2 && player_2=="AI") makemove();
        }
        else if(currentPlayer == 2){
            boxes[row][col]->setText("O");
            moves.append(QPair<int, int>(row,col));
            check();
        }
    }
}

int GamePage::checkWin(){
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] != 0 && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return 0;
}

bool GamePage::checkDraw(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                return false; // Found an empty cell, game is not draw
            }
        }
    }
    return true; // All cells are filled, game is draw
}

int GamePage::state(){
    if (checkWin()==1) {
        return  10  ;
    }else if (checkWin()==2) {
        return  -10  ;
    }else if (checkDraw()) {
        return 0;
    } else {
        return 1;
    }
}

void GamePage::check(){
    result = state();
    if (result == 10) {
        winner =player_1;
        QMessageBox::information(this, "Game Over", winner + " wins!");
        QString serializedData = serializeMovesToJson(moves);
        storeGameHistory( winner + " won",serializedData);
        resetGame();
    } else if (result == -10) {
        winner =player_2;
        QMessageBox::information(this, "Game Over", winner + " wins!");
        QString serializedData = serializeMovesToJson(moves);
        storeGameHistory( winner + " won",serializedData);
        resetGame();
    } else if(result == 0) {
        QMessageBox::information(this, "Game Over", "It's a draw!");
        QString serializedData = serializeMovesToJson(moves);
        storeGameHistory( "draw",serializedData);
        resetGame();
    } else {
        currentPlayer =(currentPlayer==1)? 2 : 1;
    }
}

void GamePage::resetGame() {
    // Reset game state and UI
    currentPlayer = 1;
    moves.clear();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 0;
            boxes[i][j]->setText(" ");
        }
    }
}

void GamePage::makemove(){
    int bestmove = INFINITY;
    int finalI, finalJ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 0) {
                board[i][j] = 2;
                int score = minimax(board,0,true);
                board[i][j] = 0;
                if(score < bestmove) {
                    bestmove = score;
                    finalI = i;
                    finalJ = j;
                }
            }
        }
    }
    board[finalI][finalJ]=2;
    boxes[finalI][finalJ]->setText("O");
    moves.append(QPair<int, int>(finalI,finalJ));
    check();
}

int GamePage::minimax (int board2[3][3], int depth, bool isMaximizing ) {

    int still = state();

    if(still != 1) {
        return still ;
    }

    if(isMaximizing) {
        int finalScore = -INFINITY;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board2[i][j] == 0) {
                    board2[i][j] = 1;
                    int score = minimax(board2, depth + 1, false);
                    board2[i][j] = 0;
                    if(score > finalScore) {
                        finalScore = score;
                    }
                }
            }
        }
        return finalScore;
    }else {
        int finalScore = INFINITY;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board2[i][j] == 0) {
                    board2[i][j] = 2;
                    int score = minimax(board2, depth + 1, true);
                    board2[i][j] = 0;
                    if(score < finalScore) {
                        finalScore = score;
                    }
                }
            }
        }
        return finalScore;
    }
}

QString GamePage::serializeMovesToJson(const QVector<QPair<int, int>>& moves) {
    QJsonArray movesArray;
    for (const auto& moves : moves) {
        QJsonObject obj;
        obj["row"] = moves.first;
        obj["col"] = moves.second;
        movesArray.append(obj);
    }

    QJsonDocument doc(movesArray);
    return doc.toJson();
}

void GamePage::storeGameHistory(QString result,QString moves){
    QSqlDatabase game_db = QSqlDatabase::addDatabase("QSQLITE");
    game_db.setDatabaseName("C:/Users/DELL/Downloads/Tic_Tac_Toe_Game_Application/Tic_Tac_Toe_Game_Application/Game_db.db");
    if (game_db.open()) {
        QSqlQuery query;
        query.prepare("INSERT INTO Game_H (User_ID, GameMode, Player_1, Player_2, result, moves) VALUES (:userID, :gameMode, :player1, :player2, :result, :moves)");
        query.bindValue(":userID", UserID);
        query.bindValue(":gameMode", GameMode);
        query.bindValue(":player1", player_1);
        query.bindValue(":player2", player_2);
        query.bindValue(":result", result);
        query.bindValue(":moves", moves);
        //query.prepare("UPDATE Game_H SET result = :result, moves = :moves WHERE ID = :id");
        if (!query.exec()){
            QMessageBox::critical(nullptr,"Error","Error! couldn't store moves");
        } else{
            qDebug() << "Game history saved successfully.";
            GameID = query.lastInsertId().toInt();  // Get the ID of the newly inserted game.
        }
        game_db.close();
    } else {
        // Handle database connection failure.
        qDebug()<<"Database not connected";
    }
}




