#include "uprtdport.h"
#include "ui_uprtdport.h"

uprtdport::uprtdport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uprtdport)
{
    ui->setupUi(this);
}

uprtdport::~uprtdport()
{
    delete ui;
}
