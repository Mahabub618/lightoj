/*****************************************************************\
IN THE NAME OF ALLAH, MOST GRACIOUS AND MOST MERCIFUL
                                                                 |
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
#define       newline cerr << endl
#define       pob                  pop_back
#define       mp                   make_pair
#define       pii                  pair<int, int>
#define       F                    first
#define       S                    second
#define       sc(x)                scanf("%d",&x)
#define       sc2(xx,zz)           scanf("%d %d",&xx,&zz)
#define       scl(x)               scanf("%lld",&x)
#define       scl2(xx,zz)          scanf("%lld %lld",&xx,&zz)
#define       pf                   printf
#define       nl                   "\n"
#define       min3(a,b,c)          min(a,b<c?b:c)
#define       max3(a,b,c)          max(a,b>c?b:c)
#define       all(v)               v.begin(), v.end()
///=============== Debugging ============================///
#define       debug(x) cerr << #x << " = " << x << endl
#define       debug2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
//#define f(x) (64 - __builtin_clzll(x))
///============ CONSTANT ===============///
#define mx9   1000000007
#define mx7   10000007
#define mx6   2000006
#define mx5   200005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mod   mx9
///==============================TEMPLATES===============================///

long double PI = acosl(-1);
bool compare_int(int a, int b){return (a>b);} //This function is use for descending order.
bool compare_string (string a, string b){return a.size()<b.size();}
bool compare_pair(const pair<int,int> &a,
                    const pair<int,int> &b){if(a.second==b.second)return a.first<b.first; else return (a.second > b.second);}
bool cmp(pair<string ,int > x , pair<string ,int > y){return (x.S < y.S);}
///=====================Graph Moves================///
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

///=====================Bitmask===================///
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}

///========================================FUNCTION=========================================///
//bool check(int n){if(n==1) return false; for(int i=2; i*i<=n; i++){if(n%i==0) return false;} return true;}
//ll bigmod(ll a, ll b, ll m){if(b==0) return 1%m;ll x=bigmod(a, b/2, m);x=(x*x)%m;if(b%2==1)x=(x*a)%m;return x;}
//bool flag[mx5];veci prime;
//void sieve(){prime.pb(2);for(ll i=3; i*i<=mx5; i+=2){if(flag[i]) continue;for(ll j=i*i; j<=mx5; j+=i+i) flag[j]=true;}for(ll i=3; i<=mx5; i+=2) if(!flag[i]) prime.pb(i);}
//ll fact(ll n){if(n==0 or n==1)return 1; else return n*fact(n-1);}
void NA(){printf("NO\n");exit(0);}
void YA(){printf("YES\n");exit(0);}

///=================START_FROM_HERE=====================///

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+100, ALPHA = 26;
ll node[N];
int to[N][ALPHA], nxt[N][ALPHA];
int dph[N], sl[N], par[N], pl[N];
vector<int> tr[N];
int tot = 1;

int add_string(string &s) {
    int u = 1;
    for(int i = 0; i < s.size(); i++) {
        int c = s[i]-'a';
        if(!to[u][c]) to[u][c] = ++tot, par[tot] = u, dph[tot] = dph[u]+1, pl[tot] = c;
        u = to[u][c];
    }
    return u;
}

void push_links() {
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if(dph[u] <= 1) sl[u] = 1;
        else {
            int v = sl[par[u]], l = pl[u];
            while(v > 1 && !to[v][l]) v = sl[v];
            if(to[v][l]) v = to[v][l];
            sl[u] = v;
        }
        if(u != 1) tr[sl[u]].push_back(u);
        for(int i = 0; i < ALPHA; i++) if(to[u][i]) q.push(to[u][i]);
    }
}

int jump(int u, int c) {
    if(nxt[u][c]) return nxt[u][c];
    int v = u;
    while(v > 1 && !to[v][c]) v = sl[v];
    if(to[v][c]) v = to[v][c];
    return nxt[u][c] = v;
}

void dfs(int u)
{
    for(int v: tr[u])
    {
        dfs(v);
        node[u]+=node[v];
    }
    return;
}
void all_clear(int x)
{
    for(int i=0; i<=x; i++)
    {
        tr[i].clear();
        dph[i] = node[i] = 0;
        par[i] = i;
        for(int j=0; j<ALPHA; j++)
        {
            to[i][j] = 0;
            nxt[i][j] = 0;
        }
    }
    tot = 1;
    return;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    for(int cas = 1; cas<=t; cas++)
    {
        int n;
        string s, st;
        vector<int> v;
        cin >> n >> s;
        for(int i=0; i<n; i++)
        {
            cin >> st;
            int nod = add_string(st);
            v.pb(nod);
        }
        push_links();

        int idx = 1;
        for(int i=0; i<s.size(); i++)
        {
            idx = jump(idx, s[i]-'a');
            node[idx]++;
        }
        dfs(1);
        cout << "Case " << cas << ":\n";
        for(int i=0; i<v.size(); i++) cout << node[v[i]] << nl;
        all_clear(tot);
    }
    return 0;
}

