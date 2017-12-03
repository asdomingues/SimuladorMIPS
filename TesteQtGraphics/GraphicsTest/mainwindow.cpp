#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Simulador MIPS");
    ui->reg->setText("\n\n0");
    ui->memoriainstrucao->setText("\nInstrução\n0");
    ui->IFID->setText("\nNPC\n0\n\nIR\n0");

    memoria_instrucao = new MemoriaInstrucao();
    memoria_instrucao->load_instructions("instrucoes.in");

    ifid = new IFID();
    alu = new Ula();
    exmem = new EXMEM();
    memwb = new MEMWB();
    idexe = new IDEXE();

    banco = new BancoDeRegistradores(NREGISTRADORES);
    ifstage = new IF(memoria_instrucao, ifid, exmem);
    idstage = new ID(banco, ifid, idexe);
    exstage = new EX(alu, idexe, exmem);
    memstage = new Mem(exmem, memwb, "registrador.in");
    wbstage = new WB(banco, memwb);

    initDataMemoryT();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print_PC(int val){
    ui->reg->setText("\n\n" + QString::number(val));
}

void MainWindow::print_MemoriaInstrucao(string str){
    ui->memoriainstrucao->setText("\nInstrução\n" + QString::fromStdString(str));
}

void MainWindow::print_IFID(int val, string str){
    ui->IFID->setText("\nNPC\n" + QString::number(val) + "\n\nIR\n" + QString::fromStdString(str));

}

void MainWindow::initDataMemoryT(){
    ui->data_t->insertColumn(0);
    ui->data_t->insertColumn(1);
    ui->data_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Posição"));
    ui->data_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Conteúdo"));
    ui->data_t->setColumnWidth(0, 60);
    ui->data_t->setColumnWidth(1, 120);
    for(int i = 0; i < TAM/4; i++){
        Memoria m = memstage->get_memoria();
        m.set_address(i*4);
        ui->data_t->insertRow(i);
        ui->data_t->setItem(i, 0, new QTableWidgetItem(QString::number(i*4)));
        ui->data_t->setItem(i, 1, new QTableWidgetItem(QString::number(m.read())));
    }
    QTableWidgetItem *item = ui->data_t->item(0,0);
    item->setBackground(Qt::yellow);
    item = ui->data_t->item(0,1);
    item->setBackground(Qt::yellow);
}
void MainWindow::updateDataMemoryT(){
    int pc = ifstage->get_pc()/4;
    if(pc == 0) pc = 1;
    QTableWidgetItem *item = ui->data_t->item(pc-1,0);
    item->setBackground(Qt::white);
    item = ui->data_t->item(pc-1,1);
    item->setBackground(Qt::white);
    item = ui->data_t->item(pc,0);
    item->setBackground(Qt::yellow);
    item = ui->data_t->item(pc,1);
    item->setBackground(Qt::yellow);
    ui->data_t->scrollToItem(item);
}

void MainWindow::on_pushButton_clicked()
{
    ifstage->write_tick();
    wbstage->write_tick();
    idstage->write_tick();
    exstage->write_tick();
    memstage->write_tick();

    ifstage->read_tick();
    idstage->read_tick();
    exstage->read_tick();
    memstage->read_tick();
    wbstage->read_tick();

    print_PC(ifstage->get_pc());
    print_MemoriaInstrucao(memoria_instrucao->read());
    print_IFID(ifid->getNPC(), ifid->getIR());
    updateDataMemoryT();

}
