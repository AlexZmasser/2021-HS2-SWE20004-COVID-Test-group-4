#include <iostream>     //Library for inputs/outputs.
#include <fstream>      //Library for inputs/outputs for stream.
#include <string>       //Library for string functionality.
#include <conio.h>      //Library for console input/output.
#include <sstream>      //Library for string stream classes.
#include <algorithm>    //Library for functions.
#include <windows.h>    //Lubrary for declarations for functions in windows API.

using namespace std;    //Defines scope.

void createPatient();    //Function prototype.
void covidResult();      //Function prototype.
void displayHotSpots();  //Function prototype.
void updatePatient();    //Function prototype.
void infectedRecord();   //Function prototype.   

ofstream patientDatabase;       //Opening a file in write mode.
ofstream symptomDatabase;       //Opening a file in write mode.
ofstream locationDatabase;      //Opening a file in write mode.

int main()  //Main function !ACTTING MENU!.
{
    string operation;   //Declearing veriable.
    int op = 0;             //Declearing veriable.
    int i = 0;          //Declearing and assigning veriable.


    while (op!=6)
    {
        operation.clear();  //Clear the string.
        cout << "Press 1 - Enter Details for COVID-19 Test Recommendation" << endl
            << "Press 2 - Submit Test Results" << endl
            << "Press 3 - Display Tier Exposure Sites" << endl
            << "Press 4 - Update Patient Details" << endl
            << "Press 5 - Display Positive Patient Details" << endl
            << "Press 6 - Exit" << endl
            << "Enter Number: ";        //Output statement.
        cin >> op;
        cin.get();

        /*getline(cin, operation);        //Read string that user inputs.
        stringstream toNum(operation);  //Object from class stringstream.
        toNum >> op; */                   //Object value of operation and stream it to integer op.

        if (1 > op || op > 6) //If input isn't within 1-6.
        {
            cout << endl << "Invalid Input Please Select 1-6" << endl << endl;  //Output statement.
            Sleep(1000);    //Waits 1 second.
        }
        switch (op)                     //Switch case structure using value op
        {
        case 1:                         //if op = 1 case 1 will run. 
            createPatient();            //Calling functions.
            break;                      //Break from the case.
        case 2:                         //if op = 2 case 2 will run. 
            covidResult();              //Calling functions.
            break;                      //Break from the case.
        case 3:                         //if op = 3 case 3 will run. 
            displayHotSpots();          //Calling functions.
            break;                      //Break from the case.
        case 4:                         //if op = 4 case 4 will run. 
            updatePatient();            //Calling functions.
            break;                      //Break from the case.
        case 5:                         //if op = 5 case 5 will run.
            infectedRecord();           //Calling functions.
            break;                      //Break from the case.
        case 6:
            cout << "Closing, Goodbye..." << endl;          //Output statement.
            break;                                          //Break from case.
        default:                                            //if none of the cases matches op then this will.
            cout << "Error 1: [Inside Default]" << endl;    //Error statement.
        }

    }    //Condition to repeat loop if number are outside range.



    system("pause");    //Pauses batch file.
    return 0;           //Return integer to the functions.
}

void createPatient()   //Function.
{

}

void covidResult()     //Function.
{

}

void displayHotSpots() //Function.
{

}

void updatePatient()   //Function.
{

}

void infectedRecord()  //Function.
{

}

