using namespace std;

#include <unordered_map>

struct Node
{
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *left;
    Node *right;
    void remove(Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node *node)
    {
        Node *mru = right->prev;
        mru->next = node;
        node->prev = mru;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->cache.clear();
        this->left = new Node(-1, -1);
        this->right = new Node(-1, -1);
        this->left->next = right;
        this->right->prev = left;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
            remove(cache[key]);

        Node *new_node = new Node(key, value);
        cache[key] = new_node;
        insert(new_node);

        if (cache.size() > capacity)
        {
            Node *lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */