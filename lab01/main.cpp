#include "exer01_sort_widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    exer01_sort_Widget w;

    w.show();

    return a.exec();
}


//    QVector<QString> luzhishen;
//    QVector<QString> linchong;
//    QVector<QString> songjiang;
//    QVector<QString> wusong;
//    luzhishen.append({"1403130209", "鲁智深",  "80",  "72"});
//    linchong.append({"1403140101",  "林冲",    "82",  "76"});
//    songjiang.append({"1403130102", "宋江",    "76",  "85"});
//    wusong.append({"1403130103",    "武松",    "88",  "80"});
//    for(int i=0;i<4;i++) {    //初始化一个m*n的二维数组,在此程序中无法使用......
//        table[i].resize(4);
//    }
    /************************
     * 给二元向量赋值
     ***********************/
//    table[0].append({"1403130209", "鲁智深",  "80",  "72"});
//    table[1].append({"1403140101", "林冲",    "82",  "76"});
//    table[2].append({"1403130102", "宋江",    "76",  "85"});
//    table[3].append({"1403130103", "武松",    "88",  "80"});
//    void sortbylesson1();
//    void sortbylesson2();



//    bool cmp(int *p,int *q)
//    {
//        if(p[0]==q[0])
//        {
//            if(p[1]==q[1])
//            {
//                return p[2]<q[2];
//            }
//            else return p[1]<q[1];
//        }
//        else return p[0]<q[0];
//    }
//    sort(a,a+10,cmp);
//    cout<<"After sort"<<endl;
//    for(i=0;i<10;++i)
//    {
//        printf("%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2]);
//    }
    //    int main() {
//        vector<vector<int> > array(4);
//        for(int i=0;i<4;i++) {
//            array[i].resize(5);
//        }
//        //输出二维数组的行和列
//        cout<<"Row:"<<array.size()<<"  Column:"<<array[0].size()<<endl;
//        //输出二维数组
//        cout<<"["<<endl;
//        for(int j=0;j<array.size();j++) {
//            cout<<"["<<" ";
//            for(int k=0;k<array[0].size();k++) {
//                cout<<array[j][k]<<" ";
//            }
//            cout<<"]"<<endl;
//        }
//        cout<<"]"<<endl;
//        return 0;
//    }

    //   ui->tableWidget->setItem(0,0,new QTableWidgetItem(table[1][1]));    //    void setItem(int row, int column, QTableWidgetItem *item)

    //    qDebug()<<table[1][1];
    //    ui->tableWidget->setColumnWidth(0, 150);                             //codes below will be used later
    //    ui->tableWidget->setRowHeight(0,50);
    //    ui->tableWidget->setColumnCount(3);
    //    ui->tableWidget->setRowCount(5);
    //    QStringList List;
    //    List<<"name0"<<"name1"<<"name2";
    //    ui->tableWidget->setHorizontalHeaderLabels(List);                     //为表格添加列名
    //    ui->tableWidget->setColumnWidth(0,100);
    //    ui->tableWidget->setColumnWidth(1,200);
    //    ui->tableWidget->horizontalHeader()->setStretchLastSection(1);        //将表头的第2列宽度延伸到整个列表全满
//exer01_sort_Widget::namesort()
//{
//       QDebug()<<table[3][2];
//}

//bool lessmark(double* a,double* b)
//{
//    return a[0]< b[0];
//}
//bool greatermark(double* a,double* b)
//{
//    return a[0]> b[0];
//}
//int main()
//{
//    vector<double* > ctn ;

//    double M[3][3]={1,3,2,
//                9,5,6,
//                4,8,7};

//    ctn.push_back(M[0]);
//    ctn.push_back(M[1]);
//    ctn.push_back(M[2]);

//    for( int row = 0; row < 3; row++ )
//    {
//        for( int col = 0; col < 3; col++ )
//        {
//            cout<<ctn[row][col]<<"   ";
//        }
//        cout<<endl;
//    }

//    cout<<endl;

//    sort(ctn.begin(), ctn.end(),lessmark) ; //升序排序

//    cout<<"升序排列后："<<endl;
//    for( int row = 0; row < 3; row++ )
//    {
//        for( int col = 0; col < 3; col++ )
//        {
//            cout<<ctn[row][col]<<"   ";
//        }
//        cout<<endl;
//    }

//    cout<<endl;

//    for( int row = 0; row < 3; row++ )
//    {
//        for( int col = 0; col < 3; col++ )
//        {
//            M[row][col]=ctn[row][col];
//            cout<<M[row][col]<<"   ";
//        }
//        cout<<endl;
//    }

//    sort(ctn.begin(), ctn.end(),greatermark) ; //降序排序
//    cout<<"降序排列后："<<endl;
//    for( int row = 0; row < 3; row++ )
//    {
//        for( int col = 0; col < 3; col++ )
//        {
//            cout<<ctn[row][col]<<"   ";
//        }
//        cout<<endl;
//    }

//    cout<<endl;

//    for( int row = 0; row < 3; row++ )
//    {
//        for( int col = 0; col < 3; col++ )
//        {
//            M[row][col]=ctn[row][col];
//            cout<<M[row][col]<<"   ";
//        }
//        cout<<endl;
//    }
//    return 0   ;
//}
