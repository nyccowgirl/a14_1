/*
 Trang Hoang
 CS110B
 Dave Harden
 12/1/20
 a14_1.cpp
 
 Assignment 14.1
 
 Write a recursive function named reverseWithinBounds that has an argument that is an array
 of characters and two arguments that are bounds on array indices. The function should
 reverse the order of those entries in the array whose indices are between the two bounds
 (including the bounds). For example, if the array is:

 a[0] == 'A' a[1] == 'B' a[2] == 'C' a[3] == 'D' a[4] == 'E'

 and the bounds are 1 and 4, then after the function is run the array elements should be:

 a[0] == 'A' a[1] == 'E' a[2] == 'D' a[3] == 'C' a[4] == 'B'

 Embed the function in a program and test it. After you have fully debugged this function,
 define another function named reverseCstring that takes a single argument that is a C
 string and modifies the argument so that it is reversed. This function will include a call
 to the recursive definition you did for the first part of this project, and need not be
 recursive. Embed this second function in a program and test it. Turn in only this final
 result (with output, of course).
 
 Created by nyccowgirl on 12/1/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
using namespace std;


void reverseWithinBounds(char array[], int left, int right);
void reverseCstring(char* cString);


int main(int argc, const char * argv[]) {
    char test[] = {'A', 'B', 'C', 'D', 'E'};
    char array[] = "Hello, World!";
    char *cString = array;
    
    for (char c : test) {
        cout << c << ' ';
    }
    cout << endl;
    reverseWithinBounds(test, 0, sizeof(test) - 1);
    for (char c : test) {
        cout << c << ' ';
    }
    cout << endl;
    
    reverseWithinBounds(test, 0, sizeof(test) - 1);
    for (char c : test) {
        cout << c << ' ';
    }
    cout << endl;
    
    reverseWithinBounds(test, 1, 4);
    for (char c : test) {
        cout << c << ' ';
    }
    cout << endl;
    
    
    cout << array << endl;
    reverseWithinBounds(array, 0, (int)strlen(array) - 1);
    cout << array << endl;
    
    cout << cString << endl;
    reverseCstring(cString);
    cout << cString << endl;
    return 0;
}






/*
 Definition of function reverseWithinBounds that takes in a character array and a left and
 right bound on array indices. It modifies the array by reversing the characters within the
 bounds (inclusive of the bounds).
 */

void reverseWithinBounds(char array[], int left, int right) {
    // base case is to do nothing if left is >= right.
    
    if (left < right) {
        char temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
        reverseWithinBounds(array, left, right);
    }
}






/*
 Definition of function reverseCstring that takes in a cstring and modifies the argument so
 that it is reversed using reverseWithinBounds function.
 */

void reverseCstring(char* cString) {
    
    reverseWithinBounds(cString, 0, (int)strlen(cString) - 1);
}

/*
 A B C D E
 E D C B A
 A B C D E
 A E D C B
 Hello, World!
 !dlroW ,olleH
 !dlroW ,olleH
 Hello, World!
 Program ended with exit code: 0
 */
