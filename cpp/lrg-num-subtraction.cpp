/*lrg-number-subtraction.cpp
 *Written by: Keefer Rourke
 *License: LGPLv3
 *
 *COPYRIGHT Keefer Rourke 2014-2015
 *
 *Description: This program will find the difference between two large numbers
 *stored as digits in vectors, similar to the way one would subtract numbers
 *on paper
 *
 *Disclaimer: This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU Lesser General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU Lesser General Public License for more details.
 *
 *You should have received a copy of the GNU Lesser General Public License
 *along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
typedef vector <int> ivec;

ivec genRandNum();
ivec subInts(ivec a, ivec b);

//allows printing of vectors
ostream & operator << (ostream & stream, ivec vec)
{
    for (int i = vec.size()-1; i >= 0; i--)
        stream << vec[i];
    return stream;
}

int main()
{
    srand(time(0)); //initialises the random number generator
    
    //generate random numbers
    ivec randNum1; 
    ivec randNum2;
    randNum1 = genRandNum();
    randNum2 = genRandNum();
    
    cout << "Generated two random numbers." << endl;

    //print numbers
    cout << "The first number is: " << randNum1 << endl;
    
    cout << "The second number is: " << randNum2 << endl;
       
    //divide numbers
    cout << "Finding the difference between the two numbers." << endl;
    ivec diff = subInts(randNum1, randNum2);
    cout << "The difference of the two numbers is: " << diff << endl;
    return 0;
}

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

ivec subInts(ivec a, ivec b) //do a - b
{
    ivec difference;
    int temp;
    
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] < b[i])
        {
            a[i+1]-=1;
            a[i]+=10;
        }

        temp = a[i] - b[i];
        difference.push_back(temp);
    }

    if (a.size() > b.size())
        difference.push_back(a[a.size()-1]);

    return difference;
}

/* Test Cases with 309 digit numbers:
 * ----------------------------------
 * 
 * Generated two random numbers.
 * The first number is: 680131141024412330558472303891552789002549198288098615631003665377554314171009726176462542618882121024314008164071362871482674190771808692296169937949661856422774009420612711087726881311253767346881669951326994335014627622154321161663523265730946780557762314830812735833367224603377424626301686698237492162902
 * The second number is: 232795796520185453955113047539552679727621351238781097621706795175298407810044757426480201149096566159565537502184418914995321840747270783540657620100966238808336549722187182742723251830757267572444508444072734032196357848591894496244114670272453859715570620804101032238561950492394393080379115760465669946798
 * Finding the difference between the two numbers.
 * The difference of the two numbers is: 447335344504226876603359256352000109274927847049317518009296870202255906360964968749982341469785554864748470661886943956487352350024537908755512317848695617614437459698425528345003629480496499774437161507254260302818269773562426665419408595458492920842191694026711703594805274110983031545922570937771822216104
 * 
 * NOTE: The above answer is verified by the GNU bc integer calculator.
 *
 * bc output:
 * bc 1.06.95
 * Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc.
 * This is free software with ABSOLUTELY NO WARRANTY.
 * For details type `warranty'. 
 * 680131141024412330558472303891552789002549198288098615631003665377554314171009726176462542618882121024314008164071362871482674190771808692296169937949661856422774009420612711087726881311253767346881669951326994335014627622154321161663523265730946780557762314830812735833367224603377424626301686698237492162902 - 232795796520185453955113047539552679727621351238781097621706795175298407810044757426480201149096566159565537502184418914995321840747270783540657620100966238808336549722187182742723251830757267572444508444072734032196357848591894496244114670272453859715570620804101032238561950492394393080379115760465669946798
 * 44733534450422687660335925635200010927492784704931751800929687020225\
 * 59063609649687499823414697855548647484706618869439564873523500245379\
 * 08755512317848695617614437459698425528345003629480496499774437161507\
 * 25426030281826977356242666541940859545849292084219169402671170359480\
 * 5274110983031545922570937771822216104
 *
 * ------------------------------------
 *
 * Generated two random numbers.
 * The first number is: 809623992123988158527623475973808571964824563730998422538007513449514013161084257666433057287273558865218680747891127565001272346365762572372357466055463690408140317800880579911068055129034882139502818136893281191699315953341759175234130217828117214069259248174117292127969078125281089905285672315515677994374
 * The second number is: 549705601000324817606264621537561218260176630509842244019485505103819432393966768802363275020027448584922518696532997624308248994444921290204242517020496035253022173976504053528761446987021173708637033052566511336896493627506940185157685396554028167619846474302655216782243473155555346097973734731253965730859
 * Finding the difference between the two numbers.
 * The difference of the two numbers is: 259918391123663340921358854436247353704647933221156178518522008345694580767117488864069782267246110280296162051358129940693023351920841282168114949034967655155118143824376526382306608142013708430865785084326769854802822325834818990076444821274089046449412773871462075345725604969725743807311937584261712263515
 *
 * NOTE: The above answer is verified  by the GNU bc integer calculator.
 * bc output:
 *
 * bc 1.06.95
 * Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc.
 * This is free software with ABSOLUTELY NO WARRANTY.
 * For details type `warranty'. 
 * 809623992123988158527623475973808571964824563730998422538007513449514013161084257666433057287273558865218680747891127565001272346365762572372357466055463690408140317800880579911068055129034882139502818136893281191699315953341759175234130217828117214069259248174117292127969078125281089905285672315515677994374 - 549705601000324817606264621537561218260176630509842244019485505103819432393966768802363275020027448584922518696532997624308248994444921290204242517020496035253022173976504053528761446987021173708637033052566511336896493627506940185157685396554028167619846474302655216782243473155555346097973734731253965730859
 * 25991839112366334092135885443624735370464793322115617851852200834569\
 * 45807671174888640697822672461102802961620513581299406930233519208412\
 * 82168114949034967655155118143824376526382306608142013708430865785084\
 * 32676985480282232583481899007644482127408904644941277387146207534572\
 * 5604969725743807311937584261712263515
 */
