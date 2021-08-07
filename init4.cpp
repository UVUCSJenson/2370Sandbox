// init4.cpp: Illustrates member initializers

#include <iostream> 
#include <string>
using namespace std;

struct Part {
    int n = 0;  // Member Initializer
    Part() {
        cout << "Executing Part()\n";
    }
    Part(int n) {
        cout << "Executing Part(int)\n";
        this->n = n;
    }
    void display() const {
        cout << "n = " << n << endl;  
    }
};

struct Whole {
    string s = "";
    Part p;
    Whole() {
        cout << "Executing Whole()\n";
    }
    Whole(const string& s, const Part& p) : s(s), p(p) {
        cout << "Executing Whole(string, Part)\n";
    }
    void display() const {
        cout << "s = \"" << s << "\" ";
        p.display();
    }
};

int main() {
    Whole w0;
    w0.display();
    Part p(1);
    Whole w("one", p);
    w.display();
}

/* Output:
Executing Part()
Executing Whole()
s = "" n = 0
Executing Part(int)
Executing Whole(string, Part)
s = "one" n = 1
*/
