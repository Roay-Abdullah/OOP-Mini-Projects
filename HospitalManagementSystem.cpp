#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
class Date
{
public:
    int day;
    int month;
    int year;

    Date(int, int, int);
};
Date::Date(int d = 0, int m = 0, int y = 0)
{
    day = d;
    month = m;
    year = y;
}
class Hospital
{
private:
    struct Patients
    {
        string name;
        Date DoA;
        string depart;
        Date DoD;

    } patients[10];

    static int count;

public:
    void deletePatient(string);
    void displayPatient();
    void insertPatient(string, Date, string, Date);
};

int Hospital::count = 0;

void Hospital::deletePatient(string Name)
{
    for (int i = 0; i < count; i++)
    {
        if (Name == patients[i].name)
        {
            for (int j = i; j < count - 1; j++)
            {
                patients[j] = patients[j + 1];
            }
            count--;
            cout << "Patient deleted successfully." << endl;
            return;
        }
    }
    cout << "Patient not found!" << endl;
}
void Hospital::insertPatient(string Name, Date DoA, string Depart, Date DoD)
{
    if (count < 10)
    {
        patients[count] = { Name, DoA, Depart, DoD };
        count++;
        cout << "Patient added successfully!" << endl;
    }
    else
    {
        cout << "Hospital is full." << endl;
    }
    cout << "Total number of registered patients: " << count << endl;
}
void Hospital::displayPatient()
{
    if (count == 0)
    {
        cout << "No patients registered." << endl;
        return;
    }
    for (int i = 0; i < count; i++)
    {
        cout << "Name: " << patients[i].name
            << ", Admission Date: " << patients[i].DoA.day << "/" << patients[i].DoA.month << "/" << patients[i].DoA.year
            << ", Department: " << patients[i].depart
            << ", Discharge Date: " << patients[i].DoD.day << "/" << patients[i].DoD.month << "/" << patients[i].DoD.year << endl;
    }
}
int main() {
    Hospital hospital;
    string Name, Depart;
    int d, m, y, cho;

    system("color 1F");

    do
    {
        system("cls");

        cout << "                          Menu                                " << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "1. Remove a patient:" << endl;
        cout << "2. Display the patients:" << endl;
        cout << "3. Insert a new patient and total number of patients:" << endl;
        cout << "4. Exit" << endl;
        cout << "Input: ";
        cin >> cho;

        switch (cho)
        {
        case 1:
            cout << "Enter the name of the patient: ";
            cin >> Name;
            hospital.deletePatient(Name);
            break;

        case 2:
            hospital.displayPatient();
            break;

        case 3:
        {
            cout << "Enter the patient's name: ";
            cin >> Name;
            cout << "Enter the date of admission (day month year): " << endl;
            cout << "Day: ";
            cin >> d;
            cout << "Month: ";
            cin >> m;
            cout << "Year: ";
            cin >> y;
            Date DoA(d, m, y);
            cout << "Enter the department: ";
            cin >> Depart;
            cout << "Enter the date of discharge (day month year): " << endl;
            cout << "Day: ";
            cin >> d;
            cout << "Month: ";
            cin >> m;
            cout << "Year: ";
            cin >> y;
            Date DoD(d, m, y);

            hospital.insertPatient(Name, DoA, Depart, DoD);
            break;

        }
        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Input." << endl;
        }

        system("pause");

    } while (cho != 4);

    return 0;
}
