#include "ItemList.h"

#include <fstream>
#include <algorithm>

bool ItemList::add(int value) {
    items_.push_back(value);
    return true;
}

ItemList::ItemList(const std::string &filename) : filename_(filename) {
    load();
}

ItemList::~ItemList() {
    save();
}

void ItemList::load() {
    std::ifstream in(filename_);
    if (!in) {
        return;
    }
    int value;
    while (in >> value) {
        items_.push_back(value);
    }
}

void ItemList::save() const {
    std::ofstream out(filename_);
    for (auto value: items_) {
        out << value << '\n';
    }
}

bool ItemList::empty() const {
    return items_.empty();
}

const std::vector<int> &ItemList::items() const {
    return items_;
}

bool ItemList::remove_value(int value) {
    auto new_start = std::remove(items_.begin(), items_.end(), value);
    if (new_start == items_.end()) {
        return false;
    }
    items_.erase(new_start, items_.end());
    return true;
}