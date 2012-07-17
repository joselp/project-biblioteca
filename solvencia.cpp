#include "solvencia.h"

Solvencia::Solvencia(QWidget *parent) :
    QWidget(parent)
{

}

void Solvencia::initGUI(QWidget *central)
{
    lblCedula = new QLabel(central);
    lblCedula->setText("Ingrese Cédula: ");
    lblCedula->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblCedula->move(QPoint(335,180));
    lblCedula->setVisible(false);

    lineEditCedula = new QLineEdit(central);
    lineEditCedula->setValidator(new QRegExpValidator(QRegExp("([0-9]{11})"),this));
    lineEditCedula->move(QPoint(465,180));
    lineEditCedula->setVisible(false);

    lblGrado = new QLabel(central);
    lblGrado->setText("Grado: ");
    lblGrado->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblGrado->move(QPoint(245,240));
    lblGrado->setVisible(false);

    comboBoxGrado = new QComboBox(central);
    comboBoxGrado->setGeometry(315,240,121,22);
    comboBoxGrado->addItem("1º Grado");
    comboBoxGrado->addItem("2º Grado");
    comboBoxGrado->addItem("3º Grado");
    comboBoxGrado->addItem("4º Grado");
    comboBoxGrado->addItem("5º Grado");
    comboBoxGrado->addItem("6º Grado");
    comboBoxGrado->addItem("7º Grado");
    comboBoxGrado->addItem("8º Grado");
    comboBoxGrado->addItem("9º Grado");
    comboBoxGrado->setVisible(false);

    lblPeriodo = new QLabel(central);
    lblPeriodo->setText("Año Escolar: ");
    lblPeriodo->setFont(QFont("Baskerville Old Face",12,QFont::Bold));
    lblPeriodo->move(462,240);
    lblPeriodo->setVisible(false);

    lineEditPeriodo = new QLineEdit(central);
    lineEditPeriodo->move(QPoint(585,240));
    lineEditPeriodo->setVisible(false);

    btnSolvencia = new QPushButton(central);
    btnSolvencia->setText("&Imprimir");
    btnSolvencia->move(QPoint(425,390));
    btnSolvencia->setIcon(QIcon(":images/impresora.png"));
    btnSolvencia->setVisible(false);
    connect(btnSolvencia, SIGNAL(clicked()), this, SLOT(slotGenerateSolvencia()));

}

void Solvencia::slotGenerateSolvencia()
{

    if( lineEditCedula->text().isEmpty() || lineEditPeriodo->text().isEmpty() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "No debe dejar campos vacios.");
        return;
    }

    QString strQuery = "SELECT * FROM personas WHERE cedula = " + lineEditCedula->text();

    qDebug() << strQuery;

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this,"ADVERTENCIA","La cédula no existe");
        lineEditCedula->setText("");
        lineEditCedula->setFocus();

        return;
    }
    else if( query.value(3).toString() != "Estudiante" ) {
        QMessageBox::warning(this,"ADVERTENCIA","La cédula no pertenece a un estudiante");
        lineEditCedula->setText("");
        lineEditCedula->setFocus();

        return;
    }

    strQuery = "SELECT * FROM libroPersona WHERE cedulaFk = " + lineEditCedula->text();

    qDebug() << strQuery;

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

        visibleWidget(true);

    } else {
        QMessageBox::warning(this, "ADVERTENCIA", "El estudiante tiene libros en préstamo.");
        return;
    }

}

QList<QString> Solvencia::cuadroTitulo()
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

QString Solvencia::cuadroConstancia()
{
    QString constancia = "El personal de la Biblioteca \"INES OTILLA FERNANDEZ\", que funciona en la Escuela ";
    constancia += "Básica \"Eloy Paredes\", en la Urbanización Humboldt, Municipio Autónomo Libertador de ";
    constancia += "la Parroquia Caracciolo Parra Pérez del estado Mérida.";

    return constancia;
}

void Solvencia::printDocument(QPrinter *printer, QSqlQuery query)
{

    QList<QString> listTitulo = cuadroTitulo();
    QString htmlConstancia = cuadroConstancia();

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
                 comboBoxGrado->currentText() + "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</u> de Educación "
                 "Básica, Año Escolar <u>&nbsp;&nbsp;&nbsp;&nbsp;" + lineEditPeriodo->text() + "&nbsp;&nbsp;&nbsp;&nbsp;</u>, "
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

void Solvencia::visibleWidget(bool visible)
{
    lblCedula->setVisible(visible);
    lineEditCedula->setVisible(visible);
    lineEditCedula->setText("");

    lblGrado->setVisible(visible);
    comboBoxGrado->setVisible(visible);
    comboBoxGrado->setCurrentIndex(0);

    lblPeriodo->setVisible(visible);
    lineEditPeriodo->setVisible(visible);
    lineEditPeriodo->setText("");

    btnSolvencia->setVisible(visible);
}
