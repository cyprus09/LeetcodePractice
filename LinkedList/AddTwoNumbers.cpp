#include "linkedlist.h"

//carry on approach normal maths
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();

        ListNode* curr = dummy;
        int carry = 0;

        while(l1 || l2){
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }
        }

        if(carry == 1){
            curr->next = new ListNode(1);
        }

        return dummy->next;
    }
};

// do not do this approach can discuss initially, not covering edge cases where either is null or only has 0, a very long approach not viable to write out completely
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1, *temp2 = l2;
        
        int sum1 = 0, sum2 = 0;
        int n1 = 0, n2 = 0;

        if(l1 == NULL && l2 == NULL){
            return NULL;
        }

        while(temp1 != NULL){
            sum1 += (temp1->val)*pow(10, n1);
            temp1 = temp1->next;
            n1++;
        }

        while(temp2 != NULL){
            sum2 += (temp2->val)*pow(10, n2);
            temp2 = temp2->next;
            n2++;
        }

        int sum = sum1 + sum2;

        ListNode* result = nullptr;
        ListNode* current = nullptr;

        while (sum > 0) {
            int digit = sum % 10;
            sum /= 10;

            ListNode* newNode = new ListNode(digit);
            if (result == nullptr) {
                result = newNode;
                current = result;
            } else {
                current->next = newNode;
                current = current->next;
            }
        }

        return result;
    }
};