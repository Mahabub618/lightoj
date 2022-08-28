#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll tr[4*N], lz[4*N], a[N];
void propagate(int u, int st, int en)
{
    if(!lz[u]) return;
    tr[u] += (1LL*(en-st+1)*lz[u]);
    if(st!=en)
    {
        lz[2*u] += lz[u];
        lz[2*u+1] += lz[u];
    }
    lz[u] = 0;
}
void build(int u, int b, int e)
{
    if(b == e)
    {
        tr[u] = a[b];
        return;
    }
    int mid = (b+e) >> 1;
    build(2*u, b, mid);
    build(2*u+1, mid+1, e);
    tr[u] = tr[2*u] + tr[2*u+1];
}
void update(int u, int st, int en, int l, int r, int x)
{
    propagate(u, st, en);
    if(r < st or en < l) return;
    else if(l <= st and en <= r)
    {
        lz[u] += x;
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
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}
int main()
{
    init_code();
    int n, m, t, type, l, r, x;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++)
    {
        memset(a, 0, sizeof a);
        memset(tr, 0, sizeof tr);
        memset(lz, 0, sizeof lz);
        
        scanf("%d %d", &n, &m);
        build(1, 1, n);
        printf("Case %d:\n", cs);
        while(m--)
        {
            scanf("%d", &type);
            if(type == 0)
            {
                scanf("%d %d %d", &l, &r, &x);
                l++, r++;
                update(1, 1, n, l, r, x);
            }
            else
            {
                scanf("%d %d", &l, &r);
                l++, r++;
                printf("%lld\n", query(1, 1, n, l, r));
            }            
        }
    }
     
return 0;
}
