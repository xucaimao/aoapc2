//算法竞赛入门经典第二版 例题6-12 UVa572 油田
//write by xucaimao,20170201-20：58开始编程，测试通过
//本程序采用DFS递归算法

#include<cstdio>
#include<cstring>

const int maxn=100+10;
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];

//递归方式的DFS
void dfs(int r,int c,int id){  
	//printf("dfs(%d,%d,%d)\n",r,c,id);
	if(r<0 || r>=m || c<0 || c>=n) return;  //越界
	if(idx[r][c]>0 || pic[r][c]!='@') return;//不是油田或者已经统计过的格子
	//printf("idx[ %d ][ %d ] = %d\n",r,c,id);
	idx[r][c]=id;//设置被访问记录
	for(int dr=-1;dr<=1;dr++)
		for(int dc=-1;dc<=1;dc++)
			//搜索格子的九个方向(包含自身)
			if(dr!=0 || dc!=0) //格子本身不再搜索，否则会陷入死循环
				dfs(r+dr,c+dc,id);
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
			{	if(idx[i][j]==0 && pic[i][j]=='@') dfs(i,j,++cnt);
				//printf("\n---------------------\n");
			}
		printf("%d\n",cnt);
	}
	return 0;
}