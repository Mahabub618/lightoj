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
vector<int> g[N];
int vis[N], depth[N], low[N], tin[N], cut[N], par[N];
int timer;
// void dfs(int u, int p, int d)
// {
//     //debug(u);
//     vis[u] = 1;
//     par[u] = p;
//     low[u] = d;
//     depth[u] = d;
//     for(auto v: g[u])
//     {
//         if(v == p) continue;
//         else if(vis[v] == false)
//         {
//             dfs(v, u, d+1);
//             low[u] = min(low[u], low[v]);
//         }
//         else
//         {
//             if(depth[v] < depth[u]) low[u] = min(low[u], depth[v]);
//         }
//     }
// }
int tot;
void dfs(int v, int p)
{
    vis[v] = 1;
    tin[v] = low[v] = timer++;
    int children = 0;
    for(auto to: g[v])
    {
        if(to == p) continue;
        if(vis[to]) low[v]  = min(low[v], tin[to]);
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] >= tin[v] and p != -1) cut[v] = 1;
            ++children;
        }
    }
    if(p == -1 and children > 1) cut[v] = 1;
}
int main()
{
    init_code();
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].pb(v);
            g[v].pb(u);
        }
        timer = 0;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i]) dfs(i, -1);
        }
        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            if(cut[i] == 1) cnt++;
        }
        cout << "Case " << cs << ": " << cnt << nl;
        
        for(int i=0; i<=n; i++)
        {
            vis[i] = cut[i] = 0;
            tin[i] = low[i] = -1;
            g[i].clear();
        }        
    }
     
return 0;
}
