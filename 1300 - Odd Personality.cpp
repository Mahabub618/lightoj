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
const int N = 2e5+5;
vector<int> g[N];
int depth[N], low[N], vis[N], is_cut[N], par[N], dis[N];
int n, m, timer, cnt;
bool not_proceed(int u, int x)
{
    if(is_cut[u] == 1 and par[u] == x) return 1;
    if(is_cut[x] == 1 and par[x] == u) return 1;
    return 0;
}
void is_bridge(int node)
{
    is_cut[node] = 1;
}
void dfs(int u, int p)
{
    vis[u] = 1;
    depth[u] = low[u] = timer++;
    for(auto v: g[u])
    {
        if(v == p) continue;
        if(vis[v]) low[u] = min(low[u], depth[v]);
        else
        {
            par[v] = u;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > depth[u]) is_bridge(v);
        }
    }
    //debug3(u, low[u], depth[u]);
    
}
void find_cutpoints()
{
    timer = 0;
    for(int i=0; i<=n; i++) // 1-indexed based
    {
        vis[i] = is_cut[i] = par[i] = dis[i] = 0;
        depth[i] = low[i] = -1;
    }
    for(int i=0; i<n; i++)
    {
        if(!vis[i]) dfs(i, -1);
    }
}
bool ok;
void cycle_det(int u, int p, int d)
{
    vis[u] = 1;
    cnt++;
    dis[u] = d;
    
    for(auto v: g[u])
    {
        if(not_proceed(u, v)) continue;
        if(vis[v] == 0) cycle_det(v, u, d+1);
        else if(vis[v] == 1 and (dis[v]-dis[u])%2 == 0) ok = true;
    }
}
int main()
{
    init_code();
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++)
    {
        scanf("%d %d",&n, &m);
        for(int i=0; i<m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            //cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        find_cutpoints();
        memset(vis, 0, sizeof vis);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                ok = false;
                cnt = 0;
                cycle_det(i, -1, 1);
                if(ok) ans += cnt;
            }
        }
        printf("Case %d: %d\n", cs, ans);
        for(int i=0; i<n; i++) g[i].clear();
    }
    
     
return 0;
}
