/*operable-integers.cpp
 *Written by: Keefer Rourke
 *License: GPLv3
 *
 *COPYRIGHT Keefer Rourke 2014-2015
 *
 *Description: This is a program that will convert letters from an input string 
 *to operable integers for encryption. The inverse operation will also be accomplished.
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
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

vector <int> stringToInt(string mtext);

//allows printing of vectors
ostream & operator << (ostream & stream, vector <int> vec)
{
    for (int i = vec.size()-1; i >= 0; i--)
        stream << vec[i];
    return stream;
}

int main()
{
    int inputChoice;
    string mtext; //this is the string of unecrypted text
    
    //get unecrypted text from user
    do
    {
        //prompt user for input text
        cout << "Enter text for encryption (no return characters):\n>";
        getline (cin, mtext);
    
        //confirm that the correct text has been entered
        char confirm;
        cout << "Are you sure this is the right text? (Y/N)" << endl;
        cin >> confirm;
        confirm = toupper(confirm);

        if (confirm == 'Y')
        {
            cout << "Continuing..." << endl;
            break; //exit infinite loop
        }
        else 
        {
            cout << "Trying again with different text..." << endl;
            continue; //get input type again
        }

    } while (true); //loop until break is reached

    vector <int> m;
    //convert unencrypted text to an operable integer
    m = stringToInt(mtext);
    cout << m << endl;
    
    return 0;
}

vector <int> stringToInt(string mtext)
{
    vector <int> nums;
    
    for (int i = 0; i < mtext.size(); i++)
     {
         nums.push_back(mtext[i]);
     }

     return nums;
}

/* Test Cases:
 * -----------
 *
 * Enter text for encryption (no return characters):
 * >hello
 * Are you sure this is the right text? (Y/N)
 * y
 * Continuing...
 * 111108108101104
 *
 * -----------------------
 *
 * Enter text for encryption (no return characters):
 * >some text as numbers
 * Are you sure this is the right text? (Y/N)
 * n
 * Trying again with different text...
 * Enter text for encryption (no return characters):
 * >Are you sure this is the right text? (Y/N)
 * some text as numbers
 * Trying again with different text...
 * Enter text for encryption (no return characters):
 * >Are you sure this is the right text? (Y/N)
 * y
 * Continuing...
 * 1151141019810911711032115973211612010111632101109111
 *
 */
