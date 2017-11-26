//算法竞赛入门经典第二版 例题6-16 UVa10129 Play on Words 
//write by xucaimao,20171105-10:30开始编程，20171112-16:05测试通过
/*
首先要判断度数的合法性： 
1. 所有vertex 的 in-deg == out-deg，
2. 有一个点in-deg == out-deg    + 1 且 还有一点 in-deg + 1 == out-deg

有向图的结论:最多只能有两个点的入度不等于出度,而且必须是其中一个点的出度恰好比
入度大1(把它作为起点),另一个的入度比出度大1(把它作为终点)。
当然,还有一个前提条件:在忽略边的方向后,图必须是连通的。



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
int startp=0,endp=0;//定义连通图的起始点，第0个字符，即'a'


void euler(int u){
	vis[u]=1;
	for(int v=0;v<26;v++)
		if(G[u][v] && !vis[v])
			euler(v);			
}

int main(){
	freopen("f0616.in","r",stdin);
	//freopen("f0616.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(G,0,sizeof(G));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		int N;
		scanf("%d",&N);
		getchar();
		while(N--){//输入N个单词，并初始化相关数据
			scanf("%s",s);
			int u=s[0]-'a';
			int v=s[strlen(s)-1]-'a';
			//考虑到可能出现重复字符，这里要采用增量的方式，不能直接赋值
			G[u][v]++;//有向边
			in[v]++;
			out[u]++;
		}

        int flag=1;
        int num_ne=0;//出入度不相等的节点数
        int num_s=0;//出度大于入度的节点书
        int num_e=0;//入度大于出度的节点数

		for(int i=0;i<26;i++)
			if(out[i]!=in[i]){
				num_ne++;
				if(out[i]==in[i]+1){//出度比入度大1，是起点
					num_s++;
					startp=i;
				}
				else if(in[i]==out[i]+1){//入度比出度大1，是终点
					num_e++;
					endp=i;

				}
				else{flag=0;break;}//出入度差值超过1，肯定不满足条件
				
			}

		
		if(num_ne>2 || num_s>1 || num_e>1)
			flag=0;
		
		if(flag){
			//进入此处暗藏的条件就是：(num_ne==2 || num_s==1 || num_e==1) (欧拉通路)
			//或者三个都等于零(欧拉回路)
			if(num_ne==0){
				//当num_ne==0，startp没有被赋值还是初始值0，需要定位到输入单词中出现的有效字符上
				//此处很关键
				for(int i=0;i<26;i++)
					if(in[i] || out[i]){
						startp=i;
						break;
					}	
			}
			memset(vis,0,sizeof(vis));
			euler(startp);//从最小字符或起点开始搜索

			for (int i = 0; i < 26; i++)
            	if( (in[i] || out[i]) && !vis[i] ) flag = 0;//有有效节点且点没有被访问	
		}

	if(!flag)printf("The door cannot be opened.\n");
	else printf("Ordering is possible.\n");		
		
	}
	return 0;
}
