#ifndef MANUALUSUARIO_H
#define MANUALUSUARIO_H

#include <QMainWindow>
#include <QWebPage>
#include <QToolBar>

namespace Ui {
class ManualUsuario;
}

class ManualUsuario : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ManualUsuario(QWidget *parent = 0);
    ~ManualUsuario();

private:
    void initGUI();
    void initAction();
    void initToolBar();
    
private slots:
    void slotHome();
    void slotBack();
    void slotForward();

private:
    Ui::ManualUsuario *ui;

    QAction *actionHome;
    QAction *actionBack;
    QAction *actionForward;
    QToolBar *toolBar;
};

#endif // MANUALUSUARIO_H
