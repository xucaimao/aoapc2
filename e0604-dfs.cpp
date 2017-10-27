//算法竞赛入门经典第二版 习题6-1 UVa439 Knight Moves 
//write by xucaimao,20171025-22:30开始编程，20171027-14:20测试通过
//直接对字符进行运算，省去了来回转换的麻烦，程序更直观
//可能有多种走法，每种走法所需要的步数是不同的。所以需要判断求最小值。
//收获:有些时候DFS没有特定的边界,需要自己设置一个合适的边界。这题推导可知，任意两点之间
//马踩6步之内一定能够到达，6步之内还未搜到说明绝对不是最优结果，果断退出。所以这里的res开始
//时最小设定为6即可，随着设的res的增大，运行时间越来越多，因为深搜可以有很多的分支，不采取较
//的边界的话，可能会浪费很多时间在无用的搜索上，所以需要剪枝。
//res设不同值的运行时间如下：
//res = 6    39ms
//res = 32  TLE !!! 


#include<cstdio>
#include<cstring>

int vis[8][8];//走过点的状态数组
int tx,ty;//目标点坐标
//八个方向移动，每一个方向[x,y]的增量值
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int minstep;

//求从坐标(x,y)到(tx,ty)的移动过程
//其实是一个dfs的过程
void dfs(int x,int y,int step){
	//步数超出既有解，不接着往下计算
	if(step>=minstep) return;		//这里其实就是一个剪枝
		
	//超出棋盘范围
	if(x<0 || x>7 || y<0 || y>7) return;		//这里其实就是一个剪枝
	
	if(x==tx && y==ty){
		//到目的地,只保存小的步数
		if(step<minstep)
			minstep=step;
		return;
	}
		
	for(int i=0;i<8;i++){
		//走一步棋,此处注意不能改变函数入口参数的值
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		//下面的语句一定要加上，否则会出现又回到前面已经走过的点，从而陷入死循环
		//e8 c7是个特例，调试中发现的奇葩
		if(!vis[nx][ny]){
			//保存数据
			vis[nx][ny]=1;
			dfs(nx,ny,step+1);
			//恢复数据
			vis[nx][ny]=0;
		}
		
	}
}

int main(){
	char ss[5];//初始位置
	char ts[5];//目标位置
	int sx,sy;//初始位置xy坐标
	freopen("e0604-1.in","r",stdin);
	while( scanf("%s%s",ss,ts)==2 ){
		sx=ss[0]-'a';//字母变成x坐标[0...7]
		sy=ss[1]-'1';//数字变成y坐标[0...7]
		tx=ts[0]-'a';
		ty=ts[1]-'1';
		minstep=6;
		memset(vis,0,sizeof(vis));
		dfs(sx,sy,0);
		printf("To get from %s to %s takes %d knight moves.\n",ss,ts,minstep);
	}
	return 0;
}
