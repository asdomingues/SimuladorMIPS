/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReiniciar;
    QWidget *centralWidget;
    QLabel *label;
    QTextBrowser *reg;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *label_11;
    QTableWidget *register_t;
    QTableWidget *instruction_t;
    QLabel *label_12;
    QLabel *label_13;
    QTableWidget *IDEX_t;
    QFrame *line_7;
    QTextBrowser *muxPC;
    QLabel *label_2;
    QFrame *line;
    QTextBrowser *IFIDIR;
    QLabel *label_3;
    QTextBrowser *IFIDPC;
    QLabel *label_15;
    QTextBrowser *rReg1;
    QFrame *line_3;
    QFrame *line_4;
    QTextBrowser *rReg2;
    QLabel *label_5;
    QLabel *label_7;
    QTextBrowser *wRegA;
    QFrame *line_5;
    QLabel *label_8;
    QTextBrowser *wRegB;
    QFrame *line_6;
    QLabel *label_9;
    QTextBrowser *IRIDEX;
    QLabel *label_10;
    QTextBrowser *ALURes;
    QLabel *label_14;
    QTableWidget *EXMEM_t;
    QLabel *label_16;
    QLabel *label_17;
    QTextBrowser *IREXMEM;
    QTableWidget *datamemory_t;
    QLabel *label_18;
    QTableWidget *MEMWB_t;
    QLabel *label_19;
    QTextBrowser *IRMEMWB;
    QLabel *label_20;
    QMenuBar *menuBar;
    QMenu *menuArquivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 651);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionReiniciar = new QAction(MainWindow);
        actionReiniciar->setObjectName(QStringLiteral("actionReiniciar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 180, 21, 16));
        reg = new QTextBrowser(centralWidget);
        reg->setObjectName(QStringLiteral("reg"));
        reg->setGeometry(QRect(50, 170, 41, 41));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 70, 31, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 550, 101, 31));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(550, 100, 71, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1100, 250, 41, 16));
        register_t = new QTableWidget(centralWidget);
        register_t->setObjectName(QStringLiteral("register_t"));
        register_t->setGeometry(QRect(540, 260, 108, 181));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(register_t->sizePolicy().hasHeightForWidth());
        register_t->setSizePolicy(sizePolicy1);
        register_t->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        register_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        register_t->setEditTriggers(QAbstractItemView::NoEditTriggers);
        register_t->verticalHeader()->setVisible(false);
        register_t->verticalHeader()->setHighlightSections(false);
        instruction_t = new QTableWidget(centralWidget);
        instruction_t->setObjectName(QStringLiteral("instruction_t"));
        instruction_t->setGeometry(QRect(60, 270, 198, 192));
        instruction_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        instruction_t->setEditTriggers(QAbstractItemView::NoEditTriggers);
        instruction_t->verticalHeader()->setVisible(false);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(90, 250, 161, 20));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(570, 230, 161, 20));
        IDEX_t = new QTableWidget(centralWidget);
        IDEX_t->setObjectName(QStringLiteral("IDEX_t"));
        IDEX_t->setGeometry(QRect(1040, 270, 156, 192));
        IDEX_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        IDEX_t->verticalHeader()->setVisible(false);
        IDEX_t->verticalHeader()->setHighlightSections(false);
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(70, 210, 3, 61));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        muxPC = new QTextBrowser(centralWidget);
        muxPC->setObjectName(QStringLiteral("muxPC"));
        muxPC->setGeometry(QRect(20, 70, 101, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 50, 71, 20));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(70, 110, 3, 61));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        IFIDIR = new QTextBrowser(centralWidget);
        IFIDIR->setObjectName(QStringLiteral("IFIDIR"));
        IFIDIR->setGeometry(QRect(160, 120, 120, 41));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 130, 63, 20));
        IFIDPC = new QTextBrowser(centralWidget);
        IFIDPC->setObjectName(QStringLiteral("IFIDPC"));
        IFIDPC->setGeometry(QRect(160, 170, 41, 41));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(130, 180, 63, 20));
        rReg1 = new QTextBrowser(centralWidget);
        rReg1->setObjectName(QStringLiteral("rReg1"));
        rReg1->setGeometry(QRect(460, 280, 71, 41));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(450, 320, 91, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(450, 410, 91, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        rReg2 = new QTextBrowser(centralWidget);
        rReg2->setObjectName(QStringLiteral("rReg2"));
        rReg2->setGeometry(QRect(460, 370, 71, 41));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(460, 250, 63, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(460, 340, 63, 20));
        wRegA = new QTextBrowser(centralWidget);
        wRegA->setObjectName(QStringLiteral("wRegA"));
        wRegA->setGeometry(QRect(660, 280, 71, 41));
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(650, 320, 91, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(680, 260, 63, 20));
        wRegB = new QTextBrowser(centralWidget);
        wRegB->setObjectName(QStringLiteral("wRegB"));
        wRegB->setGeometry(QRect(670, 360, 71, 41));
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(650, 400, 91, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(680, 340, 63, 20));
        IRIDEX = new QTextBrowser(centralWidget);
        IRIDEX->setObjectName(QStringLiteral("IRIDEX"));
        IRIDEX->setGeometry(QRect(520, 170, 181, 41));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(570, 130, 63, 20));
        ALURes = new QTextBrowser(centralWidget);
        ALURes->setObjectName(QStringLiteral("ALURes"));
        ALURes->setGeometry(QRect(810, 520, 71, 41));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(810, 500, 63, 20));
        EXMEM_t = new QTableWidget(centralWidget);
        EXMEM_t->setObjectName(QStringLiteral("EXMEM_t"));
        EXMEM_t->setGeometry(QRect(770, 280, 256, 192));
        EXMEM_t->verticalHeader()->setVisible(false);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(860, 260, 63, 20));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(870, 180, 81, 20));
        IREXMEM = new QTextBrowser(centralWidget);
        IREXMEM->setObjectName(QStringLiteral("IREXMEM"));
        IREXMEM->setGeometry(QRect(830, 210, 171, 41));
        datamemory_t = new QTableWidget(centralWidget);
        datamemory_t->setObjectName(QStringLiteral("datamemory_t"));
        datamemory_t->setGeometry(QRect(280, 260, 151, 192));
        datamemory_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        datamemory_t->setEditTriggers(QAbstractItemView::NoEditTriggers);
        datamemory_t->verticalHeader()->setVisible(false);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(290, 240, 161, 20));
        MEMWB_t = new QTableWidget(centralWidget);
        MEMWB_t->setObjectName(QStringLiteral("MEMWB_t"));
        MEMWB_t->setGeometry(QRect(1030, 50, 156, 192));
        MEMWB_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MEMWB_t->verticalHeader()->setVisible(false);
        MEMWB_t->verticalHeader()->setHighlightSections(false);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(1070, 30, 71, 16));
        IRMEMWB = new QTextBrowser(centralWidget);
        IRMEMWB->setObjectName(QStringLiteral("IRMEMWB"));
        IRMEMWB->setGeometry(QRect(840, 80, 171, 41));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(880, 60, 81, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 22));
        menuArquivo = new QMenu(menuBar);
        menuArquivo->setObjectName(QStringLiteral("menuArquivo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArquivo->menuAction());
        menuArquivo->addAction(actionReiniciar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionReiniciar->setText(QApplication::translate("MainWindow", "&Reiniciar", nullptr));
        label->setText(QApplication::translate("MainWindow", "PC", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "IF/ID", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Pr\303\263ximo Ciclo", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Est\303\241gio ID", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "ID/EX", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Mem\303\263ria de Instru\303\247\303\265es", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Banco de Registradores", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Origem PC", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "IR", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "NPC", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "addrRS", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "addrRT", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "RA", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "RB", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "ID/EX IR", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "ALUres", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "EX/MEM", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "EX/MEM IR", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Mem\303\263ria de Dados", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "MEM/WB", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "MEM/WB IR", nullptr));
        menuArquivo->setTitle(QApplication::translate("MainWindow", "Ar&quivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
