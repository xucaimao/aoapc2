//算法竞赛入门经典第二版 习题6-5 UVa1600 Patrol Robot
//write by xucaimao,20171029-08:50开始编程，20171102-21:00测试通过
/*由题，(1 ≤ m, n ≤ 20)，(0 ≤ k ≤ 20).最多有20x20=400个元素
刚开始用vis[m][n]二维数组来表示访问状态，调试时遇到一个错误的样例e0605wrong
通过多次debug，才发现是vis状态不对导致的错误。下面是网上关于这个问题的解释：
按照最基本的搜索题，我们都要定义一个vis二维数组，记录该点是否走过，并通过它达到回溯的目的。
但在这题中，机器人走路会有更多的分支选择，比如在走到同一点，有两种同一步数的走法，但是到达这
一点所破除的障碍数量却不同，在这里我们需要选择障碍物更少的，因为很有可能在以后破除障碍能更快
到达终点。用一个vis[][][]三维数组就可以记录这样一种状态，前两维记录坐标，第三维记录已经破除
障碍物的数量，数组值表示走的步数，与上边一样的道理，到达相同点并且破除障碍物数量相同时，应该
选择步数最小的。*/
//本题采用dfs
/*
<<<<<<< HEAD
使用DFS来求解本题代码要更简单一点，DFS求解与BFS求解的主要区别是标志是否访问过某位置的visit
数组改成了到某位置所需要的路径长度dist数组，需要注意递归的条件，具体实现代码如下：
*/
=======
DFS求解与BFS求解的主要区别是:
bfs中，vis[m][n][k]表示是否访问过点(m,n)且深度为k,是一个状态量，非1即0;
dfs中，vis[m][n][k]表示访问到点(m,n)且深度为k时，路径的长度(递归的深度)
 (vis[nm][nn][k]==0  || vis[nm][nn][k]>deep+1) 前面的条件好理解，没有访问过则一定可以直接访问；
 后一个条件则表示，虽然前面已经访问过，但是前面访问时经过的路径比本次长，不是最优解，因此可以重新访问。此条件是难点。
>>>>>>> b61c60d5fce398f888b5c2ad9ed638e339e44313

*/
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Point{
	int m,n;
	int k;//用于记录连续障碍数量
};

const int maxn=25;
const int maxsetp=1000;
int grid[maxn][maxn];//记录网格数据
int vis[maxn][maxn][maxn];//vis[m][n][k]访问到点(m,n)且深度为k时，路径的长度(递归的深度)
Point path[500];
int M,N,K;
queue<Point> que;
int dir[4][2]={ {0,1},{1,0},{-1,0},{0,-1} };//右下上左四个方向m,n的增量
int mindeep;


void dfs(Point p,int deep){

	if(deep>mindeep)return;

	if(p.m==M && p.n==N){//找到一个解
		//printf("One answer is : %d !!\n",p.deep);
		if(deep<mindeep) mindeep=deep;
		return;
	}

	for(int i=0;i<4;i++){//四个方向尝试
		int nm=p.m+dir[i][0];
		int nn=p.n+dir[i][1];
		//先求点的k值
		int k;
		if(grid[nm][nn]==1)k=p.k+1;
		else k=0;

		if(nm>=1 && nm<=M && nn>=1 && nn<=N && k<=K){//在网格范围内且同时满足障碍条件
			if( (vis[nm][nn][k]==0  || vis[nm][nn][k]>deep+1)  ){//未被访问过或者访问到此点的路径长度大于本次
				Point np;
				np.m=nm;np.n=nn;np.k=k;
<<<<<<< HEAD
				vis[nm][nn][k]=1;
				dfs(np,deep+1);
				//vis[nm][nn][k]=0;
=======
				//printf("(%d,%d) deep=%d k=%d ; ",nm,nn,deep,k);
				vis[nm][nn][k]=deep+1;
				dfs(np,deep+1);
>>>>>>> b61c60d5fce398f888b5c2ad9ed638e339e44313
			}
		}
	}


}

int main(){
	freopen("e0605.in","r",stdin);
	int T=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&M,&N,&K);
		memset(grid,0,sizeof(grid));
		memset(vis,0,sizeof(vis));
		for(int m=1;m<=M;m++){
			for(int n=1;n<=N;n++)
				scanf("%d",&grid[m][n]);//读入一行网格数据
		}
		mindeep=maxsetp;	
		
		Point p;
		p.m=1;p.n=1;p.k=0;
		vis[1][1][0]=1;
		dfs(p,0);

		if(mindeep==maxsetp)printf("-1\n");
		else printf("%d\n",mindeep);
	}
	return 0;
}