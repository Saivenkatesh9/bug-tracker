#include <iostream>
#include <vector>
#include <iomanip>

// Structure to represent a bug
struct Bug {
    std::string title;
    std::string description;
    std::string status;
};

// Function to display the menu
void displayMenu() {
    std::cout << "Bug Tracker Menu\n";
    std::cout << "1. Add Bug\n";
    std::cout << "2. View Bugs\n";
    std::cout << "3. Exit\n";
}

// Function to add a bug to the bug vector
void addBug(std::vector<Bug>& bugs) {
    Bug newBug;
    std::cin.ignore();  // Clear the input buffer
    std::cout << "Enter bug title: ";
    std::getline(std::cin, newBug.title);
    std::cout << "Enter bug description: ";
    std::getline(std::cin, newBug.description);
    newBug.status = "Open";  // Initial status
    bugs.push_back(newBug);
    std::cout << "Bug added successfully!\n";
}

// Function to display all bugs in the bug vector
void viewBugs(const std::vector<Bug>& bugs) {
    if (bugs.empty()) {
        std::cout << "No bugs to display.\n";
        return;
    }

    std::cout << std::setw(5) << "ID" << std::setw(20) << "Title"
              << std::setw(30) << "Description" << std::setw(15) << "Status\n";
    std::cout << std::setfill('-') << std::setw(70) << "\n";
    std::cout << std::setfill(' ');

    for (size_t i = 0; i < bugs.size(); ++i) {
        std::cout << std::setw(5) << i + 1 << std::setw(20) << bugs[i].title
                  << std::setw(30) << bugs[i].description << std::setw(15) << bugs[i].status << "\n";
    }
}

int main() {
    std::vector<Bug> bugs;  // Vector to store bugs

    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBug(bugs);
                break;
            case 2:
                viewBugs(bugs);
                break;
            case 3:
                std::cout << "Exiting the Bug Tracker.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
