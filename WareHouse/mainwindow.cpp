#include "mainwindow.h"
#include "ui_mainwindow.h"

int num_days = 1;
int num_clients = 1;
int num_product_types = 1;
int warehouse_capacity = 1;
int cnt = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    Value qwqw;
    qwqw.setModal(true);
    qwqw.exec();
    cnt = num_days;
    QString num_str = QString::number(cnt);
    QString label_text = "Days left: " + num_str;
    ui->label->setText(label_text);
    qDebug() << num_days << '\n' << num_clients << '\n' << num_product_types << '\n' << warehouse_capacity << '\n';

    transit = new QStringListModel(this);
    QStringList List_transit;
    Simulation simulation(num_clients, num_product_types, warehouse_capacity);
    std::vector<DayReport> rep = simulation.genReports(num_days);
    for (Transmission it : rep[0].get_packages()) {
        QString name =  QString::fromStdString(it.dest->name());
        QString product_name = QString::fromStdString(it.packs[0].name());
        QString product_size = QString::number(it.packs.size());
        QString transit_time = QString::number(it.time);
        QString ans = "(" + product_name + " x" + product_size + "; to: " + name + "; in:" + transit_time + ")";
        List_transit << ans;
    }
    transit->setStringList(List_transit);
    ui->listView->setModel(transit);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
    List_transit.clear();

    int cnt_clients = 1;
    consumers = new QStringListModel(this);
    QStringList List_consumers;

    for (Consumer it : rep[0].get_consumers()) {
        QString name_cons = QString::fromStdString("[Consumer ") + QString::number(cnt_clients)
                + QString::fromStdString("]");
        List_consumers << name_cons;
        for (auto& jt : it.get_products()) {
            QString name_cons = QString::fromStdString("Stored(") + QString::fromStdString(jt.first) +
                    QString::fromStdString("):") + QString::number(jt.second);
            List_consumers << name_cons;
        }
        cnt_clients++;
    }
    consumers->setStringList(List_consumers);
    ui->listView_2->setModel(consumers);
    ui->listView_2->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
    List_consumers.clear();

    warehouse_info = new QStringListModel(this);
    QStringList List_warehouse;
    Warehouse now = rep[0].get_warehouse();

    for (auto& it :now.get_storages()) {
        QString in_now = QString::fromStdString("Storage(") + QString::fromStdString(it.first) + QString::fromStdString("):") +
                QString::number(it.second.prodCount());
    }

    qDebug() << QString::number(now.get_cash());
    List_warehouse << QString::number(now.get_cash());
    warehouse_info->setStringList(List_warehouse);
    ui->listView_3->setModel(warehouse_info);
    ui->listView_3->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
    List_warehouse.clear();
}

void MainWindow::on_pushButton_clicked()
{
    try {
        if (cnt > 0) {

            cnt--;
            QString num_str = QString::number(cnt);
            QString label_text = "Days left: " + num_str;
            ui->label->setText(label_text);

            transit = new QStringListModel(this);
            QStringList List_transit;
            Simulation simulation(num_clients, num_product_types, warehouse_capacity);
            std::vector<DayReport> rep = simulation.genReports(num_days);
            for (Transmission it : rep[num_days - cnt - 1].get_packages()) {
                QString numq = QString::number(num_days - cnt - 1);
                QString name =  QString::fromStdString(it.dest->name());
                QString product_name = QString::fromStdString(it.packs[0].name());
                QString product_size = QString::number(it.packs.size());
                QString transit_time = QString::number(it.time);
                QString ans = "(" + product_name + " x" + product_size + "; to: " + name + "; in:" + transit_time + ")";
                List_transit << ans;
            }
            transit->setStringList(List_transit);
            ui->listView->setModel(transit);
            ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
            List_transit.clear();


            int cnt_clients = 1;
            consumers = new QStringListModel(this);
            QStringList List_consumers;

            for (Consumer it : rep[num_days - cnt - 1].get_consumers()) {
                QString name_cons = QString::fromStdString("[Consumer ") + QString::number(cnt_clients)
                        + QString::fromStdString("]");
                List_consumers << name_cons;
                for (auto& jt : it.get_weights()) {
                    QString val_prod = QString::fromStdString("Weight(") + QString::fromStdString(jt.first) +
                            QString::fromStdString("):")+ QString::number(jt.second);
                    List_consumers << val_prod;
                }
                for (auto& jt : it.get_products()) {
                    QString name_cons = QString::fromStdString("Stored(") + QString::fromStdString(jt.first) +
                            QString::fromStdString("):") + QString::number(jt.second);
                    List_consumers << name_cons;
                }
                cnt_clients++;
            }
            consumers->setStringList(List_consumers);
            ui->listView_2->setModel(consumers);
            ui->listView_2->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
            List_consumers.clear();

            warehouse_info = new QStringListModel(this);
            QStringList List_warehouse;
            Warehouse now = rep[num_days - cnt - 1].get_warehouse();

            List_warehouse << QString::number(now.get_cash());

            for (auto& it :now.get_storages()) {
                QString in_now = QString::fromStdString("Storage(") + QString::fromStdString(it.first) + QString::fromStdString("):") +
                        QString::number(it.second.prodCount());
                List_warehouse << in_now;
            }
            warehouse_info->setStringList(List_warehouse);
            ui->listView_3->setModel(warehouse_info);
            ui->listView_3->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
            List_warehouse.clear();

        } else {
            QMessageBox::information(this, "Information", "The simulation is over!");
        }
    }  catch (std::exception ex) {
        qDebug() << ex.what();
    }

}
