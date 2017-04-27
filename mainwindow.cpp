#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Подключаем базу данных
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(qApp->applicationDirPath()+"/db.db");
    if(!db.open()){
        qDebug() << "connection error";
        return;
    }
    buff.clear();
    qDebug() << "succesfully conected to database";
    QSqlQuery query;
    query.exec("SELECT * FROM song");
    QStandardItemModel *model = new QStandardItemModel(this);
    QStandardItem *item;
    QStringList horizontalHeader;
    horizontalHeader.append("Singer / Songname");
    model->setHorizontalHeaderLabels(horizontalHeader);
    while (query.next())
    {
      item = new QStandardItem(QString(query.value(1).toString() + " -  " + query.value(0).toString()));
      //item->appendRow(new QStandardItem(query.value(2).toString()));
      model->appendRow(item);
      buff.append(query.value(2).toString());
    }
    ui->treeView->setModel(model);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QMessageBox *msg = new QMessageBox;
    msg->setText(buff[index.row()]);
    msg->exec();
    delete msg;

}
