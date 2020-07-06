
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
    const int N = 200;
    int vis[N][N], dis[N][N], n, m;
    int ans1, ans2, ans3;
    char ar[N][N];

    int ok(int x, int y)
    {
        if(x>=0 and x<n and y>=0 and y<m and (ar[x][y]=='.' or ar[x][y]=='a' or ar[x][y]=='b' or ar[x][y]=='c') and vis[x][y]==0)
        {
            return 1;
        }
        else return 0;
    }

    int bfs(int h, int hh, char c)
    {
        queue<pii> q;
        pii pa;
        q.push({h, hh});
        vis[h][hh]=1;
        dis[h][hh]=0;

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
                    dis[xx][yy] = dis[x][y]+1;
                    if(ar[xx][yy]==c)
                    {
                        if(c=='a') ans1 = min(ans1, dis[xx][yy]);
                        if(c=='b') ans2 = min(ans2, dis[xx][yy]);
                        if(c=='c') ans3 = min(ans3, dis[xx][yy]);
                    }
                    vis[xx][yy]=1;
                    q.push({xx, yy});
                }
            }

        }
    }

    int32_t main()
    {
        //Don't see test case until get 7/8 times wrong submission..!!
        //Try to make Corner, Even, Odd or Prime case..!!
        FastIO;
        int t, a, b, cas=1, x, y;
        cin >> t;
        while(t--)
        {
            ans1=INT_MAX, ans2=INT_MAX, ans3=INT_MAX;
            cin >> n >> m;
            int h, hh;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    cin >> ar[i][j];
                    if(ar[i][j]=='h') h=i, hh=j;
                }
            }
            memset(vis, 0, sizeof vis);
            memset(dis, 0, sizeof dis);
            bfs(h, hh, 'a');

            memset(vis, 0, sizeof vis);
            memset(dis, 0, sizeof dis);
            bfs(h, hh, 'b');

            memset(vis, 0, sizeof vis);
            memset(dis, 0, sizeof dis);
            bfs(h, hh, 'c');
            //debug(ans1);
            //debug(ans2);
            //debug(ans3);
            cout << "Case " << cas++ << ": " << max(ans1, max(ans2, ans3)) << endl;
        }

    }
