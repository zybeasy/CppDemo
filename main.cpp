#include <iostream>
#include <iomanip>

#include "tree/bin_tree.h"
#include "tree/traverse.h"

using namespace std;

int main(int argc, char* argv[])
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

    cout << setfill('*') << setw(7) << "中国" << endl;

    cout << endl << "=========================================================" << endl;
	return 0;
}