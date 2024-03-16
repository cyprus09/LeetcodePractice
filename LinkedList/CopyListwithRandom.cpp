#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> deepCopy;
        Node *temp = head;

        while(temp != NULL){
            Node *newNode = new Node(temp->val);
            deepCopy[temp] = newNode;
            temp = temp->next;
        }
        Node *newHead = head;
        while(newHead != NULL){
            Node* node = deepCopy[newHead];
            node->next = (newHead->next != NULL) ? deepCopy[newHead->next]:NULL;
            node->random = (newHead->random != NULL) ? deepCopy[newHead->random]:NULL;
            newHead = newHead->next;
        }
        return deepCopy[head];
    }
};
