class Solution {
public:
    void reverse(ListNode* head, int size, ListNode** x, ListNode** y) {
        if (!head) {
            *x = nullptr;
            *y = nullptr;
            return;
        }
        ListNode* n = head;
        ListNode* m = head->next;
        ListNode* r;
        while (n && m && size > 1) {
            r = m->next;
            m->next = n;
            n = m;
            m = r;
            size--;
        }
        head->next = nullptr;
        *x = n;
        *y = head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* before = &dummy;
        int temp = left;
        while (temp > 1) {
            before = before->next;
            temp--;
        }
        ListNode* begin = before->next;
        ListNode* after = begin;
        temp = right - left + 1;
        while (temp > 0) {
            after = after->next;
            temp--;
        }
        ListNode* x = nullptr;
        ListNode* y = nullptr;
        reverse(begin, right - left + 1, &x, &y);
        before->next = x;
        y->next = after;
        return dummy.next;
    }
};


