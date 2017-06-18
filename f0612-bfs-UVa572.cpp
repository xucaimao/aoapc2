//算法竞赛入门经典第二版 例题6-12 UVa572 油田
//write by xucaimao,20170203-20:30开始编程，20170203-21:24测试通过
//本程序采用BFS算法

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct NODE{int r,c;};
const int maxn=100+10;
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];
queue<NODE> q;

//非递归方式的BFS
void bfs(int r,int c,int id){  
	NODE u,root;
	root.r=r;root.c=c;
	idx[r][c]=id;//设置被访问记录
	q.push(root);//根节点入队
	while(!q.empty() ){
		u=q.front();//队首出对
		q.pop();
		r=u.r;
		c=u.c;
		//搜索格子的九个相邻方向(包含自身)
		//本例采用循环方式遍历，可以修改为其他方式
		for(int dr=-1;dr<=1;dr++)
			for(int dc=-1;dc<=1;dc++)
				if(dr!=0 || dc!=0){ //格子本身不再搜索，否则会陷入死循环
					int r1=r+dr;
					int c1=c+dc;
					if(r1<0 || r1>=m || c1<0 || c1>=n) continue;  //越界
					else if(idx[r1][c1]>0 || pic[r1][c1]!='@') continue;//不是油田或者已经统计过的格子
					else {//符合条件的相邻块记录并入队
						idx[r1][c1]=id;//设置被访问记录
						u.r=r1;u.c=c1;
						q.push(u);
					}	
				} 
	}	
}

int main(){
	freopen("f0612.in","r",stdin);
	while(scanf("%d%d",&m,&n)==2 && m && n){
		for(int i=0;i<m;i++)  //读入油田数据
			scanf("%s",pic[i]);
		memset(idx,0,sizeof(idx));  //初始化访问状态
		int cnt=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++) 
				//pic[i][j]=='@'且[i][j]没有被访问过
				if(idx[i][j]==0 && pic[i][j]=='@') bfs(i,j,++cnt);
		printf("%d\n",cnt);
	}
	return 0;
}