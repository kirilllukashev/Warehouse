#include "value.h"
#include "ui_value.h"
#include "mainwindow.h"

Value::Value(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Value)
{
    ui->setupUi(this);
}

Value::~Value()
{
    delete ui;
}

void Value::on_pushButton_clicked()
{
    /*
    int num_days = ui->lineEdit->text().toInt();
    int num_clients = ui->lineEdit_2->text().toInt();
    int num_product_types = ui->lineEdit_3->text().toInt();
    int warehouse_capacity = ui->lineEdit_4->text().toInt();
    */
    num_days = ui->lineEdit->text().toInt();
    num_clients = ui->lineEdit_2->text().toInt();
    num_product_types = ui->lineEdit_3->text().toInt();
    warehouse_capacity = ui->lineEdit_4->text().toInt();
}
