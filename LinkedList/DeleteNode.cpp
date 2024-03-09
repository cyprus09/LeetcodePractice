#include "linkedlist.h"

//naive approach
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
    }
};

//not using extra space
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};