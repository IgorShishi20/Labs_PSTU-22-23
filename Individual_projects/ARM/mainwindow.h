#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void Resourses_inc();

    void Resourses_dec();

    void Illness();

    void Good_health();

    void Complete_contract(int);

private:
    Ui::MainWindow *ui;
private slots:
    void Ask_credit(int);

    void Provide_resourses(int);

    void Provide_everything();

    void All_provided(QLineEdit*, QWidget*);

    void Send_team(QLineEdit*,int,QWidget*);

    void Update_timer();

    void Make_contract();

    void Send_resourses(QLineEdit*,QLineEdit*,int,QWidget*);

    void Choose_project(int);

    void Random_event();
};
#endif // MAINWINDOW_H
