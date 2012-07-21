#ifndef FORMHOME_H
#define FORMHOME_H

#include <QWidget>

namespace Ui {
class FormHome;
}

class FormHome : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormHome(QWidget *parent = 0);
    ~FormHome();
    
private:
    Ui::FormHome *ui;
};

#endif // FORMHOME_H
