#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QAction>
#include <QFileDialog>

namespace Ui {
class adddialog;
}

class adddialog : public QDialog
{
    Q_OBJECT

public:
    explicit adddialog(QWidget *parent = 0);
    ~adddialog();
    void setRequestdb(QSqlDatabase);


private slots:


private:
    Ui::adddialog *ui;
    void getnewInfo();
    QSqlDatabase newdb;
    QString addNumber;
    QString addName;
    QString addMajor;
    QString addGrade;
    QString addEnroll;
    QString addphone;
    QStringList allCourse;
    void updatedialog();
    void addgradeInfo();
    void inputFinish();
signals:
    void addFinish();
};

#endif // ADDDIALOG_H
