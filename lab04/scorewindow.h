#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QMainWindow>
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

private:
    Ui::ScoreWindow *ui;
};

#endif // SCOREWINDOW_H
