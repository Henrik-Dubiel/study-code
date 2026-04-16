#include <iostream>
#include <string>
#include <cstdint>

namespace validation {
    bool isAdult(std::uint8_t age) {
        return age >= 18;
    }

    bool isSenior(std::uint8_t age) {
        return age >= 65;
    }
}

int main() {
    int inputAge = 0;
    std::uint8_t age = 0;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Please enter your age: ";

        if (!(std::cin >> inputAge)) {
            std::cout << "You did not enter a valid number. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (inputAge < 0 || inputAge > 120) {
            std::cout << "You did not enter a valid age. Please try again." << std::endl;
            continue;
        }

        age = static_cast<std::uint8_t>(inputAge);
        validInput = true;
    }

    std::cout << "You are " << inputAge << " years old." << std::endl;

    if (validation::isSenior(age)) {
        std::cout << "That means that you are a senior citizen." << std::endl;
    } else if (validation::isAdult(age)) {
        std::cout << "That means that you are an adult." << std::endl;
    } else {
        std::cout << "That means that you are still a kid or teenager." << std::endl;
    }

    // Problem when using uint8_t for user input:
    // uint8_t is often treated like a character type in streams,
    // so reading input directly into it can behave unexpectedly.

    // Fix:
    // Read the user input into an int first, validate it,
    // and then use static_cast<std::uint8_t>(inputAge).

    // Other portable data types that could make sense:
    // std::uint16_t, std::int16_t, std::uint32_t

    return 0;
}