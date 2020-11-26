#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadmin.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QStateMachine>
#include <QSignalTransition>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   QEasingCurve curve,curve1;
    ui->setupUi(this);

    //playmusic = new QMediaPlayer(this);
    playmusic = new QMediaPlayer;
    connect(playmusic, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    playmusic->setMedia(QUrl::fromLocalFile("/Users/Firas CHKOUNDALI/Documents/projet/welcome.mp3"));
    playmusic->setVolume(50);
    playmusic->play();
    animation = new QPropertyAnimation(ui->identifier,"geometry");
    animationimg = new QPropertyAnimation(ui->widget,"geometry");
    animation->setDuration(1000);
    animationimg->setDuration(1000);
    animation->setStartValue(ui->identifier->geometry());
    animationimg->setStartValue(ui->widget->geometry());
    animation->setEndValue(QRect(300,310,131,31));
    animationimg->setEndValue(QRect(20,110,711,351));
    curve.setType(QEasingCurve::OutBounce);
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    animationimg->setEasingCurve(curve1);
    animation->setLoopCount(3);
    animationimg->setLoopCount(1);
    animation->start();
    animationimg->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_identifier_clicked()
{  cadmin ca(ui->lineEditnomnutilisateur->text(),ui->lineEdit_motdepasse->text());
    /*QString nomuitlisateur=ui->lineEditnomnutilisateur->text();
    QString motdepasse=ui->lineEdit_motdepasse->text();*/

    if(/*nomuitlisateur=="test" and motdepasse=="test"*/ca.authentification()==1)
    {

        playmusic = new QMediaPlayer;
        connect(playmusic, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
        playmusic->setMedia(QUrl::fromLocalFile("/Users/Firas CHKOUNDALI/Documents/projet/music.mp3"));
        playmusic->setVolume(50);
        playmusic->play();
        QMessageBox::information(this,"identifier","nom d'utilisateur et mot de passe sont correct");
        //hide();
        Menu = new menu(this);
        Menu->show();
    }
    else if(ca.authentification()<1)
    {
        playmusic = new QMediaPlayer;
        connect(playmusic, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
        playmusic->setMedia(QUrl::fromLocalFile("/Users/Firas CHKOUNDALI/Documents/projet/music1.mp3"));
        playmusic->setVolume(50);
        playmusic->play();
        QMessageBox::information(this,"identifier","nom d'utilisateur et mot de passe ne sont pas correct");
    }
}
