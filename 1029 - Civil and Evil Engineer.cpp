
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

priority_queue<edge> pq;
priority_queue<edge> pq2;

int find(int r)
{
    if(par[r]==r) return r;

    return par[r]=find(par[r]);
}

void mst(void)
{
    for(int i=0; i<=nod; i++) par[i]=i;
    int cnt=0;
    ll sum=0, sum2=0;

    while(!pq.empty())
    {
        edge top = pq.top();
        pq.pop();
        int u = top.u;
        int v = top.v;
        int w = -top.w;
        int a = find(u);
        int b = find(v);
        //cout << u << ' ' << v << ' ' << w << endl;
        if(a!=b)
        {
            cnt++;
            sum += w;
            //cout << u << ' ' << v << ' ' << w << endl;
            par[b] = par[a];
        }
        //if(cnt==nod) break;
    }
    while(!pq.empty()) pq.pop();
    for(int i=0; i<=nod; i++) par[i] = i;
    cnt=0;
    while(!pq2.empty())
    {
        edge top = pq2.top();
        pq2.pop();
        int u = top.u;
        int v = top.v;
        int w = top.w;
        int a = find(u);
        int b = find(v);
        //cout << u << ' ' << v << ' ' << w << ' ' << a << ' ' << b << endl;


        if(a!=b)
        {
            cnt++;
            sum2+= w;
            //cout << u << ' ' << v << ' ' << w << endl;
            par[b] = par[a];
        }
        //if(cnt==nod) break;
    }
    while(!pq2.empty()) pq2.pop();
    if((sum+sum2)%2)
    {
        printf("Case %d: %lld/2\n", ca++, sum+sum2);
    }
    else
    {
        printf("Case %d: %lld\n", ca++, (sum+sum2)/2);
    }
    //cout << sum << ' ' << sum2 << endl;
}


int main()
{
    FastIO;
    int t, u, v, w;
    edge get, get2;
    cin >> t;
    while(t--)
    {
        cin >> nod;
        while(1)
        {
            cin >> u >> v >> w;
            if(u==0 && v==0 && w==0) break;
            else
            {
                if(u<v)
                {
                    get.u = u;
                    get2.u = u;
                    get.v = v;
                    get2.v = v;
                }
                else
                {
                    get2.u = v;
                    get.u = v;
                    get2.v = u;
                    get.v = u;
                }
                get.w = -w;
                get2.w = w;
                pq2.push(get2);
                pq.push(get);
            }
        }
        mst();
    }
    return 0;
}
