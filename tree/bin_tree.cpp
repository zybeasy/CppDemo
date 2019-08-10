#include <iostream>
#include <stack>
#include <queue>

#include "bin_tree.h"

using namespace std;

ostream& operator<<(ostream& out, const Node p)
{
    out << p.data << " " << p.left << " " << p.right << " " << p.parent;
    return out;
}

Node* createTreeByFullPreOrder(int* data, int len)
{
    return NULL;
}

Node* createBinTreeByPreAndMidOrder(int* pre, int* mid, int len)
{
    if(not pre || not mid || len <= 0)
        return NULL;

    return _createBinTreeByPreAndMidOrder(pre, 0, len-1, mid, 0, len-1);
}

Node* _createBinTreeByPreAndMidOrder(int* pre, int pre_begin, int pre_end,
        int *mid, int mid_begin, int mid_end)
{
    Node* node = new Node();
    node->data = pre[pre_begin];
    node->left = node->right = node->parent = NULL;

    int index = mid_begin;
    while(index < mid_end + 1) {
        if(mid[index] == pre[pre_begin])
            break;
        else
            index++;
    }

    if (index == mid_end + 1)
        throw "[ERROR] Fail to construct binary tree.";

    if (pre_begin == pre_end && mid_begin == mid_end)
        if (pre[pre_begin] != mid[mid_begin])
            throw "[ERROR] Fail to construct binary tree.";

    if (index - mid_begin > 0) {
        node->left = _createBinTreeByPreAndMidOrder(pre, pre_begin + 1, pre_begin + index - mid_begin,
                                                    mid, mid_begin, index - 1);
    }
    if (mid_end - index > 0) {
        node->right = _createBinTreeByPreAndMidOrder(pre, pre_begin + index - mid_begin + 1, pre_end,
                                                     mid, index + 1, mid_end);
    }

    return node;
}

void setParent(Node* root)
{
    queue<Node*> level;
    if(root)
        level.push(root);

    Node* cur = NULL;
    while(!level.empty())
    {
        cur = level.front();
        level.pop();
        if(cur->left)
        {
            cur->left->parent = cur;
            level.push(cur->left);
        }

        if(cur->right)
        {
            cur->right->parent = cur;
            level.push(cur->right);
        }
    }
}

Node* getMidOrderNext(Node* node)
{
    if(!node)
        return NULL;

    Node* next = NULL;

    if(node->right) {
        next = node->right;
        while(next->left)
            next = next->left;
    }

    else {
        Node* parent = node->parent;
        while(parent && parent->right == node)
        {
            node = parent;
            parent = parent->parent;
        }
        next = parent;
    }

    if(next)
        cout << *next << endl;
    else
        cout << "FUCKING NULL" << endl;

    return next;

}



