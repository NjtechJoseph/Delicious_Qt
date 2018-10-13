#ifndef EXER01_SORT_WIDGET_H
#define EXER01_SORT_WIDGET_H

#include <QWidget>
#include <qdebug.h>
#include<iostream>

using namespace std;

namespace Ui {
class exer01_sort_Widget;
}

class exer01_sort_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit exer01_sort_Widget(QWidget *parent = 0);

    void sortbyname(QVector<QVector<QString>> &table0);
    void sortbylesson1(QVector<QVector<QString>> &table0);
    void sortbylesson2(QVector<QVector<QString>> &table0);

    ~exer01_sort_Widget();
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::exer01_sort_Widget *ui;
};


typedef class student
{
public:
    QString number;
    QString name;
    QString lesson1;
    QString lesson2;
} student;


#endif // EXER01_SORT_WIDGET_H
