// Binary Search Tree operations in C++

#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
bool check_tree(struct node *root,int lo,int hi,int &count){
    if(root==NULL) return true;
    bool left=check_tree(root->left,lo,hi,count);
    bool right=check_tree(root->right,lo,hi,count);
    if(left && right && root->key>=lo && root->key<=hi){
        count++;
        return true;
    }
    return false;
}
int subtree(struct node *root,int lo,int hi){
    int count=0;
    check_tree(root,lo,hi,count);
    return count;
}
// Driver code
int main() {
  struct node *root = NULL;
  int val;
  cout<<"Enter data:";
  cin>>val;
  while(val!=-1){
    root=insert(root,val);
    cout<<"Enter data:";
    cin>>val;
  }
  cout << "Inorder traversal: ";
  inorder(root);
  int k1,k2;
  cout<<endl<<"Enter low:";
  cin>>k1;
  cout<<"Enter high:";
  cin>>k2;
  int c;
  c=subtree(root,k1,k2);
  cout<<endl;
  cout<<c;
}