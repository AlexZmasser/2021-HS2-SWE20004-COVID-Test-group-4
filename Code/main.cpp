/*Libraries */

#include <iostream>     //Library for inputs/outputs.
#include <iomanip>
#include <vector>
#include <cstring>
#include <fstream>      //Library for inputs/outputs for stream.
#include <string>       //Library for string functionality.
#include <limits>       //Library for defining numeric limits.
#include <sstream>      //Library for string stream classes.
#include <algorithm>    //Library for functions.
#include <ctime>

/*The define portion is created to formatting, how long a segment is and at space it is at a printed line  */

#define PATIENT_ID 4
#define NAME 35
#define DOB 11
#define ADRESS 35
#define DATE 17
#define TRAVEL 4
#define COVID_TEST 9
#define STATUS 6

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
void updateStatus();    //Function prototype.
void infectedRecord();   //Function prototype.
void patientEvaluation(string);
void displayAllPatients();
string dateAndTine();
void updateFile();

ofstream symptomDatabase;       //Opening a file in write mode.
ofstream locationDatabase;      //Opening a file in write mode.

int main()  //Main function !ACTTING MENU!.
{
    string operation;   //Declearing veriable.
    int op = 0;             //Declearing veriable.


    while (op != 7)
    {
        operation.clear();  //Clear the string.
        cout << "Press 1 - Enter Details for a new Patient" << endl
            << "Press 2 - Submit Test Results" << endl
            << "Press 3 - Display Tier Exposure Sites" << endl
            << "Press 4 - Update Patient Status" << endl
            << "Press 5 - Display Positive Patient Details" << endl
            << "Press 6 - Display All Patients" << endl
            << "Press 7 - Exit" << endl
            << "Enter Number: ";        //Output statement.
        cin >> op;
        cin.get();
        cout << endl;

        if (1 > op || op > 7) //If input isn't within 1-6.
        {
            cout << endl << "Invalid Input Please Select 1-6" << endl << endl;  //Output statement.
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
            updateStatus();            //Calling functions.
            break;                      //Break from the case.
        case 5:                         //if op = 5 case 5 will run.
            infectedRecord();           //Calling functions.
            break;                      //Break from the case.
        case 6:                         //if op = 5 case 5 will run.
            displayAllPatients();           //Calling functions.
            break;
        case 7:
            cout << "Closing, Goodbye..." << endl;          //Output statement.
            break;                                          //Break from case.
        default:                                            //if none of the cases matches op then this will.
            cout << "Error 1: [Inside Default]" << endl;    //Error statement.
        }
    }    //Condition to repeat loop if number are outside range.
    return 0;           //Return integer to the functions.
}

void createPatient()
{
    /* Creates Patient  */
    string name, adress, patientId, dob, date, travel, covid_test = "UNKN", status = "Alive";
    bool cont = true;
    char add;
    ofstream patientDatabase;       //Opening a file in write mode.
    patientDatabase.open("patientDatabase.text", ofstream::app);

    while (cont == true)
    {
        cout << "Please Enter the patient name : ";
        getline(cin, name);
        cout << "Please Enter " << name << "'s patient Id : ";
        getline(cin, patientId);
        cout << "Please Enter " << name << "'s adress : ";
        getline(cin, adress);
        cout << "Please enter " << name << " date of birth DD/MM/YYYY :";
        getline(cin, dob);
        
        date = dateAndTine();
        cout << "Did " << name << " travel overseas ? Yes/No :";
        getline(cin, travel);

        patientEvaluation(name);

        patientDatabase << std::left << setw(PATIENT_SPACE) << patientId << setw(NAME) << name << setw(DOB) << dob << setw(ADRESS) << adress << setw(DATE) << date << setw(TRAVEL) << travel << setw(COVID_TEST) << covid_test << setw(STATUS) << status;


        cout << "Patient Added !" << endl;
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
    cout<< endl << "<Hit enter to continue> " << endl ;
    getchar();
}

void covidResult()     //Function.
{
    /* Covid result lets you update the patient data base by searching via the patient ID. You can then change the result to ether Negative / Positive, the function then updates the main patient database. */
    string line, str1, str2, patientLookingfor, testReults;
    ifstream patientDatabase("patientDatabase.text");
    ofstream patientUpdate;
    patientUpdate.open("patientDatabaseUpdate.text");

    cout << "Please enter the Patient ID of the patient you wish to update the covid result :";
    cin >> patientLookingfor;
    cin.get();

    if (patientDatabase.is_open())
    {
        while (getline(patientDatabase, line))
        {
            str1 = line.substr(ID_START, 5);
            str2 = line.substr(NAME_SPACE, NAME);
            if (patientLookingfor.compare(str1) == 0)
            {
                cout << "Patient found! "<< str2 << endl;
                cout << "What is the coivd result of the patient ? Positive/Negative : ";
                getline(cin, testReults);
                                                      
                line.replace(COVID_TEST_SPACE, COVID_TEST, testReults+" ");
                patientUpdate << line << endl;
                
                cout << "Patient Updted "<< endl;

            }
            else
            {
                patientUpdate << line<< endl;
            }
        }
        patientDatabase.close();
    }
    else cout << "Unable to open file";
    
    updateFile();
    cout<< endl << "<Hit any key to continue> " << endl ;
    getchar();

}

void displayHotSpots() //Function.
{
    /*The displayHotSpot function displays the current Melbourne hot spot. The data saved on a .text file is read and added to a vector array. Then the user can enter new locations as needed */
    
    vector<string> hotSpot;// {"Melbourne Central", "Kew", "Melbourne Airport","Hawthorn","Richmond"};
    string line,newLocation;
    bool cont = true;
    char add;
    ifstream displayHotSpots("displayHotSpots.text");
    cout << "These are the current Hotspots :" << endl;
    if (displayHotSpots.is_open())
    {
        while (getline(displayHotSpots, line))
        {
            hotSpot.push_back(line);
            cout << line << endl;
        }
    }else cout << "Unable to open file";
    
    displayHotSpots.close();
    
    cout<< endl << "<Hit any key to continue> " << endl ;
    getchar();
    
    while (cont == true)
    {
        ofstream addHotSpots;
        addHotSpots.open("displayHotSpots.text", ofstream::app);
        cout << "Would you like to add another Hotspots? Y/N : ";
        cin >> add;
        cin.get();
        

        if (add == 'y' || add == 'Y')
        {
            cout << "What location would you like to add ?:";
            getline (cin,newLocation);
            addHotSpots << newLocation << endl;
            
            
            cont = true;
            
        }
        else if (add == 'n' || add == 'N')
        {
            cont = false;
        }
    }
    cout<< endl << "<Hit enter to continue> " << endl ;
    getchar();
    
}

void updateStatus()   //Function.
{
    /* Covid result lets you update the patient data base by searching via the patient ID. You can then change the result to ether Dead / Alive , the function then updates the main patient database. */
    string line, str1,str2, patientLookingfor, patientStatus;
    ifstream patientDatabase("patientDatabase.text");
    ofstream patientUpdate;
    patientUpdate.open("patientDatabaseUpdate.text");

    cout << "Please enter the Patient ID of the patient you wish to update the status :";
    cin >> patientLookingfor;
    cin.get();

    if (patientDatabase.is_open())
    {
        while (getline(patientDatabase, line))
        {
            str1 = line.substr(ID_START, 5);
            str2 = line.substr(NAME_SPACE, NAME);
            if (patientLookingfor.compare(str1) == 0)
            {
                cout << "Patient found! "<< str2 << endl;
                cout << "What is the coivd status of the patient ? Alive/Dead : ";
                getline(cin, patientStatus);
                                                      
                line.replace(STATUS_SPACE, STATUS, patientStatus);
                patientUpdate << line << endl;
                
                cout << "Patient Updted "<< endl;

            }
            else
            {
                patientUpdate << line<< endl;
            }
                

        }
        patientDatabase.close();
    }
    else cout << "Unable to open file";
    
    
    updateFile();
    cout<< endl << "<Hit enter to continue> " << endl ;
    getchar();


}


void infectedRecord()  //Function.
{
    /* Reads the data Base file and displays all the patients that have a positive covid test */
    string line,covid_test,result="Positive ";
    
    ifstream patientDatabase("patientDatabase.text");
    cout << std::left << setw(PATIENT_SPACE) << "Id " << setw(NAME) << "Name" << setw(DOB) << "DOB" << setw(ADRESS) << "Adress" << setw(DATE) << "Date" << setw(TRAVEL) << "Tra " << setw(COVID_TEST) << "Covid" << setw(STATUS) << "Status"<<endl;
    if (patientDatabase.is_open())
    {
        while (getline(patientDatabase, line))
        {
            covid_test = line.substr(COVID_TEST_SPACE, COVID_TEST);
            //cout << covid_test << endl ;
            if (covid_test.compare(result) == 0)
            {
                cout << line << endl;
            }
            
        }
    }
    cout<< endl << "<Hit enter to continue> " << endl ;
    getchar();



}
string dateAndTine()
{
    /* Used to get date in the format dd/mm/yyyy */
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d.%m.%Y ",timeinfo);
    string str(buffer);

    return str;
}


void patientEvaluation(string name)
{
    /* The function Patient evaluation works asking the user to input their symptoms and if they have visited any hot spots then if statements check the user input and displays the needed evaluation. This function Is called during patient creation  */
    string symptoms[10],input,line;
    int evaluation =0;
    char v;
    bool visit=false;
    vector<string> covidSymptoms,patientSymptoms;
    ifstream symptomsFile("Symptoms.text");
    
    if (symptomsFile.is_open())
    {
        while (getline(symptomsFile, line))
        {
            covidSymptoms.push_back(line);
            
        }

    }
    else cout << "Unable to open file";
    
    cout << "Covid Symptoms" << endl;
    for(int i=0; i < covidSymptoms.size(); i++)
        cout << covidSymptoms.at(i) << ", ";
    
    cout<< endl << "what are the symptoms of "<<name<<" ? enter 'end' for the next step: ";
    while (input!="end")
    {
        getline(cin,input);
        patientSymptoms.push_back(input);
        
        for(int i=0; i < covidSymptoms.size(); i++)
        {
            if (input.compare(covidSymptoms.at(i)) == 0)
                evaluation++;
            
        }
        
    }
    cout << endl;
    cout << "Has "<<name<<" visited any of these Hotspots ?Y/N" << endl;
    ifstream displayHotSpots("displayHotSpots.text");
    if (displayHotSpots.is_open())
    {
        while (getline(displayHotSpots, line))
        {
            cout << line << endl;
        }
    }else cout << "Unable to open file";
    
    cout << "Enter :";
    cin>>v;
    cin.get();
    
    if (v == 'y' || v == 'Y')
    {
        visit = true;
    }
    else if (v == 'n' || v == 'N')
    {
        visit = false;
    }
    
    cout << endl ;
    
    if (evaluation==0&&visit==false)
    {
        cout << name <<" is fine, and does not need to get tested or isolate." <<endl;
    }
    else if (evaluation>=3&&visit==false)
    {
        cout << name <<" needs to isolate at home for 14 days and watch for symptoms."<<endl;
    }
    else if (evaluation==0&&visit==true)
    {
        cout << name <<" needs to isolate at home for 14 days and watch for symptoms."<<endl;
    }
    else if (evaluation>=3&&visit==true)
    {
        cout << name << " needs to get a covid 19 test and isolate at home for 14 days !"<<endl;
    }
    cout << endl;
}


void updateFile()
{
    /* Updates the main data base by saving the new created changes to a temporary file and then the temporary  data base overwrite the main  database. */
    ifstream patientUpdate("patientDatabaseUpdate.text");
    ofstream patientDatabase;       //Opening a file in write mode.
    patientDatabase.open("patientDatabase.text");
    string line;
    
    if (patientUpdate.is_open())
    {
        while (getline(patientUpdate, line))
        {
            patientDatabase << line << endl;
        }
        patientDatabase.close();
    }
    else cout << "Unable to open file";
}
void displayAllPatients()
{
    /* reads the patientdata Displays all the patients */
    string line;
    cout << std::left << setw(PATIENT_SPACE) << "Id " << setw(NAME) << "Name" << setw(DOB) << "DOB" << setw(ADRESS) << "Adress" << setw(DATE) << "Date" << setw(TRAVEL) << "Tra " << setw(COVID_TEST) << "Covid" << setw(STATUS) << "Status"<<endl;
    
    ifstream patientDatabase("patientDatabase.text");
    if (patientDatabase.is_open())
    {
        while (getline(patientDatabase, line))
        {
            cout << line << endl;
        }
    }else cout << "Unable to open file";
    
    cout<< endl << "<Hit enter to continue> " << endl ;
    getchar();
}
