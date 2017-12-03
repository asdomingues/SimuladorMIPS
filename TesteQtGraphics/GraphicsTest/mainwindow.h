#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "include/MemoriaInstrucao.hpp"
#include "include/BancoDeRegistradores.hpp"
#include "include/IFID.hpp"
#include "include/IDEXE.hpp"
#include "include/EXMEM.hpp"
#include "include/MEMWB.hpp"
#include "include/IF.hpp"
#include "include/ID.hpp"
#include "include/EX.hpp"
#include "include/WB.hpp"
#include "include/Memoria.hpp"
#include "include/Mem.hpp"
#include "include/Ula.hpp"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void initDataMemoryT();
    void updateDataMemoryT();
    void print_PC(int val);
    void print_MemoriaInstrucao(string str);
    void print_IFID(int val, string str);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MemoriaInstrucao *memoria_instrucao;
    IFID *ifid;
    Ula *alu;
    EXMEM *exmem;
    MEMWB *memwb;
    IDEXE *idexe;
    BancoDeRegistradores *banco;

    //criar todos os estagios
    IF *ifstage;
    ID *idstage;
    EX *exstage;
    Mem *memstage;
    WB *wbstage;
};

#endif // MAINWINDOW_H