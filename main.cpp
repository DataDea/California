#include <iostream>

using namespace std;

extern void test();

extern int findMaxLength(string s);

extern string findSameString(string text);

int main() {
    string result = findSameString("");
    cout << result << endl;
    return 0;
}