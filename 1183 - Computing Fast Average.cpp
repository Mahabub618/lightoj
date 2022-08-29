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
const int N = 1e5+5;
ll tr[4*N], lz[4*N];
void build(int u, int l, int r)
{
    if(l == r)
    {
        tr[u] = lz[u] = 0;
        return;
    }
    int mid = (l+r)>>1;
    build(2*u, l, mid);
    build(2*u+1, mid+1, r);
    tr[u] = lz[u] = 0;
}
void propagate(int u, int st, int en)
{
    if(lz[u] == -1) return;
    tr[u] = (en-st+1)*lz[u];
    if(st!=en)
    {
        lz[2*u] = lz[u];
        lz[2*u+1] = lz[u];
    }
    lz[u] = -1;
}

void update(int u, int st, int en, int l, int r, ll x)
{
    propagate(u, st, en);
    if(r < st or en < l) return;
    else if(l <= st and en <= r)
    {
        lz[u]  = x;
        propagate(u, st, en);
        return;
    }
     int mid = (st+en) >> 1;
     update(2*u, st, mid, l, r, x);
     update(2*u+1, mid+1, en, l, r, x);
     tr[u] = tr[2*u] + tr[2*u+1];
}
ll query(int u, int st, int en, int l, int r)
{
    propagate(u, st, en);
    if(r < st or en < l) return 0;
    else if(l <= st and en <= r) return tr[u];

    int mid = (st+en) >> 1;
    return (query(2*u, st, mid, l, r) + query(2*u+1, mid+1, en, l, r));

}
int main()
{
    init_code();
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++)
    {
        int n, m, type, l, r, x;
        scanf("%d %d", &n, &m);
        build(1, 1, n);
        printf("Case %d:\n", cs);
        while(m--)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                scanf("%d %d %d", &l, &r, &x);
                l++, r++;
                update(1, 1, n, l, r, x);
            }
            else
            {
                scanf("%d %d", &l, &r);
                l++, r++;
                ll sum = query(1, 1, n, l, r);
                ll d = r-l+1;
                //debug4(l, r, sum, d);
                if(sum % d == 0) printf("%lld\n", sum/d);
                else
                {
                    ll gcd = __gcd(sum, d);
                    printf("%lld/%lld\n", sum/gcd, d/gcd);
                }
            }
        }
    }
     
return 0;
}
