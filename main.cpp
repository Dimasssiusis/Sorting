#include <iostream>
#include <Vector>
#include <stdlib.h>
#include <time.h>
#include <QTime>

using namespace std;
void sort_hoar(vector<int> &arr, int left, int right);
void sort_merge (vector<int> &arr, int left, int right, int num);
void sort_bubble (vector<int> &arr, int num);
void show (vector<int> arr, int num);
void copy (vector<int> arr, vector<int> &arr_temp, int num);

int main()
{
    //кодировка UTF-8
    srand(time(0));
    vector<int> arr;
    int num=10000;                          //Количество элементов в массиве
    cout<<"Work in progress..."<<endl;
    for (int i=0; i<num; i++)
    {
        int temp=rand()%21;
        arr.push_back(temp);
    }
//    show(arr, num);
//    cout<<endl;
    vector<int> arr_temp;
    arr_temp.resize(num);

    copy(arr, arr_temp, num);
    QTime time_bubble;
    time_bubble.start();                            //Запуск таймера
    sort_bubble(arr_temp, num);
    int t_bubble=time_bubble.elapsed();             //Показ времени таймера
//    show(arr_temp, num);                          //Вывод отсортированного массива
    cout<<"Bubble sorting time: "<<t_bubble<<endl;

    copy(arr, arr_temp, num);
    QTime time_hoar;
    time_hoar.start();
    sort_hoar(arr_temp, 0, num-1);
    int t_hoar=time_hoar.elapsed();
//    show(arr_temp, num);
    cout<<"Hoar sorting time: "<<t_hoar<<endl;

    copy(arr, arr_temp, num);
    QTime time_merge;
    time_merge.start();
    sort_merge(arr_temp, 0, num-1, num);
    int t_merge=time_merge.elapsed();
//    show(arr_temp, num);
    cout<<"Merge sorting time: "<<t_merge<<endl;

    copy(arr, arr_temp, num);
    QTime time_sort;
    time_sort.start();
    sort(arr_temp.begin(), arr_temp.begin()+num);   //Стандартная сортировка С++
    int t_sort=time_sort.elapsed();
//    show(arr_temp, num);
    cout<<"Standart sorting time: "<<t_sort<<endl;

    return 0;
}

void sort_bubble (vector<int> &arr, int num)        //Сортировка пузырем
{
    for (int i=0; i<num-1; i++)
        for (int j=0; j<num-i-1; j++)
            if (arr[j]>arr[j+1])
                    swap(arr[j], arr[j+1]);
}

void sort_hoar(vector<int> &arr, int left, int right)       //Сортировка Хоар
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
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i<=j);
    if (i<right) sort_hoar(arr, i, right);
    if (left<j) sort_hoar(arr, left, j);
}

void sort_merge (vector<int> &arr, int left, int right, int num)        //Сортировка слиянием
{
    if (left==right) return;
    if (right-left==1)
    {
        if (arr[left]>arr[right])
            swap(arr[left], arr[right]);
        return;
    }
    int mid=(left+right)/2;
    sort_merge(arr, left, mid, num);
    sort_merge(arr, mid+1, right, num);
    vector<int> arr_temp;
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

void copy (vector<int> arr, vector<int> &arr_temp, int num)
{
    for (int i=0; i<num; i++)
        arr_temp[i]=arr[i];
}

void show (vector<int> arr, int num)
{
    for (int i=0; i<num; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
