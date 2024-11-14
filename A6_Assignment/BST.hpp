#include <iostream>

template <typename K, typename V>
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(const K& key, const V& value) {
        Node* temp = new Node(key, value);
        if (isEmpty()) {
            root = temp;
        } else {
            Node* curr = root;
            Node* parent = nullptr;
            while (curr) {
                parent = curr;
                if (key < curr->key) {
                    curr = curr->left;
                } else if (key > curr->key) {
                    curr = curr->right;
                } else {
                    curr->value = value;  
                    delete temp;  
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

    bool search(const K& key, V& value) const {
        Node* curr = root;
        while (curr) {
            if (key == curr->key) {
                value = curr->value;
                return true;
            } else if (key < curr->key) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return false;
    }

    bool isEmpty() const { return root == nullptr; }

    void print_inorder() const { inorder(root); std::cout << std::endl; }

private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;

        Node(const K& key, const V& value) : key(key), value(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void inorder(Node* node) const {
        if (node) {
            inorder(node->left);
            std::cout << node->key << ": " << node->value << " ";
            inorder(node->right);
        }
    }
};