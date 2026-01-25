#include <iostream>
#include <vector>

void printMenu() {
    std::cout << "1. Add item \n";
    std::cout << "2. Show items \n";
    std::cout << "3. Remove item \n";
    std::cout << "4. Exit \n";
}

void handleInput(int& user_input) {
    std::cout << "Choose a number: ";
    std::cin >> user_input;
}

void addItem() {
}

void showItems() {
}

void removeItem() {
}

int main() {
    int choise;

    while (true) {
        printMenu();
        handleInput(choise);

        if (choise == 1) continue;
        if (choise == 2) continue;
        if (choise == 3) continue;
        if (choise == 4) break;
    }
}
