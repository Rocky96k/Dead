// Student Database: Bubble Sort (menu driven)
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student
{
    int id;
    char name[50];
    float cgpa;
};

// true if a must come after b for the chosen order
bool after(Student a, Student b, int choice)
{
    if (choice == 1) return strcmp(a.name, b.name) > 0; // Name A-Z
    if (choice == 2) return a.cgpa > b.cgpa;            // CGPA Ascending
    return a.cgpa < b.cgpa;                             // CGPA Descending
}

// Bubble sort on array s of size n
void bubbleSort(Student *s, int n, int choice)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (after(s[j], s[j + 1], choice))
            {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void display(Student *s, int n)
{
    cout << "\n=== Sorted Data ===\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nID: " << s[i].id << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "CGPA: " << s[i].cgpa << endl;
    }
}

int main()
{
    Student *s = NULL;
    int n = 0, choice;
    char ch;

    // Input students
    do
    {
        s = (Student *)realloc(s, (n + 1) * sizeof(Student)); // grow by one
        cout << "\nEnter Student ID: ";
        cin >> s[n].id;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(s[n].name, 50);
        cout << "Enter CGPA: ";
        cin >> s[n].cgpa;
        n++;
        cout << "Add more students? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    // Menu
    do
    {
        cout << "\n1. Sort by Name (A-Z)";
        cout << "\n2. Sort by CGPA (Ascending)";
        cout << "\n3. Sort by CGPA (Descending)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            bubbleSort(s, n, choice);
            display(s, n);
        }
        else if (choice == 4)
        {
            cout << "Exiting";
        }
        else
        {
            cout << "Input Invalid!";
        }
    } while (choice != 4);

    free(s);
    return 0;
}
