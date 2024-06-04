
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *reverseList(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
            return node;

        ListNode *newHead = reverseList(node->next);
        ListNode *front = node->next;
        front->next = node;

        node->next = nullptr;
        return newHead;
    }

public:
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            ListNode *temp1 = head;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *secondHalf = reverseList(slow->next);
        slow->next = nullptr;

        ListNode *firstHalf = head;
        while (secondHalf != nullptr)
        {
            ListNode *temp1 = firstHalf->next;
            ListNode *temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};