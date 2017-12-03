#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Simulador MIPS");
    ui->reg->setText("0");
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
    wbstage = new WB(banco, memwb);;
    this->initInstructionT();
    this->initRegisterT();
    this->initIFID();
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
    ui->IFID_t->insertColumn(0);
    ui->IFID_t->insertColumn(1);
    ui->IFID_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Nome"));
    ui->IFID_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Valor"));
    ui->IFID_t->insertRow(0);
    ui->IFID_t->insertRow(1);
    ui->IFID_t->setItem(0,0, new QTableWidgetItem(QStringLiteral("PC")));
    ui->IFID_t->setItem(1,0, new QTableWidgetItem(QStringLiteral("IR")));
    ui->muxPC->setText(ifstage->get_mux_origin() == 0 ? QStringLiteral("PC + 4") : QStringLiteral("Branch"));

}
void MainWindow::updateIFID(){
    updateInstructionT();
    print_PC();
    ui->muxPC->setText(ifstage->get_mux_origin() == 0 ? QStringLiteral("PC + 4") : QStringLiteral("Branch"));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print_PC(){
    ui->reg->setText(QString::number(ifstage->get_pc()));
}

void MainWindow::print_IFID(int val, string str){
    ui->IFID->setText("\nNPC\n" + QString::number(val) + "\n\nIR\n" + QString::fromStdString(str));
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


    print_IFID(ifid->getNPC(), ifid->getIR());
    updateIFID();
    updateRegisterT();

}
