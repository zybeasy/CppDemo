#include "sort.h"

#include <iostream>

using namespace std;

int partition(int* data, int begin, int end)
{
    int tmp = data[begin];
    int i = begin, j = end;

    while(i < j) {
        while(i < j && data[j] > tmp)
            j--;

        if(i < j) {
            data[i] = data[j];
            i++;
        }

        while(i < j && data[i] <= tmp)
            i++;

        if(i < j) {
            data[j] = data[i];
            j--;
        }
    }
    data[i] = tmp;
    return i;
}

void quick_sort(int* data, int len)
{
    if(data == NULL || len <= 1)
        return;
    int begin = 0, end = len - 1;
    int index = partition(data, 0, len-1);
    if(index > begin)
        quick_sort(data, index - begin);
    if(begin < end)
        quick_sort(data+index+1, end - index);
}

int partition_2(int *data, int len) {
    int i = 0, j = len - 1;
    while(i < j) {
        while(i < j && data[i] <= data[0])
            i++;
        while(i < j && data[j] > data[0])
            j--;

        if(i < j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }

    if(i - 1 > 0) {
        int tmp = data[i-1];
        data[i-1] = data[0];
        data[0] = tmp;
    }

    return i-1;
}

void quick_sort_2(int* data, int len) {
    if(data == NULL || len <= 1)
        return;

//    for(int i = 0; i < len; ++i)
//        cout << data[i] << " ";
//    cout << endl;

    int index = partition_2(data, len);
    if(index > 0)
        quick_sort_2(data, index+1);
    if(index < len - 1)
        quick_sort_2(data+index+1, len-index-1);
}