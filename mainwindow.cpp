#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <unordered_map>
#include <QMap>
#include <QString>
#include <QtCharts>

using namespace std;


void MainWindow::storeData(){
    climateScores.insert({"Steak", 15.5});
    climateScores.insert({"Chicken", 1.82});
    climateScores.insert({"Pork", 2.4});
    climateScores.insert({"Tofu Sofritas", 0.08});
    climateScores.insert({"Impossible", 0.75});
    climateScores.insert({"No protein", 0});
    climateScores.insert({"No beans", 0});
    climateScores.insert({"Black", 0.18});
    climateScores.insert({"Refried", 0.182});
    climateScores.insert({"No rice", 0});
    climateScores.insert({"White", 0.16});
    climateScores.insert({"Brown", 0.16});
    climateScores.insert({"No topping", 0});
    climateScores.insert({"Lettuce", 0.05});
    climateScores.insert({"Guacamole", 0.09});
    climateScores.insert({"Pico de Gallo", 0.25});
    climateScores.insert({"Avocado Salsa", 0.023});
    climateScores.insert({"Sour Cream", 0.112});
    climateScores.insert({"No cheese", 0});
    climateScores.insert({"Shredded Cheddar-Jack Cheese", 0.655});
    climateScores.insert({"No chips", 0});
    climateScores.insert({"Chips please!", 0.27});
}
void MainWindow::prepareChart(){
   QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();
   QBarCategoryAxis *axisX = new QBarCategoryAxis();

   //creating bar "groups" for each selection so they are separated, only created if an item is selected for that category
   if(bowlOrder[0]!=0){ QBarSet *protein= new QBarSet("Protein: "+QString::number(bowlOrder[0])); protein->append(bowlOrder[0]);series->append(protein);axisX->append("");}
   if(bowlOrder[1]!=0){QBarSet *beans = new QBarSet("Beans: "+QString::number(bowlOrder[1])); beans->append(bowlOrder[1]); series->append(beans);axisX->append("");}
   if(bowlOrder[2]!=0) {QBarSet *rice = new QBarSet("Rice: "+QString::number(bowlOrder[2]));rice->append(bowlOrder[2]); series->append(rice);axisX->append("");}
   if(bowlOrder[3]!=0) {QBarSet *topping = new QBarSet("Topping: "+QString::number(bowlOrder[3]));topping->append(bowlOrder[3]);series->append(topping);axisX->append("");}
   if(bowlOrder[4]!=0){QBarSet *cheese = new QBarSet("Cheese: "+QString::number(bowlOrder[4]));cheese->append(bowlOrder[4]);series->append(cheese);axisX->append("");}
   if(bowlOrder[5]!=0){ QBarSet *chips = new QBarSet("Chips: "+QString::number(bowlOrder[5]));chips->append(bowlOrder[5]);series->append(chips);axisX->append("");}
chart->createDefaultAxes();
   series->attachAxis(axisX);
   // Update the chart
   chart->update();
  chart->setAxisX(axisX, series);
   chart->addSeries(series);
    chart->setTitle("Your Bowl's Greenhouse Gas Emissions (kg)");
    QFont titleFont("Raleway", 20, QFont::Bold);
    chart->setTitleFont(titleFont);

    //display chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
}
//constructs mainwindow object.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->newOne->hide();
    ui->label_11->hide();
    ui->YEAH->hide();
    ui->pushButton_2->hide();

    //first we set every dropdown list to contain correct item options
    ui->proteinList->addItem("No protein");
    ui->proteinList->addItem("Chicken");
    ui->proteinList->addItem("Steak");
    ui->proteinList->addItem("Pork");
    ui->proteinList->addItem("Tofu Sofritas");
    ui->proteinList->addItem("Impossible");

    ui->beansList->addItem("No beans");
    ui->beansList->addItem("Black");
    ui->beansList->addItem("Refried");

    ui->riceList->addItem("No rice");
    ui->riceList->addItem("White");
    ui->riceList->addItem("Brown");

    ui->topping1->addItem("No topping");
    ui->topping1->addItem("Lettuce");
    ui->topping1->addItem("Guacamole");
    ui->topping1->addItem("Pico de Gallo");
    ui->topping1->addItem("Avocado Salsa");
    ui->topping1->addItem("Sour Cream");

    ui->cheeseList->addItem("No cheese");
    ui->cheeseList->addItem("Shredded Cheddar-Jack Cheese");

    ui->chipsList->addItem("No chips");
    ui->chipsList->addItem("Chips please!");
    storeData();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //access hash table elements and then add their emissions values to an array for user's order
    bowlOrder[0]=climateScores.at(ui->proteinList->currentText());
    bowlOrder[1]=climateScores.at(ui->beansList->currentText());
    bowlOrder[2]=climateScores.at(ui->riceList->currentText());
    bowlOrder[3]=climateScores.at(ui->topping1->currentText());
    bowlOrder[4]=climateScores.at(ui->cheeseList->currentText());
    bowlOrder[5]=climateScores.at(ui->chipsList->currentText());

    //add up all elements in array to get total climate score
    double myScore=0;
    for(int i=0; i<6; i++){
        myScore+=bowlOrder[i];
    }
    ui->pushButton->setText(QString::number(myScore));



//"erase" current screen elements
    ui->beansList->deleteLater();
    ui->cheeseList->deleteLater();
    ui->chipsList->deleteLater();
    ui->topping1->deleteLater();
    ui->proteinList->deleteLater();
    ui->riceList->deleteLater();
    ui->label->deleteLater();
    ui->label_3->deleteLater();
    ui->label_6->deleteLater();
    ui->label_5->deleteLater();
    ui->label_4->deleteLater();
    ui->label_7->deleteLater();
    ui->label_8->deleteLater();
    ui->label_9->deleteLater();
    ui->pushButton->deleteLater();

    ui->newOne->setAlignment(Qt::AlignVCenter);
    ui->newOne->show();
     ui->newOne->setAlignment(Qt::AlignHCenter);

    if(myScore<3) {
        setStyleSheet("background-color: #90EE90;");
        ui->newOne->setText("CONGRATULATIONS");
    }
    else if (myScore<8) {
        setStyleSheet("background-color: 	#FFFACD");
        ui->newOne->setText("GETTING THERE...");
    }
    else{
         setStyleSheet("background-color: red");
         ui->newOne->setText("MUCH TO DO.");

    }
    myScore=17-myScore;
    ui->YEAH->setText(QString::number((10*myScore/17), 'g', 2)+"/10");
    ui->YEAH->show();
    ui->label_11->show();
    ui->pushButton_2->show();

}

//"what can i do" button clicked
void MainWindow::on_pushButton_2_clicked()
{
    ui->newOne->hide();
    ui->YEAH->hide();
    ui->label_11->hide();
    ui->pushButton_2->hide();
    prepareChart();
}


