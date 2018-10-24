#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QList>
#include <iostream>
#include <cstdlib>
#include <QString>
#include <QMutex>

using namespace std;

#define N 4     //选择想排序的列

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


/*
 * @brief 定义学生数据类结构体
 * @param
 *
 */
typedef struct{
    QString stu_number;
    QString stu_name;
    QList<int> stu_info;
} studData;


/*
 * @brief 运算符重载函数，使其可以直接输出studData结构
 * @param
 *
 */
QDebug operator<< (QDebug d, const studData &data) {                //stu_info 的长度为列的个数-2
    d.noquote()<<qSetFieldWidth(3)<<data.stu_number<<data.stu_name;
    for(int i=0;i<data.stu_info.size();i++)
    {
       d.noquote()<<qSetFieldWidth(3)<<data.stu_info.at(i);
    }
    qDebug()<<"";
    return d;
}


/*
 * @brief 比较类，用于std::sort第三个参数
 * @param
 *
 */
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
        case SK::col01: result=1;break;    //学号不做比较     第0列
        case SK::col02: result=1;break;    //姓名不做比较     第1列
    default: result=(d1.stu_info.at(currentColumn-1)>=d2.stu_info.at(currentColumn-1));break;//其他列则使用同一种排序方法
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
    QList<studData>   student;                      //student为待处理和输出的容器
    QStringList caption;                            //caption为抽出的标题，否则无法排序
};

ScoreSorter::ScoreSorter(QString dataFile)
{
    tempfile=dataFile;
}

void ScoreSorter::readFile()
{

    QStringList tempspace;                                      //存取一行数据的容器
    QFile mfile(tempfile);
    if(!mfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug()<<"无法打开该文件!";
       }
    QString title(mfile.readLine());
    caption= title.split(" ", QString::SkipEmptyParts);         //读取标题
    while(!mfile.atEnd()) {
        studData tempstu;                                       //存取一行数据，待student容器append
        QString str(mfile.readLine());
        tempspace = str.split(" ", QString::SkipEmptyParts);
        if(tempspace.last() == "\n") tempspace.removeLast();
        if(tempspace.size()==0) continue;
        tempstu.stu_number = tempspace.at(0);                   //因为tempstu的一二个数据为学号和姓名，故先提取出来
        tempstu.stu_name =tempspace.at(1);
        tempspace.removeAt(0);                                  //提取后删除
        tempspace.removeAt(0);
    for(int i=0;i<tempspace.size();i++){
        tempstu.stu_info.append(tempspace.at(i).toInt());

        }
    qreal level=0.0;                                            //求平均值
    for(int i=0;i<tempstu.stu_info.size();i++){
        level+=tempstu.stu_info.at(i);
        }
    level=level/tempstu.stu_info.size();
    tempstu.stu_info.append(level);
        student.append(tempstu);
    }

    mfile.close();
}

void ScoreSorter::doSort()
{

    myCmp cmp_temp(N-2);
    std::sort(student.begin(),student.end(),cmp_temp);
    qDebug()<<"排序后输出，当前排序第 "<<N<<" 列："<<"\n";
    caption.removeLast();
    caption.append("平均分");
    qDebug().noquote()<<qSetFieldWidth(3)<<caption;
    for(int i=0;i<student.size();i++)
    {
        qDebug()<<student.at(i);
    }
}





//void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
//{
//    //注意编码问题
//    QByteArray localMsg = msg.toUtf8();
//    QString strMessage = QString(localMsg.constData());
//    QFile file("sorted_data.txt");
//    file.open(QIODevice::ReadWrite | QIODevice::Append);
//    QTextStream stream(&file);
//    stream.setCodec("UTF-8");
//    stream << strMessage << "\r\n";
//    qDebug().noquote()<<strMessage;
//    file.close();
//}

void msgLogger(QtMsgType type,const QMessageLogContext &context,const QString &msg)
{
    Q_UNUSED(type);
    Q_UNUSED(context);
    QFile outFile("sorted_data.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << msg << endl;
    QTextStream(stdout) << msg << endl;
}

int main()
{
    qInstallMessageHandler(msgLogger);
    QString datafile = "data.txt";
    QFile f("sorted_"+datafile);    // 如果排序后文件已存在，则删除之
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}


