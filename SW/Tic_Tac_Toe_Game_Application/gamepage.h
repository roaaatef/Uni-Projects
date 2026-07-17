#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QPair>
#include <QVector>

namespace Ui {
class GamePage;
}

class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();

    //Function for game logic
    int checkWin();
    bool checkDraw();
    int minimax (int board[3][3], int depth , bool isMaximizing);
    void makemove();
    int state();
    void check();
    void resetGame();
    QString serializeMovesToJson(const QVector<QPair<int, int>>& moves);
    void storeGameHistory(QString result,QString moves);


private:
    Ui::GamePage *ui;

    QPushButton *boxes[3][3];
    int board[3][3];    // 0: empty, 1: player 1, 2: player 2
    QString GameMode;
    QString player_1;   //Player 1 (X), Player 2 (O)
    QString player_2;
    QString winner;
    int currentPlayer;  //1=X,2=O
    int result;
    QVector<QPair<int,int>> moves;

signals:
    void homeRequested();
    void MoveMade(int row, int col);

public slots:

    void setGameMode(const QString &player1Name, const QString &player2Name, const QString &gamemode);

private slots:
    void handleHome();
    void handleMove(int row, int col);
    void on_pb_0_0_clicked();
    void on_pb_0_1_clicked();
    void on_pb_0_2_clicked();
    void on_pb_1_0_clicked();
    void on_pb_1_1_clicked();
    void on_pb_1_2_clicked();
    void on_pb_2_0_clicked();
    void on_pb_2_1_clicked();
    void on_pb_2_2_clicked();
};

#endif // GAMEPAGE_H
