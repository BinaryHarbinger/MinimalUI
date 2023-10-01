#include "MyLib.h"

#include <ctime>

using namespace std ;

string username = "unknown" ; //Some variable values like username
int clockMode = 0 ; //I will delete thaaat
int user = 0 ; // I forgot about it
bool Logged = false ; // It' s for checking you are logged or not
bool DevMode = false ; // There is nothing for you just do NOT press E + F when you are on Logg Screen
int CurrentInterface = 0 ; // That variable for parameters function function use that variable for which mode you are on like User Settings, Main Interface etc. 
bool opSelected = false ; // It says if you selected a option with your keys (1,2,3,4,5 or esc) then while loop will stop for a 'while'
bool OptionsDisabled = true ; // It will disable helping senteces like choose app or option



#ifdef _WIN32 //that part detects which Operating System are you using
const std::string OS_NAME = "Windows" ;
#elif __linux__
const std::string OS_NAME = "Linux" ;
#else
const std::string OS_NAME = "Other" ;
#endif

void clear () // It clears the terminal (Definetly I wrote it)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int ChangeUser (int& user) // This will be inactive for a while
{
    user = user + 1 ;
    return user ;
}

bool LogScreen (bool& Logged) //Logg screeen itself
{
    cout << endl << yellow << "Welcome to MinimalUI" << endl << endl
    << green << "Press Space to Login as " << blue << username << white <<  endl ;
    cout << endl << "(Isn't it your username? Press X to change User)" ;
    while (Logged == false)
    {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            Logged = true ;
            clear () ;
            cout << endl << green << "Logged as " << username << white ;
            Sleep (2000) ;
            OptionsDisabled = false ;
        }
        else if (GetAsyncKeyState('X') & 0x8000)
        {
            clear () ;
            Sleep(100) ;
            cout << endl << yellow << "Welcome to MinimalUX" << endl << endl
            << green << "Press Space to Login as " << blue << username << white <<  endl ;
            cout << endl << "(Isn't it your username? Press X to change User)" ;
        }
        else if (GetAsyncKeyState('E') && GetAsyncKeyState('F') & 0x8000)
        {
            DevMode = !DevMode ;
        }
        Sleep(150);
    }
    clear () ;
    CurrentInterface = 1 ;
    return CurrentInterface ;
    return Logged ;
    return DevMode ;
}

void parameters(int& CurrentInterface) //Parameters for every Screen (Except Logg Screen)
{
    clear ();
    cout << endl << yellow << "Minimal UI Version: " << red << "Alpha 1.1 " << white << "/ Current OS is " ;
    if (OS_NAME == "Windows")
    {
        cout << blue << "Windows" << white ;
    }
    else if (OS_NAME == "Linux")
    {
        cout << yellow << "Linux" << white;
    }
    else
    {
        cout << red << "Unknown" << white;
    }
    cout << endl << endl << green << "Logged as " << blue << username << endl << endl << endl << white;
    if (DevMode)
    {
        cout << blue << "Developer Mode Enabled" << endl << endl << red <<"CurrentInterfaceValue:" << CurrentInterface << white  ;
        jump (1) ;
    }
    if (OptionsDisabled)
    {

    }
    else if (CurrentInterface != 0)
    {
        string CurrentOption = "" ;
        if (CurrentInterface == 1)
        {
            cout << green << "1 - Applications" << white << "         2 - None Content         3 - None Content" << endl << endl ;
            CurrentOption = "an option";
        }
        else if (CurrentInterface == 2)
        {
            cout << white << "1 - Minimal File Manager" << red << " (Not inclueded in this version)" << white ;
            jump (1) ;
            cout << "2 - Clock" ;
            jump (1) ;
            CurrentOption = "Applications" ;
        }
        else if (CurrentInterface == 3)
        {
            cout << white << "1 - Change User Name" << red << "(It won't saves the new name)" << white << endl << endl 
            <<  "2 - None Content" << endl << endl << "3 - None Content" << endl << endl ;
            CurrentOption = "an option" ;
        }
        cout << "Press numbers for choosing " << CurrentOption  ;
    }
    if (CurrentInterface != 1 && OptionsDisabled == false)
    {
        cout << "         Press ESC for exit to Main Menu" ;
        jump (1) ;
    }
    else
    {
        cout << endl ;
    }
}

int clockFunction (int clockMode) //a clock function for Log Screen and App (I will delete Logg Screen Part)
{
    OptionsDisabled = true ;
    while (GetAsyncKeyState(VK_ESCAPE) == false && 0x8000) 
    {
        parameters (CurrentInterface) ;
        std::time_t currentTime;
        std::time(&currentTime);

        struct tm *localTime = std::localtime(&currentTime);

        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;
        int second = localTime->tm_sec;
        if (clockMode = 0)
        {
            cout << "It's " << hour << "." << minute ;
        }
        else
        {
            cout << "Hold Escape to Return Applications Menu" ;
            jump (1) ;
            cout << hour << "." << minute << "." << second << std::endl;
            Sleep (1000) ; // Update's it in every seconds
            clear () ;
        }
        
    }
    OptionsDisabled = false ;
    return OptionsDisabled ;
}
int options() //Main Code that detects your inputs (btw there is a delay for your cpu's health)
{
    while (opSelected != true)
    {
        if (GetAsyncKeyState('1') & 0x8000)
        {
            opSelected = true ;
            if (CurrentInterface == 1)
            {
                cout << endl << green << "Applications Opening..." ;
                Sleep(1000) ;
                clear () ;
                cout << endl << "Applications Opening..." << white ;
                Sleep (2000) ;
                CurrentInterface = 2 ;
            }
            else if (CurrentInterface == 2)
            {
                cout << endl << green << "Minimal File Manager is opening..." ;
                Sleep(3000) ;
                clear () ;
                cout << endl << red << "Error Minimal File Manager isn't included int this version" << white ;
                bool GetSpace = false ;
                SpaceWait () ;
            }
        }
        else if (GetAsyncKeyState('2') & 0x8000)
        {
            opSelected = true ;
            if (CurrentInterface == 1)
            {
                cout << "User Settings" ;
            }
            else if (CurrentInterface = 2)
            {
                jump (1) ;
                cout << green << "Clock App Opening..." ;
                Sleep (1000) ;
                clear () ;
                jump (0) ;
                cout << green << "Clock App Opening..." << white ;
                clockFunction (1) ;
            }
        }
        else if (GetAsyncKeyState('3') & 0x8000)
        {
            opSelected = true ;
            cout << "None Content" ;
        }
        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            opSelected = true ;
            if (CurrentInterface = 1)
            {
                Logged = false ;
            }
            else
            {
                opSelected = true ;
                CurrentInterface = 1 ;
            }
        }
        Sleep(100) ;
    }
    return CurrentInterface ;
}

int mainInterface (int &CurrentInterface)
{
    parameters(CurrentInterface) ;
    options() ;
    opSelected = false ;
    return opSelected ;
    return CurrentInterface ;
}

int main()
{
    while (true)
    {
        if (Logged==false)
        {
            LogScreen(Logged) ;
            clear () ;
        }
        else
        {
            mainInterface (CurrentInterface) ;
            clear () ;
        }
    }
    return 0;
}
