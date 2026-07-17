#ifndef PLAYERNAMESPAGE_H
#define PLAYERNAMESPAGE_H

#include <QWidget>

namespace Ui {
class PlayerNamesPage;
}

class PlayerNamesPage : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerNamesPage(QWidget *parent = nullptr);
    ~PlayerNamesPage();

private:
    Ui::PlayerNamesPage *ui;
    QString gamemode;

signals:
    void startGame(const QString &player1Name, const QString &player2Name, const QString &gamemode);
    void HomeRequested();

public slots:
    void setGameMode(const QString &gameMode);

private slots:
    void handleStartGame();
    void handleHome();

};

#endif // PLAYERNAMESPAGE_H
