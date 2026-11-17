// Student Database: Selection Sort (menu driven)
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

// Selection sort on array t of size n
void selectionSort(Student *t, int n, int choice)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (after(t[min], t[j], choice))
                min = j;
        Student temp = t[i];
        t[i] = t[min];
        t[min] = temp;
    }
}

void display(Student *t, int n)
{
    cout << "\nID\tName\tCGPA\n";
    for (int i = 0; i < n; i++)
        cout << t[i].id << "\t" << t[i].name << "\t" << t[i].cgpa << endl;
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
            selectionSort(s, n, choice);
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