#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool clicado = false;
    explicit MainWindow(QWidget *parent = 0);
    void set_PC(QString val);
    void set_MemoriaInstrucao(QString ir);
    void set_IFID(QString npc, QString ir);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
