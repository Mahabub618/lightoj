/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/

#include<bits/stdc++.h>
using namespace std;
#define       ll                  long long int
#define       veci                 vector<int>
#define       vecl                 vector<long long int>
#define       pb                   push_back
#define       newline cerr << endl
#define       pii                  pair<int, int>
#define       F                    first
#define       S                    second
#define       nl                   "\n"
#define       all(v)               v.begin(), v.end()
///============ CONSTANT ===============///
#define mx9   1000000007
#define mx5   200005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mod   mx9
///=============== Debugging ============================///
#ifndef ONLINE_JUDGE
#define       debug(x) cout << #x << " = " << x << endl
#define       debug2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#endif
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}
const int N = 1e4+4;
int disc[N], low[N], vis[N], col, color[N], deg[N], timer;
vector<int> g[N];
stack<int> st;

void Tarjan(int u, int p)
{
    disc[u] = low[u] = ++timer;
    st.push(u);
    vis[u] = 1;
    for(auto v: g[u])
    {
        if(v == p) continue;
        if(vis[v]) low[u] = min(low[u], disc[v]);
        else
        {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == disc[u])
    {
        ++col;
        while(!st.empty())
        {
            int val = st.top();
            st.pop();
            color[val] = col;
            if(u == val) break;
        }
    }
}
int main()
{
    init_code();
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++)
    {
        int n, m;
        cin >> n >> m;
        for(int i=0; i<m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        timer = col = 0;
        Tarjan(0, -1);
        
        for(int i=0; i<n; i++)
        {
            //debug2(i, color[i]);
            for(auto v: g[i])
            {
                if(color[i] != color[v])
                {
                    deg[color[i]]++;
                    deg[color[v]]++;
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=col; i++)
        {
            if(deg[i] == 2) ans++;
        }
        cout << "Case " << cs << ": " << (ans+1)/2 << nl;
        for(int i=0; i<=n; i++)
        {
            g[i].clear();
            deg[i] = color[i] = 0;
            disc[i] = low[i] = -1;
            vis[i] = 0;
            
        }
        while(!st.empty()) st.pop();
    }
     
return 0;
}
