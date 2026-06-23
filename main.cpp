/**
* @file main.cpp
 * @author Garrett Mandeville
 * @date 06/06/2026
 * @brief Entry point for the Airgead Banking execution sequence.
 * * Handles the high-level application loop, instantiation of calculator assets,
 * and handles termination checks based on user selection strings.
 */

#include "InvestmentCalculator.h"
#include <iostream>

int main() {
    // Instantiates an instance of our object class from memory space
    InvestmentCalculator calculator;
    char userChoice = 'y';

    // The core execution loop allowing students or users to continuously check alternate financials
    do {
        // Clear terminal screen using an ANSI Escape Code sequences for a cleaner UI/UX feel
        std::cout << "\033[2J\033[1;1H";

        // Capture banking figures from console streams
        calculator.PromptUserForInputs();

        // Render first evaluation chart (No regular monthly contributions)
        calculator.DisplayReportWithoutDeposits();

        // Render second evaluation chart (With regular monthly contributions)
        calculator.DisplayReportWithDeposits();

        // Ask user if they wish to perform another execution cycle
        std::cout << "\nWould you like to test different investment values? (y/n): ";
        std::cin >> userChoice;

    } while (userChoice == 'y' || userChoice == 'Y'); // Loop continues if 'y' or 'Y' is input

    // Closing statement confirming application destruction routines executed completely
    std::cout << "\nThank you for utilizing Airgead Banking System software. Exiting application.\n";
    return 0;
}