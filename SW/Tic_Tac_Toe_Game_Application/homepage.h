#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private:
    Ui::HomePage *ui;

signals:
    void profileRequested();
    void infoRequested();
    void gameModeChosen(const QString &gameMode);

private slots:
    void handleProfile();
    void handleInfo();
    void handleTwoPlayers();
    void handleOnePlayerVsAI();
};

#endif // HOMEPAGE_H
