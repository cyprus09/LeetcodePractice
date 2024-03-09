#include "linkedlist.h"

//carry on approach normal maths
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum/10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }
};

//do not do this approach can discuss initially, not covering edge cases where either is null or only has 0, a very long approach not viable to write out completely
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