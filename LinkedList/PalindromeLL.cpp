#include "linkedlist.h"

//extra space used
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> reverse;
        ListNode* temp = head;
        while(temp != NULL){
            reverse.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(!reverse.empty()){
            if(reverse.top() != temp->val){
                return false;
            }
            temp = temp->next;
            reverse.pop();
        }

        return true;
    }
};

//without extra space
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* node){
        ListNode* temp = node;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true; 
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* middleHead = reverseLinkedList(slow);
        ListNode* first = head;  
        while(middleHead != NULL){
            if (first->val != middleHead->val) {
                return false;
            }
            first = first->next;
            middleHead = middleHead->next;
        }

        return true;
    }
};