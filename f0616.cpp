//算法竞赛入门经典第二版 例题6-16 UVa10129 Play on Words 
//write by xucaimao,20171105-10:30开始编程，20170208-22:30测试通过
/*
首先要判断度数的合法性： 即 所有vertex 的 in-deg == out-deg，
或 有一个点in-deg == out-deg    + 1 且 还有一点 in-deg + 1 == out-deg
有向图的结论:最多只能有两个点的入度不等于出度,而且
必须是其中一个点的出度恰好比入度大1(把它作为起点),另一个的入度比出度大1(把它
作为终点)。当然,还有一个前提条件:在忽略边的方向后,图必须是连通的。



出入度与我们正常的理解刚好相反
出度 (out-degree) 是指以某顶点为弧尾，起始于该顶点的弧的数目。
入度 (in-degree) ：以某顶点为弧头，终止于该顶点的弧的数目称为该顶点的入度
*/
#include<cstdio>
#include<cstring>
const int maxn=26+4;
int G[maxn][maxn];//联通图
int in[maxn];
int out[maxn];
int vis[maxn];
char s[1010];


void euler(int u){
	vis[u]--;
	for(int v=0;v<26;v++)
		if(G[u][v] && vis[v]>0)
			euler(v);			
}

int main(){
	freopen("f0616.in","r",stdin);
	freopen("f0616.out","w",stdout);
	int T;
	scanf("%d",&T);cl
	while(T--){
		int N;
		scanf("%d",&N);
		getchar();
		while(N--){//输入N个单词，并初始化相关数据
			memset(G,0,sizeof(G));
			memset(vis,0,sizeof(vis));
			memset(s,0,sizeof(s));

			scanf("%s",s);
			int u=s[0]-'a';
			int v=s[strlen(s)-1]-'a';
			//考虑到可能出现重复字符，这里要采用增量的方式，不能直接赋值
			G[u][v]++;//有向边
			in[v]++;
			out[u]++;
			vis[u]++;
			vis[v]++;//将其置为未访问状态
        }

		int p=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=0;i<26;i++){
			if(out[i]=in[i])//出入度相等
				continue;
			if(out[i]=in[i]+1){//出度比入度大1，是起点
				cnt1++;p=i;
			}
			else if(in[i]=out[i]+1)//入度比出度大1，是终点
				cnt2++;
			else
				cnt3++;
		}
		if(cnt3>0){
			printf("The door cannot be opened.\n");
			continue;
		}

		int flag=0;
		if(cnt1==1 && cnt2==1 || cnt1==0 && cnt2==0){
			//各有一个出入点，有通路；或者是回路
			flag=1;
			euler(p);//从最小字符开始搜索
			for (int i = 0; i < 26; i++)
            	if(pvis[i]) flag = 0;//有点没有被访问
		}

		if(flag)printf("The door cannot be opened.\n");
		else printf("Ordering is possible.\n");
	}
	return 0;
}
