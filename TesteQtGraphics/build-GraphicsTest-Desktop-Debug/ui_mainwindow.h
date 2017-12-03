/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
    QFrame *line;
    QTextBrowser *memoriainstrucao;
    QLabel *label_2;
    QTextBrowser *IFID;
    QFrame *line_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QTextBrowser *BancoReg;
    QFrame *line_3;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line_4;
    QLabel *label_7;
    QLabel *label_8;
    QTextBrowser *IDEX;
    QFrame *line_5;
    QFrame *line_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QTableWidget *register_t;
    QMenuBar *menuBar;
    QMenu *menuArquivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1012, 651);
        actionReiniciar = new QAction(MainWindow);
        actionReiniciar->setObjectName(QStringLiteral("actionReiniciar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 120, 21, 16));
        reg = new QTextBrowser(centralWidget);
        reg->setObjectName(QStringLiteral("reg"));
        reg->setGeometry(QRect(30, 140, 41, 81));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(70, 170, 41, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        memoriainstrucao = new QTextBrowser(centralWidget);
        memoriainstrucao->setObjectName(QStringLiteral("memoriainstrucao"));
        memoriainstrucao->setGeometry(QRect(110, 140, 101, 81));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 110, 141, 31));
        IFID = new QTextBrowser(centralWidget);
        IFID->setObjectName(QStringLiteral("IFID"));
        IFID->setGeometry(QRect(260, 30, 71, 261));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(210, 170, 51, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 70, 61, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(280, 10, 31, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 260, 101, 31));
        BancoReg = new QTextBrowser(centralWidget);
        BancoReg->setObjectName(QStringLiteral("BancoReg"));
        BancoReg->setGeometry(QRect(400, 130, 131, 121));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(330, 140, 71, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(380, 90, 161, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(430, 30, 71, 16));
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(330, 170, 71, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(350, 130, 51, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(350, 160, 51, 16));
        IDEX = new QTextBrowser(centralWidget);
        IDEX->setObjectName(QStringLiteral("IDEX"));
        IDEX->setGeometry(QRect(580, 30, 71, 261));
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(530, 150, 51, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(530, 200, 51, 16));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(520, 140, 61, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(520, 190, 61, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(600, 10, 41, 16));
        register_t = new QTableWidget(centralWidget);
        register_t->setObjectName(QStringLiteral("register_t"));
        register_t->setGeometry(QRect(690, 80, 240, 192));
        register_t->insertColumn(0);
        register_t->insertColumn(1);
        register_t->setHorizontalHeaderItem(0, new QTableWidgetItem("Registrador"));
        register_t->setHorizontalHeaderItem(1, new QTableWidgetItem("Valor"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1012, 28));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionReiniciar->setText(QApplication::translate("MainWindow", "&Reiniciar", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "PC", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Memoria de instrucao", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Est\303\241gio IF", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "IF/ID", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Pr\303\263ximo Ciclo", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Banco de Registradores", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Est\303\241gio ID", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "RdReg1", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "RdReg2", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "RdData1", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "RdData2", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "ID/EX", Q_NULLPTR));
        menuArquivo->setTitle(QApplication::translate("MainWindow", "Ar&quivo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
