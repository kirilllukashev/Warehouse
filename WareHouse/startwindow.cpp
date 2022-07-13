#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"

#include <QString>
#include <QLabel>
#include <QDebug>

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
    /*int num_days = ui->lineEdit->text().toInt();
    int num_clients = ui->lineEdit_2->text().toInt();
    int num_product_types = ui->lineEdit_3->text().toInt();
    int warehouse_capacity = ui->lineEdit_4->text().toInt();
*/
    /*num_days = ui->lineEdit->text().toInt();
    num_clients = ui->lineEdit_2->text().toInt();
    num_product_types = ui->lineEdit_3->text().toInt();
    warehouse_capacity = ui->lineEdit_4->text().toInt();*/
}
