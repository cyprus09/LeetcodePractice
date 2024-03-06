#include "linkedlist.h"

//brute force approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head;
        stack<int> temp2;

        while(temp != NULL){
            temp2.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(!temp2.empty()){
            temp->val = temp2.top();
            temp2.pop();
            temp = temp->next;
        }

        return head;
    }
};

//optimal approach (iteratively)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
};

//recursive approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;

        head->next = NULL;

        return newHead;
    }
};