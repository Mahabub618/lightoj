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
int blk_mod[320][4], to_add[320], n, m, sz, a[N];
int query(int l, int r)
{
    int lb = l/sz;
    int lr = r/sz;
    int cnt = 0;
    if(lb == lr)
    {
        for(int i=l; i<=r; i++)
        {
            int blk = i/sz;
            if((a[i]+to_add[blk])%3 == 0) cnt++;
        }
    }
    else
    {
        for(int i=lb+1; i<=lr-1; i++)
        {
            cnt += blk_mod[i][(3+(3-to_add[i])%3)%3];
        }
        int k = (lb+1)*sz-1;
        for(int i=l; i<=k; i++)
        {
            int blk = i/sz;
            if((a[i]+to_add[blk])%3 == 0) cnt++;
        }
        for(int i=lr*sz; i<=r; i++)
        {
            int blk = i/sz;
            if((a[i]+to_add[blk]) % 3 == 0) cnt++;
        }
    }
    return cnt;
}
int main()
{
    init_code();
     int t, l, r;
     scanf("%d", &t);
     for(int cs = 1; cs <= t; cs++)
     {
        scanf("%d %d", &n, &m);
        sz = sqrt(n);
        for(int i=0; i<n; i++) blk_mod[i/sz][0]++;
        printf("Case %d:\n", cs);
        while(m--)
        {
            int type;
            scanf("%d", &type);
            if(type == 0)
            {
                scanf("%d %d", &l, &r);
                int lb = l/sz;
                int lr = r/sz;
                if(lb == lr)
                {
                    for(int i=l; i<=r; i++)
                    {
                        blk_mod[lb][a[i]%3]--;
                        a[i] += 1;
                        blk_mod[lb][a[i]%3]++;
                    }
                }
                else
                {
                    for(int i=lb+1; i<=lr-1; i++) to_add[i]+=1;
                    int k = ((lb+1)*sz)-1;
                    for(int i=l; i<=k; i++)
                    {
                        blk_mod[lb][a[i]%3]--;
                        a[i]+=1;
                        blk_mod[lb][a[i]%3]++;
                    }
                    for(int i=lr*sz; i<=r; i++)
                    {
                        blk_mod[lr][a[i]%3]--;
                        a[i]+=1;
                        blk_mod[lr][a[i]%3]++;
                    }
                }
            
            }
            else
            {
                scanf("%d %d", &l, &r);
                printf("%d\n", query(l, r));
            }
        }
        for(int i=0; i<=n; i++)
        {
            to_add[i] = 0;
            a[i] = 0;
            for(int j=0; j<4; j++) blk_mod[i][j] = 0;
        }
     }
return 0;
}
