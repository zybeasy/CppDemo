#include <iostream>
#include <cstring>

#include "test.h"
#include "sort/sort.h"

using namespace std;

void test_tree()
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
    int pre[] = {1, 2, 3, 4, 5, 6};
    int mid[] = {3, 2, 5, 4, 1, 6};
    Node* tree = createBinTreeByPreAndMidOrder(pre, mid, 6);

//    int pre[] = {1};
//    int mid[] = {1};
//    Node* tree = createBinTreeByPreAndMidOrder(pre, mid, 1);

    postOrderRecursive(tree);
    postOrderNoRecursive(tree);
    setParent(tree);

    getMidOrderNext(tree);
    getMidOrderNext(tree->left);
    getMidOrderNext(tree->left->right);
    getMidOrderNext(tree->right);
    getMidOrderNext(NULL);
}

void test_sort()
{
//    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int data[] = {-10, 4, 3, 3, -1, -5, 0, -2, 7, -9, -9, -99, 100, -999};

    int* data2 = (int*)malloc(sizeof(data));
    memcpy(data2, data, sizeof(data));
    for(int i=0; i<sizeof(data)/sizeof(int); ++i)
        cout << data2[i] << " ";
    cout << endl;

    quick_sort(data, sizeof(data)/sizeof(int));
    for(int i=0; i<sizeof(data)/sizeof(int); ++i)
        cout << data[i] << " ";
    cout << endl;

    quick_sort_2(data2, sizeof(data)/sizeof(int));
    for(int i=0; i<sizeof(data)/sizeof(int); ++i)
        cout << data2[i] << " ";
    cout << endl;
}

void test()
{

    test_chapter_2();

}
