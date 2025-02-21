#include <iostream>
#include <iomanip>
#include <limits> 
#include <cmath>    // For round function
using namespace std;

// Function prototypes
void calculateResults();
void displayResults(double percentage, double cgpa, char grade);
char getGrade(double percentage);
double getCGPA(double percentage);

int main() {
    char choice;
    
    do {
        system("cls");
        cout << "\n\t======= PAKISTAN CGPA CALCULATOR =======\n\n";
        calculateResults();
        
        cout << "\n\nDo you want to calculate again? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (tolower(choice) == 'y');
    
    cout << "\nThank you for using the calculator!\n";
    return 0;
}

void calculateResults() {
    double obtainedMarks, totalMarks;
    
    while (true) {
        cout << "Enter obtained marks: ";
        cin >> obtainedMarks;
        
        cout << "Enter total marks: ";
        cin >> totalMarks;
        
        if (totalMarks <= 0) {
            cout << "Error: Total marks must be greater than 0!\n";
            continue;
        }
        
        if (obtainedMarks < 0 || obtainedMarks > totalMarks) {
            cout << "Error: Obtained marks must be between 0 and total marks!\n";
            continue;
        }
        
        break;
    }
    
    double percentage = (obtainedMarks / totalMarks) * 100;
    double cgpa = getCGPA(percentage);
    char grade = getGrade(percentage);
    
    displayResults(percentage, cgpa, grade);
}

// Pakistan grading system with 4.0 scale
char getGrade(double percentage) {
    if (percentage >= 85) return 'A';
    if (percentage >= 80) return 'B+';
    if (percentage >= 75) return 'B';
    if (percentage >= 70) return 'C+';
    if (percentage >= 65) return 'C';
    if (percentage >= 60) return 'D';
    if (percentage >= 50) return 'E';
    return 'F';  // Below 50%
}

// CGPA calculation for Pakistani universities (4.0 scale)
double getCGPA(double percentage) {
    if (percentage >= 85) return 4.00;
    if (percentage >= 80) return 3.70;
    if (percentage >= 75) return 3.30;
    if (percentage >= 70) return 3.00;
    if (percentage >= 65) return 2.70;
    if (percentage >= 60) return 2.30;
    if (percentage >= 50) return 2.00;
    return 0.00;  // Fail
}

void displayResults(double percentage, double cgpa, char grade) {
    cout << fixed << setprecision(2);
    cout << "\n\n======= RESULTS =======";
    cout << "\nPercentage: " << percentage << "%";
    cout << "\nCGPA (4.0 scale): " << cgpa;
    cout << "\nGrade: " << grade;
    
    if (grade == 'F') {
        cout << " (Fail)";
    }
    
    cout << "\n=======================";
}
