#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QLayout>
#include <QWidget>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget *central = new QWidget();
    QVBoxLayout *playLayout = new QVBoxLayout(this);
    playButton = new QPushButton(this);
    playButton->setText(QString("Play Music"));
    pauseButton = new QPushButton;
    pauseButton->setText(QString("Pause"));
    playLayout->addWidget(playButton);
    playLayout->addWidget(pauseButton);
    central->setLayout(playLayout);
    this->setCentralWidget(central);

    QMediaPlayer *playMusic = new QMediaPlayer;
    playMusic->setMedia(QUrl::fromLocalFile("/home/yushan/Music/回音哥 - 芊芊.mp3"));
    connect(playButton,SIGNAL(clicked()), playMusic,SLOT(play()));
    connect(pauseButton,SIGNAL(clicked()),playMusic,SLOT(pause()));
}

MainWindow::~MainWindow()
{
    delete playButton;
    delete pauseButton;
}
