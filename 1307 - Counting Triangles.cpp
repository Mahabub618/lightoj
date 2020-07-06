
/*****************************************************************\
|     ---|--- \        / |~~~ |~~~ ---|--- \  /                   |
|        |     \  /\  /  |_   |_      |     \/                    |
|        |      \/  \/   |___ |___    |      |                    |
|                                                                 |
|     Author     : Mahabub.Tweety                                 |
|     Email      : mahabubrahman618@gmail.com                     |
|     University : Comilla University, Bangladesh                 |
|                  Department of Computer Science & Engineering   |
\*****************************************************************/


/*...................................Data_Types............................................*/
#include<bits/stdc++.h>

using namespace std;
#define FastIO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define       ll                  long long int
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
#define       mp                   make_pair
////============ CONSTANT ===============////
#define mx9   1000000009
#define mx7   10000007
#define mx6   1000006
#define mx5   100005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mx    (65540)
#define mod   1000000007
////=====================================////

long double PI = acosl(-1);
bool compare_int(int a, int b) //This function is use for descending order.
{
    return (a>b);
}
bool compare_string (string a, string b)
{
    return a.size() < b.size();
}
bool compare_pair(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.second==b.second) return a.first>b.first;
    else return (a.second < b.second);
}
ll fact(ll n)
{
    if(n==0 || n==1) return 1;
    else return n*fact(n-1);
}

////======================================////
/*bool check(int n)
{
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}*/
int bi(int a[], int l, int r, int x)
{
    int mid, res=-1;
    while(l<=r)
    {
        mid = l+(r-l)/2;
        if(a[mid]<x)
        {
            l = mid+1;
            res = mid;
        }
        else r=mid-1;
    }
    return res;
}
int32_t main()
{
    FastIO;
    int t, n, l, r, cnt, ca=1;
    cin >> t;
    while(t--)
    {
        cnt=0;
        cin >> n;
        int a[n+1];
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+n+1);

        for(int i=1; i<=n-2; i++)
        {
            for(int j=i+1; j<=n-1; j++)
            {
                int v = bi(a, j+1, n, a[i]+a[j]);
                if(v!=-1) cnt+=(v-j);
            }
        }
        cout << "Case " << ca++ << ": " << cnt << endl;
    }

}
