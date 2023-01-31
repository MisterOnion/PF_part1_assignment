// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT7L
// Names: Lim Sir Yuean | HARRISH NAIR A/L RAMESH | Meor Imran Najmuddin
// IDs: 1211307746 | 1211103981 | 1211101518
// Emails: 1211307746@student.mmu.edu.my | 1211103981@student.mmu.edu.my | 1211101518@student.mmu.edu.my
// Phones: 01113070602 | 0163381763 | 0177699497
// *********************************************************

// TODO: Make the game menu and game board for part 1

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time()
#include <iomanip> // for setw()
using namespace std;

// CHANGE SETTINGS (Lim Sir Yuean)
void changeSettings(int &x_axis, int &y_axis, int &zombies)
{
    cout << "|*****************************************| " << endl;
    cout << "|              Board Settings             |" << endl;
    cout << "|*****************************************|" << endl;
    cout << endl;
    cout << " Please enter odd numbers only. " << endl;
    cout << " Enter number of board rows     =>  ";
    cin >> x_axis;

    // Check if the x-axis dimension is an odd number
    while (x_axis % 2 == 0)
    {
        cout << "Please enter odd numbers only." << endl;
        cout << "Enter number of rows: ";
        cin >> x_axis;
    }

    cout << " Enter number of board columns  =>  ";
    cin >> y_axis;

    // Check if the y-axis dimension is an odd number
    while (y_axis % 2 == 0)
    {
        cout << "Please enter odd numbers only." << endl;
        cout << "Enter number of columns: ";
        cin >> y_axis;
    }

    cout << "|*****************************************| " << endl;
    cout << "|             Zombies Settings            |" << endl;
    cout << "|*****************************************|" << endl;
    cout << " Enter number of zombies        =>  ";
    cin >> zombies;
    cout << endl;
    cout << " Settings Updated." << endl;
}

// CREATE BOARD
void createBoard(int x_axis, int y_axis)
{
    // Initialize the game board with empty spaces
    cout << "################################" << endl;
    cout << " ...::: Alien vs Zombie :::... " << endl;
    cout << "################################" << endl;
    char board[x_axis][y_axis];
    for (int i = 0; i < x_axis; i++)
    {
        for (int j = 0; j < y_axis; j++)
        {
            board[i][j] = '-';
        }
    }

    // Place the Alien at the center of the game board
    int centerRow = x_axis / 2;
    int centerCol = y_axis / 2;
    board[centerRow][centerCol] = 'A';

    // board.resize(y_axis); make a class for characters

    // char objects[] = {' ', ' ', ' ', ' ', ' ', 'h', '>', 'p', 'r', '<', '^'};
    // int noOfObjects = 10;// number of objects in the objects array

    // Display the board
    if (x_axis >= 10 || y_axis >= 10)
    {
        cout << " ";
        for (int i = 1; i <= y_axis; i++) //+1
        {
            cout << i % 10 << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < x_axis; i++)
    {
        cout << " ";
        for (int j = 0; j < y_axis; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (y_axis - i);
        // display the border
        for (int j = 0; j < y_axis; ++j)
        {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
}

// DEFAULT SETTINGS
void displayMainMenu(int x_axis, int y_axis, int zombie)
{
    char answer;
    cout << " __________________________________________" << endl;
    cout << "|          Default Game Settings          |" << endl;
    cout << "|_________________________________________|" << endl;
    cout << "|                                         |" << endl;
    cout << "|   Number of Board Rows     =>  " << x_axis << "        |" << endl;
    cout << "|   Number of Board Columns  =>  " << y_axis << "        |" << endl;
    cout << "|   Number of Zombies        =>  " << zombie << "        |" << endl;
    cout << "|_________________________________________|" << endl;
    cout << endl;
    cout << " Do you want to change the settings? (y/n) => ";
    cin >> answer;
    answer = toupper(answer);
    if (answer == 'Y')
    {
        changeSettings(x_axis, y_axis, zombie);
        displayMainMenu(x_axis, y_axis, zombie);
    }
    else if (answer == 'N')
    {
        cout << "Let's play" << endl;
    }
    else
    {
        cout << "Input Error!" << endl;
        cout << endl;
        displayMainMenu(x_axis, y_axis, zombie);
    }
}

int main()
{
    int x_axis; // board of rows
    cout << "Enter number of board rows(odd numbers only):";
    cin >> x_axis;
    int y_axis; // board of column
    cout << "Enter number of board columns(odd numbers only):";
    cin >> y_axis;
    int zombie; // the number of zombies
    cout << "Enter number zombie:";
    cin >> zombie;
    displayMainMenu(x_axis, y_axis, zombie);
    createBoard(x_axis, y_axis);
    return (0);
}