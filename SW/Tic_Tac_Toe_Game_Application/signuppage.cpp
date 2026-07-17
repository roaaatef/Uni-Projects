#include "signuppage.h"
#include "ui_signuppage.h"
#include "Global.h"
#include <QMessageBox>
#include <QtSql>

SignUpPage::SignUpPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpPage)
{
    ui->setupUi(this);

    connect(ui->signupButton, &QPushButton::clicked, this, &SignUpPage::handleSignUp);
    connect(ui->loginButton, &QPushButton::clicked, this, &SignUpPage::handleLogin);

}

SignUpPage::~SignUpPage()
{
    delete ui;
}
void SignUpPage::handleSignUp(){
    if (ui->usernameLineEdit->text().isEmpty() || ui->emailLineEdit->text().isEmpty() || ui->passwordLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Sign Up", "Please fill in all fields.");
    } else {
        QString username=ui->usernameLineEdit->text();
        QString email=ui->emailLineEdit->text();
        QString password=ui->passwordLineEdit->text();
        QSqlDatabase game_db = QSqlDatabase::addDatabase("QSQLITE");
        game_db.setDatabaseName("C:/Users/DELL/Downloads/Tic_Tac_Toe_Game_Application/Tic_Tac_Toe_Game_Application/Game_db.db");
        if(!game_db.open()){
            // Handle database connection failure.
            qDebug()<<"Database not connected";
            ui->statusLabel->clear();
            ui->statusLabel->setText("Database not connected");
        } else{
            QSqlQuery query;
            query.prepare("Select * from Game_Accounts where Email=:email");
            query.bindValue(":email", email);
            query.exec();
            if(query.next()){
                ui->statusLabel->clear();
                ui->statusLabel->setText("This email has an account");
            } else{
                if(password.length() < 8 || password.length() > 64) {
                    // The password is too short or too long
                    ui->statusLabel->clear();
                    ui->statusLabel->setText("Password length min 8 & max 64 character");
                } else{
                    // The password is within the desired length range
                    ui->statusLabel->clear();
                    // Convert the password to QByteArray and hash it
                    QByteArray password_ba = password.toLocal8Bit();
                    QByteArray hash = QCryptographicHash::hash(password_ba, QCryptographicHash::Sha256);
                    // Convert the hash to a hex string
                    QString hashedPassword = hash.toHex();
                    query.prepare("INSERT INTO Game_Accounts (Username, Email, Password) VALUES (:username, :email, :password)");
                    query.bindValue(":username", username);
                    query.bindValue(":email", email);
                    query.bindValue(":password", hashedPassword);
                    if(query.exec()){
                        QMessageBox::information(nullptr,"Sign up","Sign up Sucsessful!");
                        UserID = query.lastInsertId().toInt();  // Get the ID of the newly inserted user.
                        emit signedUp();
                        ui->emailLineEdit->clear();
                        ui->usernameLineEdit->clear();
                        ui->passwordLineEdit->clear();
                    } else{
                        QMessageBox::critical(nullptr,"Sign up","Error! Sign up not sucsessful!");
                    }
                }
            }
            game_db.close();
        }
    }
}

void SignUpPage::handleLogin() {
    emit loginRequested();
    ui->emailLineEdit->clear();
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}
