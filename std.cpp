//Find the mininum circle that passes through a point in an undirected graph
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 2005
using namespace std;
int n,m;
int G[N][N];
bool vis[N];
int fa[N];
int ans = 0x3f3f3f3f;
int qlm(int);
int LCA(int, int, int);
void dfs(int,int,int,const int &);
int sum_err = 0;
int pnf = 0;
int perr[N];
int err[N];
int main(){
    freopen("in.txt", "r", stdin);
    freopen("std.txt", "w", stdout);
    char s[10];
    while (scanf("%s",s)!=EOF) {
        if(s[1]=='p') {
            scanf("%d%s%d%d",&n, s, &m, &m);
            puts("Ok");
        }
        else if (s[1]=='r') {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if (G[x][y] > 0) {
                ++ pnf;
                ++ err[x], ++ err[y];
                if (x > y)
                    swap(x, y);
                printf("er-%d, %d-%d, %d-%d\n", pnf, x, err[x], y, err[y]);
                continue;
            }
            G[x][y]=G[y][x]=z;
            puts("Ok");
        }
        else if (s[1]=='l') {
            int x;
            scanf("%d",&x);
            memset(fa, 0, sizeof(fa));
            memset(vis,0,sizeof(vis));
            ans = 0x3f3f3f3f;
            // dfs(x, 0, 0, x);
            ans = qlm(x);
            if (ans == 0x3f3f3f3f) {
                ++ sum_err;
                ++ perr[x];
                printf("pnf-%d, %d-%d\n", sum_err, x, perr[x]);
                continue;
            }
            printf("%d\n",ans);
        }
    }
    fclose(stdin);fclose(stdout);
}
void dfs(int u,int sum,int fa,const int &aim){
    for(int v=1;v<=n;++v) {
        if (vis[v]) {
            continue;
        }
        if(G[u][v]>0) {
            if (v==aim && fa!=aim) {
                ans=min(ans,sum+G[u][v]);
            }
            else {
                vis[v]=1;
                dfs(v, sum+G[u][v], u, aim);
                vis[v]=0;
            }
        }
    }
}
int LCA(int x,int y, int r){
    if(fa[x]==0 || fa[y]==0)
        return 0;
    while (fa[x] != r)
        x = fa[x];
    while (fa[y] != r)
        y = fa[y];
    return (x==y) ? 0 : 1;
}
int qlm(int x){
    //dijkstra
    int dis[N];
    for(int i=1;i<=n;i++) {
        vis[i] = false;
        dis[i] = 0x3f3f3f3f;
        if (G[x][i] > 0) {
            dis[i]=G[x][i];
            fa[i]=x;
        }
    }
    vis[x]=true;
    for(int i=1;i<=n;i++){
        int u=-1;
        for(int v=1;v<=n;v++)
            if(!vis[v]&&(u==-1||dis[v]<dis[u]))
                u=v;
        if(u==-1)
            break;
        vis[u]=true;
        for(int v=1;v<=n;v++)
            if(!vis[v] && G[u][v] > 0) {
                if (dis[u] + G[u][v] < dis[v]) {
                    dis[v] = dis[u]+G[u][v];
                    fa[v]=u;
                }
            }
    }
    int ans=0x3f3f3f3f;
    for (int u = 1; u <= n; ++ u) {
        if (u == x) continue;
        for (int v = 1; v <= n; ++v) {
            if (u == v || v == x) continue;
            if (G[u][v] > 0 && LCA(u, v, x)) {
                ans = min (ans, G[u][v] + dis[u] + dis[v]);
            }
        }
    }
    for(int v=1;v<=n;v++) {
        if (G[x][v] > 0 && fa[v] != x) {
            ans = min (ans, G[x][v] + dis[v]);
        }
    }
    return ans;
}