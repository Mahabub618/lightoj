
#include <bits/stdc++.h>
using namespace std;
string grid[12];
bool vis[12][12];
int dis[12][12];
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
int n;
bool valid(int x, int y, char ch){
    if(x<0 || x == n || y<0||y == n || grid[x][y] == '#') return false;
    else if(grid[x][y]>= 'A'&& grid[x][y]<= 'Z' && grid[x][y]  > ch+1) return false;
    return true;
}
int bfs(char ch, int x, int y){
    list< pair<int, int> >q;
    q.push_back(make_pair(x, y));
    vis[x][y]= true;
    dis[x][y] = 0;
    while(!q.empty()){
        int fromx = q.front().first;
        int fromy = q.front().second;
        vis[fromx][fromy] = true;
        q.pop_front();
        for(int i = 0; i < 4; i++){
            int tox = fromx + dx[i];
            int toy = fromy + dy[i];
            if(!valid(tox, toy, ch)) continue;
            if(vis[tox][toy]) continue;
            vis[tox][toy] = true;
            q.push_back(make_pair(tox, toy));
            dis[tox][toy] = dis[fromx][fromy] + 1;
            if(grid[tox][toy] == ch+1) return dis[tox][toy];
        }
    }
    return -1;
}
int main(){
    int ts;
    scanf("%d", &ts);
    for(int p = 1; p <= ts; p++){
    memset(vis, false, sizeof(vis));
    memset(dis, false, sizeof(dis));
    scanf("%d", &n);
    int co = 0;
    pair<int,int> positions[26];
    for(int i = 0; i <n; i++){
        //scanf("%s", grid[i]);
        cin>>grid[i];
        for(int j = 0; j <grid[i].size(); j++){
            if(grid[i][j]>= 'A' && grid[i][j]<= 'Z'){
                positions[grid[i][j]-'A'].first = i;
                positions[grid[i][j]-'A'].second = j;
                co++;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i <co-1; i++){
        int val = bfs('A'+i, positions[i].first, positions[i].second);
        if(val == -1) {
            sum = -1;
            break;
        }
        sum+= val;
        memset(vis, false, sizeof(vis));
        memset(dis, false, sizeof(dis));

    }
    if(sum == -1) printf("Case %d: Impossible\n", p);
    else printf("Case %d: %d\n",p, sum);
    }
    return 0;
}
