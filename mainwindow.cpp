#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),enteredFolder(false),folderTracker(new QDir())
{
    ui->setupUi(this);
    setWindowTitle("Valentis Runner");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    LaunchProcess("Piltuvelis");
}

void MainWindow::on_pushButton_2_clicked()
{
    LaunchProcess("GenCheck");
}

void MainWindow::on_pushButton_3_clicked()
{
    LaunchProcess("ProduktoGamyba");
}

void MainWindow::on_pushButton_4_clicked()
{
    LaunchProcess("DiffGenerator2");
}

void MainWindow::on_PiltuvelisSkirstymas_clicked()
{
    LaunchProcess("PiltuvelisSkirstymas");
}

void MainWindow::LaunchProcess(QString folderName)
{
    setCorrectFolder(folderName);

    auto executable = GetExecutableFromCurrentFolder();

    (new QProcess())->start(executable);
}

void MainWindow::setCorrectFolder(QString folderName)
{
    if(!enteredFolder)
    {
        enteredFolder = true;
        folderTracker->setCurrent(QDir::currentPath() + "/" + folderName);
        folderTracker->cdUp();
    }
    else
    {
        folderTracker->setCurrent(folderTracker->path() + "/" + folderName);
    }
}

QString MainWindow::GetExecutableFromCurrentFolder()
{
    QDir directory(folderTracker->currentPath());
    QStringList executables = directory.entryList(QStringList() << "*.exe",QDir::Files);
    return executables.first();
}
