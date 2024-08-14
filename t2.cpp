#include <iostream>
#include <fstream>
#include <string>

bool userExists(const std::string& username);
void registerUser(const std::string& username, const std::string& password);
bool loginUser(const std::string& username, const std::string& password);

int main() {
    std::string username, password;
    int choice;

    std::cout << "1. Register\n2. Login\nChoose an option: ";
    std::cin >> choice;
    std::cin.ignore(); // Ignore newline character left in the buffer

    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    switch (choice) {
        case 1:
            if (userExists(username)) {
                std::cout << "Username already exists.\n";
            } else {
                registerUser(username, password);
                std::cout << "Registration successful!\n";
            }
            break;
        case 2:
            if (loginUser(username, password)) {
                std::cout << "Login successful!\n";
            } else {
                std::cout << "Invalid username or password.\n";
            }
            break;
        default:
            std::cout << "Invalid option.\n";
    }

    return 0;
}

bool userExists(const std::string& username) {
    std::ifstream file(username + ".txt");
    return file.is_open();
}

void registerUser(const std::string& username, const std::string& password) {
    std::ofstream file(username + ".txt");
    file << password;
}

bool loginUser(const std::string& username, const std::string& password) {
    std::ifstream file(username + ".txt");
    if (!file.is_open()) return false;

    std::string storedPassword;
    std::getline(file, storedPassword);
    return storedPassword == password;
}
