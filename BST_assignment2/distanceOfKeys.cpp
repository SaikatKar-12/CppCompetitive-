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
int distance(struct node *root,int key){
    if(root==NULL || root->key==key) return 0;
    if(root->key>key) return distance(root->left,key)+1;
    else return distance(root->right,key)+1;
}
int distanceOfKeys(struct node *root,int key1,int key2){
    if(root==NULL) return 0;
    else if(root->key>key1 && root->key>key2) distanceOfKeys(root->right,key1,key2);
    else if(root->key<key1 && root->key<key2) distanceOfKeys(root->right,key1,key2);
    int a=distance(root,key1);
    int b=distance(root,key2);
    return a+b;
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
  cout<<"Enter key1:";
  cin>>k1;
  cout<<"Enter key2:";
  cin>>k2;
  int c;
  c=distanceOfKeys(root,k1,k2);
  cout<<endl<<c;
}