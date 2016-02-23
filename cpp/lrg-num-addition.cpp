/*lrg-num-addition.cpp
 *Written by: Keefer Rourke
 *License: LGPLv3
 *
 *COPYRIGHT Keefer Rourke 2014-2015
 *
 *Description: This program will add two large numbers stored as digits in vectors,
 *similar to the way one would add numbers on paper
 *
 *Disclaimer: This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU Lesser General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU Lesser General Public License
 *along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef vector <int> ivec;

ivec genRandNum();
ivec addInts(ivec a, ivec b);

//allows printing of vectors
ostream & operator << (ostream & stream, ivec vec)
{
    for (int i = vec.size()-1; i >= 0; i--)
        stream << vec[i];
    return stream;
}

//begin main program
int main()
{
    srand(time(0)); //initialises the random number generator
    
    //generate random number
    ivec randNum1; 
    ivec randNum2;
    randNum1 = genRandNum();
    randNum2 = genRandNum();   
    
    cout << "Generated two random numbers." << endl;

    //print numbers
    cout << "The first number is: " << randNum1 << endl;
    cout << "The second number is: " << randNum2 << endl;
    
    //add numbers
    cout << "Adding the two numbers." << endl;
    ivec sum = addInts(randNum1, randNum2);
    cout << "The sum of the two numbers is: " << sum << endl;

    return 0;
}

//generate random numbers
ivec genRandNum()
{
    ivec randNum;

    for (int i = 0; i < 309; i++)
    {
        int temp = rand() % 10;
        randNum.push_back(temp);
    }

    return randNum;
}

//add the numbers together
ivec addInts(ivec a, ivec b)
{
    ivec sum;
    ivec large = a;
    ivec small = b;

    //determine which vector is longer
    if (a.size() < b.size())
    {
        large = b;
        small = a;         
    }
       
    int carry = 0; //set carry to zero

    for (int i = 0; i < small.size(); i++)
    {
        int temp = small[i] + large[i] + carry; 
        carry = temp / 10;
        temp = temp % 10;
        sum.push_back(temp);
        
    }
    
    for (int i = small.size(); i < large.size(); i++)
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

/* Test Cases with 309 digit numbers:
 * ----------------------------------
 * Generated two random numbers.
 * The first number is: 939839096499071454211778050730880882239720660501234171610975080853051996704737795354962397312760114308285704943117067308463055369619138156880485054984228677452756177215340543815044345129340665986277589551684078921366778578769957581697559692546567620860679027497493694495697772764918143942008160910967780309854
 * The second number is: 509783710007147501126940109246682474071376851648395382194346418528379332229303101329853592867824974799191620075137406873584393816549735144382853941339727937425561449163243779260141067940274311038381037259882796411677694318374533456544799428484286016602363906679084515194207625821432823533447556730077768068449
 * Adding the two numbers.
 * The sum of the two numbers is: 1449622806506218955338718159977563356311097512149629553805321499381431328934040896684815990180585089107477325018254474182047449186168873301263338996323956614878317626378584323075185413069614977024658626811566875333044472897144491038242359121030853637463042934176578209689905398586350967475455717641045548378303
 *
 * NOTE: The above answer is verified by the GNU bc integer calculator.
 * bc output:
 *
 * bc 1.06.95
 * Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc.
 * This is free software with ABSOLUTELY NO WARRANTY.
 * For details type `warranty'. 
 * 939839096499071454211778050730880882239720660501234171610975080853051996704737795354962397312760114308285704943117067308463055369619138156880485054984228677452756177215340543815044345129340665986277589551684078921366778578769957581697559692546567620860679027497493694495697772764918143942008160910967780309854 + 509783710007147501126940109246682474071376851648395382194346418528379332229303101329853592867824974799191620075137406873584393816549735144382853941339727937425561449163243779260141067940274311038381037259882796411677694318374533456544799428484286016602363906679084515194207625821432823533447556730077768068449
 * 14496228065062189553387181599775633563110975121496295538053214993814\
 * 31328934040896684815990180585089107477325018254474182047449186168873\
 * 30126333899632395661487831762637858432307518541306961497702465862681\
 * 15668753330444728971444910382423591210308536374630429341765782096899\
 * 05398586350967475455717641045548378303
 *
 * -----------------------------------
 * 
 * Generated two random numbers.
 * The first number is: 311382600625040601913233564317691757088565542757758067703669694357741180367598958014204307512760344172166962783469890767274220424179420295730247810129003259635353623536546141658910383462405053017488818359354642590093743083453866054780569194040533054052869769005421137493231556689207317756458319242204258265748
 * The second number is: 525202152141085492267470140236400113981996567103468523879361429701007543723474271355248894940670456460935998179611523465137020487423581580855697885633890462383294180941304888205082112896717989121744751566302194932497751886526709119504491524234341697304961769849301377516077065417332028072053681183154790243688
 * Adding the two numbers.
 * The sum of the two numbers is: 836584752766126094180703704554091871070562109861226591583031124058748724091073229369453202453430800633102960963081414232411240911603001876585945695762893722018647804477851029863992496359123042139233569925656837522591494969980575174285060718274874751357831538854722515009308622106539345828512000425359048509436
 *
 * NOTE: The above answer is verified by the GNU bc integer calculator.
 * bc output:
 *
 * bc 1.06.95
 * Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc.
 * This is free software with ABSOLUTELY NO WARRANTY.
 * For details type `warranty'. 
 * 311382600625040601913233564317691757088565542757758067703669694357741180367598958014204307512760344172166962783469890767274220424179420295730247810129003259635353623536546141658910383462405053017488818359354642590093743083453866054780569194040533054052869769005421137493231556689207317756458319242204258265748 + 525202152141085492267470140236400113981996567103468523879361429701007543723474271355248894940670456460935998179611523465137020487423581580855697885633890462383294180941304888205082112896717989121744751566302194932497751886526709119504491524234341697304961769849301377516077065417332028072053681183154790243688
 * 83658475276612609418070370455409187107056210986122659158303112405874\
 * 87240910732293694532024534308006331029609630814142324112409116030018\
 * 76585945695762893722018647804477851029863992496359123042139233569925\
 * 65683752259149496998057517428506071827487475135783153885472251500930\
8622106539345828512000425359048509436
 */
