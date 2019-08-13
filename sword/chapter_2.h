//
// Created by zy on 2019/7/13.
//

#ifndef CPPDEMO_CHAPTER_2_H
#define CPPDEMO_CHAPTER_2_H

#include <stack>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication);

void test_chapter_2();

class QueueWithTwoStacks {
public:
    QueueWithTwoStacks();
    ~QueueWithTwoStacks();

    void push(const int data);
    int pop();

private:
    stack<int> s1;
    stack<int> s2;
};

#endif //CPPDEMO_CHAPTER_2_H
