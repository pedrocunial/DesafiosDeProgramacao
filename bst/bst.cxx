#include <iostream>


struct node_t {
  int key;
  node_t *parent;
  node_t *left;   // lesser
  node_t *right;  // greater
};

void delete_node(node_t *node);

class BST {
private:
  node_t *root;

public:
  BST();
  ~BST();
  node_t *minimum(node_t *r);
  node_t *maximum(node_t *r);
  node_t *find(node_t *r, int key);
  void add(node_t **r, int key);
  void remove(node_t **r, int key);
};

void delete_node(node_t *node)
{
  if (node->left != NULL)
    delete_node(node->left);
  if (node->right != NULL)
    delete_node(node->right);
  delete node;
}

BST::BST()
{
  root = NULL;
}

BST::~BST()
{
  delete_node(root);
}

node_t *BST::minimum(node_t *r)
{
  if (root == NULL)
    return NULL;

  node_t *node;
  if (r == NULL)
    node = root;
  else
    node = r;

  while (node->left != NULL)
    node = node->left;

  return node;
}

node_t *BST::maximum(node_t *r)
{
  if (root == NULL) return NULL;

  node_t *node;
  if (r == NULL)
    node = root;
  else
    node = r;

  while (node->right != NULL)
    node = node->right;

  return node;
}

node_t *BST::find(node_t *r, int key)
{
  if (root == NULL) return NULL;

  node_t *node;
  if (r == NULL)
    node = root;
  else
    node = r;

  while (node != NULL) {
    if (node->key == key)
      return node;
    if (node->key > key)
      node = node->left;
    else
      node = node->right;
  }
  return NULL;
}

void BST::add(node_t **r, int key)
{
  node_t *node;
  if (*r == NULL) {
    if (root == NULL) {
      root = new node_t;
      root->parent = NULL;
      root->left = NULL;
      root->right = NULL;
      root->key = key;
      return;
    }
    node = root;
  } else {
    node = *r;
  }

  node_t *parent;
  while (node != NULL) {
    if (node->key == key)
      return;
    parent = node;
    if (node->key > key)
      node = node->left;
    else
      node = node->right;
  }

  node = new node_t;
  node->key = key;
  node->parent = parent;
  node->left = NULL;
  node->right = NULL;

  if (parent == NULL) {
    if (*r == NULL)
      root = node;
    else
      *r = node;
  } else if (parent->key > key)
    parent->left = node;
  else
    parent->right = node;
}

void BST::remove(node_t **r, int key)
{
  node_t *node;
  if (*r == NULL) {
    if (root == NULL) {
      root = new node_t;
      root->parent = NULL;
      root->left = NULL;
      root->right = NULL;
      root->key = key;
      return;
    }
    node = root;
  } else {
    node = *r;
  }

  while (node != NULL) {
    if (node->key == key) {
      // rm node
      return;
    }
    if (node->key > key)
      node = node->left;
    else
      node = node->right;
  }
}

int main()
{
  return 0;
}
