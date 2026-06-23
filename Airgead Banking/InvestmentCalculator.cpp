/**
 * @file InvestmentCalculator.cpp
 * @author Garrett Mandeville
 * @date 06/06/2026
 * @brief Logic definitions and processing loops for the InvestmentCalculator class.
 */

#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip> // Needed for stream manipulators like std::setw and std::setprecision
#include <string>
#include <limits>  // Needed for std::numeric_limits to handle input buffer clearing

/**
 * Constructor definition. Enforces a predictable starting state for memory allocations.
 */
InvestmentCalculator::InvestmentCalculator() {
    m_initialInvestment = 0.0;
    m_monthlyDeposit = 0.0;
    m_annualInterest = 0.0;
    m_numberOfYears = 0;
}

/**
 * Generates uniform, clean borders and column markers for both system reports.
 */
void InvestmentCalculator::PrintReportHeader(const unsigned int t_tableWidth, const std::string t_title) const {
    std::cout << std::endl;
    // Creates a line of '=' characters across the top
    std::cout << std::string(t_tableWidth, '=') << std::endl;

    // Logic to center the title dynamically above the column frames
    std::cout << std::setw((t_tableWidth + t_title.length()) / 2) << t_title << std::endl;
    std::cout << std::string(t_tableWidth, '=') << std::endl;

    // Prints exact tracking columns matching structural specifications
    std::cout << std::left << std::setw(10) << "Year"
              << std::right << std::setw(22) << "Year End Balance"
              << std::right << std::setw(28) << "Year End Earned Interest" << std::endl;

    // Creates a subtle division line of '-' characters beneath column labels
    std::cout << std::string(t_tableWidth, '-') << std::endl;
}

/**
 * Handles terminal UI interaction, processing type safety blocks to filter illegal numbers.
 */
void InvestmentCalculator::PromptUserForInputs() {
    std::cout << std::string(34, '*') << std::endl;
    std::cout << std::string(11, '*') << " Data Input " << std::string(11, '*') << std::endl;

    // Data input loops ensure positive values are supplied using standard input validation
    do {
        std::cout << "Initial Investment Amount: $";
        // Check if data stream failed (letters entered) or value is negative
        if (!(std::cin >> m_initialInvestment) || m_initialInvestment < 0) {
            std::cout << "Invalid input. Please enter a positive number.\n";
            std::cin.clear(); // Reset stream status flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Purge bad characters
            m_initialInvestment = -1; // Keep loop active
        }
    } while (m_initialInvestment < 0);

    do {
        std::cout << "Monthly Deposit: $";
        if (!(std::cin >> m_monthlyDeposit) || m_monthlyDeposit < 0) {
            std::cout << "Invalid input. Please enter a positive number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            m_monthlyDeposit = -1;
        }
    } while (m_monthlyDeposit < 0);

    do {
        std::cout << "Annual Interest (Compounded %): ";
        if (!(std::cin >> m_annualInterest) || m_annualInterest < 0) {
            std::cout << "Invalid input. Please enter a positive interest rate.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            m_annualInterest = -1;
        }
    } while (m_annualInterest < 0);

    do {
        std::cout << "Number of Years: ";
        if (!(std::cin >> m_numberOfYears) || m_numberOfYears <= 0) {
            std::cout << "Invalid input. Please enter a number of years greater than 0.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            m_numberOfYears = 0;
        }
    } while (m_numberOfYears <= 0);

    // Prompt mechanism requesting user verification before rendering final tracking reports
    std::cout << "Press any key to continue . . .";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

/**
 * Computes monthly interest accrual assuming zero mid-month account manipulation.
 */
void InvestmentCalculator::DisplayReportWithoutDeposits() const {
    const unsigned int TABLE_WIDTH = 60;
    PrintReportHeader(TABLE_WIDTH, "Balance and Interest Without Additional Monthly Deposits");

    double openingAmount = m_initialInvestment;
    // Converts e.g. 5% to decimal form (0.05) and divides by 12 to find the monthly metric
    double monthlyInterestRate = (m_annualInterest / 100.0) / MONTHS_IN_YEAR;

    // Forces stream manipulation to render exactly two decimal places for currency representations
    std::cout << std::fixed << std::setprecision(2);

    // Outer calculation loop processing structural years
    for (int year = 1; year <= m_numberOfYears; ++year) {
        double interestYearTotal = 0.0; // Instantiates tracking marker for annual summation

        // Inner tracking loop running calculations twelve times sequentially for each month
        for (int month = 1; month <= MONTHS_IN_YEAR; ++month) {
            // Formula specified in requirement doc: (Opening Amount + Deposited Amount) * Rate
            double interestMonth = openingAmount * monthlyInterestRate;
            interestYearTotal += interestMonth; // Track interest accumulated *this* year
            openingAmount += interestMonth;     // Update principal balance for next loop iteration
        }

        // Prints current row after month loop completes its 12th phase
        std::cout << std::left << std::setw(10) << year
                  << std::right << std::setw(22) << openingAmount
                  << std::right << std::setw(28) << interestYearTotal << std::endl;
    }
}

/**
 * Computes monthly interest accrual tracking regular, fixed monthly deposits.
 */
void InvestmentCalculator::DisplayReportWithDeposits() const {
    const unsigned int TABLE_WIDTH = 60;
    PrintReportHeader(TABLE_WIDTH, "Balance and Interest With Additional Monthly Deposits");

    double openingAmount = m_initialInvestment;
    double monthlyInterestRate = (m_annualInterest / 100.0) / MONTHS_IN_YEAR;

    std::cout << std::fixed << std::setprecision(2);

    // Outer calculation loop processing structural years
    for (int year = 1; year <= m_numberOfYears; ++year) {
        double interestYearTotal = 0.0;

        // Inner calculation loop running calculations monthly
        for (int month = 1; month <= MONTHS_IN_YEAR; ++month) {
            double totalAmount = openingAmount + m_monthlyDeposit; // Combine start amount and regular deposit
            double interestMonth = totalAmount * monthlyInterestRate; // Extract interest product
            interestYearTotal += interestMonth;
            openingAmount = totalAmount + interestMonth; // Update closing frame state
        }

        std::cout << std::left << std::setw(10) << year
                  << std::right << std::setw(22) << openingAmount
                  << std::right << std::setw(28) << interestYearTotal << std::endl;
    }
}
