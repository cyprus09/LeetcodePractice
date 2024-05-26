#include <algorithm>
#include <stack>

using namespace std;

//using linked list
class MinStack
{
public:
    typedef struct node
    {
        int value;
        int minValue;
        node *next;
    } node;

    MinStack() : topNode(nullptr) {}

    void push(int val)
    {
        node *n = new node;
        n->value = n->minValue = val;
        n->next = nullptr;

        if (topNode == nullptr)
        {
            topNode = n;
        }
        else
        {
            n->minValue = min(n->value, topNode->minValue);
            n->next = topNode;
            topNode = n;
        }
    }

    void pop() { topNode = topNode->next; }

    int top() { return topNode->value; }

    int getMin() { return topNode->minValue; }

private:
    node *topNode;
};

//using built in stack library
class MinStack {
public:
    MinStack() {}

    void push(int val) {
        stk.push(val);
        if (minStack.empty() || val < minStack.top().first) {
            minStack.push({val, 1});
        } else if (val == minStack.top().first) {
            minStack.top().second++;
        }
    }

    void pop() {
        if (stk.top() == minStack.top().first) {
            minStack.top().second--;
            if (minStack.top().second == 0) {
                minStack.pop();
            }
        }
        stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return minStack.top().first; }

private:
    stack<int> stk;
    stack<pair<int, int>> minStack;
};
