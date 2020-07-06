
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
int nod, edg, ca=1;
map<string, string> par;

struct edge
{
    string u, v;
    int w;
    bool operator<(const edge& p) const
    {
        return w<p.w;
    }
};

priority_queue<edge> pq;

string find(string r)
{
    if(par[r]==r) return r;
    return par[r] = find(par[r]);
}

void mst()
{
    //for(int i=1; i<=nod; i++) par[i] = i;

    int cnt = 0;
    ll sum = 0;
    nod = par.size();
    //cout << nod << endl;

    while(!pq.empty())
    {
        edge top = pq.top();
        pq.pop();

        string u = top.u;
        string v = top.v;
        int w = -top.w;
        string a = find(u);
        string b = find(v);

        if(a!=b)
        {
            sum += w;
            par[b] = par[a];
            cnt++;
        }
    }
    if(cnt==nod-1)
    {
        printf("Case %d: %lld\n", ca++, sum);
    }
    else
    {
        printf("Case %d: Impossible\n", ca++);
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> edg;
        string u, v;
        int w, cnt=1;
        edge get;
        for(int i=0;i<edg; i++)
        {
            cin >> u >> v >> w;
            if(par[u].empty()) par[u] = u;
            if(par[v].empty()) par[v] = v;

                if(u<v)
                {
                    get.u = u;
                    get.v = v;
                    get.w = -w;
                }
                else
                {
                    get.u = v;
                    get.v = u;
                    get.w = -w;
                }
                pq.push(get);
        }
        mst();
        par.clear();
    }
}
