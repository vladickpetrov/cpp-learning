#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void printMenu() {
    std::cout << "1. Add item \n";
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

void addItem(std::vector<int> &items) {
    items.push_back(readInput("Enter as number element: "));
}

void showItems(const std::vector<int> &items) {
    for (auto item: items) {
        std::cout << item << " ";
    }
    std::cout << '\n';
}

void removeItem(std::vector<int> &items) {
    int item = readInput("Enter an element which all instances you want to delete: ");
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

    while (true) {
        printMenu();
        int choise = readInput("Enter a menu item: ");

        if (choise == 1) {
            addItem(items);
        } else if (choise == 2) {
            showItems(items);
        } else if (choise == 3) {
            removeItem(items);
        } else if (choise == 4) {
            break;
        } else {
            std::cout << "It's not an option \n";
        }
    }
}
