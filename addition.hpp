/* addition.hpp
 * Written by:  Keefer Rourke
 * License:     LGPLv3
 *
 * COPYRIGHT    Keefer Rourke 2014-2015
 *
 * Description: This is a collection of functions that can be used to perform mathematical
 *              operations on two large numbers which as passed as arguments to the appropriate
 *              functions.
 *
 * Disclaimer:  This project is free software: you can redistribute it and/or modify it under the
 *              terms of the GNU Lesser General Public License as published by the Free Software
 *              Foundation, either version 3 of the License, or (at your option) any later
 *              version.
 *
 *              While this project is free/libre open source software, you are free to use it,
 *              and any of its components, in your own free/libre or proprietary projects; however
 *              it is recommended that you consider preserving your users' freedoms with a
 *              permissive license. See <https://www.gnu.org/philosophy/free-sw.html> to learn
 *              more about free software.
 *
 *              This project is distributed in the hope that it will be useful, but WITHOUT ANY
 *              WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *              PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 *              You should have recieved a copy of the GNU Lesser General Public License along
 *              with this project. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __LRG_ADDITION__
#define __LRG_ADDITION__

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//function to add two large numbers together, each in the form of a vector of integers
//returns the sum as a vector of integers
vector <int> add(vector <int> a, vector <int> b)
{
    vector <int> sum;
    vector <int> large = a;
    vector <int> small = b;

    //determine which vector is longer, and thereby which number is larger
    if (a.size() < b.size())
    {
        large = b;
        small = a;         
    }
       
    int carry = 0; //set carry to zero

    for (int i = 0; i < (int)small.size(); i++) 
    {
        int temp = small[i] + large[i] + carry; 
        carry = temp / 10;
        temp = temp % 10;
        sum.push_back(temp);
    }
    
    for (int i = (int)small.size(); i < (int)large.size(); i++) 
    {
        int temp = large[i] + carry;
        carry = temp / 10;
        temp = temp % 10;
        sum.push_back(temp);
    }

    if (carry)
        sum.push_back(carry);

    return sum;
}

#endif
