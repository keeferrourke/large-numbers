/* multiplication.hpp
 *  Written by:  Keefer Rourke
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

#ifndef __LRG_MULTIPLICATION__
#define __LRG_MULTIPLICATION__

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "addition.hpp"

using namespace std;

//function for large number multiplication
vector <int> multiply(vector <int> a, vector <int> b) 
{
    vector <int> product, temp1, temp2;
    vector <int> large = a;
    vector <int> small = b;
     
    //determine which vector is longer
    if (a.size() < b.size()) 
    {
        large = b;
        small = a;         
    }

    int carry = 0;

    for (int i = 0; i < (int)small.size(); i++) 
    {
        carry = 0;
        for (int j = 0; j < (int)large.size(); j++) 
        {
            int temp = (small[i] * large[j]) + carry;
            carry = 0;
            
            while (temp >= 10) 
            {
                temp -= 10;
                carry++;
            }
            temp1.push_back(temp);
        }

        if (carry > 0)
            temp1.push_back(carry);
            
        if (i == 0)
            product = temp1; 
        else
        {            
            reverse (temp1.begin(), temp1.end());
            //zero shifting
            for (int j = 0; j < i; j++)
                temp1.push_back(0);

            reverse (temp1.begin(), temp1.end());
            reverse (temp2.begin(), temp2.end());
            temp2 = add(temp1, temp2);
            product = add(temp2, product);
        }
        
        //empty temp vectors
        temp1.erase(temp1.begin(), temp1.end());
        temp2.erase(temp2.begin(), temp2.end());
    }
      
    return product;
}

#endif
