class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node* next;
        Node* prev;
    };
    int capacity;
    Node* start;
    Node* end;
    unordered_map<int,Node*> mp;
    int size = 0;

    LRUCache(int capacity) {
        this->capacity = capacity;
        start = new Node();
        end = new Node();
        start->next = end;
        end->prev = start;
    }

    void detach(Node* ptr) {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    void addFront(Node* ptr) {
        Node* prev_head = start->next;
        start->next = ptr;
        ptr->prev = start;
        ptr->next = prev_head;
        prev_head->prev = ptr;
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        Node* ptr = it->second;
        detach(ptr);
        addFront(ptr);
        return ptr->value;
    }

    void cleanup() {
        if (size <= capacity) return;
        Node* last = end->prev;
        detach(last);
        mp.erase(last->key);
        delete last;
        size--;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            Node* ptr = it->second;
            ptr->value = value;
            detach(ptr);
            addFront(ptr);
        } else {
            Node* ptr = new Node();
            ptr->key = key;
            ptr->value = value;
            mp[key] = ptr;
            addFront(ptr);
            size++;
        }
        cleanup();
    }
};