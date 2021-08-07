#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> v{"5","4","3","2","1"};
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}