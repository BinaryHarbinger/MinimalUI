#pragma once

#include <iostream>

#include <Windows.h>

using namespace std ;

inline std::ostream& blue(std::ostream &s)
{
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
| FOREGROUND_GREEN | FOREGROUND_INTENSITY);
return s;
}
 
inline std::ostream& red(std::ostream &s)
{
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdout,
FOREGROUND_RED | FOREGROUND_INTENSITY);
return s;
}
 
inline std::ostream& green(std::ostream &s)
{
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdout,
FOREGROUND_GREEN | FOREGROUND_INTENSITY);
return s;
}
 
inline std::ostream& yellow(std::ostream &s)
{
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdout,
FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
return s;
}
 
inline std::ostream& white(std::ostream &s)
{
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdout,
FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
return s;
}
 
struct color {
color(WORD attribute) :m_color(attribute) {};
WORD m_color;
};
 
template <class _Elem, class _Traits>
std::basic_ostream<_Elem, _Traits>&
operator<<(std::basic_ostream<_Elem, _Traits>& i, color& c)
{
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdout, c.m_color);
return i;
}

void SpaceWait ()
{
    bool GetSpace = false ;
    cout << endl << endl << red << "Press Space to Continue" << white << endl ;
    while (GetSpace == false)
    {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            GetSpace = true ;
        }
        Sleep (100) ;
    }
}

void jump (int jumpcount)
{
    cout << endl ;
    while (jumpcount != 0)
    {
        cout << endl ;
        jumpcount -= 1 ;
    }
}