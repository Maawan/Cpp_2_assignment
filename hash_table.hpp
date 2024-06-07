#include "hash_table.h"

template <typename T>
HashTable<T>::HashTable(int table_capacity) {
    capacity = table_capacity;
    count = 0;
    table.resize(capacity);
}

template <typename T>
HashTable<T>::~HashTable() {
    clear();
}

template <typename T>
void HashTable<T>::insert(const T& data) {
    int index = hash_function(data.get_key());
    table[index].push_back(data);
    ++count;
}

template <typename T>
void HashTable<T>::remove(const std::string& key) {
    int index = hash_function(key);
    if (list_remove(table[index], key)) {
        --count;
    }
}

template <typename T>
T* HashTable<T>::get(const std::string& key) {
    int index = hash_function(key);
    return list_find(table[index], key);
}

template <typename T>
bool HashTable<T>::contains(const std::string& key) {
    int index = hash_function(key);
    return list_contains(table[index], key);
}

template <typename T>
void HashTable<T>::clear() {
    for (auto& cell : table) {
        cell.clear();
    }
    count = 0;
}

template <typename T>
bool HashTable<T>::empty() const {
    return count == 0;
}

template <typename T>
int HashTable<T>::size() const {
    return count;
}

template <typename T>
void HashTable<T>::print(std::ostream& os) const {
    for (int i = 0; i < capacity; ++i) {
        os << i << ": ";
        list_print(os, table[i]);
        os << "\n";
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const HashTable<T>& table) {
    table.print(out);
    return out;
}
