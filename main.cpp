#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

class ItemList {
public:
    void show() const;

    void add();

    void remove();

private:
    std::vector<int> items_;
};

void printMenu() {
    std::cout << "\n1. Add item \n";
    std::cout << "2. Show items \n";
    std::cout << "3. Remove item \n";
    std::cout << "4. Exit \n";
}

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

void ItemList::add() {
    items_.push_back(readInput("Enter as number element: "));
}

void ItemList::show() const {
    if (items_.empty()) {
        std::cout << "List is empty\n";
        return;
    }
    for (auto item: items_) {
        std::cout << item << " ";
    }
    std::cout << '\n';
}

void ItemList::remove() {
    if (items_.empty()) {
        std::cout << "Nothing to remove. List is empty.\n";
        return;
    }
    int item = readInput("Enter an element which all instances you want to delete: ");
    if (std::find(items_.begin(), items_.end(), item) == items_.end()) {
        std::cout << "There is no " << item << " in the list \n";
        return;
    }
    auto new_start = std::remove(items_.begin(), items_.end(), item);
    items_.erase(new_start, items_.end());
    std::cout << "New list is:\n";

    this->show();
}

int main() {
    ItemList list;

    while (true) {
        printMenu();
        int choice = readInput("Enter a menu item: ");

        if (choice == 1) {
            list.add();
        } else if (choice == 2) {
            list.show();
        } else if (choice == 3) {
            list.remove();
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "It's not an option \n";
        }
    }
}
