#ifndef REPLAY_H
#define REPLAY_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QPair>
#include <QVector>

namespace Ui {
class Replay;
}

class Replay : public QWidget
{
    Q_OBJECT

public:
    explicit Replay(QWidget *parent = nullptr);
    ~Replay();
    QVector<QPair<int,int>> getGameHistory(const int gameid);
    void printhistory (QVector<QPair<int,int>> retrievedMoves);
    void delay(int n);

private:
    Ui::Replay *ui;
    QPushButton *boxes[3][3];
    int ID;
    int i;

signals:
    void profileRequested();

public slots:
    void start(const int gameid);
private slots:
    void on_againButton_clicked();
    void handleProfile();
    void on_next_clicked();
};

#endif // REPLAY_H
