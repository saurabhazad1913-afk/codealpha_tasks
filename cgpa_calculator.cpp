#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int n;

    cout << "=====================================\n";
    cout << "         CGPA CALCULATOR\n";
    cout << "=====================================\n";

    cout << "Enter Number of Courses: ";
    cin >> n;

    vector<string> courseName(n);
    vector<int> grade(n);
    vector<int> credit(n);

    double totalCredits = 0;
    double totalGradePoints = 0;

    for(int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Course Name: ";
        cin >> courseName[i];

        cout << "Enter Grade Point (0-10): ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << "\n=====================================\n";
    cout << "           RESULT SUMMARY\n";
    cout << "=====================================\n";

    cout << left << setw(15) << "Course"
         << setw(15) << "Grade"
         << setw(15) << "Credits" << endl;

    cout << "-------------------------------------\n";

    for(int i = 0; i < n; i++)
    {
        cout << left << setw(15) << courseName[i]
             << setw(15) << grade[i]
             << setw(15) << credit[i] << endl;
    }

    cout << "-------------------------------------\n";
    cout << "Total Credits     : " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Final CGPA        : " << cgpa << endl;

    cout << "=====================================\n";

    return 0;
}
