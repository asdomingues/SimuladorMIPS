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
    QTextBrowser *rReg2;
    QLabel *label_5;
    QLabel *label_7;
    QTextBrowser *wRegA;
    QLabel *label_8;
    QTextBrowser *wRegB;
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
    QLabel *label_21;
    QLabel *label_22;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_2;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QTextBrowser *ALURes_2;
    QLabel *label_23;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
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
        label->setGeometry(QRect(40, 150, 21, 16));
        reg = new QTextBrowser(centralWidget);
        reg->setObjectName(QStringLiteral("reg"));
        reg->setGeometry(QRect(30, 170, 41, 41));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 230, 31, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 550, 101, 31));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(560, 230, 41, 16));
        register_t = new QTableWidget(centralWidget);
        register_t->setObjectName(QStringLiteral("register_t"));
        register_t->setGeometry(QRect(310, 250, 111, 192));
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
        instruction_t->setGeometry(QRect(20, 250, 181, 192));
        instruction_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        instruction_t->setEditTriggers(QAbstractItemView::NoEditTriggers);
        instruction_t->verticalHeader()->setVisible(false);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 230, 161, 20));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(290, 220, 161, 20));
        IDEX_t = new QTableWidget(centralWidget);
        IDEX_t->setObjectName(QStringLiteral("IDEX_t"));
        IDEX_t->setGeometry(QRect(500, 250, 156, 192));
        IDEX_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        IDEX_t->verticalHeader()->setVisible(false);
        IDEX_t->verticalHeader()->setHighlightSections(false);
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(40, 210, 20, 41));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        muxPC = new QTextBrowser(centralWidget);
        muxPC->setObjectName(QStringLiteral("muxPC"));
        muxPC->setGeometry(QRect(10, 70, 101, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 71, 20));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(40, 110, 16, 41));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        IFIDIR = new QTextBrowser(centralWidget);
        IFIDIR->setObjectName(QStringLiteral("IFIDIR"));
        IFIDIR->setGeometry(QRect(170, 170, 131, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 150, 51, 20));
        IFIDPC = new QTextBrowser(centralWidget);
        IFIDPC->setObjectName(QStringLiteral("IFIDPC"));
        IFIDPC->setGeometry(QRect(220, 280, 41, 41));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(220, 260, 31, 20));
        rReg1 = new QTextBrowser(centralWidget);
        rReg1->setObjectName(QStringLiteral("rReg1"));
        rReg1->setGeometry(QRect(260, 360, 31, 31));
        rReg2 = new QTextBrowser(centralWidget);
        rReg2->setObjectName(QStringLiteral("rReg2"));
        rReg2->setGeometry(QRect(260, 410, 31, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 340, 21, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 390, 63, 20));
        wRegA = new QTextBrowser(centralWidget);
        wRegA->setObjectName(QStringLiteral("wRegA"));
        wRegA->setGeometry(QRect(440, 360, 41, 31));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(440, 340, 21, 20));
        wRegB = new QTextBrowser(centralWidget);
        wRegB->setObjectName(QStringLiteral("wRegB"));
        wRegB->setGeometry(QRect(440, 410, 41, 31));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(440, 390, 63, 20));
        IRIDEX = new QTextBrowser(centralWidget);
        IRIDEX->setObjectName(QStringLiteral("IRIDEX"));
        IRIDEX->setGeometry(QRect(510, 170, 131, 31));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(540, 150, 63, 20));
        ALURes = new QTextBrowser(centralWidget);
        ALURes->setObjectName(QStringLiteral("ALURes"));
        ALURes->setGeometry(QRect(680, 430, 51, 31));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(680, 410, 63, 20));
        EXMEM_t = new QTableWidget(centralWidget);
        EXMEM_t->setObjectName(QStringLiteral("EXMEM_t"));
        EXMEM_t->setGeometry(QRect(760, 250, 156, 192));
        EXMEM_t->verticalHeader()->setVisible(false);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(810, 230, 63, 20));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(800, 150, 81, 20));
        IREXMEM = new QTextBrowser(centralWidget);
        IREXMEM->setObjectName(QStringLiteral("IREXMEM"));
        IREXMEM->setGeometry(QRect(770, 170, 131, 31));
        datamemory_t = new QTableWidget(centralWidget);
        datamemory_t->setObjectName(QStringLiteral("datamemory_t"));
        datamemory_t->setGeometry(QRect(960, 250, 111, 192));
        datamemory_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        datamemory_t->setEditTriggers(QAbstractItemView::NoEditTriggers);
        datamemory_t->verticalHeader()->setVisible(false);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(950, 230, 161, 20));
        MEMWB_t = new QTableWidget(centralWidget);
        MEMWB_t->setObjectName(QStringLiteral("MEMWB_t"));
        MEMWB_t->setGeometry(QRect(1120, 250, 141, 173));
        MEMWB_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MEMWB_t->verticalHeader()->setVisible(false);
        MEMWB_t->verticalHeader()->setHighlightSections(false);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(1160, 230, 71, 16));
        IRMEMWB = new QTextBrowser(centralWidget);
        IRMEMWB->setObjectName(QStringLiteral("IRMEMWB"));
        IRMEMWB->setGeometry(QRect(1120, 180, 131, 31));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(1150, 160, 81, 20));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(110, 130, 31, 16));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_21->setFont(font);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(350, 130, 31, 16));
        label_22->setFont(font);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(290, 370, 21, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(290, 420, 21, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(421, 420, 20, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(420, 370, 20, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(220, 30, 20, 111));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setGeometry(QRect(220, 460, 20, 101));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setGeometry(QRect(560, 20, 20, 111));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(centralWidget);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setGeometry(QRect(560, 460, 20, 101));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);
        ALURes_2 = new QTextBrowser(centralWidget);
        ALURes_2->setObjectName(QStringLiteral("ALURes_2"));
        ALURes_2->setGeometry(QRect(680, 310, 51, 61));
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(690, 330, 63, 20));
        line_11 = new QFrame(centralWidget);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setGeometry(QRect(820, 20, 20, 111));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_12 = new QFrame(centralWidget);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setGeometry(QRect(1180, 20, 20, 111));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(centralWidget);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setGeometry(QRect(820, 460, 20, 101));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);
        line_14 = new QFrame(centralWidget);
        line_14->setObjectName(QStringLiteral("line_14"));
        line_14->setGeometry(QRect(1180, 460, 20, 101));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(690, 130, 31, 16));
        label_24->setFont(font);
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(990, 130, 51, 16));
        label_25->setFont(font);
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(1260, 130, 51, 16));
        label_26->setFont(font);
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
        label_11->setText(QApplication::translate("MainWindow", "ID/EX", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Mem\303\263ria de Instru\303\247\303\265es", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Banco de Registradores", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Origem PC", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "IF/ID IR", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "NPC", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "R1", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "R2", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "RA", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "RB", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "ID/EX IR", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "ALUres", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "EX/MEM", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "EX/MEM IR", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Mem\303\263ria de Dados", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "MEM/WB", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "MEM/WB IR", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "IF", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "ID", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "ULA", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "EX", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "MEM", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "WB", nullptr));
        menuArquivo->setTitle(QApplication::translate("MainWindow", "Ar&quivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
