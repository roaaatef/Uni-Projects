#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>

namespace Ui {
class SignUpPage;
}

class SignUpPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();

private:
    Ui::SignUpPage *ui;

signals:
    void signedUp();
    void loginRequested();

private slots:
    void handleSignUp();
    void handleLogin();
};
#endif // SIGNUPPAGE_H
