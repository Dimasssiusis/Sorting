#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "p.h"
namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    p *wind;

private:
    Ui::Window *ui;
private slots:
    void sorting();
};

#endif // WINDOW_H
