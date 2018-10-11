#include "exer01_sort_widget.h"
#include "ui_exer01_sort_widget.h"
#include"qdebug.h"

exer01_sort_Widget::exer01_sort_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exer01_sort_Widget)
{
    ui->setupUi(this);
//    QVector<QVector<QString>> table(4);     //新建的二维向量
//        sortbylesson1(table);
//        for(int i=0;i<=3;i++)
//            for(int j=0;j<=3;j++)
//            {
//                ui->tableWidget->setItem(i,j,new QTableWidgetItem(table[i][j]));
//            }

}

exer01_sort_Widget::~exer01_sort_Widget()
{
    delete ui;
}



void exer01_sort_Widget::sortbyname(QVector<QVector<QString>> &table0)
{
    table0[1].append({"1403130209", "鲁智深",  "80",  "72"});
    table0[0].append({"1403140101", "林冲",    "82",  "76"});
    table0[2].append({"1403130102", "宋江",    "76",  "85"});
    table0[3].append({"1403130103", "武松",    "88",  "80"});
}

void exer01_sort_Widget::sortbylesson1(QVector<QVector<QString> > &table0)
{
    table0[2].append({"1403130209", "鲁智深",  "80",  "72"});
    table0[1].append({"1403140101", "林冲",    "82",  "76"});
    table0[3].append({"1403130102", "宋江",    "76",  "85"});
    table0[0].append({"1403130103", "武松",    "88",  "80"});
}

void exer01_sort_Widget::sortbylesson2(QVector<QVector<QString> > &table0)
{
    table0[3].append({"1403130209", "鲁智深",  "80",  "72"});
    table0[2].append({"1403140101", "林冲",    "82",  "76"});
    table0[0].append({"1403130102", "宋江",    "76",  "85"});
    table0[1].append({"1403130103", "武松",    "88",  "80"});
}






void exer01_sort_Widget::on_pushButton_clicked()
{
    QVector<QVector<QString>> table(4);     //新建的二维向量
        sortbyname(table);
        for(int i=0;i<=3;i++)
            for(int j=0;j<=3;j++)
            {
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString("")));
            }
        for(int i=0;i<=3;i++)
            for(int j=0;j<=3;j++)
            {
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(table[i][j]));
            }

}

void exer01_sort_Widget::on_pushButton_2_clicked()
{
    QVector<QVector<QString>> table(4);     //新建的二维向量
        sortbylesson1(table);
        for(int i=0;i<=3;i++)
            for(int j=0;j<=3;j++)
            {
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString("")));
            }
        for(int i=0;i<=3;i++)
            for(int j=0;j<=3;j++)
            {
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(table[i][j]));
            }

}

void exer01_sort_Widget::on_pushButton_3_clicked()
{
    QVector<QVector<QString>> table(4);     //新建的二维向量
        sortbylesson2(table);
        for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString("")));
        }
        for(int i=0;i<=3;i++)
            for(int j=0;j<=3;j++)
            {
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(table[i][j]));
            }

}


