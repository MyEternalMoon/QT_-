#include "buyticketdialog.h"
#include "ui_buyticketdialog.h"

buyTicketDialog::buyTicketDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buyTicketDialog)
{
    ui->setupUi(this);
}

buyTicketDialog::buyTicketDialog(QWidget *parent, QString user, QString id, QString from, QString to, QString fromTime, QString price) :
    QDialog(parent),
    ui(new Ui::buyTicketDialog)
{
    ui->setupUi(this);
    ui->userLabel->setText(QString::fromLocal8Bit("[OnAir]�û� %1").arg(user));
    ui->airlineLabel->setText(QString::fromLocal8Bit("%1, %2��%3, �����:%4").arg(fromTime).arg(from).arg(to).arg(id));
    ui->priceLabel->setText(QString::fromLocal8Bit("����Ʊ��Ϊ: %1").arg(price));


    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

buyTicketDialog::~buyTicketDialog()
{
    delete ui;
}
