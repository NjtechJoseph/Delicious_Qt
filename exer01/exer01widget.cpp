#include "exer01widget.h"
#include "ui_exer01widget.h"
#include <QVector>
#include <ctime>
#include <QDebug>

exer01Widget::exer01Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exer01Widget)
{
    ui->setupUi(this);
    srand((unsigned int)time(NULL));
}

exer01Widget::~exer01Widget()
{
    delete ui;
}

void exer01Widget::on_pushButton_clicked()
{
    QVector<float> v;
    for(int i=0;i<5;i++){
        v.push_back(float((rand()%100))/10.0);
    }
    qDebug()<<v;

    /*************************************************
    上几行输出QVector，以下几行控制在widget中显示QVector
    **************************************************
    **************************************************
    foreach用法解释
    例子:foreach (varItem , Items)
    foreach（variable ，container）其中，varItem(variable)是容器Items(container)中的一个项，相当于：variable=container.item ，遍历会从头遍历到尾。
     **************************************************/
    QString s="";
    foreach (float f, v) {                             //
       s += QString("%1 ").arg(f);
    }
    ui->textEdit->insertPlainText(QString("%1%2").arg(s,"\n"));     //显示
}
