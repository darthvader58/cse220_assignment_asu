#include "BST.hpp"
#include <stdexcept>

template <typename K, typename V>
class Dict {
private:
    BinarySearchTree<K, V> BST;

public:
    void add(const K& key, const V& value) {
        BST.insert(key, value);
    }

    V operator[](const K& key) const {
        V value;
        if (!BST.search(key, value)) {
            throw std::runtime_error("Error, no value");
        }
        return value;
    }

    void print() const {
        BST.print_inorder();
    }
};
