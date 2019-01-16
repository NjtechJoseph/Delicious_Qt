#include "scorewindow.h"
#include "ui_scorewindow.h"
#include "ui_adddialog.h"
#include<QMessageBox>
#include<qDebug>
#include"adddialog.h"

ScoreWindow::ScoreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScoreWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("1998");
    db.setDatabaseName("test");

    connect(ui->add_action,&QAction::triggered,this,&ScoreWindow::on_addAction_clicked);
    connect(ui->input_action,&QAction::triggered,this,&ScoreWindow::on_importAction_clicked);
}

ScoreWindow::~ScoreWindow()
{
    db.close();
    delete ui;
}

/*
 * @brief   ScoreWindow::on_btnQuery_clicked 
 *          输入查询信息后，点击开始按键槽函数
 *
 */
void ScoreWindow::on_btnQuery_clicked()
{
    if(db.open())
        db.close();
    if(!db.open())
    {
        qDebug() <<"Error: Failed to connect database"<<db.lastError();
        return;
    }
    else
    {
        getInfo();
        updataWindow();
    }
}

/*
 * @brief   连接数据库获取数据
 * @param
 *
 */
void ScoreWindow::getInfo()
{
    QString str;
    if(ui->NumButton->isChecked())
        str=QString("where sNumber ='%1' ").arg(ui->InputEdit->text());
    else if(ui->NameButton->isChecked())
        str=QString("where sName ='%1'").arg(ui->InputEdit->text());
    else if(ui->allButton->isChecked())
        str=QString("");

    QSqlQuery sql_query;    //数据库操作类
    //得到学生成绩信息
    QString select_sql = QString("select t_stud_info.sName as '姓名',t_courses.courseName as '课程名称',"
                                 "t_stud_course_info.scScores as '成绩'，t_courses.courseCredit as '学分'"
                                 "from"
                                 "(t_stud_course_info inner join t_courses on t_stud_course_info.scCourseID = t_courses.courseID)"
                                 "inner join t_stud_info on t_stud_info.sNumber = t_stu_course_info.scNumber "
                                 "%1 "
                                 "order by t_stud_course_info.scNumber "
                                 ";").arg(str);
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        qDebug()<<sql_query.next();
        while(sql_query.next())
        {
            sName<<sql_query.value(0).toString();
            course_Name<<sql_query.value(1).toString();
            scScores<<sql_query.value(2).toString();
            courseCredit<<sql_query.value(3).toString();
        }

    }
    //得到指定学生相关信息
    select_sql=QString("select * from t_stu_info %1").arg(str);
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            number=sql_query.value(0).toString();
            name=sql_query.value(1).toString();
            major=sql_query.value(2).toString();
            grade=sql_query.value(3).toString();
        }
    }
}

/*
 * @brief   绘制界面的函数
 * @param
 *
 */
void ScoreWindow::updateWindow()
{
    QString temp;
    //cellpadding规定单元边沿与内容之间的空白
    //align规定表格相对周围元素的对齐方式
    //border规定表格边框的宽度
    temp.append("<table border='1' cellpadding='10' align='center' > <tr> <tdcolspan='4'align='center' bgcolor='#9DCEFF' >");
    if(!sName.size()) return;
    temp.append(sName.at(0));
    temp.append("</td>      </tr>");
    temp.append(" <tr>   <td width='80' >序号</td>   <td>课程名称</td>   <td>成绩</td>    <td>学分</td>      </tr> ");
    for(int i=0;i<sName.size();i++)
    {
        temp.append(" <tr>   <td> ");
        temp.append(QString::number(i+1));
        temp.append("</td>   <td>");
        temp.append(course_Name.at(i));
        temp.append("</td>   <td>");
        temp.append(scScores.at(i));
        temp.append("</td>   <td>");
        temp.append(courseCredit.at(i));
        temp.append("</td>    </tr> ");
    }
    temp.append("<tr bgcolor='#9DCEFF' >     <td colspan='4'align='center' >");
    temp.append("平均绩点为");
    temp.append(leveltrans(scScores,courseCredit));
    temp.append("</td>      </tr></table>");

    ui->textEdit->clear();
    ui->textEdit->append(temp);
    ui->numEdit->setText(number);
    ui->nameEdit->setText(name);
    ui->majorEdit->setText(major);
    ui->gradeEdit->setText(grade);
    sName.clear();
    course_Name.clear();
    scScores.clear();
    courseCredit.clear();
}



/*
 * @brief 根据成绩和学分得到平均绩点，同时处理等级信息
 * @param score credit
 *
 */
QString ScoreWindow::convertlevel(QStringList score, QStringList credit)
{
    QStringList levelList;
    levelList<<"splendid"<<"good"<<"moderate"<<"pass"<<"not pass"<<"delayed exam"<<"miss exam";
    double mypoint=0;
    double sum=0;
    for(int i=0;i<score.size();i++)
    {
        QString toscore=score.at(i);
        QString mycredit=credit.at(i);
        if(levelList.contains(score.at(i)))
        {
            switch (levelList.indexOf(score.at(i)))
            {
            case 0:
                toscore="95";
                break;
            case 1:
                toscore="85";
                break;
            case 2:
                toscore="75";
                break;
            case 3:
                toscore="65";
                break;
            case 4:
                toscore="50";
                break;
            case 5:
                toscore="0";
                break;
            case 6:
                toscore="0";
                break;
            default:
                break;
            }
        }
        if(!toscore.toDouble())
            mypoint+=0;
        else
            mypoint+=((toscore.toDouble()/10-5)*mycredit.toDouble());
        sum+=mycredit.toDouble();
    }
    double avg=mypoint/sum;
    QString s= QString::number(avg);
    return s;
}

/*
 * @brief   创建增加记录界面
 * @param
 *
 */
void ScoreWindow::on_addAction_clicked()
{
    myaddDialog=new addDialog(this);
    connect(myaddDialog,&addDialog::addFinish,this,&ScoreWindow::closeAddDialog);
    myaddDialog->show();
    myaddDialog->setRequest(db);
}

/*
 * @brief 接收到信号后关闭dialog框
 * @param
 *
 */

void ScoreWindow::closeAddDialog()
{
    myaddDialog->close();
}



/*
 * @brief 批量导入槽函数
 * @param
 */
void ScoreWindow::on_importAction_clicked()
{
    path = QFileDialog::getOpenFileName(this, tr("批量导入"), ".", tr("csv Files(*.csv)"));
    if(path.length() == 0) {
        QMessageBox::information(NULL, tr("Info"), tr("You didn't select any files."));
        return;
    } else {
        QMessageBox::information(NULL, tr("Info"), tr("You selected ") + path);
    }
    //读取文件
    QStringList tempText;
    QFile file(path);
    qDebug()<<path;
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(NULL,tr("错误"),tr("文件打开失败！ "));
        return;
    }
    QTextStream out(&file);
    while(!out.atEnd()){
        tempText.append(out.readLine().trimmed());
    }
    file.close();
    //数据库操作
    if(tempText.isEmpty())
        return;
    if(db.isOpen()){
        qDebug()<<"Error: failed to connect database."<<db.lastError();
        return;
    }
    else {
        QString tempdata;
        QStringList singledata;
        QString selected_sql;
        QStringList signalcourseID;//注意
        QSqlQuery sql_query;
        tempdata=tempText.at(0);
        singledata=tempdata.split(',');
        qDebug()<<singledata;
        qDebug()<<singledata.size();

        for(int i=0;i<4;i++){
            select_sql = QString("select courseID from t_courses where courseName='%1';").arg(singledata.at(5+i));

            if(!sql_query.exec(select_sql))
            {
                qDebug()<<sql_query.lastError();
            }
            else
            {
                while(sql_query.next())
                {
                    signalcourseID<<sql_query.value(0).toString();
                }
            }
        }
        qDebug()<<signalcourseID;
        for(int i=1;i<tempText.size();i++){
            tempdata=tempText.at(i);
            singledata=tempdata.split(',')
            qDebug()<<singledata;
            for(int j=0;j<4;j++){
                select_sql = QString("insert into t_stud_course_info value ('','%1','%2','%3','','');").arg(singledata.at(1),signalcourseID.at(j),singledata.at(5+j));
                if(!sql_query.exec(selected_sql)){
                    qDebug()<<sql_query.lastError();
                }
                else{
                    qDebug()<<"插入成功";
                }
            }
        }
        QMessageBox::information(NULL,tr("info"),tr("导入成功"));
    }
}
