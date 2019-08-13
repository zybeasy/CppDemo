//
// Created by zy on 2019/7/13.
//
#include <iostream>

#include "List.h"

using namespace std;

ListNode* create_list(int* data, int len)
{
    if(!data || len <= 0)
        return NULL;

    ListNode* head = CreateListNode(data[0]);
    ListNode* pre = head;
    for(int i=1; i<len; ++i) {
        ListNode* cur = CreateListNode(data[i]);
        pre->m_pNext = cur;
        pre = cur;
    }

    return head;
}

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_pNext = NULL;
    pNode->m_nValue = value;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == NULL)
    {
        cout << "Error to connect two nodes." << endl;
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{
    if(pNode == NULL)
        cout << "The node is NULL" << endl;
    else
        cout << "The key in node is " << pNode->m_nValue << endl;
}

void PrintList(ListNode* pHead)
{
    ListNode* cur = pHead;
    while(cur)
    {
        cout << cur->m_nValue << " ";
        cur = cur->m_pNext;
    }

    cout << endl;
}

void DestroyList(ListNode* pHead)
{
    ListNode* cur = pHead;
    while(cur)
    {
        pHead = cur->m_pNext;
        delete cur;
        cur = pHead;
    }
}

void AddtoTail(ListNode** pHead, int value)
{
    if(pHead == NULL)
    {
        cout << "Invalid Param." << endl;
        exit(1);
    }

    ListNode* pNew = CreateListNode(value);

    if(*pHead == NULL)
        *pHead = pNew;
    else
    {
        ListNode* cur = *pHead;
        while(cur->m_pNext)
        {
            cur = cur->m_pNext;
        }
        cur->m_pNext = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == NULL || *pHead == NULL)
        return;

    ListNode* toDel = NULL;
    if((*pHead)->m_nValue == value)
    {
        toDel = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pre = *pHead;
        while(pre->m_pNext && pre->m_pNext->m_nValue != value)
        {
            pre = pre->m_pNext;
        }
        if(pre->m_pNext && pre->m_pNext->m_nValue == value)
        {
            toDel = pre->m_pNext;
            pre->m_pNext = toDel->m_pNext;
        }
    }

    if(toDel)
    {
        delete toDel;
        toDel = NULL;
    }
}

void reverse_part_of_list(ListNode** head, int begin, int end)
{
    if(!head || !(*head) || begin < 0 || end < 0 || begin > end)
        return;

    ListNode* pre = NULL;
    ListNode* cur = *head;
    int len = 0;
    int index = 0;
    while(cur)
    {
        if(index++ < begin)
            pre = cur;
        cur = cur->m_pNext;
        len++;
    }

    if(len <= begin || len <= end)
        return;

    ListNode* old = NULL;
    ListNode* next = NULL;
    cur = pre ? pre->m_pNext : *head;
    ListNode* tmp = cur;
    index = begin;
    while(cur && index++<=end) {
        next = cur->m_pNext;
        cur->m_pNext = old;
        old = cur;
        cur = next;
    }

    if(pre)
        pre->m_pNext = old;
    else
        *head = old;

    if(cur)
        tmp->m_pNext = cur;
}
