#include "linkedlist.h"

//naive approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* merged = new ListNode();
        ListNode* ans = merged;
    
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val > temp2->val){
                merged->next = temp2;
                temp2 = temp2->next;
            }else{
                merged->next = temp1;
                temp1 = temp1->next;
            }
            merged = merged->next; 
        }

        while(temp1 != NULL){
            merged->next = temp1;
            temp1 = temp1->next;
            merged = merged->next;
        }

        while(temp2 != NULL){
            merged->next = temp2;
            temp2 = temp2->next;
            merged = merged->next;
        }

        return ans->next;
    }
};

//inplace merge
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1->val > list2->val) swap(list1, list2);

        ListNode* result = list1;

        while(list1 != NULL && list2 != NULL){
            ListNode *temp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return result;
    }
};