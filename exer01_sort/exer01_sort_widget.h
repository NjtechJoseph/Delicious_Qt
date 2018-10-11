#ifndef EXER01_SORT_WIDGET_H
#define EXER01_SORT_WIDGET_H

#include <QWidget>

namespace Ui {
class exer01_sort_Widget;
}

class exer01_sort_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit exer01_sort_Widget(QWidget *parent = 0);
    ~exer01_sort_Widget();

private slots:

private:
    Ui::exer01_sort_Widget *ui;
};

#endif // EXER01_SORT_WIDGET_H
