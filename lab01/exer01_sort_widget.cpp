#include "exer01_sort_widget.h"
#include "ui_exer01_sort_widget.h"
#include"qdebug.h"

//student lu;
exer01_sort_Widget::exer01_sort_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exer01_sort_Widget)
{
    ui->setupUi(this);
}

exer01_sort_Widget::~exer01_sort_Widget()
{
    delete ui;
}


bool name_mark(student m,student n)
{
    return (m.name)>(n.name);
}

bool lesson1_mark(student m,student n)
{
    return (m.lesson1)>(n.lesson1);
}

bool lesson2_mark(student m,student n)
{
    return (m.lesson2)>(n.lesson2);
}
    student lu,lin,song,wu;




void exer01_sort_Widget::on_pushButton_clicked()
{
    lu.number="1403130209";
    lu.name="鲁智深";
    lu.lesson1="80";
    lu.lesson2="72";

    lin.number="1403140101";
    lin.name="林冲";
    lin.lesson1="82";
    lin.lesson2="76";

    song.number="1403140102";
    song.name="宋江";
    song.lesson1="76";
    song.lesson2="85";

    wu.number="1403140103";
    wu.name="武松";
    wu.lesson1="88";
    wu.lesson2="80";

    QVector<student> table;
    table.push_back(lu);
    table.push_back(lin);
    table.push_back(song);
    table.push_back(wu);

    QVector<student> table0=table;
    std::sort(table0.begin(),table0.end(),name_mark);
        for(int i=0;i<=3;i++)
            for(int j=0;j<=3;j++)
            {
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString("")));
            }

                ui->tableWidget->setItem(0,0,new QTableWidgetItem(table0.at(0).number));
                ui->tableWidget->setItem(0,1,new QTableWidgetItem(table0.at(0).name));
                ui->tableWidget->setItem(0,2,new QTableWidgetItem(table0.at(0).lesson1));
                ui->tableWidget->setItem(0,3,new QTableWidgetItem(table0.at(0).lesson2));
                ui->tableWidget->setItem(1,0,new QTableWidgetItem(table0.at(1).number));
                ui->tableWidget->setItem(1,1,new QTableWidgetItem(table0.at(1).name));
                ui->tableWidget->setItem(1,2,new QTableWidgetItem(table0.at(1).lesson1));
                ui->tableWidget->setItem(1,3,new QTableWidgetItem(table0.at(1).lesson2));
                ui->tableWidget->setItem(2,0,new QTableWidgetItem(table0.at(2).number));
                ui->tableWidget->setItem(2,1,new QTableWidgetItem(table0.at(2).name));
                ui->tableWidget->setItem(2,2,new QTableWidgetItem(table0.at(2).lesson1));
                ui->tableWidget->setItem(2,3,new QTableWidgetItem(table0.at(2).lesson2));
                ui->tableWidget->setItem(3,0,new QTableWidgetItem(table0.at(3).number));
                ui->tableWidget->setItem(3,1,new QTableWidgetItem(table0.at(3).name));
                ui->tableWidget->setItem(3,2,new QTableWidgetItem(table0.at(3).lesson1));
                ui->tableWidget->setItem(3,3,new QTableWidgetItem(table0.at(3).lesson2));


}

void exer01_sort_Widget::on_pushButton_2_clicked()
{
    lu.number="1403130209";
    lu.name="鲁智深";
    lu.lesson1="80";
    lu.lesson2="72";

    lin.number="1403140101";
    lin.name="林冲";
    lin.lesson1="82";
    lin.lesson2="76";

    song.number="1403140102";
    song.name="宋江";
    song.lesson1="76";
    song.lesson2="85";

    wu.number="1403140103";
    wu.name="武松";
    wu.lesson1="88";
    wu.lesson2="80";

    QVector<student> table;
    table.push_back(lu);
    table.push_back(lin);
    table.push_back(song);
    table.push_back(wu);

    QVector<student> table0=table;
    std::sort(table0.begin(),table0.end(),lesson1_mark);
        for(int i=0;i<=3;i++)
            for(int j=0;j<=3;j++)
            {
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString("")));
            }
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(table0.at(0).number));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(table0.at(0).name));
        ui->tableWidget->setItem(0,2,new QTableWidgetItem(table0.at(0).lesson1));
        ui->tableWidget->setItem(0,3,new QTableWidgetItem(table0.at(0).lesson2));
        ui->tableWidget->setItem(1,0,new QTableWidgetItem(table0.at(1).number));
        ui->tableWidget->setItem(1,1,new QTableWidgetItem(table0.at(1).name));
        ui->tableWidget->setItem(1,2,new QTableWidgetItem(table0.at(1).lesson1));
        ui->tableWidget->setItem(1,3,new QTableWidgetItem(table0.at(1).lesson2));
        ui->tableWidget->setItem(2,0,new QTableWidgetItem(table0.at(2).number));
        ui->tableWidget->setItem(2,1,new QTableWidgetItem(table0.at(2).name));
        ui->tableWidget->setItem(2,2,new QTableWidgetItem(table0.at(2).lesson1));
        ui->tableWidget->setItem(2,3,new QTableWidgetItem(table0.at(2).lesson2));
        ui->tableWidget->setItem(3,0,new QTableWidgetItem(table0.at(3).number));
        ui->tableWidget->setItem(3,1,new QTableWidgetItem(table0.at(3).name));
        ui->tableWidget->setItem(3,2,new QTableWidgetItem(table0.at(3).lesson1));
        ui->tableWidget->setItem(3,3,new QTableWidgetItem(table0.at(3).lesson2));
}

void exer01_sort_Widget::on_pushButton_3_clicked()
{
    lu.number="1403130209";
    lu.name="鲁智深";
    lu.lesson1="80";
    lu.lesson2="72";

    lin.number="1403140101";
    lin.name="林冲";
    lin.lesson1="82";
    lin.lesson2="76";

    song.number="1403140102";
    song.name="宋江";
    song.lesson1="76";
    song.lesson2="85";

    wu.number="1403140103";
    wu.name="武松";
    wu.lesson1="88";
    wu.lesson2="80";

    QVector<student> table;
    table.push_back(lu);
    table.push_back(lin);
    table.push_back(song);
    table.push_back(wu);

    QVector<student> table0=table;
    std::sort(table0.begin(),table0.end(),lesson2_mark);

        for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString("")));
        }
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(table0.at(0).number));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(table0.at(0).name));
        ui->tableWidget->setItem(0,2,new QTableWidgetItem(table0.at(0).lesson1));
        ui->tableWidget->setItem(0,3,new QTableWidgetItem(table0.at(0).lesson2));
        ui->tableWidget->setItem(1,0,new QTableWidgetItem(table0.at(1).number));
        ui->tableWidget->setItem(1,1,new QTableWidgetItem(table0.at(1).name));
        ui->tableWidget->setItem(1,2,new QTableWidgetItem(table0.at(1).lesson1));
        ui->tableWidget->setItem(1,3,new QTableWidgetItem(table0.at(1).lesson2));
        ui->tableWidget->setItem(2,0,new QTableWidgetItem(table0.at(2).number));
        ui->tableWidget->setItem(2,1,new QTableWidgetItem(table0.at(2).name));
        ui->tableWidget->setItem(2,2,new QTableWidgetItem(table0.at(2).lesson1));
        ui->tableWidget->setItem(2,3,new QTableWidgetItem(table0.at(2).lesson2));
        ui->tableWidget->setItem(3,0,new QTableWidgetItem(table0.at(3).number));
        ui->tableWidget->setItem(3,1,new QTableWidgetItem(table0.at(3).name));
        ui->tableWidget->setItem(3,2,new QTableWidgetItem(table0.at(3).lesson1));
        ui->tableWidget->setItem(3,3,new QTableWidgetItem(table0.at(3).lesson2));
}



