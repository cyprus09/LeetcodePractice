#include "linkedlist.h"

class Solution {
public:
    void reverseLinkedList(ListNode* node){
        ListNode *temp = node;
        ListNode *prev = NULL;

        while(temp != NULL){
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
    }

    ListNode* getKthNode(ListNode* node, int k){
        k -= 1;

        while(node != NULL && k > 0){
            k--;
            node = node->next;
        }

        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL){
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == NULL){
                if(prevLast){
                    prevLast->next = temp;
                } 
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            reverseLinkedList(temp);

            if(temp == head){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode; 
        }

        return head;
    }
};