#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::choice()
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

    if(ui->checkBox_4->isChecked())
        if(str.isEmpty())
            str += "G";
        else
            str += " G";

    if(ui->checkBox_5->isChecked())
        if(str.isEmpty())
            str += "A";
        else
            str += " A";

    if(ui->checkBox_6->isChecked())
        if(str.isEmpty())
            str += "E";
        else
            str += " E";

    if(ui->checkBox_7->isChecked())
        if(str.isEmpty())
            str += "D";
        else
            str += " D";

    if(ui->checkBox_8->isChecked())
        if(str.isEmpty())
            str += "F";
        else
            str += " F";

    if(ui->checkBox_9->isChecked())
        if(str.isEmpty())
            str += "Fm";
        else
            str += " Fm";

    if(ui->checkBox_10->isChecked())
        if(str.isEmpty())
            str += "B";
        else
            str += " B";

    if(ui->checkBox_11->isChecked())
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

void Dialog::on_buttonBox_accepted()
{
    QString str = QString("INSERT INTO song(song,singer,text,chords)"
                            "VALUES('%1'"
                          ",'" + ui->lineEdit_2->text() +
                          "','" + ui->textEdit->toPlainText() +
                          "','" + choice() + "')").arg(ui->lineEdit->text());
    emit song(str);
    qDebug() << choice();
}
