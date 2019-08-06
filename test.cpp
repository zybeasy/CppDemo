#include <iostream>

#include "test.h"

using namespace std;

void test()
{
    Node tmp = {99, NULL, NULL};
    Node node1 = {1, NULL, NULL};
    Node node2 = {2, NULL, &tmp};

    Node root = {0, &node1, &node2};

    preOrderRecursive(&root);
    preOrderNoRecursive(&root );

    midOrderRecursive(&root);
    midOrderNoRecursive(&root);

    postOrderRecursive(&root);
    postOrderNoRecursive(&root);

    levelOrder(&root);

    test_chapter_2();

    int pre[] = {1, 2, 3, 4, 5, 6};
    int mid[] = {3, 2, 5, 4, 1, 6};
    createBinTreeByPreAndMidOrder(pre, mid, 6);
}
