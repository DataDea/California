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
#include <vector>

using namespace std;

/**
 * 自己的方案有点问题
 */

string convert(string text, int nums) {

    if (text.empty() || text == " " || text.size() == 0) {
        return text;
    }
    int len = static_cast<int>(text.size());
    char a[len][nums];
    for (int k = 0; k < len; k++) {
        for (int m = 0; m < nums; m++) {
            a[k][m] = ' ';
        }
    }
    //PAYPALISHIRING
    int index = 0;
    int tap = 0;
    for (int i = 0; i < len; i++) {
        for (int j = nums - 1; j > -1; j--) {
            if (i / (nums - 1) == 0) {
                tap++;
            }
            if (i / (nums - 1) == 0) {
                a[i][j] = text[index++];
                continue;
            }
            if (i - tap * (nums - 1) == j) {
                a[i][j] = text[index++];
                continue;
            }

        }
    }
    string result;
    for (int j = nums - 1; j > -1; j--) {
        for (int i = 0; i < len; i++) {
            char temp = a[i][j];
            if (temp != ' ') {
                result = result + temp;
            }
        }
    }
    return result;
}

string officeConvert1(string s, int numRows) {

    if (numRows == 1) return s;

    vector<string> rows((unsigned long) min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows) ret += row;
    return ret;
}


/**
 算法
    首先访问 行0中的所有字符接着访问行1然后行2依此类推...
    对于所有整数 kk，
    行0中的字符位于索引k(2⋅numRows−2) 处;
    行numRows−1中的字符位于索引k(2⋅numRows−2)+numRows−1 处;
    内部的行i中的字符位于索引k(2{numRows}-2)+i以及(2⋅numRows−2)−i 处;
 */
string officeConvert2(string s, int numRows) {

    if (numRows == 1) return s;

    string ret;
    int n = static_cast<int>(s.size());
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < n; j += cycleLen) {
            ret += s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                ret += s[j + cycleLen - i];
        }
    }
    return ret;
}
