#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->reg->setText("\n\n0");
    ui->memoriainstrucao->setText("\nInstrução\n0");
    ui->IFID->setText("\nNPC\n0\n\nIR\n0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_PC(QString val){
    ui->reg->setText("\n\n" + val);
}

void MainWindow::set_MemoriaInstrucao(QString ir){
    ui->memoriainstrucao->setText("\nInstrução\n" + ir);
}

void MainWindow::set_IFID(QString npc, QString ir){
    ui->IFID->setText("\nNPC\n" + npc + "\n\nIR\n" + ir);
}

void MainWindow::on_pushButton_clicked()
{
    clicado = true;
}
