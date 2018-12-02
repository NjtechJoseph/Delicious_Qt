#include "scorewindow.h"
#include "ui_scorewindow.h"

ScoreWindow::ScoreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScoreWindow)
{
    ui->setupUi(this);
}

ScoreWindow::~ScoreWindow()
{
    delete ui;
}
