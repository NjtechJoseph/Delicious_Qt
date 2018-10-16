#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>

using namespace std;

#define N 4

namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}

/******************************************** *
 *          定义学生数据类结构体               *
 * ****************************************** */
typedef struct{
    QList<QString> stu_info;
} studData;


 /******************************************** *
  * 运算符重载函数，使其可以直接输出studData结构 *
  * ****************************************** */
QDebug operator<< (QDebug d, const studData &data) {
    for(int i=0;i<data.stu_info.size();i++)
        d<<data.stu_info.at(i);
    return d;
}


 //比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};



bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
    case SK::col01:
        result=(d1.stu_info.at(currentColumn)>d2.stu_info.at(currentColumn));    //比较qvector里的string
        break;
    }
    return result;
}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void readFile();
    void doSort();
private:
    QString tempfile;
    QByteArray line;
    QVector<studData> student;

};

ScoreSorter::ScoreSorter(QString dataFile)
{
    tempfile=dataFile;
}

void ScoreSorter::doSort()
{
    myCmp bigger(N);
    std::sort(student.begin(),student.end(),bigger);
    qDebug()<<"排序后输出，当前排序第 "<<N<<" 列：";
    qDebug()<<student;
    qDebug()<<"------------------------------------------------\n";
}

void ScoreSorter::readFile()
{
    QFile file(tempfile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"文件打开失败\n";
    while (!file.atEnd())
    {
        studData tempstu;
        this->line = file.readLine();
        QString string_data(line);
        string_data.remove("\n");
        tempstu.stu_info=string_data.split(" ",QString::SkipEmptyParts);
        student.append(tempstu);
    }
    file.close();
}

//void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
//{
//    // 自定义qDebug
//}

int main()
{
    QByteArray datafile = "data.txt";
    QFile f("sorted_"+datafile);    // 如果排序后文件已存在，则删除之
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();

    return 0;
}
