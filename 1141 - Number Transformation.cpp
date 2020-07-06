
    ///Created: 2020-07-01-01.23
    /*****************************************************************\
         IN THE NAME OF ALLAH, MOST GRACIOUS AND MOST MERCIFUL       |
    |                                                                 |
    |     Author     : Mahabub Rahman                                 |
    |     Email      : mahabubrahman618@gmail.com                     |
    |     University : Comilla University, Bangladesh              |
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
    #define       debug(x) cerr << #x << " = " << x << endl
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
    #define       min3(a,b,c)          min(a,b<c?b:c)
    #define       max3(a,b,c)          max(a,b>c?b:c)
    #define       all(v)               v.begin(), v.end()
    //#define f(x) (64 - __builtin_clzll(x))
    ////============ CONSTANT ===============////
    #define mx9   1000000007
    #define mx7   10000007
    #define mx6   2000006
    #define mx5   200005
    #define inf   1<<30                                           //infinity value
    #define eps   1e-9
    #define mod   mx9
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
        if(a.second==b.second) return a.first<b.first;
        else return (a.second > b.second);
    }
    bool cmp(pair<string ,int > x , pair<string ,int > y)
    {
        return x.second < y.second;
    }
    int fx[9] = { 0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 } ;
    int fy[9] = { -1 , 1 , 0 , 0 , -1 , 1 , -1 , 1 } ;
    /*ll fact(ll n)
    {
        if(n==0 || n==1) return 1;
        else return n*fact(n-1);
    }*/
    void NA()
    {
        cout << "NO" << endl;
        exit(0);
    }
    void YA()
    {
        cout << "YES" << endl;
        exit(0);
    }

    ////=================FUNCTION=====================////
    /*bool check(int n)
    {
        if(n==1) return false;
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }*/
    /*ll bigmod(ll a, ll b, ll m)
    {
        if(b==0)return 1%m;
        ll x = bigmod(a, b/2, m);
        x = (x*x)%m;
        if(b%2==1) x = (x*a)%m;
        return x;
    }*/
    /*bool flag[mx5];
    veci prime;
    void sieve()
    {
        prime.pb(2);
        for(ll i=3; i*i<=100000; i+=2)
        {
            if(flag[i]) continue;
            for(ll j=i*i; j<=100000; j+=i+i) flag[j] = true;
        }
        for(int i=3; i<=100000; i+=2) if(!flag[i]) prime.pb(i);
    }*/
    ////=================START_FROM_HERE=====================////
    const int N = 1005;
    int d[N], dis[N], vis[N];

    int bfs(int src, int des)
    {
        dis[src]=0;
        vis[src]=1;
        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            //cout << "v = " << v << " dis = " << dis[v] << endl;
            if(v==des) return dis[v];
            if(d[v]==v) continue;
            vector<int> fac;
            int x = v;
            while(x>1)
            {
                int k = d[x];
                while(x%k==0) x/=k;
                fac.pb(k);
            }

            for(int i=0; i<fac.size(); i++)
            {
                int u = v+fac[i];
                if(vis[u]==0 and u<=des)
                {
                    vis[u] = 1;
                    dis[u] = dis[v]+1;
                    q.push(u);
                }
            }

        }
        return -1;
    }
    int32_t main()
    {
        //Don't see test case until get 7/8 times wrong submission..!!
        //Try to make Corner, Even, Odd or Prime case..!!
        FastIO;
        for(int i=2; i<N; i++)
        {
            if(!d[i])
            {
                for(int j=i; j<N; j+=i) d[j]=i;
            }
        }

        int t, a, b, cas=1;
        cin >> t;
        while(t--)
        {
            memset(vis, 0, sizeof vis);
            memset(dis, 0, sizeof dis);
            cin >> a >> b;
            int ans = bfs(a, b);
            cout << "Case " << cas++ << ": " << ans << endl;
        }

    }
