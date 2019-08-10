//
// Created by zy on 2019/7/13.
//

#include <iostream>
#include <stack>

#include "chapter_2.h"
#include "utils/List.h"

using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == NULL || length <= 0 || duplication == NULL)
    {
        return false;
    }

    for(int i = 0; i < length; ++i)
        if(numbers[i] < 0 && numbers[i] > length - 1)
            return false;

    for(int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }

            int tmp = numbers[i];
            numbers[i] = numbers[tmp];
            numbers[tmp] = tmp;
        }
    }

    return false;
}

int getDuplication(const int* numbers, int length)
{
    if(numbers == NULL || length < 2)
        return -1;

    int begin = 1;
    int end = length - 1;

    while(begin <= end)
    {
        int mid = (end - begin) / 2 + begin;
        int count = 0;
        for(int i = 0; i < length; ++i)
        {
            if(numbers[i] >= begin && numbers[i] <= mid)
                count++;
        }

        if(count > mid - begin + 1)
        {
            if(begin == mid)
            {
                return begin;
            }
            else
            {
                end = mid;
            }
        }
        else
        {
            begin = mid + 1;
        }
    }

    return -1;
}

int getDuplication2(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;

    int start = 1;
    int end = length - 1;
    while(end >= start)
    {
        int count = 0;
        int middle = ((end - start) >> 1) + start;
        for(int i = 0; i < length; ++i)
        {
            if(numbers[i] >= start && numbers[i] <= middle)
                count++;
        }
        if(end == start)
        {
            if(count > 1)
                return start;
            else
                break;
        }

        if(count > (middle - start + 1))
            end = middle;
        else
            start = middle + 1;
    }
    return -1;
}

bool Find(int *matrix, int rows, int cols, int value)
{
    bool found = false;

    if(matrix && rows > 0 && cols > 0)
    {
        int row = 0;
        int col = cols - 1;

        while(col >= 0 && row < rows)
        {
            if(matrix[row*cols + col] == value)
            {
                cout << "[Row, COL]: " << "[" << row << ", " << col << "]" << endl;
                found = true;
                break;
            }
            else if(matrix[row*cols + col] > value)
                col--;
            else if(matrix[row*cols + col] < value)
                row++;
        }
    }

    return found;
}


void PrintListReverse(ListNode *pHead)
{
    stack<ListNode*> s;

    ListNode* cur = pHead;
    while(cur)
    {
        s.push(cur);
        cur = cur->m_pNext;
    }

    while(!s.empty())
    {
        ListNode* tmp = s.top();
        s.pop();
        cout << tmp->m_nValue << " ";
    }

    cout << endl;
}

void ReplaceBlank(char str[], int length)
{
    if(str == NULL || length <= 0)
        return;

    int ori_len = 0;
    int blank_count = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ori_len++;
        if(str[i] == ' ')
            blank_count++;
        i++;
    }

    int new_len = ori_len + 2 * blank_count;
    if(new_len > length)
        return;

    while(ori_len <= new_len && ori_len >= 0)
    {
        if(str[ori_len] == ' ')
        {
            str[new_len--] = '0';
            str[new_len--] = '2';
            str[new_len--] = '%';
        } else{
            str[new_len--] = str[ori_len];
        }

        ori_len--;
    }
}
void test_chapter_2()
{
    cout << "TEST_CHAPTER_2 ====================================" << endl;

    int duplication;
    int data[] = {2, 1, 3, 1, 4};
    if(duplicate(data, sizeof(data)/sizeof(int), &duplication))
        cout << duplication << endl;

    int data2[] = {2, 3, 5, 4, 3, 2, 6, 7};
    cout << getDuplication(data2, sizeof(data2)/sizeof(int)) << endl;

    cout << getDuplication2(data2, sizeof(data2)/sizeof(int)) << endl;

    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    cout << Find((int*)matrix, 4, 4, 4) << endl;

    const int length = 100;
    char cd1[length] = " hello world  ";
    ReplaceBlank(cd1, length);
    cout << cd1 << endl;

    char cd2[length] = "WULA";
    ReplaceBlank(cd2, length);
    cout << cd2 << endl;

    ListNode* p1 = CreateListNode(1);
    ListNode* p2 = CreateListNode(2);
    ListNode* p3 = CreateListNode(3);
    ConnectListNodes(p1, p2);
    ConnectListNodes(p2, p3);
    PrintListReverse(p1);

    DestroyList(p1);

    QueueWithTwoStacks q;
    q.push(10);
    q.push(20);
    cout << q.pop() << endl;
    q.push(30);
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    cout << "TEST_CHAPTER_2 ====================================" << endl;
}

QueueWithTwoStacks::QueueWithTwoStacks() {}
QueueWithTwoStacks::~QueueWithTwoStacks() {}

void QueueWithTwoStacks::push(const int data)
{
    s1.push(data);
}

int QueueWithTwoStacks::pop()
{
    int top;
    if(s2.empty())
    {
        if(s1.empty())
            throw "ERROR";
        else {
            while(!s1.empty())
            {
                top = s1.top();
                s1.pop();
                s2.push(top);
            }
        }
    }

    top = s2.top();
    s2.pop();
    return top;
}