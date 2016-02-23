/* subtraction.hpp
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

#ifndef __LRG_SUBTRACTION__
#define __LRG_SUBTRACTION__

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

//function to subtract one large number from another, each in the form of a vector of integers
//note that second argument of this function is always subtracted from the first argument
//returns the difference as a vector of integers
vector <int> subtract(vector <int> a, vector <int> b) //do a - b
{
    vector <int> difference;
    int temp;
    
    for (int i = 0; i < (int)b.size(); i++)
    {
        if (a[i] < b[i])
        {
            a[i+1]--;
            a[i]+=10;
        }

        temp = a[i] - b[i];
        difference.push_back(temp);
    }

    if (a.size() > b.size())
        difference.push_back(a[(int)a.size()-1]);

    return difference;
}

#endif
