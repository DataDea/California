#include <iostream>

using namespace std;

extern void test();

extern int findMaxLength(string s);

int main() {
    int max = findMaxLength("abcabcdea");
    cout << max << endl;
    return 0;
}