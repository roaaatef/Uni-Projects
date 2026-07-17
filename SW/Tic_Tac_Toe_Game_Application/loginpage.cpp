#include "loginpage.h"
#include "ui_loginpage.h"
#include "Global.h"
#include <QtSql>
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent): QWidget(parent), ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginPage::handleLogin);
    connect(ui->signupButton, &QPushButton::clicked, this, &LoginPage::handleSignUp);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::handleLogin() {
    if (ui->emailLineEdit->text().isEmpty() || ui->passwordLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Log in", "Please fill in all fields.");
    } else {
        QString email=ui->emailLineEdit->text();
        QString password=ui->passwordLineEdit->text();
        QSqlDatabase game_db = QSqlDatabase::addDatabase("QSQLITE");
        game_db.setDatabaseName("C:/Users/DELL/Downloads/Tic_Tac_Toe_Game_Application/Tic_Tac_Toe_Game_Application/Game_db.db");

        if(!game_db.open()){
            qDebug()<<"Database not connected";
            ui->statusLabel->clear();
            ui->statusLabel->setText("Database not connected");
        }
        else{
            // Handle database connection failure
            qDebug()<<"Database connected";
            ui->statusLabel->clear();
            ui->statusLabel->setText("Database connected");
            // Convert the password to QByteArray and hash it
            QByteArray password_ba = password.toLocal8Bit();
            QByteArray hash = QCryptographicHash::hash(password_ba, QCryptographicHash::Sha256);
            // Convert the hash to a hex string
            QString hashedLoginPassword = hash.toHex();
            QSqlQuery query;
            query.prepare("SELECT * FROM Game_Accounts WHERE Email = :email and Password= :password;");
            query.bindValue(":email", email);
            query.bindValue(":password", hashedLoginPassword);
            if (query.exec() && query.next()) {
                UserID = query.value("ID").toInt();
                qDebug() << "User logged in successfully! User ID:" << UserID;
                emit loggedIn();
                ui->emailLineEdit->clear();
                ui->passwordLineEdit->clear();
            } else {
                // Handle login failure
                qDebug() << "Error loading user profile:" << query.lastError().text();
                qDebug() << "Incorrect email or password.";
                ui->statusLabel->clear();
                ui->statusLabel->setText("Incorrect email or password");
            }
            game_db.close();
        }
    }
}

void LoginPage::handleSignUp() {
    emit signUpRequested();
    ui->emailLineEdit->clear();
    ui->passwordLineEdit->clear();
}
