#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItem"
#include <QDebug>
#include <QMessageBox>
#include "dialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(qApp->applicationDirPath()+"/db.db");
    model = new QStandardItemModel;
    db.open();
    QSqlQuery query;
    query.exec("SELECT * FROM song");
    QStandardItem *item;
    QStringList horizontalHeader;
    horizontalHeader.append("Singer / Songname");
    model->setHorizontalHeaderLabels(horizontalHeader);
    while (query.next())
    {
      item = new QStandardItem(QString(query.value(1).toString() + " -  " + query.value(0).toString()));
      model->appendRow(item);
      buff.append(query.value(2).toString());
    }
    ui->treeView->setModel(model);
    //ui->treeView->resize();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}


void MainWindow::on_pushButton_clicked()
{
    //Подключаем базу данных
    if(model)
        delete model;
    model = new QStandardItemModel(this);
    if(!db.open()){
        qDebug() << "connection error";
        return;
    }
    buff.clear();
    QSqlQuery query;
    query.exec("SELECT * FROM song WHERE chords='" + choice() + "'");
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
    qDebug() << choice();
    ui->label_4->setText(choice());
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QMessageBox *msg = new QMessageBox;
    msg->setText(buff[index.row()]);
    msg->exec();
    delete msg;

}

QString MainWindow::choice()
{
    QString str = "";
    if(ui->checkBox->isChecked())
        if(str.isEmpty())
            str += "Am";
        else
            str += " Am";

    if(ui->checkBox_2->isChecked())
        if(str.isEmpty())
            str += "C";
        else
            str += " C";

    if(ui->checkBox_3->isChecked())
        if(str.isEmpty())
            str += "Em";
        else
            str += " Em";

    if(ui->checkBox_7->isChecked())
        if(str.isEmpty())
            str += "G";
        else
            str += " G";

    if(ui->checkBox_9->isChecked())
        if(str.isEmpty())
            str += "A";
        else
            str += " A";

    if(ui->checkBox_10->isChecked())
        if(str.isEmpty())
            str += "E";
        else
            str += " E";

    if(ui->checkBox_11->isChecked())
        if(str.isEmpty())
            str += "D";
        else
            str += " D";

    if(ui->checkBox_4->isChecked())
        if(str.isEmpty())
            str += "F";
        else
            str += " F";

    if(ui->checkBox_5->isChecked())
        if(str.isEmpty())
            str += "Fm";
        else
            str += " Fm";

    if(ui->checkBox_6->isChecked())
        if(str.isEmpty())
            str += "B";
        else
            str += " B";

    if(ui->checkBox_8->isChecked())
        if(str.isEmpty())
            str += "Bm";
        else
            str += " Bm";

    if(ui->checkBox_12->isChecked())
        if(str.isEmpty())
            str += "F#";
        else
            str += " F#";

    if(ui->checkBox_13->isChecked())
        if(str.isEmpty())
            str += "F#m";
        else
            str += " F#m";

    if(ui->checkBox_14->isChecked())
        if(str.isEmpty())
            str += "Gm";
        else
            str += " Gm";

    return str;
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog *dlg = new Dialog;
    connect(dlg, SIGNAL(song(QString)), this, SLOT(add(QString)));
    dlg->exec();
    delete dlg;
}

void MainWindow::add(QString str)
{
    QSqlQuery query;
    query.exec(str);
    qDebug() << query.lastError().text();
}
