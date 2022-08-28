/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/
#include<bits/stdc++.h>
using namespace std;
#define       ll                  long long int
#define       pb                   push_back
#define       newline cerr << endl
#define       S                    second
#define       nl                   "\n"

const int N = 1e7+7;
bitset<N> flag;
vector<ll> prime, v, ans;
void Sieve()
{
    for(int i=4; i<N; i+=2) flag[i] = 1;
    for(int i=3; i*i<N; i+=2)
    {
        if(flag[i]) continue;
        for(int j=i*i; j<N; j+=(2*i)) flag[j] = 1;
    }
    prime.pb(2);
    for(int i=3; i<N; i+=2)
    {
        if(!flag[i]) prime.pb(i);
    }
}
int segmented_sieve(ll l, ll r)
{
    ll root = sqrt(r)+1;
    
    for(ll i=l; i<=r; i++) v.pb(i);
        
    if(l == 0) v[1] = 0;
    else if(l == 1) v[0] = 0;
    
    for(ll i=0; prime[i]<=root; i++)
    {
        ll p = prime[i];
        ll start = p*p;
        if(start < l) start = ((l+p-1)/p)*p;
        for(ll j=start; j<=r; j+=p) v[j-l] = 0;
    }
    for(ll i=l; i<=r; i++)
    {
        if(v[i-l] != 0) ans.pb(v[i-l]);
    }
    return ans.size();
    
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
    Sieve();
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++)
    {
        ll l, r;
        cin >> l >> r;
        cout << "Case " << cs << ": " << segmented_sieve(l, r) << nl;
        v.clear();
        ans.clear();
    }
return 0;
}
