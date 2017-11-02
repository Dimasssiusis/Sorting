#include "window.h"
#include "ui_window.h"
#include <stdlib.h>
#include <time.h>
#include <QTime>

void sort_hoar(std::vector<int> &arr, int left, int right);
void sort_merge (std::vector<int> &arr, int left, int right, int num);
void sort_bubble (std::vector<int> &arr, int num);
void copy (std::vector<int> arr, std::vector<int> &arr_temp, int num);
Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    connect(ui->pb, SIGNAL(clicked(bool)), this, SLOT(sorting()));
}

Window::~Window()
{
    delete ui;
}

void Window::sorting()
{
    //кодировка UTF-8
    srand(time(0));
    std::vector<int> arr;
    int num=100;
    if (ui->le->text().isEmpty()==false) num=ui->le->text().toInt();
    for (int i=0; i<num; i++)
    {
        int temp=rand()%201;
        arr.push_back(temp);
    }

    std::vector<int> arr_temp;
    arr_temp.resize(num);

    copy(arr, arr_temp, num);
    QTime time_bubble;
    time_bubble.start();
    sort_bubble(arr_temp, num);
    int t_bubble=time_bubble.elapsed();
    ui->lcd_bubble->display (t_bubble);

    copy(arr, arr_temp, num);
    QTime time_hoar;
    time_hoar.start();
    sort_hoar(arr_temp, 0, num-1);
    int t_hoar=time_hoar.elapsed();
    ui->lcd_hoar->display(t_hoar);

    copy(arr, arr_temp, num);
    QTime time_merge;
    time_merge.start();
    sort_merge(arr_temp, 0, num-1, num);
    int t_merge=time_merge.elapsed();
    ui->lcd_mege->display(t_merge);

    copy(arr, arr_temp, num);
    QTime time_sort;
    time_sort.start();
    sort(arr_temp.begin(), arr_temp.begin()+num);
    int t_sort=time_sort.elapsed();
    ui->lcd_sort->display(t_sort);

    wind=new p (arr, arr_temp);
    wind->show();

}

void sort_bubble (std::vector<int> &arr, int num)
{
    for (int i=0; i<num-1; i++)
        for (int j=0; j<num-i-1; j++)
            if (arr[j]>arr[j+1])
                    std::swap(arr[j], arr[j+1]);
}

void sort_hoar(std::vector<int> &arr, int left, int right)
{
    int i=left;
    int j=right;
    int middle=(left+right+1)/2;
    do
    {
        while(arr[i]<arr[middle]) i++;
        while(arr[j]>arr[middle]) j--;
        if (i<=j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i<=j);
    if (i<right) sort_hoar(arr, i, right);
    if (left<j) sort_hoar(arr, left, j);
}

void sort_merge (std::vector<int> &arr, int left, int right, int num)
{
    if (left==right) return;
    if (right-left==1)
    {
        if (arr[left]>arr[right])
            std::swap(arr[left], arr[right]);
        return;
    }
    int mid=(left+right)/2;
    sort_merge(arr, left, mid, num);
    sort_merge(arr, mid+1, right, num);
    std::vector<int> arr_temp;
    arr_temp.resize(num);
    int _left=left;
    int _right=mid+1;
    int cur=0;
    while (right-left+1 != cur)
    {
        if (_left>mid)
            arr_temp[cur++]=arr[_right++];
        else if (_right>right)
            arr_temp[cur++]=arr[_left++];
        else if (arr[_left]>arr[_right])
            arr_temp[cur++]=arr[_right++];
        else arr_temp[cur++]=arr[_left++];
    }
    for (int i=0; i<cur; i++)
        arr[i+left]=arr_temp[i];
}

void copy (std::vector<int> arr, std::vector<int> &arr_temp, int num)
{
    for (int i=0; i<num; i++)
        arr_temp[i]=arr[i];
}
