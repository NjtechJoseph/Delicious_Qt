#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include"adddialog.h"
#include <QMainWindow>
#include <QtSql>
#include<QAction>
#include<QMenuBar>
#include<QFileDialog>
//#include<QMenuBar>

namespace Ui {
class ScoreWindow;
}

class ScoreWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScoreWindow(QWidget *parent = 0);
    ~ScoreWindow();

private slots:
    void on_btnQuery_clicked();
    
private:
    Ui::ScoreWindow *ui;
    QSqlDatabase db;
    QStringList sName;
    QStringList course_Name;
    QStringList scScores;
    QStringList leveltoScore;
    QStringList courseCredit;

    QString name;
    QString number;
    QString major;
    QString grade;

    addDialog *myaddDialog;
    QString path;
    void countpoints(const QString &Score,const QString &credit);
    QString convertlevel(QStringList score,QStringList credit);
    void performancePoints(QStringList scoreList);
    void getInfo();
    void updateWindow();
    void closeAddDialog();
    void on_exit_clicked();
    void importCsv(QString);
    void on_filename_clicked();
    void on_addAction_clicked();
    void on_importAction_clicked();


};

#endif // SCOREWINDOW_H
