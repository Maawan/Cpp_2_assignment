/*
* bt_node.hpp
* Written by : SENG1120 Staff (c1234567)
* Modified : 05/10/2023
*
* This file contains the implementation of the BTNode class defined in bt_node.h.
*/

#include "bt_node.h"

// Default constructor
template <typename T>
BTNode<T>::BTNode() {
    this->data = T();  // Default-initialize the data
    this->left = nullptr;  // Initialize left child to nullptr
    this->right = nullptr;  // Initialize right child to nullptr
}

// Parameterized constructor
template <typename T>
BTNode<T>::BTNode(const T& new_data) {
    this->data = new_data;  // Initialize data with the supplied value
    this->left = nullptr;  // Initialize left child to nullptr
    this->right = nullptr;  // Initialize right child to nullptr
}

// Destructor
template <typename T>
BTNode<T>::~BTNode() {
    // No dynamic memory allocation for data, so nothing specific to do here
    // Pointers left and right should be managed by the binary tree implementation
}

// Set the data of the node
template <typename T>
void BTNode<T>::set_data(const T& new_data) {
    data = new_data;
}

// Set the left child of the node
template <typename T>
void BTNode<T>::set_left(BTNode<T>* new_left) {
    left = new_left;
}

// Set the right child of the node
template <typename T>
void BTNode<T>::set_right(BTNode<T>* new_right) {
    right = new_right;
}

// Get the data of the node
template <typename T>
T& BTNode<T>::get_data() {
    return data;
}

// Get the left child of the node
template <typename T>
BTNode<T>* BTNode<T>::get_left() const {
    return left;
}

// Get the right child of the node
template <typename T>
BTNode<T>* BTNode<T>::get_right() const {
    return right;
}

// Stream insertion operator
template <typename T>
std::ostream& operator<<(std::ostream& out, const BTNode<T>& node) {
    out << node.get_data();
    return out;
}
