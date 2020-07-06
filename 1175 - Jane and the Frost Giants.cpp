    ///Created: 2020-07-03-23.34
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
/*----------------------Graph Moves----------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

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
    const int N = 201;
    int vis[N][N], jx, jy, ffx, ffy, n, m;
    int dif[N][N], dij[N][N];
    queue<pii> q;
    char mat[N][N];

    int ok(int x, int y)
    {
        if(x>=0 and x<n and y>=0 and y<m and vis[x][y]==0 and mat[x][y]=='.') return 1;
        else return 0;
    }

    void bfs(int flag)
    {
        pii pa;
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
                    if(flag==1) dij[xx][yy] = dij[x][y]+1;
                    if(flag==2) dif[xx][yy] = dif[x][y]+1;
                    vis[xx][yy] = 1;
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
        int t, cas=1;
        cin >> t;
        while(t--)
        {
            memset(vis, 0, sizeof vis);
            memset(mat, 0, sizeof mat);
            memset(dif, 0, sizeof dif);
            memset(dij, 0, sizeof dij);

            cin >> n >> m;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    dif[i][j]=1e9;
                    dij[i][j]=1e9;
                }
            }
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    cin >> mat[i][j];
                    if(mat[i][j]=='J')
                    {
                        jx = i;
                        jy = j;
                        dij[i][j]=1;
                    }
                    if(mat[i][j]=='F')
                    {
                        dif[i][j]=1;
                        vis[i][j]=1;
                        q.push({i, j});
                    }
                }
            }
            bfs(2);
            while(!q.empty()) q.pop();

            q.push({jx, jy});
            memset(vis, 0, sizeof vis);
            bfs(1);
            bool ok = false;
            int ans = INT_MAX;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if((i==0 or i==n-1) or (j==0 or j==m-1))
                    {
                        if(dij[i][j])
                        {
                            if(dij[i][j]<dif[i][j])
                            {
                                ok = true;
                                ans = min(ans, dij[i][j]);
                            }
                        }
                    }
                }
            }

            cout << "Case " << cas++ << ": ";
            ok == false ? cout << "IMPOSSIBLE" << endl : cout << ans << endl;
        }
    }


