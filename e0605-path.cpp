//算法竞赛入门经典第二版 习题6-5 UVa1600 Patrol Robot
//write by xucaimao,20171029-08:50开始编程，20171029-12:17测试通过
/*由题，(1 ≤ m, n ≤ 20)，(0 ≤ k ≤ 20).最多有20x20=400个元素
刚开始用vis[m][n]二维数组来表示访问状态，调试时遇到一个错误的样例e0605wrong
通过多次debug，才发现是vis状态不对导致的错误。下面是网上关于这个问题的解释
按照最基本的搜索题，我们都要定义一个vis二维数组，记录该点是否走过，并通过它达到回溯的目的。
但在这题中，机器人走路会有更多的分支选择，比如在走到同一点，有两种同一步数的走法，但是到达这
一点所破除的障碍数量却不同，在这里我们需要选择障碍物更少的，因为很有可能在以后破除障碍能更快
到达终点。用一个vis[][][]三维数组就可以记录这样一种状态，前两维记录坐标，第三维记录已经破除
障碍物的数量，数组值表示走的步数，与上边一样的道理，到达相同点并且破除障碍物数量相同时，应该
选择步数最小的。*/
//增加打印路径的功能，路径的记录也要通过三维数组。同时路径的回溯也很有难度
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

struct Point{
	int m,n;
	int deep;//总路径长度
	int k;//用于记录连续障碍数量
};

const int maxn=25;
const int maxdeep=10000;
int grid[maxn][maxn];//记录网格数据
int vis[maxn][maxn][maxn];//此处是错误的根源，开始的时候少了第三维度
Point father[maxn][maxn][maxn];//parent[m][n]的值就是点m,n的父节点
Point minfa[maxn][maxn][maxn];
int M,N,K;
queue<Point> que;
Point pend;//用于记录最后的目标点

int dir[4][2]={ {0,1},{1,0},{-1,0},{0,-1} };//右下上左四个方向m,n的增量
int mindeep;
int datanum=0;//总的数据组数

void printpath(Point fa[maxn][maxn][maxn]){
	vector<Point> path;
	path.clear();
	Point p=pend;//此处也是一个关键点。
	while(true){
		if(p.m>=1 && p.m<=M && p.n>=1 && p.n<=N){
			path.push_back(p);
			if(p.m==1 && p.n==1)break;
			p=fa[p.m][p.n][p.k];
			
		}
		else{
			printf("Error!!!\n");
			return;
		} 	
	}
	int len=path.size();
	for(int i=len-1;i>=0;i--)
		printf("（%2d,%2d） ",path[i].m,path[i].n);
	printf("\n");
}

void bfs(){
	Point p;
	p.m=1;p.n=1;p.deep=0;p.k=0;
	que.push(p);//(1,1)进入队列
	vis[1][1][0]=1;
	father[1][1][0]=p;//记录路径的首点
	while(!que.empty()){
		p=que.front();//队首元素出队列，此处掌握有问题
		que.pop();
		//if(p.m==12 && p.n==1)
			//printf("To 12,1\n");
		if(p.m==M && p.n==N){//找到一个解
			//printf("One answer is : %d !!\n",p.deep);
			if(p.deep<mindeep) {
				mindeep=p.deep;
				//在此处记录很关键。开始在95行记录，有个别case通不过。
				pend=p;//记录路径的最后一点。必须有这一步，然后由这一点回溯得到完整的路径。
				memcpy(minfa,father,sizeof(father));//保存最短路径
			}
			continue;
		}
		for(int i=0;i<4;i++){//四个方向尝试
			int nm=p.m+dir[i][0];
			int nn=p.n+dir[i][1];
			//先求点的k值
			int k;
			if(grid[nm][nn]==1)k=p.k+1;
			else k=0;

			if(nm>=1 && nm<=M && nn>=1 && nn<=N && !vis[nm][nn][k]){//在网格范围内且未被访问过
				if(k<=K){//同时满足障碍条件
					Point np;
					np.m=nm;np.n=nn;np.deep=p.deep+1;np.k=k;
					que.push(np);
					//pend=np;
					father[nm][nn][k]=p;//记录点[nm,nn]的父节点
					//printf("push %d,%d \n",nm,nn);
					vis[nm][nn][k]=1;
				}
			}
		}
	}
}

int main(){
	freopen("e0605.in","r",stdin);
	scanf("%d",&datanum);
	int di=1;
	while(datanum--){
		scanf("%d%d%d",&M,&N,&K);
		memset(grid,0,sizeof(grid));
		memset(vis,0,sizeof(vis));
		memset(father,0,sizeof(father));
		memset(minfa,0,sizeof(minfa));
		for(int m=1;m<=M;m++){
			for(int n=1;n<=N;n++)
				scanf("%d",&grid[m][n]);//读入一行网格数据
		}
		mindeep=maxdeep;	
		bfs();
		printf("DATA %d :",di++);
		if(mindeep==maxdeep)printf("No path to move!!\n");
		else if(mindeep==0)printf("No move!!\n");
		else{
			printf("Need %d steps to move!!\n",mindeep);
			printpath(minfa);
		} 
	}
	return 0;
}