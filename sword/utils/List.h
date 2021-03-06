//
// Created by zy on 2019/7/13.
//

#ifndef CPPDEMO_LIST_H
#define CPPDEMO_LIST_H


struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);

ListNode* create_list(int* data, int len);

void reverse_part_of_list(ListNode** head, int begin, int end);


#endif //CPPDEMO_LIST_H
