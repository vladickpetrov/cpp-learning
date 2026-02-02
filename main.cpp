#include <iostream>
#include <algorithm>
#include <limits>

#include "ItemList.h"

void printMenu() {
    std::cout << "\n1. Add item \n";
    std::cout << "2. Show items \n";
    std::cout << "3. Remove item \n";
    std::cout << "4. Exit \n";
}

void run_test(const std::string& test_name, bool (*test_func)()) {
    if (test_func()) {
        std::cout << "[OK]   " << test_name << '\n';
    } else {
        std::cout << "[FAIL]   " << test_name << '\n';
    }
}

bool test_empty_on_start() {
    ItemList list("test_empty.txt");
    return list.empty();
}

bool test_add() {
    ItemList list("test_add.txt");
    list.add(1);
    for (int i : list.items()) {
        std::cout << i;
    }

    return !list.empty() && list.items().size() == 1;
}

bool test_remove_existing() {
    ItemList list("test_remove_existing.txt");
    list.add(3);
    list.remove_value(3);
    return list.empty();
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
