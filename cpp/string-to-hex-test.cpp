/*string-to-hex-test.cpp
 *Written by: Keefer Rourke
 *License: GPLv3
 *
 *COPYRIGHT Keefer Rourke 2014-2015
 *
 *Description: This is an experiment. An attempt to convert characters to hexadecimal,
 *and hexadecimal to characters.
 *
 *Disclaimer: This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int toDec(string hexStr);

int main()
{
    //convert input letter to hex
    string input;

    cout << "Enter a string: ";
    getline(cin, input);
    
    //hex manipulator convert decimal values to hex easily
    //int(input) represents the char as an int
    cout << "HEX: ";
    for (int i = 0; i < input.length(); i++)
    {
        cout << hex << int(input[i]);
    }
    cout << endl;
    
    
    //--------------------------------------
    //convert input hex to decimal, then to characters
    //this has nothing to do with the first part of the program
    
    string str;

    cout << "\nEnter a number in hex: ";
    cin >> str;

    int len = str.length();
    vector <char> arr;
    
    //convert the string (which is a hex number) to an array of characters
    for (int i = 0; i < len; i++)
    {
        arr.push_back(str[i]);
    }
    
    string str2;
    int decNum;
    
    //add two characters (i.e two digits) to a string and convert it to decimal,
    //then output the decimal as a char
    for (int i = 0; i < arr.size(); i+=2)
    {
        //add two digits (one ASCII character) to the string
        str2.push_back(arr[i]);
        str2.push_back(arr[i+1]);
        
        //call function to convert hex to decimal
        decNum = toDec(str2);
        //print the decimal number interpreted as an ASCII char
        cout << (char)decNum;
        
        //empty the string
        str2.erase(0,2);
    }
    cout << endl;

    return 0;
}

int toDec(string hexStr)
{
    stringstream ss;
    int decNum;
    
    //hex modifier interprets the valid hexadecimal string as a hex integer
    //this is stored in the stream as a decimal number
    ss << hex << hexStr;
    //save the value stored in the stream to the variable
    ss >> decNum;
    
    //return the converted decimal number
    return decNum;
}

/* Test Cases:
 * -----------
 *
 * Enter a string: hello world!
 * HEX: 68656c6c6f20776f726c6421
 *
 * Enter a number in hex: 68656c6c6f20776f726c6421
 * hello world!
 * 
 * ----------------------
 *
 * Enter a string: Highschool Musical 
 * HEX: 486967687363686f6f6c204d75736963616c
 *
 * Enter a number in hex: 486967687363686f6f6c204d75736963616c
 * Highschool Musical
 * 
 * ----------------------
 *
 * Enter a string: Kaneki did nothing wrong!         
 * HEX: 4b616e656b6920646964206e6f7468696e672077726f6e6721
 * 
 * Enter a number in hex: 4b616e656b6920646964206e6f7468696e672077726f6e6721
 * Kaneki did nothing wrong!
 *
 * ----------------------
 *
 * Enter a string: If it works, it isn't X windows. 
 * HEX: 496620697420776f726b732c2069742069736e277420582077696e646f77732e20
 *
 * Enter a number in hex: 496620697420776f726b732c2069742069736e277420582077696e646f77732e20
 * If it works, it isn't X windows. 
 * 
 * ----------------------
 * 
 * Enter a string: Happy feast of the pig!
 * HEX: 4861707079206665617374206f66207468652070696721
 * 
 * Enter a number in hex: 4861707079206665617374206f66207468652070696721
 * Happy feast of the pig!
 */
