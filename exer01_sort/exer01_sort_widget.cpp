#include "exer01_sort_widget.h"
#include "ui_exer01_sort_widget.h"
#include"qdebug.h"

exer01_sort_Widget::exer01_sort_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exer01_sort_Widget)
{
    QVector<QString> luzhishen;
    QVector<QString> linchong;
    QVector<QString> songjiang;
    QVector<QString> wusong;
    luzhishen.append({"1403130209", "鲁智深",  "80",  "72"});
    linchong.append({"1403140101",  "林冲",    "82",  "76"});
    songjiang.append({"1403130102", "宋江",    "76",  "85"});
    wusong.append({"1403130103",    "武松",    "88",  "80"});
    ui->setupUi(this);

    //    ui->tableWidget->setItem(0,0,new QTableWidgetItem(luzhishen[1]));    //    void setItem(int row, int column, QTableWidgetItem *item)

    //    qDebug()<<values[0];
    //    ui->tableWidget->setColumnWidth(0, 150);//will be used later
    //    ui->tableWidget->setRowHeight(0,50);
    //    ui->tableWidget->setColumnCount(3);
    //    ui->tableWidget->setRowCount(5);
    //    QStringList List;
    //    List<<"name0"<<"name1"<<"name2";
    //    ui->tableWidget->setHorizontalHeaderLabels(List);                     //为表格添加列名
    //    ui->tableWidget->setColumnWidth(0,100);
    //    ui->tableWidget->setColumnWidth(1,200);
    //    ui->tableWidget->horizontalHeader()->setStretchLastSection(1);        //将表头的第2列宽度延伸到整个列表全满
}

exer01_sort_Widget::~exer01_sort_Widget()
{
    delete ui;
}


