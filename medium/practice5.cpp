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

using namespace std;


int sign(int x) {
    int a = x >> 31;
    int b = (x & 0x0000FFFF) | (x >> 16 & 0x0000FFFF);
    b = (b & 0x000000FF) | (b >> 8 & 0x000000FF);
    b = (b & 0x0000000F) | (b >> 4 & 0x0000000F);
    b = (b & 0x00000003) | (b >> 2 & 0x00000003);
    b = (b & 0x00000001) | (b >> 1 & 0x00000001);
    return a | b;
}

int reverse(int x) {
    int flag = sign(x);
    int temp = flag * x, result = 0;
    string s;
    while (temp != 0) {
        int element = temp % 10;
        temp = temp / 10;
        s += to_string(element);
    }
    for (int i = 0, j = s.size() - 1; i < s.size() && j > -1; i++, j--) {
        int e = s[i];
        int t = 1;
        for (int p = j; p > 0; p--) {
            t *= 10;
        }
        if (e != 0) {
            result += e * t;
        }
    }
    return result;
}
