#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etiket.h"
#include <QRandomGenerator>
#include <QList>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {

     ui->setupUi(this);
     ui->pushButton->setIcon(QIcon(":/prefix/puzzle.jpg"));
     ui->pushButton->setIconSize(ui->pushButton->size());


    QList<QString> imagePaths = {
        ":/prefix/0.png",
        ":/prefix/1.png",
        ":/prefix/2.png",
        ":/prefix/3.png",
        ":/prefix/4.png",
        ":/prefix/5.png",
        ":/prefix/6.png",
        ":/prefix/7.png",
        ":/prefix/8.png",
        ":/prefix/9.png",
        ":/prefix/10.png",
        ":/prefix/11.png",
        ":/prefix/12.png",
        ":/prefix/13.png",
        ":/prefix/14.png",
        ":/prefix/15.png",
        ":/prefix/16.png",
        ":/prefix/17.png",
        ":/prefix/18.png",
        ":/prefix/19.png",
        ":/prefix/20.png",
        ":/prefix/21.png",
        ":/prefix/22.png",
        ":/prefix/23.png",
        ":/prefix/24.png",


    };

    std::random_shuffle(imagePaths.begin(), imagePaths.end());

    int X = 50;
    int Y = 50;
    int imageIndex = 0;

    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            Etiket *et = new Etiket(this);
            et->setImagePath(imagePaths[imageIndex]);
            et->setGeometry(X, Y, 100, 100);
            et->show();
            X += 90;
            imageIndex++;
        }
        X = 50;
        Y += 70;
    }
}


MainWindow::~MainWindow() {
    delete ui;
}
