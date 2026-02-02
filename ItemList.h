#pragma once

#include <vector>
#include <string>

class ItemList {
public:
    ItemList(const std::string &filename);

    ~ItemList();

    bool empty() const;

    bool add(int value);

    bool remove_value(int value);

    const std::vector<int> &items() const;

private:
    void load();

    void save() const;

private:
    std::string filename_;
    std::vector<int> items_;
};