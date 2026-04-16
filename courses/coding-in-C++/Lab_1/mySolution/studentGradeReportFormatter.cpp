#include <iostream>
#include <string>
#include <cstdint>
#include <iomanip>
#include <limits>

// Reads a score safely and stores it using a portable type.
void readScore(const std::string& prompt, std::uint8_t& score) {
    int input = 0;

    while (true) {
        std::cout << prompt;

        if (!(std::cin >> input)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (input < 0 || input > 100) {
            std::cout << "Invalid score. Please enter a value between 0 and 100." << std::endl;
            continue;
        }

        score = static_cast<std::uint8_t>(input);
        break;
    }
}

void readStudentData(std::string& name,
                     std::uint8_t& homework,
                     std::uint8_t& midterm,
                     std::uint8_t& finalExam) {
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    readScore("Homework score: ", homework);
    readScore("Midterm score: ", midterm);
    readScore("Final exam score: ", finalExam);
}

void calculateGrade(std::uint8_t homework,
                    std::uint8_t midterm,
                    std::uint8_t finalExam,
                    double& finalGrade,
                    std::string& letterGrade) {
    finalGrade = homework * 0.40 + midterm * 0.25 + finalExam * 0.35;

    if (finalGrade >= 90.0) {
        letterGrade = "A";
    } else if (finalGrade >= 80.0) {
        letterGrade = "B";
    } else if (finalGrade >= 70.0) {
        letterGrade = "C";
    } else if (finalGrade >= 60.0) {
        letterGrade = "D";
    } else if (finalGrade >= 50.0) {
        letterGrade = "E";
    } else {
        letterGrade = "F";
    }
}

void printReport(const std::string& name,
                 std::uint8_t homework,
                 std::uint8_t midterm,
                 std::uint8_t finalExam,
                 double finalGrade,
                 const std::string& letterGrade) {
    std::string status;

    if (letterGrade == "A" || letterGrade == "B" || letterGrade == "C") {
        status = "PASS";
    } else if (letterGrade == "D" || letterGrade == "E") {
        status = "CONDITIONAL PASS";
    } else {
        status = "FAIL";
    }

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Student Report" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << std::endl;

    std::cout << "Scores" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    std::cout << std::left << std::setw(16) << "Homework"
              << " : " << std::right << std::fixed << std::setprecision(2)
              << static_cast<double>(homework) << std::endl;

    std::cout << std::left << std::setw(16) << "Midterm"
              << " : " << std::right << std::fixed << std::setprecision(2)
              << static_cast<double>(midterm) << std::endl;

    std::cout << std::left << std::setw(16) << "Final Exam"
              << " : " << std::right << std::fixed << std::setprecision(2)
              << static_cast<double>(finalExam) << std::endl;

    std::cout << std::endl;

    std::cout << std::left << std::setw(16) << "Final Grade"
              << " : " << std::right << std::fixed << std::setprecision(2)
              << finalGrade << std::endl;

    std::cout << std::left << std::setw(16) << "Letter Grade"
              << " : " << letterGrade << std::endl;

    std::cout << std::left << std::setw(16) << "Status"
              << " : " << status << std::endl;

    std::cout << "-------------------------------------" << std::endl;
}

int main() {
    std::string name;
    std::uint8_t homework = 0;
    std::uint8_t midterm = 0;
    std::uint8_t finalExam = 0;
    double finalGrade = 0.0;
    std::string letterGrade;

    readStudentData(name, homework, midterm, finalExam);
    calculateGrade(homework, midterm, finalExam, finalGrade, letterGrade);
    printReport(name, homework, midterm, finalExam, finalGrade, letterGrade);

    return 0;
}