#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

#include "traverse.h"

using namespace std;

void preOrderRecursive(Node* root, bool is_root)
{
    if(!root)
        return;
    if(is_root)
        cout << left << setw(23) << "前序遍历 递归:" << "\t";

    cout << root->data << " ";
    preOrderRecursive(root->left, false);
    preOrderRecursive(root->right, false);

    if(is_root)
        cout << endl;
}

void preOrderNoRecursive(Node* root)
{
    stack<Node*> s;
    Node* cur = root;
    cout  << setw(20) << "前序遍历 非递归:" << "\t";

    while(cur || !s.empty())
    {
        while (cur)
        {
            cout << cur->data << " ";
            s.push(cur);
            cur = cur->left;
        }

        if (!s.empty())
        {
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
    }

    cout << endl;
}


void midOrderRecursive(Node* root, bool is_root)
{
    if(!root)
        return;

    if(is_root)
        cout << left << setw(23) << "中序遍历 递归:" << "\t";

    midOrderRecursive(root->left, false);
    cout << root->data << " ";
    midOrderRecursive(root->right, false);

    if(is_root)
        cout << endl;
}

void midOrderNoRecursive(Node* root)
{
    stack<Node*> s;
    Node* cur = root;
    cout  << setw(20) << "中序遍历 非递归:" << "\t";

    while(cur || !s.empty())
    {
        while(cur)
        {
            s.push(cur);
            cur = cur->left;
        }

        if(!s.empty())
        {
            cur = s.top();
            s.pop();
            cout << cur->data << " ";
            cur = cur->right;
        }
    }

    cout << endl;
}


void postOrderRecursive(Node* root, bool is_root)
{
    if(!root)
        return;

    if(is_root)
        cout << left << setw(23) << "后序遍历 递归:" << "\t";

    postOrderRecursive(root->left, false);
    postOrderRecursive(root->right, false);
    cout << root->data << " ";

    if(is_root)
        cout << endl;

}

void postOrderNoRecursive(Node* root)
{
    stack<Node*> s;
    Node* pre = NULL;
    cout  << setw(20) << "后序遍历 非递归:" << "\t";

    while(root || !s.empty())
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }

        if(!s.empty())
        {
            root = s.top();
            if(root->right == NULL || root->right == pre)
            {
                s.pop();
                cout << root->data << " ";
                pre = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }
        }
    }

    cout << endl;
}


void levelOrder(Node* root)
{
    queue<Node*> q;
    Node* cur = NULL;

    cout  << setw(20) << "层次遍历:" << "\t";

    if(root)
        q.push(root);

    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
    }

    cout << endl;

}