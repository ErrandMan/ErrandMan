#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    analysisData="";

    header<<"員工編號"<<"分機"<<"英文名"<<"電話"<<"信箱";
    qDebug()<<header.toStdList();

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setColumnWidth(0, 70);
    ui->tableWidget->setColumnWidth(1, 70);
    ui->tableWidget->setColumnWidth(3, 120);
    ui->tableWidget->setColumnWidth(4, 190);
    ui->tableWidget->setRowCount(300);

    ui->tableWidget_encryption->setColumnCount(5);
    ui->tableWidget_encryption->setHorizontalHeaderLabels(header);
    ui->tableWidget_encryption->setColumnWidth(0, 70);
    ui->tableWidget_encryption->setColumnWidth(1, 70);
    ui->tableWidget_encryption->setColumnWidth(3, 120);
    ui->tableWidget_encryption->setColumnWidth(4, 190);
    ui->tableWidget_encryption->setRowCount(300);
    ui->tableWidget_encryption->sizeHint();

    connect(ui->pushButton_wordDataInput, &QPushButton::clicked, this, &MainWindow::wordDataInputMothed);
    connect(ui->pushButton_tableClaer, &QPushButton::clicked, this, &MainWindow::tableClearMothed);



}
void MainWindow::encryption(){
    int columData,count=0;
    int colum=0,row=0;
    member="";
    int analysisDataSize=analysisData.length();

    for(int i=0; i<analysisDataSize;i++){
        if(analysisData[i]=="#"){
            count++;
        }
    }
    columData=count/5;
    qDebug()<<"columData:"<<columData;

    for(int i=1; i<analysisDataSize;i++){
        if(analysisData[i]=="#"){
last:
            ui->tableWidget_encryption->setItem(row, colum, new QTableWidgetItem(member));
            member="";
            colum++;
            if(colum==5){
                row++;
                colum=0;
            }

        }else{
            member=member+analysisData[i];
            if(i==analysisDataSize-1){goto last;}
        }
    }

    ui->label_used->setText("已導入筆數 :  "+QString::number(columData));
    ui->label_remain->setText("空間餘額 :  "+QString::number(300-columData));




}

void MainWindow::tableClearMothed(){
    ui->tableWidget_encryption->clearContents();
    analysisData="";
    encryption();

}

void MainWindow::wordDataInputMothed(){
    wordDataInput=ui->plainTextEdit_input->toPlainText();
    wordDataInput=wordDataInput.trimmed();
    wordDataInput=wordDataInput.simplified();
    wordDataInput=wordDataInput.replace(" ","#");
    wordDataInput="#"+wordDataInput;
    analysisData=analysisData+wordDataInput;
    wordDataInput="";

    if(ui->checkBox_clear->isChecked()==true){
        ui->plainTextEdit_input->clear();
    }
    qDebug()<<analysisData;

    encryption();
}

MainWindow::~MainWindow()
{
    delete ui;
}
