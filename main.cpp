#include <iostream>
#include <vector>
#include <algorithm>

void printMenu() {
    std::cout << "1. Add item \n";
    std::cout << "2. Show items \n";
    std::cout << "3. Remove item \n";
    std::cout << "4. Exit \n";
}

void handleInput(int &user_input) {
    std::cout << "Enter a number: \n";
    std::cin >> user_input;
}

void addItem(std::vector<int> &items, int &item) {
    handleInput(item);
    items.push_back(item);
}

void showItems(const std::vector<int> &items) {
    for (auto item: items) {
        std::cout << item << " ";
    }
    std::cout << '\n';
}

void removeItem(std::vector<int> &items, int &item) {
    handleInput(item);
    if (std::find(items.begin(), items.end(), item) == items.end()) {
        std::cout << "There is no " << item << " in the list \n";
        return;
    }
    auto new_start = std::remove(items.begin(), items.end(), item);
    items.erase(new_start, items.end());
    std::cout << "New list is:\n";

    showItems(items);
}

int main() {
    std::vector<int> items;
    int choise;
    int item;

    while (true) {
        printMenu();
        handleInput(choise);

        if (choise == 1) {
            addItem(items, item);
        } else if (choise == 2) {
            showItems(items);
        } else if (choise == 3) {
            removeItem(items, item);
        } else if (choise == 4) {
            break;
        } else {
            std::cout << "It's not an option \n";
        }
    }
}
