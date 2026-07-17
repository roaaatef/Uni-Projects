#include "infopage.h"
#include "ui_infopage.h"

InfoPage::InfoPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoPage)
{
    ui->setupUi(this);

    connect(ui->homeButton, &QPushButton::clicked, this, &InfoPage::handleHome);
}

InfoPage::~InfoPage()
{
    delete ui;
}

void InfoPage::handleHome(){
    emit homeRequested();
}
