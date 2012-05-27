/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 27. May 13:36:56 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInicio;
    QAction *actionSalir;
    QWidget *centralWidget;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *btnCancelar;
    QLabel *lbCedula;
    QLabel *lbApellido;
    QLabel *lbtipo;
    QRadioButton *rbProf;
    QLineEdit *leCedula;
    QLineEdit *leApellido;
    QLineEdit *leNombre;
    QPushButton *btnAceptar;
    QRadioButton *rbEstu;
    QLabel *lbNombre;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionInicio = new QAction(MainWindow);
        actionInicio->setObjectName(QString::fromUtf8("actionInicio"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(150, 30, 20, 551));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(2);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::VLine);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 31));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 71, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 140, 61, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 160, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 190, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 220, 75, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 250, 75, 23));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 280, 161, 16));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 120, 161, 16));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(2);
        line_3->setFrameShape(QFrame::HLine);
        btnCancelar = new QPushButton(centralWidget);
        btnCancelar->setObjectName(QString::fromUtf8("btnCancelar"));
        btnCancelar->setGeometry(QRect(500, 280, 75, 23));
        lbCedula = new QLabel(centralWidget);
        lbCedula->setObjectName(QString::fromUtf8("lbCedula"));
        lbCedula->setGeometry(QRect(280, 190, 56, 21));
        lbApellido = new QLabel(centralWidget);
        lbApellido->setObjectName(QString::fromUtf8("lbApellido"));
        lbApellido->setGeometry(QRect(480, 140, 56, 21));
        lbtipo = new QLabel(centralWidget);
        lbtipo->setObjectName(QString::fromUtf8("lbtipo"));
        lbtipo->setGeometry(QRect(480, 190, 56, 21));
        rbProf = new QRadioButton(centralWidget);
        rbProf->setObjectName(QString::fromUtf8("rbProf"));
        rbProf->setGeometry(QRect(540, 190, 71, 17));
        leCedula = new QLineEdit(centralWidget);
        leCedula->setObjectName(QString::fromUtf8("leCedula"));
        leCedula->setGeometry(QRect(330, 190, 131, 20));
        leApellido = new QLineEdit(centralWidget);
        leApellido->setObjectName(QString::fromUtf8("leApellido"));
        leApellido->setGeometry(QRect(540, 140, 161, 20));
        leNombre = new QLineEdit(centralWidget);
        leNombre->setObjectName(QString::fromUtf8("leNombre"));
        leNombre->setGeometry(QRect(330, 140, 131, 20));
        btnAceptar = new QPushButton(centralWidget);
        btnAceptar->setObjectName(QString::fromUtf8("btnAceptar"));
        btnAceptar->setGeometry(QRect(400, 280, 75, 23));
        rbEstu = new QRadioButton(centralWidget);
        rbEstu->setObjectName(QString::fromUtf8("rbEstu"));
        rbEstu->setGeometry(QRect(540, 220, 93, 17));
        lbNombre = new QLabel(centralWidget);
        lbNombre->setObjectName(QString::fromUtf8("lbNombre"));
        lbNombre->setGeometry(QRect(270, 140, 51, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionInicio);
        menuArchivo->addAction(actionSalir);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionInicio->setText(QApplication::translate("MainWindow", "Inicio", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Prestamo: ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Usuarios: ", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Agregar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Buscar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Editar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Eliminar", 0, QApplication::UnicodeUTF8));
        btnCancelar->setText(QApplication::translate("MainWindow", "Cancelar", 0, QApplication::UnicodeUTF8));
        lbCedula->setText(QApplication::translate("MainWindow", "Cedula:", 0, QApplication::UnicodeUTF8));
        lbApellido->setText(QApplication::translate("MainWindow", "Apellido:", 0, QApplication::UnicodeUTF8));
        lbtipo->setText(QApplication::translate("MainWindow", "Tipo:", 0, QApplication::UnicodeUTF8));
        rbProf->setText(QApplication::translate("MainWindow", "Profesor", 0, QApplication::UnicodeUTF8));
        btnAceptar->setText(QApplication::translate("MainWindow", "Aceptar", 0, QApplication::UnicodeUTF8));
        rbEstu->setText(QApplication::translate("MainWindow", "Estudiante", 0, QApplication::UnicodeUTF8));
        lbNombre->setText(QApplication::translate("MainWindow", "Nombre: ", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
