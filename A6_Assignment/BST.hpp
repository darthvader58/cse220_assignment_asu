// bst.hpp
#include <iostream>
#include <string>
using namespace std;

class BinarySearchTree {
public:
    BinarySearchTree() {root = NULL;}

    void insert(int key, const string& value) {
        Node* temp = new Node(key, value);
        if (isEmpty()) {
            root = temp;
        } else {
            Node* current = root;
            Node* parent = nullptr;
            while (current) {
                parent = current;
                if (key < current->key) {
                    current = current->left;
                } else if (key > current->key) {
                    current = current->right;
                } else {
                    current->value = value;  // Overwrite if key exists
                    delete temp;  // Prevent memory leak
                    return;
                }
            }
            if (key < parent->key) {
                parent->left = temp;
            } else {
                parent->right = temp;
            }
        }
    }

    bool search(int key, string& value) const {
        Node* current = root;
        while (current) {
            if (key == current->key) {
                value = current->value;
                return true;
            } else if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    bool isEmpty() const { return root == nullptr; }

    void print_inorder() const { inorder(root); cout << endl; }

private:
    struct Node {
        int key;
        string value;
        Node* left;
        Node* right;
        //Node(int key, const string& value) : key(key), value(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void inorder(Node* node) const {
        if (node) {
            inorder(node->left);
            cout << node->key << ": " << node->value << " ";
            inorder(node->right);
        }
    }
};
