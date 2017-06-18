//算法竞赛入门经典第二版 例题6-15 UVa10305 给任务排序
//write by xucaimao,20170206-20:30开始编程，20170208-22:30测试通过
//udebug测试有问题，解不是唯一的，本程序求出的只是一种解。

#include<cstdio>
#include<cstring>//memset

const int maxn=105;
int g[maxn][maxn];
int topo[maxn];//用于存放拓扑序列
int visit[maxn];//访问状态
int n,m,t;

bool dfs(int u){
	visit[u]=-1;//正在递归访问中
	for(int v=1;v<=n;v++) 
		if(g[u][v]){//u<v
			if(visit[v]<0)return false;//
			else if(!visit[v] && !dfs(v)) return false;
		}
	visit[u]=1;//访问结束,说明u向后可以连通
	topo[--t]=u;
	return true;
}

//对n个任务排序
bool toposort(){
	t=n;
	memset(visit,0,sizeof(visit));
	memset(topo,0,sizeof(topo));
	for(int u=1;u<=n;u++)
		if(!visit[u] && !dfs(u) )return false;
	return true;
}

int main(){
	
	freopen("f0615.in","r",stdin);
	while(scanf("%d%d",&n,&m)==2 && (n || m) ){
		int i,j;
		memset(g,0,sizeof(g));
		for(int k=0;k<m;k++){
			scanf("%d%d",&i,&j);
			g[i][j]=1;
			//printf("%d %d ",i,j);
		}
		//printf("\n");
		if(toposort() ){
			for(int k=0;k<n;k++){
				if(k>0)printf(" ");//行头行尾没有多余的空格
				printf("%d",topo[k]);
			}
			printf("\n");
		}
	}
	return 0;
}
	