#include "adddialog.h"
#include "ui_adddialog.h"

adddialog::adddialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddialog)
{
    ui->setupUi(this);

    connect(ui->pushAdd,&QPushButton::clicked,this,&adddialog::getnewInfo);
    connect(ui->grade_Add,&QPushButton::clicked,this,&adddialog::addgradeInfo);
    connect(ui->pushOk,&QPushButton::clicked,this,&adddialog::inputFinish);
}

adddialog::~adddialog()
{
    delete ui;
}



addDialog::~addDialog()
{
    delete ui;
}
/**
 * @brief addDialog::setRequestdb
 * 私有变量传递函数
 * @param getdb
 */
void addDialog::setRequestdb(QSqlDatabase getdb)
{
    newdb =getdb ;
}


void adddialog::getnewInfo()
{
    if (newdb.open())
        newdb.close();

    if(!newdb.open())
    {
        qDebug() << "Error: Failed to connect database." << newdb.lastError();
        return;
    }
    else
    {
        QSqlQuery sql_query;
        QString select_sql = QString("select * from t_courses");

        if(!sql_query.exec(select_sql))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                allCourse<<sql_query.value(1).toString();

            }
        }


        /*得到学生信息*/

        QString str;
        QString data1=ui->lineEdit_Num->text();
        QString data2=ui->lineEdit_Name->text();
        if(!data1.isEmpty())

            str=QString("where sNumber ='%1'").arg(data1);

        else if(!data2.isEmpty())

            str=QString("where sName ='%1'").arg(data2);

        select_sql = QString("select * from t_stud_info %1").arg(str);

        if(!sql_query.exec(select_sql))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                addNumber=sql_query.value(0).toString();
                addName=sql_query.value(1).toString();
                addMajor=sql_query.value(2).toString();
                addGrade=sql_query.value(3).toString();
            }
            updatedialog();
        }
    }
}







