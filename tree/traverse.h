#ifndef CPPDEMO_TRAVERSE_H
#define CPPDEMO_TRAVERSE_H

#include "bin_tree.h"

void preOrderRecursive(Node *root, bool is_root=true);
void preOrderNoRecursive(Node *root);

void midOrderRecursive(Node *root, bool is_root=true);
void midOrderNoRecursive(Node *root);

void postOrderRecursive(Node *root, bool is_root=true);
void postOrderNoRecursive(Node *root);

void levelOrder(Node* root);

#endif //CPPDEMO_TRAVERSE_H
