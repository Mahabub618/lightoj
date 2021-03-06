    ///Created: 2020-07-02-22.58
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
    const int N = 501;
    char ar[N][N];
    int vis[N][N], ans[N][N], tot, n, m;
    int ok(int x, int y)
    {
        if(x>0 and x<=n and y>0 and y<=m and vis[x][y]==0 and (ar[x][y]=='.' or ar[x][y]=='C'))
        {
            return 1;
        }
        else return 0;
    }
    void allclear()
    {
        memset(vis, 0, sizeof vis);
    }
    int bfs(int a, int b)
    {
        tot = 0;
        queue<pii> q;
        pii pa;
        q.push({a, b});
        vis[a][b]=1;
        while(!q.empty())
        {
            pa = q.front();
            q.pop();
            int x = pa.F;
            int y = pa.S;

            for(int k=0; k<4; k++)
            {
                int xx = x+fx[k];
                int yy = y+fy[k];

                int res = ok(xx, yy);
                if(res==1)
                {
                    if(ar[xx][yy]=='C') tot++;
                    vis[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
        }
        return tot;
    }

    int32_t main()
    {
        //Don't see test case until get 7/8 times wrong submission..!!
        //Try to make Corner, Even, Odd or Prime case..!!
        FastIO;
        int t, cas=1, q, x, y;
        cin >> t;
        while(t--)
        {
            char ch;
            memset(ans, -1, sizeof ans);
            cin >> n >> m >> q;
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++) cin >> ar[i][j];
            }

            //printf("Case %d:\n", cas++);
            cout << "Case " << cas++ << ":" << endl;
            while(q--)
            {
                allclear();
                cin >> x >> y;
                if(ans[x][y]==-1)
                {
                    int cnt = bfs(x, y);
                    for(int i=1; i<=n; i++)
                    {
                        for(int j=1; j<=m; j++)
                        {
                            if(vis[i][j]) ans[i][j] = cnt;
                        }
                    }
                }
                cout << ans[x][y] << endl;
            }
        }

    }

