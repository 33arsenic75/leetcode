class MyLinkedList {
public:
    ListNode* head;
    ListNode* tail;
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        ListNode* n = head;
        for (int i = 0; n != nullptr && i < index; i++) {
            n = n->next;
        }
        return n != nullptr ? n->val : -1; // Return -1 if index is out of bounds
    }

    void addAtHead(int val) {
        ListNode* n = new ListNode(val);
        n->next = head;
        head = n;
        if (tail == nullptr) { // If the list was empty
            tail = head;
        }
    }

    void addAtTail(int val) {
        ListNode* n = new ListNode(val);
        if (tail != nullptr) {
            tail->next = n;
            tail = n;
        } else { // If the list was empty
            head = tail = n;
        }
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* n = head;
        for (int i = 0; n != nullptr && i < index - 1; i++) {
            n = n->next;
        }

        if (n == nullptr) return; // If index is out of bounds

        ListNode* r = new ListNode(val);
        r->next = n->next;
        n->next = r;

        if (r->next == nullptr) { // If added at the end, update tail
            tail = r;
        }
    }

    void deleteAtIndex(int index) {
        if (index == 0 && head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) { // If the list is now empty
                tail = nullptr;
            }
            return;
        }

        ListNode* n = head;
        for (int i = 0; n != nullptr && i < index - 1; i++) {
            n = n->next;
        }

        if (n == nullptr || n->next == nullptr) return; // If index is out of bounds

        ListNode* m = n->next;
        n->next = m->next;
        if (n->next == nullptr) { // If deleted the last element, update tail
            tail = n;
        }
        delete m;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index, val);
 * obj->deleteAtIndex(index);
 */
