#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>

#include "Simulation.h"
#include "value.h"
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <vector>

extern int num_days;
extern int num_clients;
extern int num_product_types;
extern int warehouse_capacity;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *transit;
    QStringListModel *consumers;
    QStringListModel *warehouse_info;
};
#endif // MAINWINDOW_H
