#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStandardItemModel>
#include "person_.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStandardItemModel model;
    
private slots:
    void on_centralWidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
