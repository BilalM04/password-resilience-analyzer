# Password Resilience Analyzer - C Programming Project

The Password Resilience Analyzer is a C programming project designed to assess the strength of passwords against various attack strategies. This tool allows users to analyze the resilience of their passwords, providing insights into potential vulnerabilities and prompting the creation of stronger, more secure combinations.

## Project Objectives

The Password Resilience Analyzer aims to evaluate the strength of a password based on predetermined rules and guidelines. Users can test new passwords, view the strength of the last tested password, and exit the program through a user-friendly main menu interface.

## Features

### 1. Main Menu
- **Test a new password:** Allows users to enter a password for strength analysis.
- **View strength of the last tested password:** Displays the strength rating (Weak, Moderate, Strong) of the previously tested password.
- **Exit:** Closes the program.

### 2. Strength Tests
- Evaluates the password based on various criteria:
  - Presence of lowercase letters
  - Presence of uppercase letters
  - Numerical digits
  - Special characters such as !@#$%^&*()
  - Length (12+ characters)

### 3. Password Strength Score
- Computes the total strength score, ranging from 0 (weakest) to 5 (strongest).
- Adds a point to the score for each strength criterion met.

### 4. Output
- Categorizes the password based on the computed score:
  - 0-2 points: "Weak"
  - 3-4 points: "Moderate"
  - 5 points: "Strong"
