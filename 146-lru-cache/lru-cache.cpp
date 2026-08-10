 class LRUCache {
private:

    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;  // MRU side
    Node* tail;  // LRU side

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:

    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Recently used → move to front
        removeNode(node);
        addToFront(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            // Make it most recently used
            removeNode(node);
            addToFront(node);

            return;
        }

        // Key doesn't exist
        Node* newNode = new Node(key, value);

        mp[key] = newNode;
        addToFront(newNode);

        // Capacity exceeded
        if (mp.size() > capacity) {

            // tail->prev is the LRU node
            Node* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);

            delete lru;
        }
    }
};

 