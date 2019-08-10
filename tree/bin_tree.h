#ifndef CPPDEMO_BIN_TREE_H
#define CPPDEMO_BIN_TREE_H

using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
}Node, *PNode;

ostream& operator<<(ostream& out, const Node p);

Node* createTreeByFullPreOrder(int* data, int len);

Node* _createBinTreeByPreAndMidOrder(int* pre, int pre_begin, int pre_end,
        int* mid, int mid_begin, int mid_end);
Node* createBinTreeByPreAndMidOrder(int* pre, int* mid, int len);

void setParent(Node* root);

Node* getMidOrderNext(Node* node);

#endif //CPPDEMO_BIN_TREE_H
