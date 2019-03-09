#include <iostream>

using namespace std;

extern void test();

extern int findMaxLength(string s);

extern string findBackString(string text);

extern string officeLongestPalindrome(string text);

extern string officeConvert1(string s, int numRows);
extern string officeConvert2(string s, int numRows);

extern string convert(string text, int nums);

int main() {
    // 基于当前系统的当前日期/时间
    time_t start = time(0);
    // 把 now 转换为字符串形式
    char *s1 = ctime(&start);
    cout << s1 << endl;
    string result = officeConvert2("PAYPALISHIRING", 3);
    cout << result << endl;
    // 基于当前系统的当前日期/时间
    time_t end = time(0);
    // 把 now 转换为字符串形式
    char *s2 = ctime(&end);
    cout << s2 << endl;
    return 0;
}