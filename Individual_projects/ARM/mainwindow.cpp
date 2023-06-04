#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customdialog.h"
#include <QPushButton>
#include <QProgressBar>
#include <QTimer>
#include <QDialog>
#include <QRandomGenerator>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTextStream>

//NEWS

QPushButton* send_team_back[10];
QProgressBar* progress_bar[10];

int matrix_resourses[5][6] =
{{500,50,150,200,100,150},{1000,100,250,400,150,100},
{750,200,300,650,200,50},{1500,100,400,750,250,250},
{2000, 300,600,1000,300,400}};

int reward_contract[5] = {5500,7500,9000,15000,24000};

bool illness_matrix[5][5];

int contract_reward[5] = {5340, 7500, 10000, 14500, 23550};

QString material_type[6] = {" тыс. ₽", " тонн пиломатериалов", " центнеров цемента", " центнеров черепицы",
                            " центнеров металлических изделий", " тыс. кв. м. стекл. покрытия" };

int contract_type [10];

void MainWindow::Choose_project(int i){
    QWidget* wid = new QWidget;
    QLineEdit* line = new QLineEdit(wid);
    QLabel* label_contract = new QLabel(wid);
    QPushButton* btn = new QPushButton(wid);
    label_contract->setText("Выберите контракт для выполнения");
    wid->setStyleSheet("background-color: #686868; color:white;font: 14px;");
    wid->setGeometry(100,100,300,150);
    label_contract->setGeometry(10,10,300,20);
    line->setGeometry(10,35,250,30);
    btn->setGeometry(60,70,150,50);
    connect(btn,&QPushButton::clicked,this,[this,line,i,wid](){MainWindow::Send_team(line,i,wid);});
    btn->setText("Ok");
    wid->show();
}

void MainWindow::Send_team(QLineEdit *line, int i, QWidget *wid){
    int contract = line->text().toInt() % 10;
    ui->Contract_widget->item(contract,1)->setText(QString::number(i+1));
    wid->close();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //everyone has good health from the start
    for(int i=0;i<25;i++){
        illness_matrix[i/5][i%5]=true;
        ui->Workers_widget->item(i/5,i%5)->setBackground(QColor("lightgreen"));
    }
    //contracts have no type from start
    for(int i =0;i<10;i++) contract_type[i] = -1;
    // buttons for buying resourses, sending them to build smth and for sending group of workers to build something
    QPushButton* ask_resourses_buttons[6] = {
        ui->ask_credit, ui->ask_wood,
        ui->ask_cement, ui->ask_roof,
        ui->ask_metal, ui->ask_glass};
    QPushButton* send_resourse_buttons[6] = {
        ui->send_money, ui->send_wood,
        ui->send_cement, ui->send_roof,
        ui->send_metal, ui->send_glass};
    QPushButton* make_contract[5] = {
            ui->contract_add_1, ui->contract_add_2, ui->contract_add_3,
            ui->contract_add_4, ui->contract_add_5};
    //connect buttons and complete table with contracts
    for(int i=0;i<5;i++) connect(make_contract[i], &QPushButton::clicked,this,[this,i](){MainWindow::Choose_project(i);});
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            ui->Contract_widget->setItem(i,j,new QTableWidgetItem);
            ui->Contract_widget->item(i,j)->setText("");
        }
    }
    for(int i=0;i<6;i++){
        ui->Resource_widget->setItem(i,1,new QTableWidgetItem);
        connect(ask_resourses_buttons[i],&QPushButton::clicked,this,[this,i]{MainWindow::Ask_credit(i);});
        connect(send_resourse_buttons[i], &QPushButton::clicked,this,[this,i](){MainWindow::Provide_resourses(i);});}
    //now we start to use random generators
    QRandomGenerator* random = new QRandomGenerator;
    //add progress bars and buttons to send group of workers back
    for(int i=0;i<10;i++){
        send_team_back[i] = new QPushButton("Заменить бригаду");
        progress_bar[i] = new QProgressBar;
        progress_bar[i]->setValue(0);
        ui->Contract_widget->setCellWidget(i,8,progress_bar[i]);
        ui->Contract_widget->setCellWidget(i,9,send_team_back[i]);
        send_team_back[i]->setStyleSheet("QPushButton{background-color: #262626;color: white;}");
        connect(send_team_back[i],&QPushButton::clicked, this, [this,i]{ui->Contract_widget->item(i,1)->setText("");});
    }
    QPixmap bkgnd("./background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::Update_timer);
    timer->start(500);
    QTimer *timer_contract = new QTimer(this);
    timer_contract->start(5000);
    connect(timer_contract,&QTimer::timeout,this,&MainWindow::Make_contract);
    QTimer *random_event = new QTimer(this);
    random_event->start(1000);
    connect(random_event,&QTimer::timeout,this,&MainWindow::Random_event);
    //connect button for completing contract
    connect(ui->Complete_contract,&QPushButton::clicked,this,&MainWindow::Provide_everything);
    this->setWindowTitle("АРМ главы филиала строительной компании");
}

void MainWindow::Provide_everything(){
    QWidget* wid = new QWidget;
    QLineEdit* line = new QLineEdit(wid);
    QLabel* label_contract = new QLabel(wid);
    QPushButton* btn = new QPushButton(wid);
    label_contract->setText("Выберите контракт для выполнения");
    wid->setStyleSheet("background-color: #686868; color:white;font: 14px;");
    wid->setGeometry(100,100,300,150);
    label_contract->setGeometry(10,10,300,20);
    line->setGeometry(10,35,250,30);
    btn->setGeometry(60,70,150,50);
    connect(btn,&QPushButton::clicked,this,[this,line,wid](){MainWindow::All_provided(line,wid);});
    btn->setText("Ok");
    wid->show();
}

void MainWindow::All_provided(QLineEdit* line, QWidget* wid){
    int contract = line->text().toInt();
    for(int i=0;i<6;i++){
        int need = ui->Contract_widget->item(contract,i+2)->text().toInt();
        int need_overall = ui->Resource_widget->item(i,1)->text().toInt();
        int have = ui->Resource_widget->item(i,0)->text().toInt();
        need_overall-=need;
        have-=need;
        ui->Resource_widget->item(i,0)->setText(QString::number(have));
        ui->Resource_widget->item(i,1)->setText(QString::number(need_overall));
        ui->Contract_widget->item(contract,i+2)->setText("0");
    }
    wid->close();
}

void MainWindow::Random_event(){
    int i = qrand() % 20;
    switch (i) {
    case 1: Resourses_inc(); break;
    case 3: Resourses_dec(); break;
    case 7: Illness(); break;
    case 12: Good_health(); break;
    }
}

void MainWindow::Resourses_inc(){
    int amount;
    int type = qrand() % 6;
    if(type==0) amount = 100 + qrand() % 900;
    else amount = 10 + qrand() % 90;
    int resourse = ui->Resource_widget->item(type,0)->text().toInt();
    resourse += amount;
    ui->Resource_widget->item(type,0)->setText(QString::number(resourse));
    QString str = "Мы получили " + QString::number(amount) + material_type[type];
    ui->News->append(str);
}

void MainWindow::Resourses_dec(){
    int amount;
    int type = qrand() % 6;
    if(type==0) amount = 100 + qrand() % 900;
    else amount = 10 + qrand() % 90;
    int resourse = ui->Resource_widget->item(type,0)->text().toInt();
    resourse -= amount;
    ui->Resource_widget->item(type,0)->setText(QString::number(resourse));
    QString str = "Мы потеряли " + QString::number(amount) + material_type[type];
    ui->News->append(str);
}

void MainWindow::Complete_contract(int i){
    int type = contract_type[i];
    int total = ui->Resource_widget->item(0,0)->text().toInt();
    total += reward_contract[type];
    ui->Resource_widget->item(0,0)->setText(QString::number(total));
    for(int j=0;j<8;j++) ui->Contract_widget->item(i,j)->setText("");
}

void MainWindow::Illness(){
    int worker = qrand() % 25;
    if(illness_matrix[worker / 5][worker % 5]){
        illness_matrix[worker / 5][worker % 5] = false;
        ui->Workers_widget->item(worker/5,worker%5)->setBackground(QColor("tomato"));
        QString str = "Сотрудник " + QString::number(ui->Workers_widget->item(worker/5,worker%5)->text().toInt()) + " болен";
        ui->News->append(str);
    }
    else for(int i=0;i<25;i++)
        if(illness_matrix[i/5][i%5]){
            illness_matrix[i/5][i%5] = false;
            ui->Workers_widget->item(i/5,i%5)->setBackground(QColor("tomato"));
            QString str = "Сотрудник " + QString::number(ui->Workers_widget->item(i/5,i%5)->text().toInt()) + " болен";
            ui->News->append(str);
            break;
        }
}

void MainWindow::Good_health(){
    int worker = qrand() % 25;
    if(!illness_matrix[worker / 5][worker % 5]){
        illness_matrix[worker / 5][worker % 5] = true;
        ui->Workers_widget->item(worker/5,worker%5)->setBackground(QColor("lightgreen"));
        QString str = "Сотрудник " + QString::number(ui->Workers_widget->item(worker/5,worker%5)->text().toInt()) + " выздоровел";
        ui->News->append(str);
    }
    else for(int i=0;i<25;i++)
        if(!illness_matrix[i/5][i%5]){
            illness_matrix[i/5][i%5] = true;
            ui->Workers_widget->item(i/5,i%5)->setBackground(QColor("lightgreen"));
            QString str = "Сотрудник " + QString::number(ui->Workers_widget->item(i/5,i%5)->text().toInt()) + " выздоровел";
            ui->News->append(str);
            break;
        }
}

void MainWindow::Update_timer(){
    for(int i=0;i<10;i++){
        QString str = ui->Contract_widget->item(i,1)->text();
        bool contract_ready = (str=="1") || (str=="2") || (str=="3") || (str=="4") || (str=="5");
        contract_ready = contract_ready && ui->Contract_widget->item(i,2)->text()=="0";
        contract_ready = contract_ready && ui->Contract_widget->item(i,3)->text()=="0";
        contract_ready = contract_ready && ui->Contract_widget->item(i,4)->text()=="0";
        contract_ready = contract_ready && ui->Contract_widget->item(i,5)->text()=="0";
        contract_ready = contract_ready && ui->Contract_widget->item(i,6)->text()=="0";
        contract_ready = contract_ready && ui->Contract_widget->item(i,7)->text()=="0";
        bool team_working = illness_matrix[str.toInt()][0] || illness_matrix[str.toInt()][1] ||
                illness_matrix[str.toInt()][2] ||illness_matrix[str.toInt()][3] || illness_matrix[str.toInt()][4];
        bool have_resourses = true;
        for(int i =0;i<6;i++){
            have_resourses = have_resourses && (ui->Resource_widget->item(i,0)->text().toInt()>0);
        }
        if(contract_ready && team_working && have_resourses){
            if(progress_bar[i]->value()==99){
                Complete_contract(i);
                progress_bar[i]->setValue(0);
            }
            else{
                progress_bar[i]->setValue(progress_bar[i]->value()+1);
            }
        }
    }
}

void MainWindow::Ask_credit(int i){
    int need = ui->Resource_widget->item(i,0)->text().toInt();
    if(i!=0) need += 1000;
    int money = ui->Resource_widget->item(0,0)->text().toInt();
    switch (i) {
    case 1: money -= 1000; break;
    case 2: money -= 2000; break;
    case 3: money -= 5000; break;
    case 4: money -= 8000; break;
    case 5: money -= 12000;break;
    }
    ui->Resource_widget->item(0,0)->setText(QString::number(money));
    ui->Resource_widget->item(i,0)->setText(QString::number(need));
}

void MainWindow::Provide_resourses(int i){
    QWidget* wid = new QWidget;
    wid->setStyleSheet("color: white; background-color: #686868;");
    QLineEdit* line = new QLineEdit(wid);
    QLabel* label_res = new QLabel(wid);
    QLabel* label_proj = new QLabel(wid);
    QPushButton* btn = new QPushButton(wid);
    QLineEdit* line_contract = new QLineEdit(wid);
    label_res->setText("Сколько нужно отправить");
    label_proj->setText("На какой проект выделяем ресурсы");
    wid->setGeometry(100,100,320,200);
    label_res->setGeometry(10,10,300,20);
    line->setGeometry(10,35,300,30);
    label_proj->setGeometry(10,70,300,20);
    line_contract->setGeometry(10,100,300,30);
    btn->setGeometry(85,140,150,50);
    connect(btn,&QPushButton::clicked,this,[this,line,line_contract,i,wid](){MainWindow::Send_resourses(line,line_contract,i,wid);});
    btn->setText("Ok");
    wid->show();
}

void MainWindow::Send_resourses(QLineEdit* line,QLineEdit* line_contract,int i,QWidget* wid){
    //get data from dialog and how much resourses we have and we need for all contracts
    int contract_number = line_contract->text().toInt();
    int amount = line->text().toInt();
    int curr_amount = ui->Resource_widget->item(i,0)->text().toInt();
    int curr_need = ui->Resource_widget->item(i,1)->text().toInt();
    //how much resourses we need for particular contract
    int contract_need = ui->Contract_widget->item(contract_number,i+2)->text().toInt();
    //get minimum of amount we provided and amount we need for contract
    int min = qMin(contract_need,amount);
    curr_need -= min;
    curr_amount -= min;
    contract_need -= min;
    ui->Resource_widget->item(i,1)->setText(QString::number(curr_need));
    ui->Resource_widget->item(i,0)->setText(QString::number(curr_amount));
    ui->Contract_widget->item(contract_number,i+2)->setText(QString::number(contract_need));
    wid->close();
}

void MainWindow::Make_contract(){
    // randomize index of contract and its type
    int contr_num = 10000 + qrand() % 40000;
    int contr_type = qrand() % 5;
    //int coeff_resources = random->bounded(0,50);
    for(int i = 0;i<10;i++){
        QTableWidgetItem* item = ui->Contract_widget->item(i,0);
        QString str = item->text();
        QString s = ui->Contract_widget->item(i,0)->text();
        if(s.isEmpty()){
            QString str = QString::number(contr_num) + " " + QString::number(contr_type);
            contract_type[i] = contr_type;
            ui->Contract_widget->item(i,0)->setText(str);
            ui->Contract_widget->item(i,2)->setText(QString::number(matrix_resourses[contr_type][0]));
            ui->Contract_widget->item(i,3)->setText(QString::number(matrix_resourses[contr_type][1]));
            ui->Contract_widget->item(i,4)->setText(QString::number(matrix_resourses[contr_type][2]));
            ui->Contract_widget->item(i,5)->setText(QString::number(matrix_resourses[contr_type][3]));
            ui->Contract_widget->item(i,6)->setText(QString::number(matrix_resourses[contr_type][4]));
            ui->Contract_widget->item(i,7)->setText(QString::number(matrix_resourses[contr_type][5]));
            int res[6];
            for(int j=0;j<6;j++){
                res[j] = ui->Resource_widget->item(j,1)->text().toInt();
                res[j] = res[j] + matrix_resourses[contr_type][j];
                ui->Resource_widget->item(j,1)->setText(QString::number(res[j]));
            }
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
