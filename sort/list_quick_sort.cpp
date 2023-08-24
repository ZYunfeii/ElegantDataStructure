#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode* next;
    int val;
};

ListNode* getPor(ListNode* head, ListNode* end) {
    if (!head || head->next == end) return head;
    int p = head->val;
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    while (p2 != end) {
        if (p2->val < p) {
            p1 = p1->next;
            swap(p1->val, p2->val);
        }
        p2 = p2->next;
    }
    swap(p1->val, head->val);
    return p1;
}

void quickSort(ListNode* head, ListNode* end) {
    if (head != end) {
        ListNode* p = getPor(head, end);
        quickSort(head, p);
        quickSort(p->next, end);
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(-1);
    head->next->next->next = new ListNode(4);
    quickSort(head, nullptr);
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << endl;
        cur = cur->next;
    }
    return 0;
}