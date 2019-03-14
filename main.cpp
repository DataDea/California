#include <iostream>
#include <math.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

extern void test();

extern int findMaxLength(string s);

extern string findBackString(string text);

extern string officeLongestPalindrome(string text);

extern string officeConvert1(string s, int numRows);

extern string officeConvert2(string s, int numRows);

extern string convert(string text, int nums);

extern int64_t reverse(int x);

extern int officalReverse(int x);

extern int myAtoi(string str);

extern ListNode *call();

int main() {
    // 基于当前系统的当前日期/时间
    time_t start = time(0);
    // 把 now 转换为字符串形式
    char *s1 = ctime(&start);
    cout << s1 << endl;
    call();
    // 基于当前系统的当前日期/时间
    time_t end = time(0);
    // 把 now 转5换为字符串形式
    char *s2 = ctime(&end);
    cout << s2 << endl;
    return 0;
}