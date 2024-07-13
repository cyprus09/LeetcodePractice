#include "linkedlist.h"

// uses extra space
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *temp = head;
        unordered_set<ListNode *> st;
        while (temp != NULL)
        {
            st.insert(temp);
            temp = temp->next;
            if (st.find(temp) != st.end())
            {
                return true;
            }
        }
        return false;
    }
};

// slow-fast pointer approach
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};