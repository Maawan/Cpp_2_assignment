/*
* bs_tree.hpp
* Written by : SENG1120 Staff (c1234567)
* Modified : 05/10/2023
*
* This file contains the implementation of the BSTree class defined in bs_tree.h.
*/

#include "bs_tree.h"

// Default constructor
template <typename T>
BSTree<T>::BSTree() {
    root = nullptr;
    count = 0;
}

// Destructor
template <typename T>
BSTree<T>::~BSTree() {
    clear();
}

// Insert data into the tree
template <typename T>
void BSTree<T>::insert(const T& data) {
    root = insert(data, root);
    ++count;
}

// Remove item with specified key from the tree
template <typename T>
void BSTree<T>::remove(const std::string& key) {
    root = remove(key, root);
}

// Determine if an item with specified key exists in the tree
template <typename T>
bool BSTree<T>::contains(const std::string& key) const {
    return contains(key, root);
}

// Clear all nodes from the tree
template <typename T>
void BSTree<T>::clear() {
    clear(root);
    root = nullptr;
    count = 0;
}

// Find item with specified key in the tree
template <typename T>
T* BSTree<T>::find(const std::string& key) const {
    BTNode<T>* node = find(key, root);
    return node ? &(node->get_data()) : nullptr;
}

// Find item with minimum data value in the tree
template <typename T>
T& BSTree<T>::find_min() const {
    if (empty()) {
        throw empty_collection_exception();
    }
    BTNode<T>* node = find_min(root);
    return node->get_data();
}

// Find item with maximum data value in the tree
template <typename T>
T& BSTree<T>::find_max() const {
    if (empty()) {
        throw empty_collection_exception();
    }
    BTNode<T>* node = find_max(root);
    return node->get_data();
}

// Check if the tree is empty
template <typename T>
bool BSTree<T>::empty() const {
    return root == nullptr;
}

// Return the number of nodes in the tree
template <typename T>
int BSTree<T>::size() const {
    return count;
}

// Print tree using inorder traversal
template <typename T>
void BSTree<T>::print_inorder(std::ostream& out) const {
    print_inorder(out, root);
}

// Print tree using preorder traversal
template <typename T>
void BSTree<T>::print_preorder(std::ostream& out) const {
    print_preorder(out, root);
}

// Print tree using postorder traversal
template <typename T>
void BSTree<T>::print_postorder(std::ostream& out) const {
    print_postorder(out, root);
}

// Clear all nodes from the sub-tree rooted at the supplied node
template <typename T>
void BSTree<T>::clear(BTNode<T>* node) {
    if (node != nullptr) {
        clear(node->get_left());
        clear(node->get_right());
        delete node;
    }
}

// Insert data into the sub-tree rooted at the supplied node
template <typename T>
BTNode<T>* BSTree<T>::insert(const T& data, BTNode<T>* node) {
    if (node == nullptr) {
        return new BTNode<T>(data);
    }
    if (data < node->get_data()) {
        node->set_left(insert(data, node->get_left()));
    } else {
        node->set_right(insert(data, node->get_right()));
    }
    return node;
}

// Remove item with specified key from the sub-tree rooted at the supplied node
template <typename T>
BTNode<T>* BSTree<T>::remove(const std::string& key, BTNode<T>* node) {
    if (node == nullptr) {
        return node;
    }
    if (key < node->get_data().get_key()) {
        node->set_left(remove(key, node->get_left()));
    } else if (key > node->get_data().get_key()) {
        node->set_right(remove(key, node->get_right()));
    } else {
        if (node->get_left() == nullptr) {
            BTNode<T>* rightChild = node->get_right();
            delete node;
            --count;
            return rightChild;
        } else if (node->get_right() == nullptr){
            BTNode<T>* leftChild = node->get_left();
            delete node;
            --count;
            return leftChild;
        }else{
            BTNode<T>* minNode = find_min(node->get_right());
            node->set_data(minNode->get_data());
            node->set_right(remove(minNode->get_data().get_key(), node->get_right()));
        }
    }
    return node;
}

// Determine if an item with specified key exists in the sub-tree rooted at the supplied node
template <typename T>
bool BSTree<T>::contains(const std::string& key, BTNode<T>* node) const {
    if (node == nullptr) {
        return false;
    }
    if (key < node->get_data().get_key()) {
        return contains(key, node->get_left());
    } else if (key > node->get_data().get_key()) {
        return contains(key, node->get_right());
    } else {
        return true;
    }
}

// Find item with specified key in the sub-tree rooted at the supplied node
template <typename T>
BTNode<T>* BSTree<T>::find(const std::string& key, BTNode<T>* node) const {
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->get_data().get_key()) {
        return find(key, node->get_left());
    } else if (key > node->get_data().get_key()) {
        return find(key, node->get_right());
    } else {
        return node;
    }
}

// Find item with minimum data value in the sub-tree rooted at the supplied node
template <typename T>
BTNode<T>* BSTree<T>::find_min(BTNode<T>* node) const {
    while (node->get_left() != nullptr) {
        node = node->get_left();
    }
    return node;
}

// Find item with maximum data value in the sub-tree rooted at the supplied node
template <typename T>
BTNode<T>* BSTree<T>::find_max(BTNode<T>* node) const {
    while (node->get_right() != nullptr) {
        node = node->get_right();
    }
    return node;
}

// Append the value of each node in the sub-tree rooted at the supplied node to the stream using inorder traversal
template <typename T>
void BSTree<T>::print_inorder(std::ostream& out, BTNode<T>* node) const {
    if (node != nullptr) {
        print_inorder(out, node->get_left());
        out << node->get_data() << " ";
        print_inorder(out, node->get_right());
    }
}

// Append the value of each node in the sub-tree rooted at the supplied node to the stream using preorder traversal
template <typename T>
void BSTree<T>::print_preorder(std::ostream& out, BTNode<T>* node) const {
    if (node != nullptr) {
        out << node->get_data() << " ";
        print_preorder(out, node->get_left());
        print_preorder(out, node->get_right());
    }
}

// Append the value of each node in the sub-tree rooted at the supplied node to the stream using postorder traversal
template <typename T>
void BSTree<T>::print_postorder(std::ostream& out, BTNode<T>* node) const {
    if (node != nullptr) {
        print_postorder(out, node->get_left());
        print_postorder(out, node->get_right());
        out << node->get_data() << " ";
    }
}

// Stream insertion operator for BSTree
template <typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree) {
    tree.print_inorder(out);
    return out;
}
