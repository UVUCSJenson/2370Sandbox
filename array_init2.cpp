#include <iostream>
using namespace std;

class Foo {
public:
    Foo() {
        cout << "a Foo is born at " << static_cast<void*>(this) << endl;
    }
    ~Foo() {
        cout << "a Foo has died at " << static_cast<void*>(this) << endl;
    }
};

int main() {
    Foo a[5];
    Foo f;
}

/* Output:
a Foo is born at 0x7ffee8f06a20
a Foo is born at 0x7ffee8f06a21
a Foo is born at 0x7ffee8f06a22
a Foo is born at 0x7ffee8f06a23
a Foo is born at 0x7ffee8f06a24
a Foo is born at 0x7ffeee739a90
a Foo has died at 0x7ffeee739a90
a Foo has died at 0x7ffee8f06a24
a Foo has died at 0x7ffee8f06a23
a Foo has died at 0x7ffee8f06a22
a Foo has died at 0x7ffee8f06a21
a Foo has died at 0x7ffee8f06a20
*/
