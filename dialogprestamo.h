#ifndef DIALOGPRESTAMO_H
#define DIALOGPRESTAMO_H

#include <QWidget>
#include <QtGui>

namespace Ui {
    class DialogPrestamo;
}

class DialogPrestamo : public QWidget
{
    Q_OBJECT

public:
    explicit DialogPrestamo(QWidget *parent = 0);
    void setNombre(QString );
    void setApellido(QString );
    void setCedula(QString );
    void setTipoUser(QString );
    void setCota(QString );
    void setAutor(QString );
    void setTitulo(QString );
    void setEditorial(QString );
    void setPublicacion(QString );
    void setEjemplar(QString );
    void setAdquisicion(QString );
    void setEstado(QString );
    ~DialogPrestamo();

private:
    void initGUI();

private slots:
    void slotAceptar();

private:
    Ui::DialogPrestamo *ui;
};

#endif // DIALOGPRESTAMO_H
