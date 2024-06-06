#include <unordered_map>

using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *left, *right;

    void remove(Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node *node)
    {
        Node *prev = right->prev;
        Node *next = right;

        prev->next = node;
        next->prev = node;

        node->next = next;
        node->prev = prev;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            remove(cache[key]);
            delete cache[key];
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);

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