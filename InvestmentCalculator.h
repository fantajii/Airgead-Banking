/**
* @file InvestmentCalculator.h
 * @author Garrett Mandeville
 * @date 06/06/2026
 * @brief Class definition for the Airgead Banking compound interest simulator.
 * * This header file declares the InvestmentCalculator class structure, wrapping
 * member variables for financial state and exposing public methods for UI/calculation.
 */

#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

#include <string>

class InvestmentCalculator {
private:
    // Member variables mapping to the application's required data fields
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

    // Constant to eliminate "Magic Numbers" throughout financial calculations
    const int MONTHS_IN_YEAR = 12;

    /**
     * @brief Formats and displays a standardized table header.
     * @param t_tableWidth Total character width of the table border.
     * @param t_title The specific string title to center over the table data.
     */
    void PrintReportHeader(const unsigned int t_tableWidth, const std::string t_title) const;

public:
    /**
     * @brief Default constructor initializing all numeric values to 0.
     */
    InvestmentCalculator();

    /**
     * @brief Displays the data input screen and captures validated data streams.
     */
    void PromptUserForInputs();

    /**
     * @brief Computes and prints static year-end balances assuming NO monthly inputs.
     */
    void DisplayReportWithoutDeposits() const;

    /**
     * @brief Computes and prints static year-end balances incorporating monthly inputs.
     */
    void DisplayReportWithDeposits() const;
};

#endif // INVESTMENT_CALCULATOR_H