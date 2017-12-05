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
    this->initIDEX();
    this->initEXMEM();
    this->initMEMWB();
    this->initDataMemoryT();
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


void MainWindow::initDataMemoryT(){
    ui->datamemory_t->insertColumn(0);
    ui->datamemory_t->insertColumn(1);
    ui->datamemory_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Posição"));
    ui->datamemory_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Valor"));
    ui->datamemory_t->setColumnWidth(0, 60);
    ui->datamemory_t->setColumnWidth(1, 120);
    for(int i = 0; i < TAM/4; i++){
        ui->datamemory_t->insertRow(i);
        ui->datamemory_t->setItem(i,1, new QTableWidgetItem(QString::fromStdString(to_string(memstage->get_memory_data(i*4)))));
        ui->datamemory_t->setItem(i,0, new QTableWidgetItem (QString::number(i*4)));
    }
}

void MainWindow::updateDataMemoryT(){
    QTableWidgetItem *item;
    for(int i = 0; i < TAM/4; i++){
        item = ui->datamemory_t->item(i,1);
        item->setText(QString::fromStdString(to_string(memstage->get_memory_data(i*4))));
    }
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
    ui->register_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Reg"));
    ui->register_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Valor"));
    ui->register_t->setColumnWidth(0, 40);
    ui->register_t->setColumnWidth(1, 49);
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

void MainWindow::initIDEX(){
    initIDEXT();
    ui->rReg1->setText(QString::number(idstage->get_reg1()));
    ui->rReg2->setText(QString::number(idstage->get_reg2()));
    ui->wRegA->setText(QString::number(idexe->getA()));
    ui->wRegB->setText(QString::number(idexe->getB()));
    ui->IRIDEX->setText(QString::fromStdString(idexe->getIR()));
}

void MainWindow::updateIDEX(){
    updateIDEXT();
    ui->rReg1->setText(QString::number(idstage->get_reg1()));
    ui->rReg2->setText(QString::number(idstage->get_reg2()));
    ui->wRegA->setText(QString::number(idexe->getA()));
    ui->wRegB->setText(QString::number(idexe->getB()));
    ui->IRIDEX->setText(QString::fromStdString(idexe->getIR()));
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
    ui->IDEX_t->insertRow(12);
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
    ui->IDEX_t->setItem(11,0, new QTableWidgetItem(QStringLiteral("imm")));
    ui->IDEX_t->setItem(12,0, new QTableWidgetItem(QStringLiteral("aluOP")));
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
    ui->IDEX_t->setItem(11,1, new QTableWidgetItem(QString::number(idexe->getImm())));
    ui->IDEX_t->setItem(12,1, new QTableWidgetItem(QString::fromStdString(idexe->getAluOP())));
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
    item->setText(QString::number(idexe->getImm()));
    item = ui->IDEX_t->item(12,1);
    item->setText(QString::fromStdString(idexe->getAluOP()));
}

void MainWindow::initEXMEM(){
    ui->ALURes->setText(QString::number(exmem->get_alu_out()));
    ui->IREXMEM->setText(QString::fromStdString(exmem->get_ir()));
    initEXMEMT();
}
void MainWindow::updateEXMEM(){
    ui->ALURes->setText(QString::number(exmem->get_alu_out()));
    ui->IREXMEM->setText(QString::fromStdString(exmem->get_ir()));
    updateEXMEMT();
}

void MainWindow::initEXMEMT(){
    ui->EXMEM_t->insertColumn(0);
    ui->EXMEM_t->insertColumn(1);
    ui->EXMEM_t->insertRow(0);
    ui->EXMEM_t->insertRow(1);
    ui->EXMEM_t->insertRow(2);
    ui->EXMEM_t->insertRow(3);
    ui->EXMEM_t->insertRow(4);
    ui->EXMEM_t->insertRow(5);
    ui->EXMEM_t->insertRow(6);
    ui->EXMEM_t->insertRow(7);
    ui->EXMEM_t->insertRow(8);
    ui->EXMEM_t->insertRow(9);
    ui->EXMEM_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Nome"));
    ui->EXMEM_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Valor"));
    ui->EXMEM_t->setItem(0,0, new QTableWidgetItem(QStringLiteral("branchAddr")));
    ui->EXMEM_t->setItem(1,0, new QTableWidgetItem(QStringLiteral("zero")));
    ui->EXMEM_t->setItem(2,0, new QTableWidgetItem(QStringLiteral("aluOUT")));
    ui->EXMEM_t->setItem(3,0, new QTableWidgetItem(QStringLiteral("aluIN2")));
    ui->EXMEM_t->setItem(4,0, new QTableWidgetItem(QStringLiteral("wrRegAddr")));
    ui->EXMEM_t->setItem(5,0, new QTableWidgetItem(QStringLiteral("regWrite")));
    ui->EXMEM_t->setItem(6,0, new QTableWidgetItem(QStringLiteral("branch")));
    ui->EXMEM_t->setItem(7,0, new QTableWidgetItem(QStringLiteral("memRead")));
    ui->EXMEM_t->setItem(8,0, new QTableWidgetItem(QStringLiteral("memWrite")));
    ui->EXMEM_t->setItem(9,0, new QTableWidgetItem(QStringLiteral("memToReg")));
    ui->EXMEM_t->setItem(0,1, new QTableWidgetItem(QString::number(exmem->get_branch_address())));
    ui->EXMEM_t->setItem(1,1, new QTableWidgetItem(QString::number(exmem->get_alu_zero())));
    ui->EXMEM_t->setItem(2,1, new QTableWidgetItem(QString::number(exmem->get_alu_out())));
    ui->EXMEM_t->setItem(3,1, new QTableWidgetItem(QString::number(exmem->get_alu_in2())));
    ui->EXMEM_t->setItem(4,1, new QTableWidgetItem(QString::number(exmem->get_write_reg_address())));
    ui->EXMEM_t->setItem(5,1, new QTableWidgetItem(QString::number(exmem->get_reg_write())));
    ui->EXMEM_t->setItem(6,1, new QTableWidgetItem(QString::number(exmem->get_branch())));
    ui->EXMEM_t->setItem(7,1, new QTableWidgetItem(QString::number(exmem->get_mem_read())));
    ui->EXMEM_t->setItem(8,1, new QTableWidgetItem(QString::number(exmem->get_mem_write())));
    ui->EXMEM_t->setItem(9,1, new QTableWidgetItem(QString::number(exmem->get_mem_to_reg())));
}

void MainWindow::updateEXMEMT(){
    QTableWidgetItem *item;
    item = ui->EXMEM_t->item(0,1);
    item->setText(QString::number(exmem->get_branch_address()));
    item = ui->EXMEM_t->item(1,1);
    item->setText(QString::number(exmem->get_alu_zero()));
    item = ui->EXMEM_t->item(2,1);
    item->setText(QString::number(exmem->get_alu_out()));
    item = ui->EXMEM_t->item(3,1);
    item->setText(QString::number(exmem->get_alu_in2()));
    item = ui->EXMEM_t->item(4,1);
    item->setText(QString::number(exmem->get_write_reg_address()));
    item = ui->EXMEM_t->item(5,1);
    item->setText(QString::number(exmem->get_reg_write()));
    item = ui->EXMEM_t->item(6,1);
    item->setText(QString::number(exmem->get_branch()));
    item = ui->EXMEM_t->item(7,1);
    item->setText(QString::number(exmem->get_mem_read()));
    item = ui->EXMEM_t->item(8,1);
    item->setText(QString::number(exmem->get_mem_write()));
    item = ui->EXMEM_t->item(9,1);
    item->setText(QString::number(exmem->get_mem_to_reg()));
}

void MainWindow::initMEMWB(){
    ui->IRMEMWB->setText(QString::fromStdString(memwb->getir()));
    ui->MEMWB_t->insertColumn(0);
    ui->MEMWB_t->insertColumn(1);
    ui->MEMWB_t->insertRow(0);
    ui->MEMWB_t->insertRow(1);
    ui->MEMWB_t->insertRow(2);
    ui->MEMWB_t->insertRow(3);
    ui->MEMWB_t->insertRow(4);
    ui->MEMWB_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Nome"));
    ui->MEMWB_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Valor"));
    ui->MEMWB_t->setItem(0,0, new QTableWidgetItem(QStringLiteral("aluOUT")));
    ui->MEMWB_t->setItem(1,0, new QTableWidgetItem(QStringLiteral("loadData")));
    ui->MEMWB_t->setItem(2,0, new QTableWidgetItem(QStringLiteral("regWrite")));
    ui->MEMWB_t->setItem(3,0, new QTableWidgetItem(QStringLiteral("memToReg")));
    ui->MEMWB_t->setItem(4,0, new QTableWidgetItem(QStringLiteral("wrRegAddr")));
    ui->MEMWB_t->setItem(0,1, new QTableWidgetItem(QString::number(memwb->getALUOut())));
    ui->MEMWB_t->setItem(1,1, new QTableWidgetItem(QString::number(memwb->getLMemoryData())));
    ui->MEMWB_t->setItem(2,1, new QTableWidgetItem(QString::number(memwb->getRegWrite())));
    ui->MEMWB_t->setItem(3,1, new QTableWidgetItem(QString::number(memwb->getMemtoReg())));
    ui->MEMWB_t->setItem(4,1, new QTableWidgetItem(QString::number(memwb->get_reg_address())));


}
void MainWindow::updateMEMWB(){
    QTableWidgetItem *item;
    ui->IRMEMWB->setText(QString::fromStdString(memwb->getir()));
    item = ui->MEMWB_t->item(0,1);
    item->setText(QString::number(memwb->getALUOut()));
    item = ui->MEMWB_t->item(1,1);
    item->setText(QString::number(memwb->getLMemoryData()));
    item = ui->MEMWB_t->item(2,1);
    item->setText(QString::number(memwb->getRegWrite()));
    item = ui->MEMWB_t->item(3,1);
    item->setText(QString::number(memwb->getMemtoReg()));
    item = ui->MEMWB_t->item(4,1);
    item->setText(QString::number(memwb->get_reg_address()));
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
    updateIDEX();
    updateEXMEM();
    updateMEMWB();
    updateDataMemoryT();
}
