#ifndef P_H
#define P_H

#include <QWidget>
#include <vector>
namespace Ui {
class p;
}

class p : public QWidget
{
    Q_OBJECT

public:
    explicit p(std::vector<int> vec_in, std::vector<int> vec_out, QWidget *parent = 0);
    ~p();

private:
    Ui::p *ui;
};

#endif // P_H
