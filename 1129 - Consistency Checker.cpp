
 #include<bits/stdc++.h>
    #define ll long long int
    using namespace std;

    const int n = 1e5+100;
    int to[n][10];
    int tot=1;
    int cnt[n];

    void add_string(string s)
    {
        int cur = 1;
        cnt[cur]++;
        for(int i=0; i<s.size(); i++)
        {
            int ch = s[i]-'0';
            if(!to[cur][ch]) to[cur][ch] = ++tot;
            cur = to[cur][ch];
            cnt[cur]++;
        }
    }
    int query(string s)
    {
        int cur = 1;
        for(int i=0; i<s.size(); i++)
        {
            int ch = s[i]-'0';
            if(!to[cur][ch]) return 0;
            cur = to[cur][ch];
        }
        return cnt[cur];
    }

    int main()
    {
        ll t, cas=1;
        cin >> t;
        while(t--)
        {
            memset(cnt, 0, sizeof cnt);
            memset(to, 0, sizeof(to));
            tot = 1;
            bool ok = true;
            int tt;
            string s;
            vector<string> ss;
            cin >> tt;
            for(int i=0; i<tt; i++)
            {
                cin >> s;
                ss.push_back(s);
                add_string(s);
            }
            //cout << "Tot = " << tot << endl;
            for(int i=0; i<tt; i++)
            {
                int k = query(ss[i]);
                if(k>1)
                {
                    ok = false;
                    break;
                }
            }
            ok == true ? cout << "Case " << cas++ << ": YES" << endl  : cout << "Case " << cas++ << ": NO" << endl;
        }
    }

