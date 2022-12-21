#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include "meatrecipe.h"
#include "vegrecipe.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void buttonClicked();
    void rb1Toggled(bool checked);
    void rb2Toggled(bool checked);
    void rb3Toggled(bool checked);
    void rb4Toggled(bool checked);
    void submitClicked();

private:
    Ui::MainWindow *ui;
    //remove the firstbutton and secondbutton
    //QPushButton *firstButton;
    //QPushButton *secondButton;


    QLabel *testLabel; //"welcome to budgie! \n What would you like to eat?"
    QLabel *testLabel2; //"What is your budget?

    QRadioButton *rb1; //the meat button
    QRadioButton *rb2; //the vegetable button
    QButtonGroup *bg;

    QRadioButton *rb3;
    QRadioButton *rb4;
    QButtonGroup *bg2;

    QPushButton *submit;
    QLabel *result;
    int isMeat; //meat = 1, veg = 0
    int isBudget; //low cost = 1, biggest discount = 0;


};
#endif // MAINWINDOW_H
