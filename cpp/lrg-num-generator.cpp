/*lrg-num-generator.cpp
 *Written by: Keefer Rourke
 *License: GPLv3
 *
 *COPYRIGHT Keefer Rourke 2014-2015
 *
 *Description: This program generates a 1024-bit (309 digit long) number and prints it to the console
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
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector <int> genRandNum();

//allows printing of vectors
ostream & operator << (ostream & stream, vector <int> vec)
{
    for (int i = vec.size()-1; i >= 0; i--)
        stream << vec[i];
    return stream;
}

int main()
{
    srand(time(0)); //initialises the random number generator
    
    //generate random number
    vector <int> randNum; 
    randNum = genRandNum();
    
    //print large number
    cout << randNum << endl;
    return 0;
}

vector <int> genRandNum()
{
    vector <int> randNum;
    
    //fill a 309 digit long vector with random numbers from 0 to 9
    for (int i = 0; i <= 309; i++)
    {
        int temp = rand() % 10;
        randNum.push_back(temp);
    }

    return randNum;
}

/* Test cases:
 * ------------------
 *
 * 8206054105028275509396712121733003295786663176601168436049853888839700038755334170939706577303710847215340996121121303707259094341077312467208080849625504372337155585325922622009482822292508264006830317850041766861057431106804652024761938399389152611510013062816262134881090552197930775022435492633189824846304
 *
 * ------------------
 *
 *  2735890638429648917737250096674573596901776171928058704132298907537323268505374835434092419816821403254323834947924266237309340693992139779400364582971685753670154325827791666160107671008259463820611413549604133637385867643309620896172555149613040702211248883470262648451447322836897346521111649107709201439492
 *
 *  -----------------
 *
 *  2864480347700332840048435418750646383364615659158261192456898124302773986638099795762663557282053987735634739283298989636201915425297970452697218925020339639923610542683326919378557177849411116676834549744882925903621830452074017388566074409216279846825676772760259255228182413109005990209251887271691477831217
 *
 *  -----------------
 *
 *  7734210153327396547570908321688330286482681865976745068752324695470368969699603958621422751702209028626087675212528877183739026920164941214279273057223161198686529143582588420662496085151203426664800496684707629092295558783984449261286718663668753485360952305806337815598571215612541632430955832239580706449307
 */
