#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow),
      cpuWidget(this), memoryWidget{this}
{
    ui->setupUi(this);
    ui -> centralWidget -> setLayout(new QHBoxLayout());
    ui -> centralWidget-> layout()->addWidget(&cpuWidget);
    ui->centralWidget->layout()->addWidget(& memoryWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

