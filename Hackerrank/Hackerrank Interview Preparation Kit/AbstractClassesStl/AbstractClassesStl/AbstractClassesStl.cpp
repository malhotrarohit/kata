// AbstractClassesStl.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Refer to problem : https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem

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
    LRUCache(int capacity) { cp = capacity; }
    void set(int key, int value);
    int get(int key);
private:
    vector<Node*> cache;
};

void LRUCache::set(int key, int value)
{
    Node* node = nullptr;
    vector<Node*>::iterator it = cache.begin();
    // find if key is there in the map
    if (mp.find(key) != mp.end())
    {
        node = mp[key];
    }
    // key found, update the value, move existing entry to 'front' of the LRU cache
    if (node != nullptr)
    {
        node->value = value;
        while(it != cache.end() && *it != node)
        {
            it++;
        }
        cache.erase(it);
        cache.push_back(node);
    }
    // key not found, create new node, insert to 'front' of the LRU cache, insert into map
    // if size > capacity, delete 'tail' node from both LRU cache and map
    else 
    {
        node = new Node(key, value);
        cache.push_back(node);
        mp[key] = node;
        if (cache.size() > cp)
        {
            mp.erase((*cache.begin())->key);
            delete *cache.begin();
            cache.erase(cache.begin());
        }
    }
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

int main() 
{
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