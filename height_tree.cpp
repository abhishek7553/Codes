#include <iostream> 
#include <queue> 
#include <stack> 
using namespace std; 
  
// A Binary Tree Node 
struct node 
{ 
    struct node *left; 
    int data; 
    struct node *right; 
}; 
  
// Iterative method to find the height of Binary Tree 
int treeHeight(node *root) 
{ 
    // Base Case 
    if (root == NULL) 
        return 0; 
  
    // Create an empty queue for level order tarversal 
    queue<node *> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
    int height = 0; 
  
    while (1) 
    { 
        // nodeCount (queue size) indicates number of nodes 
        // at current lelvel. 
        int nodeCount = q.size(); 
        if (nodeCount == 0) 
            return height; 
  
        height++; 
  
        // Dequeue all nodes of current level and Enqueue all 
        // nodes of next level 
        while (nodeCount > 0) 
        { 
            node *node = q.front(); 
            cout<<node->data;
			q.pop(); 
            if (node->left != NULL) 
                q.push(node->left); 
            if (node->right != NULL) 
                q.push(node->right); 
            nodeCount--; 
        } 
        cout<<endl;
    } 
} 
void iterativePreorder(node *root) 
{ 
    // Base Case 
    if (root == NULL) 
       return; 
  
    // Create an empty stack and push root to it 
    stack<node *> nodeStack; 
    nodeStack.push(root); 
  
    /* Pop all items one by one. Do following for every popped item 
       a) print it 
       b) push its right child 
       c) push its left child 
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) 
    { 
        // Pop the top item from stack and print it 
        struct node *node = nodeStack.top(); 
        printf ("%d ", node->data); 
        nodeStack.pop(); 
  
        // Push right and left children of the popped node to stack 
        if (node->right) 
            nodeStack.push(node->right); 
            
        if (node->left) 
            nodeStack.push(node->left); 
            
    } 
} 
  
  
// Utility function to create a new tree node 
node* newNode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create binary tree shown in above diagram 
    node *root = newNode(6); 
    root->left = newNode(3); 
    root->right = newNode(8); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
    root->right->right = newNode(9); 
     iterativePreorder(root) ;cout<<endl;
    cout <<endl<< "Height of tree is " << treeHeight(root); 
    return 0; 
} 
