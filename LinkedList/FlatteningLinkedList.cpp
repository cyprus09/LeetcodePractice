class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next),
                                           child(child) {}
};

#include <iostream>

using namespace std;

Node *mergeLists(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *temp = new Node();
    Node *dummy = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->child = a;
            temp = a;
            a = a->child;
        }
        else
        {
            temp->child = b;
            temp = b;
            b = b->child;
        }
    }

    if (a)
        temp->child = a;
    else
        temp->child = b;

    return dummy->child;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *down = head;
    Node *right = flattenLinkedList(head->next);

    down->next = NULL;
    Node *ans = mergeLists(down, right);

    return ans;
}
