#include <queue>
#include <iostream>

using namespace std;

// Implement a class called binary tree that does BFS on it
//  class -> binary tree
//  constructor
//  method --> does a bfs search across the binary tree
//  data type as int
//  node value --> (val root)
//.           50
//       30.         60
//.  10.   45    52

class Node
{
  int val;

  Node *left;
  Node *right;

  Node(int x) : val(x), left(NULL), right(NULL);
};

class BinaryTreeClass
{
public:
  BinaryTreeClass() {};

  void bfs(queue<Node *> &q)
  {
    if (!root)
      return;

    queue<Node *> q;
    q.push(root);

    Node *node = q.front();
    q.pop();
    cout << node->val << " ";

    if (node->left)
      bfs(root->left);
    if (node->right)
      bfs(root->right);
  }
};