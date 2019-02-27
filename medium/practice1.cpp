//
// Created by 杨海 on 2019-02-27.
//

/**
 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *solution(ListNode *l1, ListNode *l2) {
    ListNode *p = l1;
    ListNode *q = l2;
    ListNode *tmp;
    int temp = 0;
    auto *head = (struct ListNode *) malloc(sizeof(ListNode));
    int sum = p->val + q->val;
    head->val = sum % 10;
    temp = head->val / 10;
    tmp = head;
    while (p != NULL || q != NULL) {
        int l = (p) ? 0 : p->val;
        int r = (p) ? 0 : p->val;
        auto *cur = (struct ListNode *) malloc(sizeof(ListNode));
        cur->next = NULL;
        cur->val = (l + r + temp) % 10;
        temp = (l + r + temp) / 10;
        tmp->next = cur;
        tmp = cur;
        p = p->next;
        q = q->next;
    }
    if (temp != 0) {
        auto *cur = (struct ListNode *) malloc(sizeof(ListNode));
        cur->next = NULL;
        cur->val = temp;
        tmp->next = cur;
    }
    return head;
}

