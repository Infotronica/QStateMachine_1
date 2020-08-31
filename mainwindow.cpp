#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // State 1. assigning properties for some objects when the current state is State 1
    s1.assignProperty(ui->label, "text", "Current State: 1");
    s1.assignProperty(ui->labelPixmap, "geometry", QRect(50,50,250,250));

    // State 2. assigning properties for some objects when the current state is State 2
    s2.assignProperty(ui->label, "text", "Current State: 2");
    s2.assignProperty(ui->labelPixmap, "geometry", QRect(500,250,250,250));

    /*
     * the animation for the transition is used for see the labelPixmap object
     * moving in the space
     */
    propertyAnimation.setTargetObject(ui->labelPixmap);
    propertyAnimation.setPropertyName("geometry");

    /*
     * Adding Event Transitions
     * is for assign event for the pushButton object
     */

    eventTransition1.setEventSource(ui->pushButton); // object is pushButton
    eventTransition1.setEventType(QEvent::MouseButtonPress); // event
    eventTransition1.setTargetState(&s2); // the target state
    eventTransition1.addAnimation(&propertyAnimation); // the animation
    s1.addTransition(&eventTransition1); // assign the event transition to State 1

    eventTransition2.setEventSource(ui->pushButton); // object is pushButton
    eventTransition2.setEventType(QEvent::MouseButtonPress); // event
    eventTransition2.setTargetState(&s1); // the target state
    eventTransition2.addAnimation(&propertyAnimation); // the animation
    s2.addTransition(&eventTransition2); // assign the event transition to State 1

    // State machine begins
    stateMachine.addState(&s1); // add State 1
    stateMachine.addState(&s2); // add State 2
    stateMachine.setInitialState(&s1); // assign the initial State
    stateMachine.start(); // start machine
}

MainWindow::~MainWindow()
{
    stateMachine.stop(); // stop machine
    delete ui;
}
