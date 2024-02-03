#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void digits();

    void on_pushButton_dot_clicked();

    void operations();

    void on_pushButton_AC_clicked();

    void on_pushButton_equal_clicked();

    void math_operations();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
