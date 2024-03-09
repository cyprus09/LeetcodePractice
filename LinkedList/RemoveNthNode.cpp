#include "linkedlist.h"

//brute force
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        int count = 0;
        ListNode *temp = head;
        ListNode *prev = NULL;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        if(count == n){
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        int result = count - n;
        temp = head;

        while(temp != NULL){
            result--;
            if(result == 0){
                break;
            }
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};

//optimal approach
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < n; i++) fast = fast->next;

        if(fast == NULL) return head->next;

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};