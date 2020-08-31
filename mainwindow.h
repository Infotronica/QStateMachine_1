#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStateMachine>
#include <QEventTransition>
#include <QPropertyAnimation>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QStateMachine stateMachine;
    QState s1;
    QState s2;
    QPropertyAnimation propertyAnimation;
    QEventTransition eventTransition1;
    QEventTransition eventTransition2;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
