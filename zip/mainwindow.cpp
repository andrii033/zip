#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    QStringList strList = QFileDialog::getOpenFileNames(0, "Open Dialog", "", "*");
    getInfo(strList);
    if(inCompress()==0)
    {
        for(auto x:strList)
        {
            ui->label->setText(ui->label->text()+x+"\n");
        }
        ui->label->setText(ui->label->text()+"files are zipped");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*zipped");
    if(outCompress(str.toStdString())==0)
    {
        ui->label->setText(str+"\nthe file is unzipped");
    }
}
