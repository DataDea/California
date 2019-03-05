//
// Created by 杨海 on 2019-03-01.
//

/**
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 示例 1:
 输入: "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

 示例 2:
 输入: "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

 示例 3:
 输入: "pwwkew"
 输出: 3
 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */
#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>

using namespace std;

int findMaxLength(string s) {  //"pwwkew"
    int max = 0;
    if (s == " ") {
        return 1;
    }
    if (s == "") {
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        char p = s[i];
        string temp;
        stringstream stream;
        stream << p;
        temp = stream.str();
        bool flag = false;
        for (int j = i + 1; j < s.size(); j++) {
            char tmp = s[j];
            for (int k = 0; k < temp.size(); k++) {
                char element = temp[k];
                if (element == tmp) {
                    if (temp.size() >= max) {
                        max = temp.size();
                    }
                    flag = true;
                    goto out;
                }
            }
            temp = temp + tmp;
            out:
            if (flag) {
                break;
            }
        }
        if (temp.size() >= max) {
            max = temp.size();
        }
    }
    return max;
}
