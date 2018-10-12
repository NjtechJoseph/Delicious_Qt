#include <QCoreApplication>
#include"qdebug.h"
#include<iostream>

using namespace std;





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




int main(int argc, char *argv[])
{
    student lu,lin,song,wu;

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

    QVector<student> table1=table;
    std::sort(table0.begin(),table0.end(),lesson1_mark);

    QVector<student> table2=table;
    std::sort(table0.begin(),table0.end(),lesson2_mark);


    return 0;
}
