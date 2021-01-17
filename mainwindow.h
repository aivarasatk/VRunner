#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_PiltuvelisSkirstymas_clicked();

    void LaunchProcess(QString folderName);

    QString GetExecutableFromCurrentFolder();

private:
    Ui::MainWindow *ui;
    bool enteredFolder;
    QDir* folderTracker;

    void setCorrectFolder(QString folderName);
};

#endif // MAINWINDOW_H
