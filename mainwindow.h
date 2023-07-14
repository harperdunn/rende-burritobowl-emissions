#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <unordered_map>
#include <QPixmap>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void storeData();
    void prepareChart();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    std::unordered_map<QString, float> climateScores;
    float bowlOrder[6];
};
#endif // MAINWINDOW_H
