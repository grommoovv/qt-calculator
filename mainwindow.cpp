#include "mainwindow.h"
#include "ui_mainwindow.h"

double NUM_FIRST;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits()
{
    QPushButton *button = (QPushButton*) sender();

    double all_numbers;
    QString new_label;

    if (ui->label_result->text().contains(".") && button->text() == "0") {
        new_label = ui->label_result->text() + button->text();
    }

    all_numbers = (ui->label_result->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 12);

    ui->label_result->setText(new_label);
}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->label_result->text().contains('.'))) {
        ui->label_result->setText(ui->label_result->text() + ".");
    }
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton*) sender();

    double all_numbers;
    QString new_label;

    if (button->text() == "+/-") {
        all_numbers = (ui->label_result->text().toDouble());
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 12);

        ui->label_result->setText(new_label);
    }

    if (button->text() == "%") {
        all_numbers = (ui->label_result->text().toDouble());
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 12);

        ui->label_result->setText(new_label);
    }

}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    ui->label_result->setText("0");
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton*) sender();

    NUM_FIRST = ui->label_result->text().toDouble();
    ui->label_result->setText("");

    button->setChecked(true);


}

void MainWindow::on_pushButton_equal_clicked()
{
    double label_number, NUM_SECOND;
    QString new_label;

    NUM_SECOND = ui->label_result->text().toDouble();


    if (ui->pushButton_plus->isChecked()) {
        label_number = NUM_FIRST + NUM_SECOND;

        new_label = QString::number(label_number, 'g', 12);

        ui->label_result->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }

    if (ui->pushButton_minus->isChecked()) {
        label_number = NUM_FIRST - NUM_SECOND;

        new_label = QString::number(label_number, 'g', 12);

        ui->label_result->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }

    if (ui->pushButton_multiply->isChecked()) {
        label_number = NUM_FIRST * NUM_SECOND;

        new_label = QString::number(label_number, 'g', 12);

        ui->label_result->setText(new_label);
        ui->pushButton_multiply->setChecked(false);
    }

    if (ui->pushButton_divide->isChecked()) {
        if (NUM_SECOND == 0) {
            ui->label_result->setText(0);
        }

        label_number = NUM_FIRST / NUM_SECOND;

        new_label = QString::number(label_number, 'g', 12);

        ui->label_result->setText(new_label);
        ui->pushButton_divide->setChecked(false);
    }
}

