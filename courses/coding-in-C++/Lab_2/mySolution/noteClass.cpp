#include <iostream>
#include <string>

class Note {
private:
    std::string* text;

public:
    // Constructor
    Note(std::string input) {
        text = new std::string(input);
    }

    // Copy Constructor (DAS ist der wichtige Teil)
    Note(const Note& other) {
        text = new std::string(*other.text);
    }

    // Destructor
    ~Note() {
        delete text;
        text = nullptr;
        std::cout << "Memory released" << std::endl;
    }

    void display() {
        std::cout << *text << std::endl;
    }
};

int main() {
    Note note1("Test");
    Note note2 = note1;

    note1.display();
    note2.display();

    // Why is the problem resolved?
    // The copy constructor creates a deep copy.
    // Each object now has its own memory instead of sharing the same pointer.
    // Therefore each destructor deletes its own memory safely.

    return 0;
}