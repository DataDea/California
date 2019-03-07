//
// Created by 杨海 on 2019-03-07.
//

/**
    给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
    示例 1：
    输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。
    示例 2：
    输入: "cbbd"
    输出: "bb"
 */

#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>

using namespace std;

bool isBackText(string text) {
    int len = static_cast<int>(text.size());
    int mid = len / 2;
    int left = mid - 1;
    int right = mid + 1;
    if (len % 2 == 0) {
        right = mid;
    }
    while (left >= 0 && right <= len - 1) {
        char l = text[left];
        char r = text[right];
        if (l == r) {
            left--;
            right++;
        } else {
            return false;
        }
    }

    return true;
}

string findBackString(string text) {
    int max = 0;
    string target;
    for (int i = 0; i < text.size(); i++) {
        char p = text[i];
        string temp;
        stringstream stream;
        stream << p;
        temp = stream.str();
        if (temp.size() > max) {
            max = static_cast<int>(temp.size());
            target = temp;
        }
        for (int j = i + 1; j < text.size(); j++) {
            char tmp = text[j];
            temp = temp + tmp;
            bool flag = isBackText(temp);
            if (flag) {
                if (temp.size() > max) {
                    max = static_cast<int>(temp.size());
                    target = temp;
                }
            }
        }
    }
    return target;
}
