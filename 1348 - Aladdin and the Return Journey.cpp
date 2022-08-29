/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/

#include<bits/stdc++.h>
using namespace std;
#define       ll                  int
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
const ll N = 3e4+3;
vector<ll> g[N];
ll a[N], par[N][22], depth[N], st[N], et[N], timer = 0;
ll tr[4*N];
void dfs(ll u, ll p, ll d)
{
    par[u][0] = p;
    depth[u] = d;
    st[u] = ++timer;
    for(auto v: g[u])
    {
        if(v != p) dfs(v, u, d+1);
    }
    et[u] = timer;
}
ll kth_parent(ll u, ll k)
{
    for(int b=21; b>=0; b--)
    {
        if((k>>b)&1) u = par[u][b];
    }
    return u;
}
ll LCA(ll u, ll v)
{
    if(depth[u] < depth[v]) swap(u, v);
    ll dif = depth[u] - depth[v];
    u = kth_parent(u, dif);
    if(u == v) return v;
    else
    {
        for(int k=19; k>=0; k--)
        {
            if(par[u][k] != par[v][k] and par[u][k] != -1)
            {
                u = par[u][k];
                v = par[v][k];
            }
        }
        return par[v][0];
    }
}
void build(ll u, ll b, ll e)
{
    tr[u] = 0;
    if(b == e) return;
    ll mid = (b+e) >> 1;
    build(2*u, b, mid);
    build(2*u+1, mid+1, e);
}
void update(ll u, ll b, ll e, ll i, ll j, ll x)
{
    if(b > j or e < i) return;
    if(b >= i and e <= j)
    {
        tr[u] += x;
        return;
    }
    ll mid = (b+e) >> 1;
    update(2*u, b, mid, i, j, x);
    update(2*u+1, mid+1, e, i, j, x);
}
ll query(ll u, ll b, ll e, ll i, ll j, ll carry)
{
    if(e < i or b > j) return 0;
    carry += tr[u];
    if(b >= i and e <= j) return carry;
    ll mid = (b+e) >> 1;
    ll left = query(2*u, b, mid, i, j, carry);
    ll right = query(2*u+1, mid+1, e, i, j, carry);
    return left|right;
}
int main()
{
    init_code();
    ll t;
    scanf("%d", &t);
    for(ll cs = 1; cs <= t; cs++)
    {
        ll n;
        scanf("%d", &n);
        build(1, 1, n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n-1; i++)
        {
            ll l, r;
            scanf("%d %d", &l, &r);
            g[l].pb(r);
            g[r].pb(l);
        }
        timer = 0;
        dfs(0, -1, 0);
        for(int k=1; k<22; k++)
        {
            for(int u=0; u<n; u++)
            {
                if(par[u][k-1] == -1) par[u][k] = -1;
                else par[u][k] = par[par[u][k-1]][k-1];
            }
        }
        for(int i=0; i<n; i++) update(1, 1, timer, st[i], et[i], a[i]);
        ll q;
        scanf("%d", &q);
        printf("Case %d:\n", cs);
        while(q--)
        {
            ll type;
            scanf("%d", &type);
            if(type)
            {
                ll id, x;
                scanf("%d %d", &id, &x);
                ll sum = query(1, 1, timer, st[id], st[id], 0LL);
                if(par[id][0] != -1) sum -= query(1, 1, timer, st[par[id][0]], st[par[id][0]], 0LL);
                update(1, 1, timer, st[id], et[id], x-sum);
                a[id] = x;
            }
            else
            {
                ll l, r;
                scanf("%d %d", &l, &r);
                ll lca = LCA(l, r);
                
                ll suml = query(1, 1, timer, st[l], st[l], 0LL);
                ll sumr = query(1, 1, timer, st[r], st[r], 0LL);
                ll sumz = query(1, 1, timer, st[lca], st[lca], 0LL);
                
                printf("%d\n", suml+sumr-2*sumz+a[lca]);
            }
        }
        for(int i=0; i<n; i++) g[i].clear();
    }
        
     
return 0;
}
