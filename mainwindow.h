#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QTableWidget>
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
    void encryption();
    void wordDataInputMothed();
    void tableClearMothed();

private:
    Ui::MainWindow *ui;
    QStringList header;
    QString wordDataInput, analysisData, member;
    //QTableWidgetItem  extension, nameEN, cellPhone, eMail;

    QTableWidget *table  =  new QTableWidget(6, 100);
};

#endif // MAINWINDOW_H
