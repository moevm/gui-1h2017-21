#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QtSql>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void add(QString str);

private:
    Ui::MainWindow *ui;
    QStringList buff;
    QStandardItemModel *model;
    QSqlDatabase db;
    QString choice();
};

#endif // MAINWINDOW_H
