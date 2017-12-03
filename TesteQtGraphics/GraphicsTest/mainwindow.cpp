#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Simulador MIPS");
    ui->reg->setText("0");


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
    wbstage = new WB(banco, memwb);;
    this->initInstructionT();
    this->initRegisterT();
    this->initIFID();
    this->initIDEXT();
}
void MainWindow::initInstructionT(){
    ui->instruction_t->insertColumn(0);
    ui->instruction_t->insertColumn(1);
    ui->instruction_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Posição"));
    ui->instruction_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Conteúdo"));
    ui->instruction_t->setColumnWidth(0, 60);
    ui->instruction_t->setColumnWidth(1, 120);
    for(int i = 0; i < TAM/4; i++){
        /*TODO
            Mudar background do item sendo executado.
            Scroll to item.
        */
        ui->instruction_t->insertRow(i);
        memoria_instrucao->set_address(i*4);
        ui->instruction_t->setItem(i,1, new QTableWidgetItem(QString::fromStdString(memoria_instrucao->read())));
        ui->instruction_t->setItem(i,0, new QTableWidgetItem (QString::number(i*4)));
    }
    QTableWidgetItem *item = ui->instruction_t->item(0,0);
    item->setBackground(Qt::yellow);
    item = ui->instruction_t->item(0,1);
    item->setBackground(Qt::yellow);
}
void MainWindow::updateInstructionT(){
    int pc = ifstage->get_pc()/4;
    QTableWidgetItem *item = ui->instruction_t->item(pc-1,0);
    item->setBackground(Qt::white);
    item = ui->instruction_t->item(pc-1,1);
    item->setBackground(Qt::white);
    item = ui->instruction_t->item(pc,0);
    item->setBackground(Qt::yellow);
    item = ui->instruction_t->item(pc,1);
    item->setBackground(Qt::yellow);
    ui->instruction_t->scrollToItem(item);
}
void MainWindow::initRegisterT(){
    ui->register_t->insertColumn(0);
    ui->register_t->insertColumn(1);
    ui->register_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Registrador"));
    ui->register_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Valor"));
    for(int i = 0; i < NREGISTRADORES; i++){
        ui->register_t->insertRow(i);
        ui->register_t->setItem(i,0, new QTableWidgetItem(QString::fromStdString(banco->get_name(i))));
        ui->register_t->setItem(i,1, new QTableWidgetItem (QString::number(banco->read_reg1(i))));
    }
}
void MainWindow::updateRegisterT(){
    QTableWidgetItem *item;
    for(int i = 0; i < NREGISTRADORES; i++){
       item = ui->register_t->item(i,1);
       //cout <<"i = " << item << "      " << item->text().toStdString() << endl;
       item->setText(QString::number(banco->read_reg1(i)));
       //ui->register_t->setItem(i,1, new QTableWidgetItem (new QString::number(banco->read_reg1(i))));
    }
}

void MainWindow::initIFID(){
    ui->IFIDIR->setText(QString::fromStdString(ifid->getIR()));
    ui->IFIDPC->setText(QString::number(ifid->getNPC()));
    ui->muxPC->setText(ifstage->get_mux_origin() == 0 ? QStringLiteral("PC + 4") : QStringLiteral("Branch"));

}
void MainWindow::updateIFID(){
    updateInstructionT();
    print_PC();
    ui->IFIDIR->setText(QString::fromStdString(ifid->getIR()));
    ui->IFIDPC->setText(QString::number(ifid->getNPC()));
    ui->muxPC->setText(ifstage->get_mux_origin() == 0 ? QStringLiteral("PC + 4") : QStringLiteral("Branch"));
}
void MainWindow::initIDEXT(){
    ui->IDEX_t->insertColumn(0);
    ui->IDEX_t->insertColumn(1);
    ui->IDEX_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Nome"));
    ui->IDEX_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Valor"));
    ui->IDEX_t->insertRow(0);
    ui->IDEX_t->insertRow(1);
    ui->IDEX_t->insertRow(2);
    ui->IDEX_t->insertRow(3);
    ui->IDEX_t->insertRow(4);
    ui->IDEX_t->insertRow(5);
    ui->IDEX_t->insertRow(6);
    ui->IDEX_t->insertRow(7);
    ui->IDEX_t->insertRow(8);
    ui->IDEX_t->insertRow(9);
    ui->IDEX_t->insertRow(10);
    ui->IDEX_t->insertRow(11);
    ui->IDEX_t->setItem(0,0, new QTableWidgetItem(QStringLiteral("RT")));
    ui->IDEX_t->setItem(1,0, new QTableWidgetItem(QStringLiteral("RD")));
    ui->IDEX_t->setItem(2,0, new QTableWidgetItem(QStringLiteral("RA")));
    ui->IDEX_t->setItem(3,0, new QTableWidgetItem(QStringLiteral("RB")));
    ui->IDEX_t->setItem(4,0, new QTableWidgetItem(QStringLiteral("regDest")));
    ui->IDEX_t->setItem(5,0, new QTableWidgetItem(QStringLiteral("regWrite")));
    ui->IDEX_t->setItem(6,0, new QTableWidgetItem(QStringLiteral("aluSrc")));
    ui->IDEX_t->setItem(7,0, new QTableWidgetItem(QStringLiteral("branch")));
    ui->IDEX_t->setItem(8,0, new QTableWidgetItem(QStringLiteral("memRead")));
    ui->IDEX_t->setItem(9,0, new QTableWidgetItem(QStringLiteral("memWrite")));
    ui->IDEX_t->setItem(10,0, new QTableWidgetItem(QStringLiteral("writeToReg")));
    ui->IDEX_t->setItem(11,0, new QTableWidgetItem(QStringLiteral("aluOP")));
    ui->IDEX_t->setItem(0,1, new QTableWidgetItem(QString::number(idexe->getRT())));
    ui->IDEX_t->setItem(1,1, new QTableWidgetItem(QString::number(idexe->getRD())));
    ui->IDEX_t->setItem(2,1, new QTableWidgetItem(QString::number(idexe->getA())));
    ui->IDEX_t->setItem(3,1, new QTableWidgetItem(QString::number(idexe->getB())));
    ui->IDEX_t->setItem(4,1, new QTableWidgetItem(QString::number(idexe->getRegDest())));
    ui->IDEX_t->setItem(5,1, new QTableWidgetItem(QString::number(idexe->getRegWrite())));
    ui->IDEX_t->setItem(6,1, new QTableWidgetItem(QString::number(idexe->getAluSrc()))); //adicionar semantica
    ui->IDEX_t->setItem(7,1, new QTableWidgetItem(QString::number(idexe->getBranch())));
    ui->IDEX_t->setItem(8,1, new QTableWidgetItem(QString::number(idexe->getMemRead())));
    ui->IDEX_t->setItem(9,1, new QTableWidgetItem(QString::number(idexe->getMemWrite())));
    ui->IDEX_t->setItem(10,1, new QTableWidgetItem(QString::number(idexe->getMemToReg())));
    ui->IDEX_t->setItem(11,1, new QTableWidgetItem(QString::fromStdString(idexe->getAluOP())));
    ui->IDEX_t->setColumnWidth(0, 85);
    ui->IDEX_t->setColumnWidth(1, 53);
    updateIDEXT();
}
void MainWindow::updateIDEXT(){
    QTableWidgetItem *item;
    item = ui->IDEX_t->item(0,1);
    item->setText(QString::number(idexe->getRT()));
    item = ui->IDEX_t->item(1,1);
    item->setText(QString::number(idexe->getRD()));
    item = ui->IDEX_t->item(2,1);
    item->setText(QString::number(idexe->getA()));
    item = ui->IDEX_t->item(3,1);
    item->setText(QString::number(idexe->getB()));
    item = ui->IDEX_t->item(4,1);
    item->setText(QString::number(idexe->getRegDest()));
    item = ui->IDEX_t->item(5,1);
    item->setText(QString::number(idexe->getRegWrite()));
    item = ui->IDEX_t->item(6,1);
    item->setText(QString::number(idexe->getAluSrc()));
    item = ui->IDEX_t->item(7,1);
    item->setText(QString::number(idexe->getBranch()));
    item = ui->IDEX_t->item(8,1);
    item->setText(QString::number(idexe->getMemRead()));
    item = ui->IDEX_t->item(9,1);
    item->setText(QString::number(idexe->getMemWrite()));
    item = ui->IDEX_t->item(10,1);
    item->setText(QString::number(idexe->getMemToReg()));
    item = ui->IDEX_t->item(11,1);
    item->setText(QString::fromStdString(idexe->getAluOP()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print_PC(){
    ui->reg->setText(QString::number(ifstage->get_pc()));
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

    updateIFID();
    updateRegisterT();
    updateIDEXT();

}
