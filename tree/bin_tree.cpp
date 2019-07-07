#include <iostream>
#include <stack>


#include "bin_tree.h"

using namespace std;

ostream& operator<<(ostream& out, const Node p)
{
    out << p.data << " " << p.left << " " << p.right;
}

Node* createTreeByFullPreORder(int* data, int len)
{
    stack<Node*> s;
    Node* root = NULL;
    for(int i=0; i<len; ++i)
    {
        if(data[i] != 0)
        {
            Node *cur = new Node;
            cur->data = data[i];
            cur->left = NULL;
            cur->right = NULL;

            if(!s.empty())
            {

            }
        }

        if(!root)
            root = cur;


    }
}



