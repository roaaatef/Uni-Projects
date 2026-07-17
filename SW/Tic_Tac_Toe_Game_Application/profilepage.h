#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QWidget>

namespace Ui {
class ProfilePage;
}

class ProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilePage(QWidget *parent = nullptr);
    ~ProfilePage();
    void loadUserHistory();

private:
    Ui::ProfilePage *ui;
    void loadGameHistory();

signals:
    void HistoryRequested();
    void homeRequested();
    void replayRequested(const int& gameid);
    void logoutRequested();

private slots:
    void handleHistory();
    void handleHome();
    void handleReplay(const QModelIndex &index);
    void handleLogout();
};

#endif // PROFILEPAGE_H
