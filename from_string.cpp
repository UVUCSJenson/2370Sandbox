#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<typename T>
T from_string(const string& s) {
    istringstream iss(s);
    T result;
    iss >> result;
    return result;
}

int main() {
    int n = from_string<int>("15");
    cout << n << endl;
}