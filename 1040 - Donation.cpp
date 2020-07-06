
/*****************************************************************\
|     IN THE NAME OF ALLAH, MOST GRACIOUS AND MOST MERCIFUL       |
|                                                                 |
|     Author     : Mahabub Rahman                                 |
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
    else return (a.second > b.second);
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
int nod, edg, par[mx5], ca=1;

struct edge
{
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w<p.w;
    }
};
int find(int r)
{
    if(par[r]==r) return r;
    return par[r] = find(par[r]);
}

priority_queue<edge> pq;

void mst(ll tot)
{
    for(int i=1; i<=nod; i++) par[i]=i;
    int cnt=0;
    ll sum=0;
    while(!pq.empty())
    {
        edge top = pq.top();
        pq.pop();
        int u = top.u;
        int v = top.v;
        int w = -top.w;
        int a = find(u);
        int b = find(v);
        if(a!=b && w>0)
        {
            sum += w;
            cnt++;
            par[b] = par[a];
        }
        //if(cnt==nod-1) break;
    }
    if(cnt==nod-1)
    {
        printf("Case %d: %lld\n", ca++, tot-sum);
    }
    else
    {
        printf("Case %d: -1\n", ca++);
    }
}

int32_t main()
{
    FastIO;
    int t, n, tot, w;
    cin >> t;
    while(t--)
    {
        edge get;
        tot=0;
        cin >> nod;
        for(int i=1; i<=nod; i++)
        {
            for(int j=1; j<=nod; j++)
            {
                cin >> w;
                tot+=w;
                if(w>0 && i!=j)
                {
                    if(i<j)
                    {
                        get.u = i;
                        get.v = j;
                        get.w = -w;
                    }
                    else
                    {
                        get.u = j;
                        get.v = i;
                        get.w = -w;
                    }
                    pq.push(get);
                }
            }
        }
        mst(tot);
    }

}
