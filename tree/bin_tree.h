#ifndef CPPDEMO_BIN_TREE_H
#define CPPDEMO_BIN_TREE_H

using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node, *PNode;

ostream& operator<<(ostream& out, const Node p);

Node* createTreeByFullPreOrder(int* data, int len);

#endif //CPPDEMO_BIN_TREE_H
