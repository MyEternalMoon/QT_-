#include "orderwidget.h"
#include "ui_orderwidget.h"
#include <QDate>
orderWidget::orderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderWidget)
{
    ui->setupUi(this);
}

void orderWidget::initInfo(QString user, QString id, QDate date, int price)
{
    ui->userLabel->setText(QString::fromLocal8Bit("�û���: %1").arg(user));
    ui->airlineLabel->setText(QString::fromLocal8Bit("�����: %1").arg(id));
    ui->priceLabel->setText(QString::fromLocal8Bit("�������: %1.00").arg(price));
    ui->dateLabel->setText(QString::fromLocal8Bit("��������:%1").arg(date.toString("yyyy.MM.dd")));
}

orderWidget::~orderWidget()
{
    delete ui;
}
