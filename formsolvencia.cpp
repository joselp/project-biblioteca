#include "formsolvencia.h"
#include "ui_formsolvencia.h"

FormSolvencia::FormSolvencia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSolvencia)
{
    ui->setupUi(this);

    initGUI();
}

FormSolvencia::~FormSolvencia()
{
    delete ui;
}

void FormSolvencia::initGUI()
{
    ui->lineEditCedula->setFocus();
    ui->lineEditCedula->setValidator(new QRegExpValidator(QRegExp("([0-9]{11})"),this));

    connect(ui->btnSolvencia, SIGNAL(clicked()), this, SLOT(slotGenerateSolvencia()));
}

void FormSolvencia::slotGenerateSolvencia()
{
    if( ui->lineEditCedula->text().isEmpty() || ui->lineEditPeriodo->text().isEmpty() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "No debe dejar campos vacios.");
        return;
    }

    QString strQuery = "SELECT * FROM personas WHERE cedula = " + ui->lineEditCedula->text();

    QSqlQuery query;

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this,"ADVERTENCIA","La cédula no existe");
        ui->lineEditCedula->setText("");
        ui->lineEditCedula->setFocus();

        return;
    }
    else if( query.value(3).toString() != "Estudiante" ) {
        QMessageBox::warning(this,"ADVERTENCIA","La cédula no pertenece a un estudiante");
        ui->lineEditCedula->setText("");
        ui->lineEditCedula->setFocus();

        return;
    }

    strQuery = "SELECT * FROM libroPersona WHERE cedulaFk = " + ui->lineEditCedula->text();

    QSqlQuery query2;
    query2.exec(strQuery);

    if( !query2.next() ) {

        QPrinter printer(QPrinter::HighResolution);
        printer.setPageSize(QPrinter::Letter);
        printer.setOrientation(QPrinter::Portrait);
        printer.setPaperSource(QPrinter::Tractor);

        qApp->processEvents();

        QPrintDialog dialog(&printer, this);
        dialog.setWindowTitle("Imprimir Documento");

        if( dialog.exec() != QDialog::Accepted )
            return;

        printDocument(&printer, query);

        clearWidget();

    } else {
        QMessageBox::warning(this, "ADVERTENCIA", "El estudiante tiene libros en préstamo.");
        return;
    }

}

QList<QString> FormSolvencia::cuadroTitulo()
{
    QList<QString> listString;
    QString titulo = "República Bolivariana de Venezuela";
    listString.append(titulo);

    titulo = "ESCUELA BASICA NACIONAL \"ELOY PAREDES\"";
    listString.append(titulo);
    titulo = "MÉRIDA ESTADO MÉRIDA";
    listString.append(titulo);

    return listString;
}

QString FormSolvencia::cuadroConstancia()
{
    QString constancia = "El personal de la Biblioteca \"INES OTILLA FERNANDEZ\", que funciona en la Escuela ";
    constancia += "Básica \"Eloy Paredes\", en la Urbanización Humboldt, Municipio Autónomo Libertador de ";
    constancia += "la Parroquia Caracciolo Parra Pérez del estado Mérida.";

    return constancia;
}

void FormSolvencia::printDocument(QPrinter * printer, QSqlQuery query)
{
    QList<QString> listTitulo = cuadroTitulo();
    QString htmlConstancia = cuadroConstancia();

    QTextDocument doc;

    doc.setHtml( "<p align=left><font face=\"Arial\" size = 4><b>" + listTitulo.at(0) + "</b></font><br>"
                 "<img src = \":images/melogo.png\" align = left width = \"250\" heigth = \"50\"> <br clear = right>"
                 "<br><br><br><br><br>"
                 "<font face=\"Arial\" size = 4><b>" + listTitulo.at(1) + "</b></font><br>"
                 "<font face=\"Arial\" size = 4><b>" + listTitulo.at(2) + "</b></font></p>"
                 "<br><br><br>"
                 "<H1 align = center><font face=\"Arial\"> CONSTANCIA </font></H1><br>"
                 "<p aling=\"justify\"><font face=\"Arial\" size = 5><b> " + htmlConstancia + "</b></font></p><br>"
                 "<H1 align = center><font face=\"Arial\"> HACE CONSTAR </font></H1><br>"
                 "<p aling=\"justify\"><font face=\"Arial\" size = 5><b> Que <u>&nbsp;&nbsp;&nbsp;" + query.value(2).toString() +
                 " , " + query.value(1).toString() + "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</u>, alumno (a) titular de la Cédula de "
                 "Identidad N° <u>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" + query.value(0).toString() + "&nbsp;&nbsp;&nbsp;&nbsp;"
                 "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</u>, del <u>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" +
                 ui->comboBoxGrado->currentText() + "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</u> de Educación "
                 "Básica, Año Escolar <u>&nbsp;&nbsp;&nbsp;&nbsp;" + ui->lineEditPeriodo->text() + "&nbsp;&nbsp;&nbsp;&nbsp;</u>, "
                 "se encuentra solvente en esta Biblioteca.</b></font></p><br>"
                 "<p aling = \"justify\"><font face = \"Arial\" size = 5><b> Constancia que se expide a solicitud de parte interesada para los fines legales "
                 "consiguientes en la ciudad de Mérida, a los <u>&nbsp;&nbsp;" + QString::number(QDate::currentDate().day()) + "&nbsp;&nbsp;</u> "
                 "días del mes de <u>&nbsp;&nbsp;&nbsp;" + QDate::longMonthName(QDate::currentDate().month())  + "&nbsp;&nbsp;&nbsp;</u> "
                 "del año <u>&nbsp;&nbsp;&nbsp;" + QString::number(QDate::currentDate().year()) + "&nbsp;&nbsp;&nbsp;</u>."
                 "</b></font></p><br><br><br><br><br>"
                 "<p><font face = \"Arial\" size = 5><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; "
                 "SELLO <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; "
                 "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; "
                 "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; "
                 "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; "
                 "<span style=\"text-decoration:overline\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;BIBLIOTECARIO"
                 "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></b></font></p>");

    doc.print(printer);

}

void FormSolvencia::clearWidget()
{
    ui->lineEditCedula->setFocus();
    ui->lineEditCedula->setText("");
    ui->comboBoxGrado->setCurrentIndex(0);
    ui->lineEditPeriodo->setText("");
}

void FormSolvencia::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == 16777220 )
        slotGenerateSolvencia();
}
