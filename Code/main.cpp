#include <iostream>     //Library for inputs/outputs.
#include <iomanip>
#include <vector>
#include <cstring>
#include <fstream>      //Library for inputs/outputs for stream.
#include <string>       //Library for string functionality.
#include <limits>       //Library for defining numeric limits.
#include <sstream>      //Library for string stream classes.
#include <algorithm>    //Library for functions.

#define PATIENT_ID 4
#define NAME 35
#define DOB 11
#define ADRESS 35
#define DATE 11
#define TRAVEL 3
#define COVID_TEST 8
#define STATUS 5

#define ID_START 0
#define PATIENT_SPACE 10
#define NAME_SPACE (PATIENT_SPACE)
#define DOB_SPACE (NAME_SPACE + NAME)
#define ADRESS_SPACE (DOB_SPACE + DOB)
#define DATE_SPACE (ADRESS_SPACE + ADRESS)
#define TRAVEL_SPACE (DATE_SPACE + DATE)
#define COVID_TEST_SPACE (TRAVEL_SPACE + TRAVEL)
#define STATUS_SPACE (COVID_TEST_SPACE + COVID_TEST)


using namespace std;    //Defines scope.

void createPatient();    //Function prototype.
void covidResult();      //Function prototype.
void displayHotSpots();  //Function prototype.
void updatePatient();    //Function prototype.
void infectedRecord();   //Function prototype.
void patientEvaluation();

ofstream symptomDatabase;       //Opening a file in write mode.
ofstream locationDatabase;      //Opening a file in write mode.

string Patient_id, name, dob, adress, date;
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
        system("CLS");
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
    
    //system("clear");
    string name, courseDetails, units, grades, StudentId;
    bool cont = true;
    char add;
    int unitNumber;
    ofstream patientDatabase;       //Opening a file in write mode.
    patientDatabase.open("patientDatabase.text", ofstream::app);

    while (cont == true)
    {
        cout << "Please Enter the studens full name : ";
        getline(cin, name);
        cout << "Please Enter " << name << "'s Student Id : ";
        getline(cin, StudentId);
        cout << "Please Enter " << name << "'s course details : ";
        getline(cin, courseDetails);
        cout << "How many Units does " << name << " have ?";
        cin >> unitNumber;
        cin.get();

        patientDatabase << left <<setw(PATIENT_ID) << name << setw(12) << StudentId << setw(20) << courseDetails << endl <<
            left << setw(20) << "Units " << setw(12) << "Grades " << endl;
        for (int i = 1;i <= unitNumber;i++)
        {
            cout << "Please Enter " << name << " unit " << i << ":";
            getline(cin, units);
            cout << "Please Enter " << name << " grade for " << units << " : ";
            getline(cin, grades);
            patientDatabase << left << setw(20) << units << setw(12) << grades << endl;
        }

        cout << "Student Added !" << endl;
        cout << "Would you like to add another? Y/N : ";
        cin >> add;
        cin.get();
        if (add == 'y' || add == 'Y')
        {
            cont = true;
        }
        else if (add == 'n' || add == 'N')
        {
            cont = false;
        }
        patientDatabase << endl;
    }
    

}

void covidResult()     //Function.
{

}

void displayHotSpots() //Function.
{
    vector<string> hotSpot; // {"Melbourne Central", "Kew", "Melbourne Airport","Hawthorn","Richmond"};
    ofstream displayHotSpots;
    displayHotSpots.open("displayHotSpots.text", ofstream::app);
    cout <<"These are the current Hotspots :"<<endl;
    
    
    for(int i = 0; i <hotSpot.size() ; i++)
    {
        displayHotSpots << hotSpot[i] << endl;
        cout << hotSpot[i] << endl;
    }


}

void updatePatient()   //Function.
{

}

void infectedRecord()  //Function.
{

}

