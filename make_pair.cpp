#include <iostream>
#include <string>
#include <typeinfo>
#include <utility>
using namespace std;

int main() {
    auto p = make_pair("one", 1);
    cout << p.first << ',' << p.second << endl;
    cout << typeid(p).name() << endl;

    auto p2 = make_pair("one"s, 1);
    cout << typeid(p2).name() << endl;
}