class Solution {
public:
    int size(ListNode* n) {
        int count = 0;
        while (n) {
            count++;
            n = n->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; // If list is empty or k is 0, no rotation needed

        int sz = size(head);
        k %= sz; // Adjust k to be within range

        if (k == 0) return head; // If k is now 0, no rotation needed

        ListNode* curr = head;
        for (int i = 0; i < sz - k - 1; ++i) {
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr; // Break the list
        ListNode* tail = newHead;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head; // Connect the old head to the old tail, making it circular

        return newHead;
    }
};
