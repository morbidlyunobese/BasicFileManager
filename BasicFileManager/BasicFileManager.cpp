#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <filesystem>
#include <fstream>

// https://en.cppreference.com/w/cpp/filesystem 
// file system reference docs i used ^

namespace fs = std::filesystem;

void userChoices() {
	std::cout << "1. Create Dir.\n";
    std::cout << "2. Iterate Dir.\n";
	std::cout << "3. Delete Dir.\n";
    std::cout << "4. Exit.\n";
}

void filePath(std::string& path, std::string& name) {
    std::cout << "Enter root: ";
    std::getline(std::cin, path);
    std::cout << "Enter path: ";
    std::getline(std::cin, name);
}

void createDir() {
    std::string path, name;

    filePath(path, name);
    fs::path dirPath = fs::path(path) / name;

    std::cout << "Created a folder in " << dirPath << "\n";
	const fs::path dir{ path };
	fs::create_directory(dir / name);
}

void iterateDir() {
    std::string path, name;

    filePath(path, name);
    fs::path dirPath = fs::path(path) / name;

    for (auto const& dir_entry : fs::directory_iterator{ dirPath }) {
        std::cout << dir_entry.path() << "\n";
    }
}

void deleteDir() {
    std::string path, name;
    char choice;

    filePath(path, name);
    fs::path dirPath = fs::path(path) / name;

    std::cout << "Are you sure you want to delete path: " << dirPath << "?\n (Y or N): ";
    std::cin >> choice;

    switch (choice) {
        case 'Y':
            try {
                std::uintmax_t n{ fs::remove_all(dirPath) };
                std::cout << "Path " << dirPath << " removed successfully!\n";
            }
            catch (const std::exception& error) {
                std::cerr << "Error caught: " << error.what() << std::endl;
            }
            break;

        case 'N':
            std::cout << "Cancelled deletion.";
            break;

        default:
            std::cout << "Invalid char, please select Y or N.";
            break;
    }
}

/*void getFileSize() {
    std::string path, name;
    dirPath(path, name);

    fs::path filePath = fs::path(path) / name;

    std::cout << "Getting size of: " << filePath;

}*/

int main() {
	
	bool loop = true;
	while (loop) {
		int choice;

        userChoices();

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
            deleteDir();
            break;

        case 4:
            std::cout << "Exit Successful!";
            loop = false;
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
