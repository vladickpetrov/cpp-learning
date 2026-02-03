#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

template<typename Type>
class ItemList {
public:
    ItemList(const std::string &filename);

    ~ItemList();

    bool empty() const;

    bool add(const Type &value);

    bool remove_value(const Type &value);

    const std::vector<Type> &items() const;

private:
    void load();

    void save() const;

private:
    std::string filename_;
    std::vector<Type> items_;
};

template<typename Type>
bool ItemList<Type>::add(const Type &value) {
    items_.push_back(value);
    return true;
}

template<typename Type>
ItemList<Type>::ItemList(const std::string &filename) : filename_(filename) {
    load();
}

template<typename Type>
ItemList<Type>::~ItemList() {
    save();
}

template<typename Type>
void ItemList<Type>::load() {
    std::ifstream in(filename_);
    if (!in) {
        return;
    }
    Type value;
    while (in >> value) {
        items_.push_back(value);
    }
}

template<typename Type>
void ItemList<Type>::save() const {
    std::ofstream out(filename_);
    for (auto value: items_) {
        out << value << '\n';
    }
}

template<typename Type>
bool ItemList<Type>::empty() const {
    return items_.empty();
}

template<typename Type>
const std::vector<Type> &ItemList<Type>::items() const {
    return items_;
}

template<typename Type>
bool ItemList<Type>::remove_value(const Type &value) {
    auto new_start = std::remove(items_.begin(), items_.end(), value);
    if (new_start == items_.end()) {
        return false;
    }
    items_.erase(new_start, items_.end());
    return true;
}
