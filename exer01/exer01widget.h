#ifndef EXER01WIDGET_H
#define EXER01WIDGET_H

#include <QWidget>

namespace Ui {
class exer01Widget;
}

class exer01Widget : public QWidget
{
    Q_OBJECT

public:
    explicit exer01Widget(QWidget *parent = 0);
    ~exer01Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::exer01Widget *ui;
};

#endif // EXER01WIDGET_H
