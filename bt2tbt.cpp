#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    bool lthread;
    bool rthread;
};

node* createNode(int x) {
    node* temp = new node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->lthread = false;
    temp->rthread = false;
    return temp;
}

node* buildTree() {
    int x;
    cout << "Enter data (-1 for NULL): ";
    cin >> x;

    if (x == -1)
        return NULL;

    node* root = createNode(x);

    cout << "Left child of " << x << ":\n";
    root->left = buildTree();

    cout << "Right child of " << x << ":\n";
    root->right = buildTree();

    return root;
}

void convert(node* root, node*& prev) {
    if (root == NULL)
        return;

    convert(root->left, prev);

    if (root->left == NULL) {
        root->left = prev;
        root->lthread = true;
    }

    if (prev != NULL && prev->right == NULL) {
        prev->right = root;
        prev->rthread = true;
    }

    prev = root;

    convert(root->right, prev);
}

node* leftMost(node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL && root->lthread == false)
        root = root->left;

    return root;
}

void inorder(node* root) {
    node* curr = leftMost(root);

    while (curr != NULL) {
        cout << curr->data << " ";

        if (curr->rthread)
            curr = curr->right;
        else
            curr = leftMost(curr->right);
    }
}

int main() {
    node* root = NULL;

    cout << "Build binary tree:\n";
    root = buildTree();

    node* prev = NULL;
    convert(root, prev);

    cout << "Inorder traversal of threaded binary tree: ";
    inorder(root);

    return 0;
//tree in preorder: root, left subtree, right subtree. Enter -1 whenever a child is missing
}