#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFormLayout>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QWidget>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalWidget->setVisible(false);
    ui->frame->setVisible(false);
    ui->pushButton_2->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Введите размерности и элементы массивов.");
    ui->pushButton->setText("Далее");
    ui->verticalWidget->setVisible(true);
    m=ui->comboBox->currentIndex()+1;
    n=ui->comboBox_2->currentIndex()+1;
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::NextClick);
    }

void MainWindow::NextClick()
{
    QString text1=ui->line3_2->text();
    QString text2=ui->line4->text();
    QVector<QString>temp1=text1.split(" ");
    QVector<QString>temp2=text2.split(" ");
    if(temp1.size()!=m||temp2.size()!=n)
    {
        QMessageBox::critical(this, "Error", "An error has occurred!");
        QCoreApplication::exit(1);
    }
    QVector<QString>v;
    for(int i=0;i<temp2.size();i++)
        v.push_back(temp2[i]);
    for(int i=0;i<temp1.size();i++)
        v.push_back(temp1[i]);
    ui->verticalWidget->setVisible(false);
    ui->label->setText("Совмещенный массив с концом в начале:");
    ui->frame->setVisible(true);
    ui->pushButton->hide();
    for(int i=0;i<v.size();i++)
        ui->line3->setText(ui->line3->text() + " " + v[i]);
    ui->pushButton_2->setVisible(true);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &QWidget::close);

}
