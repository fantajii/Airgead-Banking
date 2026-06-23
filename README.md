# Airgead Banking App

An interactive financial analysis tool developed in C++ for Airgead Banking. This application allows users to input investment details—initial capital, monthly deposits, annual interest rates, and investment terms—to generate comprehensive compound interest reports both with and without additional monthly contributions.

## Project Overview

### Problem Solved
Airgead Banking required a reliable, accurate, and user-friendly command-line application to help clients visualize the long-term growth of their investments. The program bridges the gap between complex financial calculations and actionable client insights by modeling compound interest over time and displaying the data in structured, easy-to-read annual breakdowns.

### Key Features
* **Dynamic Data Input:** Captures user investment parameters securely via a clean command-line interface.
* **Dual-Report Generation:** Calculates and displays year-end balances and earned interest under two distinct scenarios: without additional monthly deposits and with additional monthly deposits.
* **Industry-Standard Formatting:** Outputs clear, aligned tabular data tracking month-by-month compounding scaled up to an annual overview.

---

## Performance Reflection

### What I Did Particularly Well
* **Object-Oriented Design** I implemented a robust, modular design by separating the logic into dedicated `Investment` or `Calculator` classes. This encapsulation ensured that financial calculations remained independent of the user interface logic.
* **Input Validation:** I engineered thorough input validation loops to handle invalid data types (e.g., strings entered where numbers were expected) and negative values, ensuring the application remains crash-resistant.

### Code Enhancements & Future Improvements
While the program successfully fulfills all functional requirements, it could be enhanced in the following ways to improve security, efficiency, and robustness:
1.  **Data Type Precision:** Transitioning from standard floating-point types (`double`/`float`) to an integer-based cents approach or a dedicated fixed-point library to completely eliminate any potential floating-point rounding errors inherent to financial computing.
2.  **Input Robustness:** Implementing more advanced `std::cin` clearing and ignoring techniques to handle malicious or massive buffer overflows, making the application more secure against unexpected user inputs.
3.  **File I/O Integration:** Adding the ability to export the generated reports to external `.csv` or `.txt` files for client records, enhancing usability.

### Challenges and Solutions
* **The Challenge:** Managing the precise monthly compounding formulas inside a loop while correctly accumulating the annual interest totals for the final display.
* **The Resolution:** I overcame this by breaking the problem down on paper first, mapping out the mathematical progression month by month. I utilized standard debugging techniques, printing intermediate values to the console to ensure the code's math precisely matched manual calculations.
* **Support Network:** Through this process, I expanded my technical support network by utilizing official C++ documentation (`cppreference.com`), participating in peer code reviews, and leveraging structured flowcharting tools to map program execution logic before writing code.

### Transferable Skills
* **Object-Oriented Programming (OOP) in C++:** Building this project solidified my understanding of class structures, access modifiers, setters/getters, and object instantiation, which will directly translate to future software engineering courses and industry roles.
* **Algorithmic Logic:** Developing the loop architectures required to simulate compounding timelines sharpened my general algorithmic thinking and problem-solving framework.

### Maintainability, Readability, and Adaptability
To ensure the codebase aligns with industry standards, I focused on the following pillars of clean code:
* **Readability:** Followed a strict, consistent naming convention (camelCase/snake_case) for variables and functions, combined with expressive naming that clearly defines the purpose of each identifier.
* **Documentation:** Utilized clear header blocks for functions and classes, alongside purposeful inline comments explaining *why* certain logic was implemented, rather than just *what* the line does.
* **Maintainability & Adaptability:** Hardcoded constants were avoided in favor of configurable class variables, meaning interest calculation rules or reporting formats can be updated easily in a single location without breaking the application logic.
