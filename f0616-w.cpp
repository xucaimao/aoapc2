/*
 欧拉道路的定义是： 除了起点和终点外， 其他点的“进出” 次数应该相等。 换句话说，除了起点和
 终点外， 其他点的度数应该是偶数。
对于有向图， 则必须其中一个点的出度恰好比入度大1， 另一个的入度比出度大。
如果奇点数不存在的话， 则可以从任意点出发，最终一定会回到该点（成为欧拉回路）。
题目给的单词量比较大，但是有用的只有首和尾的字母，所以只需要存首尾字母就可以了。 
欧拉道路还有关键的一部是判断这一个图是连通的， 并且只有一个一个连通分支。
这个可以用并查集的方法， 也可一用dfs直接搜索。
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100;

int T, n, G[maxn][maxn], c[maxn], in[maxn], out[maxn];
int vis[maxn];

void dfs(int u)
{
    vis[u] = 1;　　　　　　　　　　　　　　　　//访问标记
    for (int v =0; v < 26; v++)　　　　　　 //字母节点
        if (!vis[v] && G[u][v]) dfs(v);　　//没有被访问并且有有向边
}

int main()
{
    char s[2000];
    scanf("%d", &T);
    while (T--) {
        memset(vis, 1, sizeof(vis));
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        scanf("%d", &n);

        for (int i =0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s);
            int r = s[0]-'a';　　　　　　//首
            int t = s[len-1] - 'a';　　 //尾
            G[r][t] = 1;　　　　　　　　　//有有向边
            in[t]++;out[r]++;          //很重要！！！，出入度别写反了,
            vis[r] = vis[t] = 0;　　　　//将其置为未访问状态
        }
        int flag = 0;
        int p = 0, cnt1 = 0, cnt2 =0, cnt3 = 0;
        for (int i = 0; i < 26; i++) {
                if (out[i] == in[i])
                    continue;　　　　　　//环的情况
                if (out[i] == in[i]+1) {
                    cnt1++;p = i;　　　　//起始点
                } else if (in[i] == out[i] + 1)
                    cnt2++;　　　　　　　　//其余点
                else
                    cnt3++;　　　　　　　//没有满足
        }
        if (cnt3 > 0) {
            printf("The door cannot be opened.\n");
            continue;
        }
　　　　 // 环或者是
        if (cnt1==1 &&cnt2 == 1 || cnt1==0 && cnt2==0)
            flag = 1;
        else
            flag = 0;
        dfs(p);
        for (int i = 0; i < 26; i++)
            if(!vis[i]) flag = 0;
        if (flag) printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}