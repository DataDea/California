//
// Created by 杨海 on 2019-03-14.
//

/**
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

    示例：

    给定一个链表: 1->2->3->4->5, 和 n = 2.

    当删除了倒数第二个节点后，链表变为 1->2->3->5.
    说明：

    给定的 n 保证是有效的。

    进阶：

    你能尝试使用一趟扫描实现吗
*/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd1(ListNode *head, int n) {

        if (n < 0) {
            return head;
        }
        if (head == NULL) {
            return NULL;
        }
        ListNode *cur = head, *font = head, *before = head;
        while (cur != NULL) {
            int count = 0;
            ListNode *tmp = cur->next;
            while (tmp->next != NULL) {
                count++;
                tmp = tmp->next;
            }
            if (count == n) {
                before->next = tmp->next;
                return head;
            }
            before = cur;
            cur = cur->next;

        }
        return head;
    }

public:
    void iterate(ListNode *head) {
        ListNode *tmp = head;
        while (tmp != NULL) {
            cout << tmp->val << endl;
            tmp = tmp->next;
        }
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dumpy = (ListNode *) malloc(sizeof(ListNode));
        dumpy->next = head;
        int lens = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            lens++;
            temp = temp->next;
        }
        int index = lens - n + 1;
        ListNode *cur = head, *before = head;
        int count = 0;
        while (cur != NULL) {
            if (++count == index) {
                before->next = cur->next;
                break;
            }
            before = cur;
            cur = cur->next;
        }
        return dumpy->next;
    }

public:
    Solution() {};
};


ListNode *call() {

    Solution *s = new(Solution);
    int lens;
    cout << "请输入节点的个数" << endl;
    cin >> lens;
    int i = 0;
    ListNode *cur = NULL;
    ListNode *head;
    while (i < lens) {
        cout << "输入节点的值" << endl;
        int val;
        cin >> val;
        if (i == 0) {
            head = static_cast<ListNode *>(malloc(sizeof(ListNode)));
            head->val = val;
            cur = head;
        } else {
            auto *temp = static_cast<ListNode *>(malloc(sizeof(ListNode)));
            temp->val = val;
            cur->next = temp;
            cur = temp;
        }
        i++;
    }
    cout << "%%%%%%%%%%%%%%%%%%移除倒数第N个元素前的值%%%%%%%%%%%%%%%%%%%%%%" << endl;
    s->iterate(head);
    cout << "%%%%%%%%%%%%%%%%%%移除倒数第N个元素前的值%%%%%%%%%%%%%%%%%%%%%%" << endl;
    int n;
    cout << "输入删除倒数节点编号" << endl;
    cin >> n;
    s->removeNthFromEnd(head, n);
    cout << "%%%%%%%%%%%%%%%%%%移除倒数第N个元素后的值%%%%%%%%%%%%%%%%%%%%%%" << endl;
    s->iterate(head);
    cout << "%%%%%%%%%%%%%%%%%%移除倒数第N个元素后的值%%%%%%%%%%%%%%%%%%%%%%" << endl;

}

