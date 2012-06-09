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
    lblCedula->move(QPoint(335,140));
    lblCedula->setVisible(false);

    lineEditCedula = new QLineEdit(central);
    lineEditCedula->setValidator(new QIntValidator(1,99999999,this));
    lineEditCedula->move(QPoint(465,140));
    lineEditCedula->setVisible(false);

    btnSolvencia = new QPushButton(central);
    btnSolvencia->setText("&Generar");
    btnSolvencia->move(QPoint(425,180));
    btnSolvencia->setVisible(false);
    connect(btnSolvencia, SIGNAL(clicked()), this, SLOT(slotGenerateSolvencia()));

}

void Solvencia::slotGenerateSolvencia()
{

    if( lineEditCedula->text().isEmpty() ) {
        QMessageBox::warning(this, "Advertencia", "No debe dejar campos vacios.");
        return;
    }

    QString strQuery = "SELECT * FROM libroPersona WHERE cedulaFk = " + lineEditCedula->text();

    qDebug() << strQuery;

    query.exec(strQuery);

    if( !query.next() ) {

        QPrinter printer(QPrinter::HighResolution);
        QPrintDialog dialog(&printer, this);
        dialog.setWindowTitle("Imprimir Documento");
        if( dialog.exec() != QDialog::Accepted )
            return;

        printDocument(&printer);

        visibleWidget(false);

    } else {
        QMessageBox::warning(this, "Advertencia", "El usuario tiene libros en préstamo.");
        return;
    }

}

void Solvencia::printDocument(QPrinter *printer)
{


    int izquierdo = printer->pageRect().left() + printer->resolution()*0.5;
    int superior = printer->pageRect().top() + printer->resolution()*0.5;
    int derecho = printer->pageRect().width() - printer->resolution()*1.0;

    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setOutputFileName("solvencia.pdf");

    QPainter painter;
    painter.begin(printer);

    QFont ftTitulo("Arial", 16, QFont::Bold);
    QFontMetrics tamTitulo(ftTitulo, printer);

    QRect rectTitulo(izquierdo, superior, derecho, tamTitulo.lineSpacing());

    painter.setFont(ftTitulo);
    painter.drawText(rectTitulo, Qt::AlignCenter, tr("SOLVENCIA BIBLIOTECA"));

    rectTitulo.translate(0, rectTitulo.height());

    painter.setFont(QFont("Arial", 10));
    painter.drawText(rectTitulo, Qt::AlignCenter, tr("U.E.N Eloy Paredes\n\n"));

    rectTitulo.translate(0, rectTitulo.height());

    // Contenido
    QFont ftContenido("Arial", 12);
    QFontMetrics tamContenido(ftContenido, printer);

    QRect rectContenido(izquierdo, superior + 1000, derecho + 1100, tamContenido.lineSpacing());

    QString strQuery = "SELECT * FROM personas WHERE cedula = " + lineEditCedula->text();
    qDebug() << strQuery;

    query.exec(strQuery);

    QString linea;
    if( query.next() ) {

        linea = "El estudiante: " + query.value(1).toString() + ", " + query.value(2).toString()
                + " con cédula de identidad: V-0" + query.value(0).toString() + ",";
    }

    qDebug() << linea;

    painter.setFont(ftContenido);
    painter.drawText(rectContenido, Qt::AlignLeft, linea);

    QRect rectContenido1(izquierdo, superior + 1300, derecho + 1100, tamContenido.lineSpacing());

    linea = "se encuentra solvente en la biblioteca de la institución.";

    painter.drawText(rectContenido1, Qt::AlignLeft, linea);

    painter.end();

}

void Solvencia::visibleWidget(bool visible)
{
    lblCedula->setVisible(visible);
    lineEditCedula->setVisible(visible);
    lineEditCedula->setText("");

    btnSolvencia->setVisible(visible);
}
