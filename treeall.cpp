#include <iostream>
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
