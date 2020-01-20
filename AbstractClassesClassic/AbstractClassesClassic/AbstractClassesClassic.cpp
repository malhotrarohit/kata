#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : Cache
{
public:
    LRUCache(int capacity) { cp = capacity; head = nullptr; tail = nullptr; }
    void set(int key, int value);
    int get(int key);
private:
    int size = 0;
};

void LRUCache::set(int key, int value)
{
    Node* prev;
    Node* next;
    Node* node = head;
    // start at the head and search for key until we either reach the end or find the key
    while (node != nullptr && node->key != key)
    {
        node = node->next;
    }

    // key not found, insert new node(key, value) at head
    if (node == nullptr)
    {
        node = new Node(key, value);
        node->prev = nullptr;
        node->next = head;
        // if list already has a head
        if (head != nullptr)
        {
            head->prev = node;
        }
        // make new node, the new head
        head = node;
        // if its the only node in the list
        if (tail == nullptr)
        {
            tail = node;
        }
        // increment size
        size++;
        // if size exceeds capacity its time to delete the tail
        if (size > cp)
        {
            prev = tail->prev;
            if (prev != nullptr) 
            {
                prev->next = nullptr;
            }
            tail->prev = nullptr;
            mp.erase(tail->key);
            delete tail;
            tail = prev;
            size--;
        }
    }
    // key found, update value and move to head
    else
    {
        // update value in existing node
        node->value = value;
        // cache previous and next nodes
        prev = node->prev;
        next = node->next;
        // if prev exists update its next node
        if (prev != nullptr)
        {
            prev->next = next;
        }
        // if next exists update its previous node
        if (next != nullptr)
        {
            next->prev = prev;
        }
        // if current node is the tail
        if (tail == node)
        {
            // if prev exists, make it the new tail
            if (prev != nullptr)
            {
                tail = prev;
            }
        }
        // if not already head, make current node the new head
        if (node != head)
        {
            node->prev = nullptr;
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    // after inserting node in doubly linked list insert/update its key in the map
    mp[key] = node;
}

int LRUCache::get(int key)
{
    if (mp.find(key) != mp.end())
    {
        return mp[key]->value;
    }
    else 
    {
        return -1;
    }
}

int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
