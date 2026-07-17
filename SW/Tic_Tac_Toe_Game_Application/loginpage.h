#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private:
    Ui::LoginPage *ui;

signals:
    void loggedIn();
    void signUpRequested();

private slots:
    void handleLogin();
    void handleSignUp();
};

#endif // LOGINPAGE_H
