#pragma once

#include <iostream>

#include <Windows.h>

using namespace std ;

inline std::ostream& blue(std::ostream &s) // I took that part from Libary Called ConsoleColor you can took it too if you want look for down
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
}            // Here is where the ConsoleColor Library ends. If you want to use it, you can do it like this: cout << red << "hello world";. In fact, you only have red, blue, white, and yellow, and you have to change the color if you want colorful text in just one print. If you don't change the color, the entire print will have that color.

void SpaceWait () //It kinda stops program and waits for Space Key input
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

void jump (int jumpcount) //Jumps the Lines
{
    cout << endl ;
    while (jumpcount != 0)
    {
        cout << endl ;
        jumpcount -= 1 ;
    }
}