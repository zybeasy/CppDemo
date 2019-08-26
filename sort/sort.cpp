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