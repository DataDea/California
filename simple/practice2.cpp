//
// Created by 杨海 on 2019-03-11.
//

/**
    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

    示例 1:
    输入: 123
    输出: 321

    示例 2:
    输入: -123
    输出: -321

    示例 3:
    输入: 120
    输出: 21
 */


#include <iostream>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;


/**
 *  自己解决方案
 */
int sign(int x) {
    int a = x >> 31;
    int b = (x & 0x0000FFFF) | (x >> 16 & 0x0000FFFF);
    b = (b & 0x000000FF) | (b >> 8 & 0x000000FF);
    b = (b & 0x0000000F) | (b >> 4 & 0x0000000F);
    b = (b & 0x00000003) | (b >> 2 & 0x00000003);
    b = (b & 0x00000001) | (b >> 1 & 0x00000001);
    return a | b;
}

int64_t reverse(int x) {
    int flag = sign(x);
    int temp = x ;
    int64_t result = 0;
    string s;
    while (temp != 0) {
        int element = temp % 10 * flag;
        temp = temp / 10;
        s += to_string(element);
    }
    char *tmp = (char *)s.data();
    if (atol(tmp) > 2147483647) {
        return 0;
    }
    result = atol(tmp) * flag;
    return result;
//    c++11的写法
//    stringstream ss;
//    ss << s;
//    ss >> result;
//    return result * flag;
}

/**
 * 官方解决方案
 */
int officalReverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}