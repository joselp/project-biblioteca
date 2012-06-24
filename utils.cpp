#include "utils.h"

Utils::Utils()
{

}

void Utils::run(){

    QFile archivo(nombreArchivo);

    if (!archivo.open(QIODevice::ReadOnly)) {
        qDebug()<<"Error al abrir el archivo";
        return;
    }

    archivo.readLine(0);
    archivo.readLine(0);

    while(!archivo.atEnd()){
        c=0;
        comienzo=0;
        fin=0;
        line = archivo.readLine(0);
        aux = line.toStdString();

        for(int i=0;i<c+1;i++){

            comienzo = c;

            c = aux.find(';',c+1) ;

            fin = c;

            if(i==0)
                this->cota = aux.substr(comienzo,fin-comienzo).c_str();
            if(i==1)
                this->autor = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==2)
                this->titulo = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==3)
                this->materia = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==4)
                this->editorial = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==5)
                this->anhoPublicacion = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==6)
                this->lugar = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==7)
                this->canjeado = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==8)
                this->donado = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==9)
                this->comprado = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==10)
                this->volumen = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==11)
                this->ejemplar = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==12)
                this->bueno = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==13)
                this->malo = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==14)
                this->regular = aux.substr(comienzo+1,fin-comienzo-1).c_str();

        }

        QSqlQuery sql;
        sql.exec("INSERT INTO libros values('"+this->cota.toUpper()+"',\""+this->autor+"\",\""+this->titulo
                 +"\",\""+this->materia+"\",\""+this->editorial+"\",\""+this->anhoPublicacion
                 +"\",\""+this->lugar+"\",\""+this->canjeado+"\",\""+this->donado+"\",\""+this->comprado+"\",\""+this->volumen
                 +"\",\""+this->ejemplar+"\",\""+this->bueno+"\",\""+this->regular+"\",\""+this->malo+"\"); COMMIT");
    }


}

void Utils::cargarArchivo(QWidget * a){

    j=0;
    k=0;

    nombreArchivo = QFileDialog::getOpenFileName(a,("Abrir archivo"), "C:\\",("csv(*.csv)"));
    QFile archivo(nombreArchivo);

    if (!archivo.open(QIODevice::ReadOnly)) {
        qDebug()<<"Error";
        return;
    }

    //Cantidad de lineas del archivo para calcular el tamaño maximo de la barra.
    while(!archivo.atEnd()){
        archivo.readLine(0);
        j++;

    }

//    progress = new QProgressBar(a);
//    progress->setTextVisible(false);
//    progress->setGeometry(0,0,161,31);

//    progress->show();
//    progress->setMinimum(0);
//    progress->setMaximum(j);
//    progress->setValue(0);

    progressDialog = new QProgressDialog(a);
    progressDialog->setLabelText("Cargando");
    progressDialog->setRange(0,j);
    progressDialog->setCancelButton(0);
    progressDialog->setWindowModality(Qt::WindowModal);
    progressDialog->setWindowTitle(tr("Cargando Archivo"));
    progressDialog->setMaximumWidth(250);
    progressDialog->setMinimumWidth(250);
//    progressDialog->setWindowFlags(Qt::Tool | Qt::CustomizeWindowHint); /*Sale sin Marco*/
    progressDialog->setWindowFlags(Qt::Tool | Qt::WindowTitleHint | Qt::CustomizeWindowHint); /*Sale Con marco sin botones*/
    progressDialog->show();

    archivo.seek(0);
    archivo.readLine(0);
    archivo.readLine(0);

    while(!archivo.atEnd()){

        k++;
        c=0;
        comienzo=0;
        fin=0;
        line = archivo.readLine(0);
        aux = line.toStdString();

        //progress->setValue(k);
        progressDialog->setValue(k);

        qApp->processEvents();

        for(int i=0;i<c+1;i++) {

            comienzo = c;

            c = aux.find(';',c+1) ;

            fin = c;

            if(i==0)
                this->cota = aux.substr(comienzo,fin-comienzo).c_str();
            if(i==1)
                this->autor = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==2)
                this->titulo = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==3)
                this->materia = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==4)
                this->editorial = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==5)
                this->anhoPublicacion = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==6)
                this->lugar = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==7)
                this->canjeado = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==8)
                this->donado = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==9)
                this->comprado = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==10)
                this->volumen = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==11)
                this->ejemplar = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==12)
                this->bueno = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==13)
                this->malo = aux.substr(comienzo+1,fin-comienzo-1).c_str();
            if(i==14)
                this->regular = aux.substr(comienzo+1,fin-comienzo-1).c_str();

        }

        QSqlQuery sql;
        sql.exec("INSERT INTO libros values('"+this->cota.toUpper()+"',\""+this->autor+"\",\""+this->titulo
                 +"\",\""+this->materia+"\",\""+this->editorial+"\",\""+this->anhoPublicacion
                 +"\",\""+this->lugar+"\",\""+this->canjeado+"\",\""+this->donado+"\",\""+this->comprado+"\",\""+this->volumen
                 +"\",\""+this->ejemplar+"\",\""+this->bueno+"\",\""+this->regular+"\",\""+this->malo+"\"); COMMIT");
    }
    //progress->hide();

    progressDialog->setValue(j);
    progressDialog->close();

}
