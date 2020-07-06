
#include<bits/stdc++.h>

using namespace std;
#define pa pair<int, int>
#define white 0
#define black 1
#define FastIO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
vector<vector<pa> > a;
bool visited[100005];
int cas=1, lc, rc, n, cnt;
void dfs(int u)
{
    visited[u]=true;

    for(int i=0; i<2; i++)
    {
        int temp = a[u][i].first;
        if(!visited[temp])
        {
            if(a[u][i].second<0) rc+=abs(a[u][i].second);
            else lc+=a[u][i].second;

          dfs(temp);
        }
    }
}
int main()
{
    FastIO;
    int u,v,s, t;
    cin >> t;
    while(t--)
    {
        a.clear();
        memset(visited, false, sizeof visited);
        cin >> n;
        a.resize(n);
        for(int i=0; i<n; i++)
        {
            cin >> u >> v >> s;
            a[--u].push_back(pa(--v, s));
            a[v].push_back(pa(u, -s));
        }
        lc=0, rc=0;
        dfs(0);
        int v1 = a[0][0].second;
        int v2 = a[0][1].second;
        if((v1>0 && v2>0) ||(v1<0 and v2>0))
        {
            rc += abs(v2);
        }
        else lc+=abs(v2);

        cout << "Case " << cas++ << ": " << min(lc, rc) << endl;
    }
    return 0;
}
