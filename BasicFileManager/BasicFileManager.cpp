#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

// https://en.cppreference.com/w/cpp/filesystem 
// file system reference docs i used ^

namespace fs = std::filesystem;

void choices() {
	std::cout << "1. Create Dir.\n";
    std::cout << "2. Iterate Dir.\n";
	std::cout << "3. Exit.\n";
}

void directory(std::string& path, std::string& name) {
    std::cout << "Enter path: ";
    std::getline(std::cin, path);
    std::cout << "Enter DIR name: ";
    std::getline(std::cin, name);
}

void createDir() {
    std::string path, name;

    directory(path, name);
    fs::path dirPath = fs::path(path) / name;

    std::cout << "Created a folder in " << dirPath << "\n";
	const fs::path dir{ path };
	fs::create_directory(dir / name);
}

void iterateDir() {
    std::string path, name;

    directory(path, name);
    fs::path dirPath = fs::path(path) / name;

    for (auto const& dir_entry : fs::directory_iterator{ dirPath }) {
        std::cout << dir_entry.path() << "\n";
    }
}

void deleteDir() {
    
}

int main() {
	
	bool loop = true;
	while (loop) {
		int choice;

        choices();

		std::cout << "Enter choice: ";
		std::cin >> choice;
		std::cin.ignore();

        switch (choice) {
        case 1: {
            createDir();
            break;
        }
        case 2:
            iterateDir();
            break;

        case 3:
            std::cout << "Exit Successful!";
            loop = false;
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
