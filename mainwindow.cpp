#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
//#include "advisor.h"
#include "recipe.h"
//#include "ingredient.h"
#include <QRadioButton>
#include <QButtonGroup>
#include "meatrecipe.h"
#include "vegrecipe.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //remove the firstbutton and secondbutton
    //firstButton = new QPushButton("First Button", this);
    //secondButton = new QPushButton("Second Button", this);
    //firstButton->setGeometry(100, 100, 200, 50);
    //secondButton->setGeometry(400, 100, 200, 50);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("~/CSC_211_Final_Qmake/food_prices.db");
    QLabel *dbstatus = new QLabel("DBStatus", this);
    dbstatus->setGeometry(10, 25, 200, 50);
    try{
        db.setDatabaseName("food_prices.db");
        if (!db.open()){
            throw QString("DB Error");
        }
        else{
            dbstatus->setText("Database connected");
        }
    }
    catch (QString s){
        dbstatus->setText(s);
    }



    testLabel = new QLabel("Welcome to Budgie 2.0! \n What would you like to eat?", this);
    testLabel->setGeometry(300, 50, 200, 50);
    //testLabel->setText("");

    //radio buttons
    rb1 = new QRadioButton("Meat", this);
    rb2 = new QRadioButton("Vegetables", this);
    rb1->setGeometry(100, 100, 100, 100);
    rb2->setGeometry(300, 100, 100, 100);

    //the button group
    bg = new QButtonGroup();
    bg->addButton(rb1);
    bg->addButton(rb2);


    //the second radio buttons
    testLabel2 = new QLabel("What is your budget range?", this);
    testLabel2->setGeometry(300, 150, 200, 50);
    rb3 = new QRadioButton ("Something cheap", this);
    rb3->setGeometry(100, 200, 200, 100);
    rb4 = new QRadioButton ("Something discounted", this);
    rb4->setGeometry(300, 200, 200, 100);

    //the second button group;
    bg2 = new QButtonGroup();
    bg2->addButton(rb3);
    bg2->addButton(rb4);


    submit = new QPushButton("Submit", this);
    submit->setGeometry(300, 300, 200, 50);
    result = new QLabel("", this);
    result->setGeometry(200, 350, 500, 100);


    //connecting a "clicked" signal to a "buttonClicked()" function (aka slot)
    //connect(firstButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    //radio signal for toggle
    connect(rb1, SIGNAL(toggled(bool)), this, SLOT(rb1Toggled(bool)));
    connect(rb2, SIGNAL(toggled(bool)), this, SLOT(rb2Toggled(bool)));
    connect(rb3, SIGNAL(toggled(bool)), this, SLOT(rb3Toggled(bool)));
    connect(rb4, SIGNAL(toggled(bool)), this, SLOT(rb4Toggled(bool)));

    //signal for submit button
    connect(submit, SIGNAL(clicked()), this, SLOT(submitClicked()));
}

//void MainWindow::buttonClicked(){
//    testLabel->setText("What do you want to eat?");
//}

void MainWindow::rb1Toggled(bool checked){
    if (checked){
        isMeat = 1;
    }
}

void MainWindow::rb2Toggled(bool checked){
    if (checked){
        isMeat = 0;
    }
}

void MainWindow::rb3Toggled(bool checked){
    if (checked){
        isBudget = 1;
    }
}
void MainWindow::rb4Toggled(bool checked){
    if (checked){
        isBudget = 0;
    }
}

void MainWindow::submitClicked(){
    if (isMeat == 1 && isBudget == 1){
        Ingredient chicken_thigh(meat, 1.49, .10);
        Ingredient broccoli(vegetable, 0.99, -.10);
        Ingredient potato(vegetable, .79, 0);
        meatrecipe(chicken_thigh, "Roasted Chicken Thigh", broccoli, potato);
        result->setText("For a budget oriented meat recipe, you should choose Roasted Chicken Thigh \n since it costs $1.49 ");
    }

    else if (isMeat == 1 && isBudget == 0){
        Ingredient chicken_breast(meat, 2.99, .30);
        Ingredient spinach(vegetable, 1.99, .30);
        Ingredient sweet_potato(vegetable, .69, .26);
        meatrecipe(chicken_breast, "Roasted Chicken Breast", spinach, sweet_potato);
        result->setText("For a discounted meat recipe, you should try Roasted Chicken Breast \n since it is 30% cheaper than last week ");
    }

    else if (isMeat == 0 && isBudget == 1){
        Ingredient lentil(vegetable, .99, .10);
        Ingredient carrot(vegetable, 0.79, .00);
        Ingredient potato(vegetable, .79, 0);
        result->setText("For a budget oriented vegetable recipe, you should choose Lentil Soup \n since it costs $0.99");
    }
    else{
        Ingredient kale(vegetable, 1.49, .15);
        Ingredient broccoli(vegetable, 0.99, -.10);
        Ingredient sweet_potato(vegetable, .79, 0);
        result->setText("For a discounted vegetable recipe, you should try Kale Salad \n since it is 15% cheaper than last week");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


