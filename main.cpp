#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

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

void printMenu() {
    std::cout << "\n1. Add item \n";
    std::cout << "2. Show items \n";
    std::cout << "3. Remove item \n";
    std::cout << "4. Exit \n";
}

void run_test(const std::string& test_name, bool (*test_func)()) {
    if (test()) {
        std::cout << "[OK]   " << test_name << '\n';
    } else {
        std::cout << "[FAIL]   " << test_name << '\n';
    }
}

bool test_empty_on_strat(){}

int readInput(const std::string &prompt) {
    int input;
    std::cout << prompt;
    std::cin >> input;
    while (std::cin.fail()) {
        std::cout << "Invalid input. Try again. \n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << prompt;
        std::cin >> input;
    }
    return input;
}

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

int main() {
    ItemList list("items.txt");

    while (true) {
        printMenu();
        int choice = readInput("Enter a menu item: ");

        if (choice == 1) {
            int add_value = readInput("Enter an element you want to add: ");
            list.add(add_value);
        } else if (choice == 2) {
            if (list.empty()) {
                std::cout << "List is empty\n";
            } else {
                for (auto item: list.items()) {
                    std::cout << item << " ";
                }
                std::cout << '\n';
            }
        } else if (choice == 3) {
            int rem_value = readInput("Enter an element which all instances you want to delete: ");
            list.remove_value(rem_value);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "It's not an option \n";
        }
    }
}
