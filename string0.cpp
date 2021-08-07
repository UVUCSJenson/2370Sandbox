// string0.cpp: A String implementation
//             Trace statments announce every function invocation.
//             There is a *delete* for every *new* (via destructors)
//   
#include <cstddef>  // For size_t
#include <cstring>
#include <iostream>   
using namespace std;

class String {
    char* data_ptr;
public:
    String() {
        cout << "default ctor\n";
        data_ptr = new char[1];          // For the '\0'
        data_ptr[0] = '\0';
    }
    String(const char* s) {
        cout << "char* ctor\n";
        data_ptr = new char[strlen(s) + 1];    // Extra byte for '\0'
        strcpy(data_ptr, s);
    }
    String(const String& s2) {
        cout << "copy ctor\n";
        data_ptr = new char[strlen(s2.data_ptr) + 1];    // Extra byte for '\0'
        strcpy(data_ptr, s2.data_ptr);
    }
    String& operator=(const String& s) {
        cout << "assignment opr\n";
        if (&s != this) {
            delete [] data_ptr;
            data_ptr = new char[strlen(s.data_ptr) + 1];    // Extra byte for '\0'
            strcpy(data_ptr, s.data_ptr);
        }
        return *this;
    }
    ~String() {                          // Destructor
        cout << "dtor\n";
        delete [] data_ptr;
    }
    size_t size() const {
        return strlen(data_ptr);
    }
    friend ostream& operator<<(ostream& os, const String& s) {
        return os << s.data_ptr;
    }   
};

int main() {
    String s0;
    cout << "s0.size() == " << s0.size() << endl;
    String s("hello");
    cout << s << " has size " << s.size() << endl;

    String t(s); 
    cout << t << endl;

    s0 = t;
    cout << s0 << endl;
}

