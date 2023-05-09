#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertNode(Node* node, int data) {
        if (node == nullptr) {
            node = new Node(data);
        } else if (data <= node->data) {
            node->left = insertNode(node->left, data);
        } else {
            node->right = insertNode(node->right, data);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int data) {
        if (node == nullptr) {
            return nullptr;
        } else if (data < node->data) {
            node->left = deleteNode(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        } else {
            // node to be deleted found
            if (node->left == nullptr && node->right == nullptr) {
                // case 1: node is a leaf node
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                // case 2a: node has only a right child
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                // case 2b: node has only a left child
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                // case 3: node has both left and right child
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void preOrderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }
    bool isPerfectBinaryTree(Node* root) {
    if (root == nullptr) {
        return true;
    }
    int leftHeight = 0, rightHeight = 0;
    Node* left = root->left;
    Node* right = root->right;
    while (left != nullptr) {
        left = left->left;
        leftHeight++;
    }
    while (right != nullptr) {
        right = right->right;
        rightHeight++;
    }
    if (leftHeight != rightHeight) {
        return false;
    }
    return isPerfectBinaryTree(root->left) && isPerfectBinaryTree(root->right);
}

bool isFullBinaryTree(Node* root) {
    if (root == nullptr) {
        return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }
    if (root->left != nullptr && root->right != nullptr) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }
    return false;
}
bool isCompleteBinaryTree(Node* root) {
    if (root == nullptr) {
        return true;
    }
    
    queue<Node*> q;
    q.push(root);
    bool flag = false;
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        if (current->left) {
            if (flag) {
                return false;
            }
            q.push(current->left);
        } else {
            flag = true;
        }
        
        if (current->right) {
            if (flag) {
                return false;
            }
            q.push(current->right);
        } else {
            flag = true;
        }
    }
    return true;
}


bool isLeftSkewed(Node* root) {
    if (root == nullptr) {
        return true;
    }
    if (root->right != nullptr) {
        return false;
    }
    return isLeftSkewed(root->left);
}

bool isRightSkewed(Node* root) {
    if (root == nullptr) {
        return true;
    }
    if (root->left != nullptr) {
        return false;
    }
    return isRightSkewed(root->right);
}




public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertNode(root, data);
    }

    void remove(int data) {
        root = deleteNode(root, data);
    }

    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    void preOrder() {
        preOrderTraversal(root);
        cout << endl;
    }

    void postOrder() {
        postOrderTraversal(root);
        cout << endl;
    }
    bool isPerfect(){
        return isPerfectBinaryTree(root);
    }
    bool isFull(){
        return isFullBinaryTree(root);
    }
    bool isComplete(){
        return isCompleteBinaryTree(root);
    }
    bool isRight(){
        return isRightSkewed(root);
    }
    bool isLeft(){
        return isLeftSkewed(root);
    }
    

};

int main() {
    BinarySearchTree tree;
    tree.insert(7);
    tree.insert(1);
    tree.insert(8);
    tree.insert(5);
    tree.insert(3);
    tree.inOrder();
    tree.preOrder();
    tree.postOrder();
}
