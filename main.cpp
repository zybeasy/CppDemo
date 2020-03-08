#include <iostream>
#include <iomanip>

#include <ctime>

#include <vector>
#include <deque>

#include "test.h"
#include <bitset>
#include <cstring>
#include <sys/sysinfo.h>

#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <tar.h>

using namespace std;

vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
    vector<int> maxInWindows;

    if(num.size() >= size && size >= 1) {
        deque<int> index;

        for(int i=0; i<size; ++i) {
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            index.push_back(i);
        }

        deque<int>::const_iterator iterator_index = index.begin();
        while(iterator_index < index.end()) {
            cout << *iterator_index << " - ";
            iterator_index++;
        }
        cout << endl;
    }
}



int main(int argc, char* argv[])
{
//    test_tree();

//    test();

    test_sort();

    cout << sizeof(size_t) << endl;

    struct NPC {
        int m;
        int data;
    };

    NPC *pNpc = new NPC();
    cout << pNpc->m << " " << pNpc->data << endl;

    cout << bitset<32>(9) << endl;
    cout << bitset<32>(-9) << endl;

    cout << __cplusplus << " XXXXX" << endl;

    cout << setfill('*') << setw(7) << "中国" << endl;

    fork();

    cout << endl << "=========================================================" << endl;
	return 0;
}
