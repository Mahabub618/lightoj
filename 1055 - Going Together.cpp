    ///Crated: 2020-07-04-01.28
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
    const int N = 11;
    char s[N][N];
    map<pii, int> m;
    int vis[N][N][N][N][N][N], dis[N][N][N][N][N][N];
    int n;

    void allclear()
    {
        m.clear();
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
    }

    struct st
    {
        pii a, b, c;
    };
    int ok(pii x)
    {
        if(x.F>=0 and x.F<n and x.S>=0 and x.S<n and s[x.F][x.S]!='#') return 1;
        else return 0;
    }
    int bfs(st src)
    {
        queue<st> q;
        st pa;
        q.push(src);
        vis[src.a.F][src.a.S][src.b.F][src.b.S][src.c.F][src.c.S]=1;
        dis[src.a.F][src.a.S][src.b.F][src.b.S][src.c.F][src.c.S]=0;
        while(!q.empty())
        {
            pa = q.front();
            q.pop();
            if(m[pa.a] and m[pa.b] and m[pa.c] and pa.a!=pa.b and pa.a!=pa.c and pa.b!=pa.c)
            {
                return dis[pa.a.F][pa.a.S][pa.b.F][pa.b.S][pa.c.F][pa.c.S];
            }

            for(int k=0; k<4; k++)
            {
                pii aa = pii(pa.a.F+fx[k], pa.a.S+fy[k]);
                if(!ok(aa)) aa = pa.a;

                pii bb = pii(pa.b.F+fx[k], pa.b.S+fy[k]);
                if(!ok(bb)) bb = pa.b;

                pii cc = pii(pa.c.F+fx[k], pa.c.S+fy[k]);
                if(!ok(cc)) cc = pa.c;

                if(aa==bb)
                {
                    //if(bb==cc) cc=pa.c;
                    aa = pa.a;
                    bb = pa.b;
                }
                if(aa==cc)
                {
                    aa = pa.a;
                    cc = pa.c;
                }
                if(bb==cc)
                {
                    bb = pa.b;
                    cc = pa.c;
                    //if(aa==bb) aa=pa.a;
                }
                st v;
                v.a = aa;
                v.b = bb;
                v.c = cc;
                if(vis[v.a.F][v.a.S][v.b.F][v.b.S][v.c.F][v.c.S]==0)
                {
                    vis[v.a.F][v.a.S][v.b.F][v.b.S][v.c.F][v.c.S]=1;
                    dis[v.a.F][v.a.S][v.b.F][v.b.S][v.c.F][v.c.S]=dis[pa.a.F][pa.a.S][pa.b.F][pa.b.S][pa.c.F][pa.c.S]+1;
                    q.push(v);
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
        int t, cas=1;
        cin >> t;
        while(t--)
        {
            allclear();
            st pa;
            cin >> n;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cin >> s[i][j];
                    if(s[i][j]=='X') m[pii(i,j)]=1;
                    if(s[i][j]=='A') pa.a=pii(i, j);
                    if(s[i][j]=='B') pa.b=pii(i, j);
                    if(s[i][j]=='C') pa.c=pii(i, j);
                }
            }
            int ans = bfs(pa);
            cout << "Case " << cas++ << ": ";
            ans == -1 ? cout << "trapped" << endl : cout << ans << endl;

        }

    }
