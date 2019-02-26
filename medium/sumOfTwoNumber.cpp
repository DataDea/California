//
// Created by 杨海 on 2019-02-26.
//

/**
 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数,并返回他们的数组下标.
 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 示例:
    给定 nums = [2, 7, 11, 15], target = 9
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * 方法一
 */
vector<int> solution1(vector<int> &array, int target) {
    vector<int> result;
    for (int i = 0; i <= array.size() - 2; i++) {
        for (int j = i + 1; j <= array.size() - 1; j++) {
            if ((array[i] + array[j]) == target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

/**
 * 方法二
 */
vector<int> solution2(vector<int> &array, int target) {
    map<int, int> keys;
    vector<int> index;
    for (int i = 0; i < array.size(); i++) {
        keys.insert(array[i], i);
    }
    for (int j = 0; j < array.size(); j++) {
        int temp = array[j];
        if (keys.count(target - temp) > 0) {
            index.push_back(j);
            index.push_back(keys[target - temp]);
        }
    }
    return index;
}

/**
 * 方法三
 */
vector<int> solution3(vector<int> &array, int target) {
    map<int, int> keys;
    vector<int> index;
    for (int i = 0; i < array.size(); i++) {
        keys.insert(array[i], i);
        int temp = target - array[i];
        if (keys.count(temp) > 0) {
            index.push_back(i);
            index.push_back(keys[temp]);
            return index;
        }

    }
    return index;
}