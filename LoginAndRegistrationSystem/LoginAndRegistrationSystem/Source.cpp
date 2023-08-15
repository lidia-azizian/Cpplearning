#include <iostream>
#include <fstream>
#include <string>

void clearScreen() {
    std::cout << "\x1B[2J\x1B[H";
}

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

bool userExists(const std::string& userId, const std::string& password) {
    std::ifstream input("data.txt");
    std::string Id, pass;
    while (input >> Id >> pass) {
        if (Id == userId && pass == password) {
            return true;
        }
    }
    return false;
}

void loginUser() {
    std::string userId, password;
    clearScreen();
    std::cout << "\t\t\tEnter your Id:____________________________\n\n\n";
    std::cout << "\t\t\t";
    std::cin >> userId;
    std::cout << "\t\t\tEnter your password:_______________________\n\n\n";
    std::cout << "\t\t\t";
    std::cin >> password;
    clearScreen();
    if (userExists(userId, password)) {
        std::cout << "\t\t\tYou logged in successfully:_______________\n\n\n";
    }
    else {
        std::cout << "\t\t\tSign-in failed:___________________________\n\n\n";
    }
    clearScreen();

}

void registerUser() {
    std::string ruserId, rpassword;
    clearScreen();
    std::cout << "\t\t\tEnter your Id:____________________________\n\n\n";
    std::cout << "\t\t\t";
    std::cin >> ruserId;
    std::cout << "\t\t\tEnter your password:_______________________\n\n\n";
    std::cout << "\t\t\t";
    std::cin >> rpassword;

    std::ofstream output("data.txt", std::ios::app);
    if (output.is_open()) {
        output << ruserId << ' ' << rpassword << std::endl;
        output.close();
        clearScreen();
        std::cout << "\t\t\tRegistration succeeded:___________________\n\n\n";
    }
    else {
        std::cerr << "Error opening data.txt for registration" << std::endl;
    }
}

void retrievePassword() {
    std::string fuserId;
    clearScreen();
    std::cout << "\t\t\tEnter your Id:____________________________\n\n\n";
    std::cout << "\t\t\t";
    std::cin >> fuserId;

    if (fileExists("data.txt")) {
        std::ifstream file("data.txt");
        std::string Id, pass;
        bool found = false;
        while (file >> Id >> pass) {
            if (Id == fuserId) {
                clearScreen();
                system("cls");

                std::cout << "\t\t\tYour password is:________________________\n\n\n";
                std::cout << "\t\t\t" << pass << std::endl;
                found = true;
                break;
            }
        }
        if (!found) {
            system("cls");

            clearScreen();
            std::cout << "\t\t\tYour account was not found:______________\n\n\n";
        }
        file.close();
    }
    else {
        std::cerr << "Data file not found" << std::endl;
    }
}

int main() {
    char c;
    do {
        clearScreen();
        std::cout << "\t\t\t__________________________________________\n\n\n";
        std::cout << "\t\t\t___________________MENU___________________\n\n\n";
        std::cout << "\t\t\t__________________________________________\n\n\n";
        std::cout << "\t\t\tEnter l to login:_________________________\n\n\n";
        std::cout << "\t\t\tEnter r for registration:________________\n\n\n";
        std::cout << "\t\t\tEnter f if you forget the password:_______\n\n\n";
        std::cout << "\t\t\t__________________________________________\n\n\n";
        std::cout << "\t\t\tPlease enter your choice:_________________\n\n\n";
        std::cout << "\t\t\t";
        std::cin >> c;

        switch (c) {
        case 'l':
            loginUser();
            break;
        case 'r':
            registerUser();
            break;
        case 'f':
            retrievePassword();
            break;
        default:
            std::cout << "\t\t\tPlease enter one of the suggested options_\n\n\n";
            break;
        }
    } while (c != 'q'); // Exit when user enters 'q'

    return 0;
}
