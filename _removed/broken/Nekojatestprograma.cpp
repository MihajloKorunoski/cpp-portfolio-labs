//------------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
using namespace std;
const char FILE_PATH[] = "E:\\iofile";
//------------------------------------------------------------------------------
struct Student
{
    char names [ 16 ];
    int other;
};
fstream MyFile ( FILE_PATH , ios :: binary | ios :: in | ios :: out );
void createFile();
void mainMenu();
void funcSwitch();
void addRecord();
int displayRecord();
void updateRecord();
void deleteRecord();
void printRecords();
int searchRecord();
//------------------------------------------------------------------------------
int main ( int argc, char* argv [] )
{
    createFile();
    mainMenu();
}
//------------------------------------------------------------------------------
void mainMenu()
{
    cout << "Welcome to School Enrolment System" << endl << endl
          << "Please enter your selection: " << endl
          << "1.   Register - New Student (Add record)" << endl
          << "2.   Look Up - Existing Student (Display record)" << endl
          << "3.   Change Details (Update record)" << endl
          << "4.   Remove Student (Delete record)" << endl
          << "5.   Show all Students (Print all)" << endl
          << "6.   Exit " << endl << endl
          << "Selection: ";
    funcSwitch();
}
//------------------------------------------------------------------------------
void funcSwitch()
{
   char choice;
    choice = getch();
    clrscr();
    while ( choice != 54 )
   {
      switch ( choice )
        {
         case '1' :
            addRecord();
            getch();
                clrscr();
               break;
         case '2' :
            displayRecord();
            getch();
               break;
         case '3' :
            updateRecord();
            getch();
               break;
         case '4' :
            deleteRecord();
            getch();
               break;
         case '5' :
            printRecords();
            getch();
               break;
         case '6' :
            break;
         default :
                cout << choice << " is not a vaild choice" << endl << endl
                      << "Press any key to choose again... ";
            getch();
                clrscr();
      }
      mainMenu();
        choice = getch();
        clrscr();
   }
}
//------------------------------------------------------------------------------
void addRecord()
{
    Student temp;
    cout << "Welcome new Student!" << endl
          << "We're going to set you up with a new Enrolment..." << endl
          << "All we need is a few details, let's begin: " << endl;
    cout << endl << "Please enter first name : ";
    cin >> temp.names;
    cout << endl << "Please enter your age : ";
    cin >> temp.other;
    MyFile.open ( FILE_PATH , ios :: binary | ios :: app | ios :: out );
    MyFile.clear();
    MyFile.write ( ( const char* ) &temp, sizeof ( Student ) );
    MyFile.clear();
    MyFile.close();
}
//------------------------------------------------------------------------------
int searchRecord()
{
    return 0;
}
//------------------------------------------------------------------------------
int displayRecord()
{
    Student temp;
    int age;
    int position;
    cout << "Enter age of person you are seeking: ";
    cin >> age;
    clrscr();
    MyFile.open ( FILE_PATH , ios :: binary | ios :: in );
    MyFile.clear();
    MyFile.seekp ( position * sizeof ( Student ), ios :: beg );
    MyFile.read ( ( char* ) &temp, sizeof ( Student ) );
    if ( age != temp.other )
    {
        cout << endl << "No record found. Press any key to continue...";
    }
    else
    {
        cout << "We found your record: " << endl << endl
              << "Name: " << temp.names << endl
              << "Age:  " << temp.other << endl;
    }
         cout << endl << "Press any key to continue..." << endl;
         getch();
         clrscr();
         mainMenu();
         MyFile.close();
         return 0;
}
//------------------------------------------------------------------------------
void updateRecord()
{
    Student temp;
    time_t t;
    char choice;
    int position;
    position = displayRecord ();
    MyFile.open( FILE_PATH, ios :: binary | ios :: out );
    MyFile.clear();
    if( position != -1 )
    {
        cout << endl << "Do you want to Update this Record( y or n )";
        choice = getch();
    }
    if( choice == 'y' )
    {
        cout << endl << "Enter name : ";
        cin >> temp.names;
        cout << endl << "And your age : ";
        cin >> temp.other;
        MyFile.open( FILE_PATH, ios :: binary | ios :: out );
        MyFile.clear();
        MyFile.seekp( position * sizeof( Student ), ios :: beg );
      MyFile.clear();
        MyFile.write( ( const char* ) &temp, sizeof( Student ) );
      MyFile.close();
    }
}
//------------------------------------------------------------------------------
void deleteRecord()
{
    Student temp;
    char choice;
    int position;
    -MyFile.open( FILE_PATH, ios :: binary | ios :: in | ios :: out );
    MyFile.clear();
    MyFile.seekp( position * sizeof( Student ), ios :: beg );
    MyFile.read( ( char* )&temp, sizeof( Student ) );
    cout << endl << endl;
    cout << "Would you like to delete this record? Yes (y) or No (n): ";
    cin >> choice;
    choice = getch();
    MyFile.seekp( position * sizeof( Student ), ios :: beg );
    MyFile.write( ( const char* )&temp, sizeof( Student ) );
    getch();
    clrscr();
    mainMenu();
    MyFile.close();
}
//-----------------------------------------------------------------------------
void printRecords()
{
    Student temp;
    MyFile.open ( FILE_PATH , ios :: binary | ios :: in );
    MyFile.clear();
    MyFile.read ( ( char* ) &temp, sizeof ( Student ) );
    while ( ! MyFile.eof() )
    {
        cout << "Name: " << temp.names << endl
              << "Age:  " << temp.other << endl << endl;
        MyFile.read ( ( char* ) &temp, sizeof ( Student ) );
    }
    cout << endl << "Press any key to continue back to main menu" << endl;
    getch();
    clrscr();
    mainMenu();
    MyFile.close();
}
//------------------------------------------------------------------------------
void createFile()
{
    if( ! MyFile )
    {
        MyFile.close();
        MyFile.open(FILE_PATH, ios::binary | ios::in | ios::out);
    }
    if ( ! MyFile )
    {
        cout << "File Error: File does not exist. Creating new file..."
              << endl << "Click to continue to main menu...";
        getch();
        clrscr();
    }
}
