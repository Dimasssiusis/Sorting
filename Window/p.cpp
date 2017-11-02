#include "p.h"
#include "ui_p.h"

p::p(std::vector<int> vec_in, std::vector<int> vec_out, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::p)
{
    ui->setupUi(this);
    for (unsigned int i=0; i<vec_in.size(); i++)
    {
        ui->tb_in->append(QString::number(vec_in[i]));
        ui->tb_out->append(QString::number(vec_out[i]));
    }
    move(1100, 338);
}

p::~p()
{
    delete ui;
}
