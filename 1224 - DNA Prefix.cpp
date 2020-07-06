
    #include<bits/stdc++.h>
    #define ll long long int

    using namespace std;

    const int n = 2500000+3;
    //ll to[n][26];
    map<pair<int, int>, int> to;
    int tot=1;
    int cnt[n];
    ll ma = 0;

    void add_string(string s)
    {
        int cur = 1;
        cnt[cur]++;
        for(int i=0; i<s.size(); i++)
        {
            int ch = s[i]-'A';
            if(!to[{cur, ch}]) to[{cur, ch}] = ++tot;
            cur = to[{cur, ch}];
            cnt[cur]++;
            ma = max(ma, cnt[cur]*(i+1)*1LL);
        }
    }

    int main()
    {
        int t, cas=1;
        scanf("%d", &t);
        while(t--)
        {
            memset(cnt, 0, sizeof cnt);
            to.clear();
            tot = 1;
            ma = 0;
            int tt;
            string s;
            scanf("%d", &tt);
            for(ll i=0; i<tt; i++)
            {
                cin >> s;
                int l = s.size();
                ma = max(ma, l*1LL);
                add_string(s);
            }
            printf("Case %d: %d\n", cas++, ma);
        }
    }
