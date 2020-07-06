/* ************************************************************* */
/*     Author     : Mahabub.Tweety                               */
/*     Email      : mahabubrahman618@gmail.com                   */
/*     University : Comilla University, Bangladesh               */
/*                  Department of Computer Science & Engineering */
/* ***************************************************************

/*
    Compiled : CNU c++ 14
    Copyright 2019 by Mahabub Rahman & Comilla University Sailor ; all rights reserved.
    Permission is granted for use in non-commercial applications provided this
    copyright notice remains intact   and unchanged.
*/


/*...................................Data_Types............................................*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>
#include<math.h>

using namespace std;

#define       lli                  long long int
#define       ull                  unsigned long long int
#define       veci                 vector<int>
#define       vecc                 vector<char>
#define       vecs                 vector<string>
#define       vecl                 vector<long long int>
#define       vecp                 vector<  pair<int,int> >
#define       mapstrint            map< string , int >
#define       mapstrstr            map< string , string >
#define       mapint               map< int, int >
#define       pb                   push_back
#define       pob                  pop_back
////============ CONSTANT ===============////
#define mx7   10000007
#define mx6   1000006
#define mx5   100005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mx    (65540)
#define mod   1000000007
////=====================================////

long double PI = acosl(-1);
bool myfunc(int a, int b) //This function is use for descending order.
{
    return (a>b);
}

int main()
{
    lli t, k=1, divider;
    cin >> t;
    while(t--)
    {
        char s[100000], a[10];
        cin >> divider >> a;
        lli reminder = 0, cnt=0;
        for(lli i=0; ; i++)
        {
            s[i]=a[0];
            reminder = ((reminder*10)+(s[i]-'0'))%divider;
            if(reminder) cnt++;
            else break;
        }
        cout << "Case " << k++ << ": " << cnt+1 << endl;
    }
    return 0;
}
