#include "mainwindow.h"
#include <QApplication>
#include <QTextBrowser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString pc = "4", npc = "8", ir = "add r1, 100";
    w.clicado = false;
    w.set_PC(pc);
    w.set_MemoriaInstrucao(ir);
    w.set_IFID(npc, ir);
    w.show();


    return a.exec();
}
