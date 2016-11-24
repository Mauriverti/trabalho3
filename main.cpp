#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {

    cout << "ola" << endl;

    list<int> l;
    list<int>::iterator it;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);


    for (it = l.begin(); it != l.end(); it++) {
        cout << *it << endl;
    }


    return 0;
}
