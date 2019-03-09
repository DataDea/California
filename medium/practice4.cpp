//
// Created by 杨海 on 2019-03-07.
//
/**
    将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

    比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

    L   C   I   R
    E T O E S I I G
    E   D   H   N
    之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

    请你实现这个将字符串进行指定行数变换的函数：

    string convert(string s, int numRows);
    示例 1:

    输入: s = "LEETCODEISHIRING", numRows = 3
    输出: "LCIRETOESIIGEDHN"
    示例 2:

    输入: s = "LEETCODEISHIRING", numRows = 4
    输出: "LDREOEIIECIHNTSG"
    解释:

    L     D     R
    E   O E   I I
    E C   I H   N
    T     S     G

 */

#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>

using namespace std;


string convert(string text, int nums) {

    if (text.empty() || text == " " || text.size() == 0) {
        return text;
    }
    int len = static_cast<int>(text.size());
    char a[len][4];
    for (int k = 0; k < len; k++) {
        for (int m = 0; m < nums; m++) {
            a[k][m] = ' ';
        }
    }
    int index = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < nums; j++) {
            if (i / (nums - 1) == 0) {
                a[i][j] = text[index++];
                continue;
            }
            if (i + j == nums - 1) {
                a[i][j] = text[index++];
                continue;
            }
            if (i + 2 + j - nums == nums) {
                a[i][j] = text[index++];
                continue;
            }
        }
    }
    string result;
    for (int k = 0; k < len; k++) {
        for (int m = 0; m < nums; m++) {
            char temp = a[k][m];
            if (temp != ' ') {
                result = result + temp;
            }
        }
    }
    return result;
}