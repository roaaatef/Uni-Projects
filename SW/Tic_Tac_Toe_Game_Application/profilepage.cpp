#include "profilepage.h"
#include "ui_profilepage.h"
#include "Global.h"
#include <QTableWidget>
#include <QtSql>
#include <QMessageBox>

#include <QVBoxLayout>
#include <QTableView>
#include <QStandardItemModel>

ProfilePage::ProfilePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfilePage)
{
    ui->setupUi(this);

    connect(ui->loadHistoryButton, &QPushButton::clicked, this, &ProfilePage::handleHistory);
    QObject::connect(this,&ProfilePage::HistoryRequested,this,&ProfilePage::loadGameHistory);

    connect(ui->homeButton, &QPushButton::clicked, this, &ProfilePage::handleHome);

    connect(ui->logoutButton, &QPushButton::clicked, this, &ProfilePage::handleLogout);

    // Connect the click event to the slot
    connect(ui->historyTableView, &QTableView::clicked, this, &ProfilePage::handleReplay);
}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::handleHome(){
    emit homeRequested();
}

void ProfilePage::handleHistory(){
    emit HistoryRequested();
}

void ProfilePage::handleReplay(const QModelIndex &index){
    int column = index.column();
    // Check if the clicked cell is in the last column
    if (column != ui->historyTableView->model()->columnCount() - 1){
        // If not, return without doing anything
        return;
    }
    int row = index.row();
    // Get the game id from the clicked row
    int game_id = ui->historyTableView->model()->data(ui->historyTableView->model()->index(row, 0)).toInt();
    // Now you can use the game_id to retrieve and display the game moves
    emit replayRequested(game_id);
}

void ProfilePage::loadUserHistory(){

    ui->profileLabel->setText("Profile ID: "+QString::number(UserID));

    QSqlDatabase game_db = QSqlDatabase::addDatabase("QSQLITE");
    game_db.setDatabaseName("C:/Users/DELL/Downloads/Tic_Tac_Toe_Game_Application/Tic_Tac_Toe_Game_Application/Game_db.db");

    if (game_db.open()){
        QSqlQuery query;
        query.prepare("SELECT Username, Email FROM Game_Accounts WHERE ID = ?");
        query.addBindValue(UserID);
        if (query.exec() && query.next()){
            ui->usernameLabel->setText("Username: " + query.value(0).toString());
            ui->emailLabel->setText("Email: " + query.value(1).toString());
        } else{
            QMessageBox::critical(nullptr,"Error","Query Failed!");
        }
        game_db.close();
    }else{
        // Handle database connection failure.
        qDebug()<<"Database not connected";
    }
}

void ProfilePage::loadGameHistory(){
    QSqlDatabase game_db = QSqlDatabase::addDatabase("QSQLITE");
    game_db.setDatabaseName("C:/Users/DELL/Downloads/Tic_Tac_Toe_Game_Application/Tic_Tac_Toe_Game_Application/Game_db.db");

    if (game_db.open()){
        // Set the model to use the view
        QSqlTableModel *TableModel = new QSqlTableModel(nullptr, game_db);
        TableModel->setTable("Game_H");
        TableModel->setFilter("USER_ID = " + QString::number(UserID));
        TableModel->select();
        // Create a new model for the view
        QStandardItemModel *newModel = new QStandardItemModel(TableModel->rowCount(), TableModel->columnCount() + 1, this);
        // Copy data from the old model to the new one
        for(int row = 0; row < TableModel->rowCount(); ++row) {
            for(int col = 0; col < TableModel->columnCount(); ++col) {
                QStandardItem *item = new QStandardItem(TableModel->record(row).value(col).toString());
                newModel->setItem(row, col, item);
            }
            // Add new item in the new column
            QStandardItem *replayItem = new QStandardItem("Replay");
            newModel->setItem(row, TableModel->columnCount(), replayItem);
        }
        ui->historyTableView->setModel(newModel);

        //hide unwanted columns
        for (int c = 0; c < newModel->columnCount(); ++c){
            if (c != 2 && c != 3 && c != 4 && c != 5 && c != 7 && c != newModel->columnCount() - 1){
                ui->historyTableView->hideColumn(c);
            }
        }
        game_db.close();
    } else{
        // Handle database connection failure.
        qDebug()<<"Database not connected";
    }
}

void ProfilePage::handleLogout() {
     emit logoutRequested();
     UserID=0;
     GameID=0;
 }

