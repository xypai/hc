// ref: https://stackoverflow.com/questions/24098956/vector-of-arrays-of-objects-push-back

#include <iostream>
#include <vector>
using namespace std;

struct elem {
    int value;
    elem(int value) : value(value) {}
};

struct nih_array {
    elem data[2][2];
};

int main() {
    vector<nih_array> v;

    v.push_back({1, 2, 3, 4});
    v.push_back({11, 22, 33, 44});
    cout << v[0].data[1][0].value << endl; // "3", no problem here
    nih_array* ptr = v.data();
    cout << ptr->data[1][0].value << endl; // "3", no problem here
    cout << (++ptr)->data[1][0].value << endl; // "33", no problem here
}