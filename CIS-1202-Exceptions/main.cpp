//
//  main.cpp
//  CIS-1202-Exceptions
//
//  Created by Qi Zhang on 12/5/21.
//
// Qi Zhang
// CIS 1202 101
// Dec 5, 2021
//
// Write a function to calculate character offsets, throwing exceptions in error conditions.
//
// Use a source code management tool as you develop this program.  Commit changes frequently using descriptive commit messages.  Push your changes to GitHub or other publicly accessible location for your instructor to clone

#include <iostream>
using namespace std;

// Function prototype
char character(char, int);

// Exception without passing data back
class invalidCharacterExcpeption
{};

// Exception without passing data back
class invalidRangeException
{};

int main()
{
    char charOrigin, charTarget;
    int offsetTarget;
    
    // Prompt user input
    cout << "Enter a start char: ";
    cin >> charOrigin;
    
    cout << "Enter the offset number (right move as postitive, left move as negative): ";
    cin >> offsetTarget;
    
    
    try
    {
        charTarget = character(charOrigin, offsetTarget);
        cout << "character('" << charOrigin << "', " << offsetTarget << ") should return '" << charTarget << "'. " << endl;
    }
    catch (invalidCharacterExcpeption)
    {
        cout << "character('" << charOrigin << "', " << offsetTarget << ") should throw an invalidCharacterExcpeption. " << endl;
    }
    catch (invalidRangeException)
    {
        cout << "character('" << charOrigin << "', " << offsetTarget << ") should throw an invalidRangeException. " << endl;
    }
    
    return 0;
}


//Do not allow upper- and lower-case transitions.  character('A', 32) should throw an exception, not return 'a'.
char character(char start, int offset)
{
    char returnChar;
    
    //character('?', 5) 
    if (
        start < 'A'
        ||
        start > 'z'
        ||
        (
         start > 'Z'
         &&
         start < 'a'
         )
        )
        throw invalidCharacterExcpeption();
    else
    {
        returnChar = static_cast<char>(start + offset);
        
        //character('a', -1)
        if (
            returnChar < 'A'
            ||
            returnChar > 'z'
            ||
            (
             returnChar > 'Z'
             &&
             returnChar < 'a'
             )
            )
            throw invalidRangeException();
        else
        {
            //character('A', 32)
            if (
                (
                 returnChar >= 'A'
                 &&
                 returnChar <= 'Z'
                 &&
                 start >= 'a'
                 &&
                 start <= 'z'
                 )
                ||
                (
                 start >= 'A'
                 &&
                 start <= 'Z'
                 &&
                 returnChar >= 'a'
                 &&
                 returnChar <= 'z'
                 )
                )
                throw invalidRangeException();
        }
        
    }
    
    return returnChar;
}
