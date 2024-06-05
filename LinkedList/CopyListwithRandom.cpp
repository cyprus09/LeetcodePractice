#include <iostream>
#include <unordered_map>

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

/* altough the following approach is correct, sometimes the next and random 
pointers might point to null values, which we should not be accessing, hence checking
if the value is null before is a better approach
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copyNodes;

        Node* oldNode = head;
        while(oldNode){
            Node* newNode = new Node(oldNode->val);
            copyNodes[oldNode] = newNode;
            oldNode = oldNode->next;
        }

        oldNode = head;
        while(oldNode){
            Node* copyNode = copyNodes[oldNode];
            copyNode->next = copyNodes[oldNode->next];
            copyNode->random = copyNodes[oldNode->random];
            oldNode = oldNode->next;
        }

        return copyNodes[head];
    }
};

//checking for null values before assigning
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
