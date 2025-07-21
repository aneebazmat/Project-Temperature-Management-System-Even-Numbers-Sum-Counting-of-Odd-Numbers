// #include<iostream>
// #include<iomanip>
// #include<fstream>
// #include<string>
// using namespace std;
//
// int main()
//{
//
//     cout << "************** PF LAB FINAL *****************" << endl;
//     cout << "\n";
//     cout << "Name : Hafiz Aneeb Azmat" << endl;
//     cout << "Roll NO : SP25-BCS-039" << endl;
//     cout << "Section : C" << endl;
//     cout << "\n";
//
//
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <iomanip>

void display();
void getInput(int array[], int size);
float evenSum(int *array, int size);
int oddNumbers(int *array, int size);
void displayresult(float evenTOTAL, int oddNUMBERS);
void getTemperature(int array[], int size);
float total(int array[], int size);
float average(float TOTAL, int days, int size);
int aboveAverageDays(int array[], float AVERAGE, int size);
float highest(int array[], int size);
float lowest(int array[], int size);
void DisplayResult(int array[], float AVERAGE, int aboveAverage, float HIGHEST, float LOWEST, int size);
void storeInFile(int array[], float AVERAGE, int aboveAverage, float HIGHEST, float LOWEST, int size);

using namespace std;
int main()
{
    display();
    char choice;
    cout << "Enter choice ( X / Y ) : ";
    cin >> choice;
    switch (choice)
    {

    case 'X':
    case 'x':
    {
        int days;
        cout << "Enter number of days to record temperature record (maximum 100) : ";
        cin >> days;

        int size = days;
        float TOTAL;
        float AVERAGE;
        int aboveAverage;
        float HIGHEST;
        float LOWEST;
        int array[size] = {};
        getTemperature(array, size);
        TOTAL = total(array, size);
        AVERAGE = average(TOTAL, days, size);
        aboveAverage = aboveAverageDays(array, AVERAGE, size);
        HIGHEST = highest(array, size);
        LOWEST = lowest(array, size);
        DisplayResult(array, AVERAGE, aboveAverage, HIGHEST, LOWEST, size);
        storeInFile(array, AVERAGE, aboveAverage, HIGHEST, LOWEST, size);

        break;
    }

    case 'Y':
    case 'y':
    {
        int size;
        float evenTOTAL;
        int oddNUMBERS;

        cout << "Enter number of elemets( size ) of an array : ";
        cin >> size;

        int array[size] = {};
        getInput(array, size);
        evenTOTAL = evenSum(array, size);
        oddNUMBERS = oddNumbers(array, size);
        displayresult(evenTOTAL, oddNUMBERS);

        break;
    }
    }

    return 0;
}

// Funtion to display Menu

void display()
{
    cout << "\n";
    cout << "********** PF FINAL LAB **************" << endl;
    cout << "\n";
    cout << "Press X to execute part A" << endl;
    cout << "Press Y to execute part B" << endl;
    cout << "\n";
    cout << "X) Part A " << endl;
    cout << "Y) Part B " << endl;
}

// Function to get input

void getInput(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int value;
        do
        {
            cout << "Enter element " << (i + 1) << " : ";
            cin >> value;
            if (value < 0)
            {
                cout << "Please enter positive value ( > 0) : ";
                cin.clear();
                cin.ignore(100, '\n');
                cin >> value;
            }
        } while (value < 0);

        array[i] = value;
    }
}

// Function to find array of even elements

float evenSum(int *array, int size)
{
    float total;
    int *arrayptr = array;
    for (int i = 0; i < size; i++)
    {
        if (*(arrayptr + i) % 2 == 0)
        {
            total += *(arrayptr + i);
        }
    }
    return total;
}

// Function to count odd number

int oddNumbers(int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}

void displayresult(float evenTOTAL, int oddNUMBERS)
{
    cout << "The sum of all even numbers in Array : " << evenTOTAL << endl;
    cout << "Total odd numbers in Array : " << oddNUMBERS << endl;
    return;
}

void getTemperature(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int value;
        do
        {
            cout << "Enter temperature (in Celcius) for day " << (i + 1) << " : ";
            cin >> value;
            if (value < 50  || value > 60)
            {
                cout << "Please enter temperature between ( 50 - 60) : ";
                cin.clear();
                cin.ignore(100, '\n');
                cin >> value;
            }
        } while (value < 50  || value > 60);

        array[i] = value;
    }
}

float total(int array[], int size)
{
    float Total = 0;
    for (int i = 0; i < size; i++)
    {
        Total += array[i];
    }
    return Total;
}

float average(float TOTAL, int days, int size)
{
    float Average = 0;
    for (int i = 0; i < size; i++)
    {
        Average += TOTAL / days;
    }
    return Average;
}

int aboveAverageDays(int array[], float AVERAGE, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > AVERAGE)
            ;
        count++;
    }
    return count;
}

float highest(int array[], int size)
{
    float max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

float lowest(int array[], int size)
{
    float min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

void DisplayResult(int array[], float AVERAGE, int aboveAverage, float HIGHEST, float LOWEST, int size)
{
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Temperature for day " << (i + 1) << " : " << array[i] << endl;
    }
    cout << "\n";
    cout << "Average Temperature : " << AVERAGE << endl;
    cout << "Number of days above average : " << aboveAverage << endl;
    cout << "Highest temperature :  " << HIGHEST << endl;
    cout << "Lowest Temperature :  " << LOWEST << endl;
    cout << "\n";
}

void storeInFile(int array[], float AVERAGE, int aboveAverage, float HIGHEST, float LOWEST, int size)
{
    ofstream outFile;
    outFile.open("temp_report.txt");

    if (!outFile)
    {
        cout << "Invalid File opening.Please open correct file." << endl;
        return;
    }
    else
    {

        for (int i = 0; i < size; i++)
        {
            outFile << "Temperature for day " << (i + 1) << " : " << array[i] << endl;
        }
        outFile << "Average Temperature : " << AVERAGE << endl;
        outFile << "Number of days above average : " << aboveAverage << endl;
        outFile << "Highest temperature :  " << HIGHEST << endl;
        outFile << "Lowest Temperature :  " << LOWEST << endl;
    }
}
