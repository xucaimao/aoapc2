//算法竞赛入门经典第二版 习题6-1 UVa439 Knight Moves 
//write by xucaimao,20171025-22:30开始编程，20171026-13:00测试通过
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
char ss[5];//初始位置
char ts[5];//目标位置
//八个方向移动，每一个方向[字母,数字]的增量值
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int minstep;

//其实是一个dfs的过程
//入口是字母坐标和数字坐标的两个字符
void dfs(char pchr,char pnum,int step){
	//步数超出既有解，不接着往下计算
	if(step>=minstep) return;		//这里其实就是一个剪枝
		
	//超出棋盘范围
	if(pchr<'a' || pchr>'h' || pnum<'1' || pnum>'8') return;		//这里其实就是一个剪枝
	
	if(pchr==ts[0] && pnum==ts[1]){
		//到目的地,只保存小的步数
		if(step<minstep)
			minstep=step;
		return;
	}
		
	for(int i=0;i<8;i++){
		//走一步棋,此处注意不能改变函数入口参数的值
		char npchr=pchr+dir[i][0];
		char npnum=pnum+dir[i][1];
		//下面的语句一定要加上，否则会出现又回到前面已经走过的点，从而陷入死循环
		//e8 c7是个特例，调试中发现的奇葩
		if(vis[npchr-'a'][npnum-'0']) continue;
		//保存数据
		vis[npchr-'a'][npnum-'0']=1;
		dfs(npchr,npnum,step+1);
		//恢复数据
		vis[npchr-'a'][npnum-'0']=0;
	}
}

int main(){
	freopen("e0604.in","r",stdin);
	while( scanf("%s%s",ss,ts)==2 ){
		minstep=6;
		memset(vis,0,sizeof(vis));
		vis[ss[0]-'a'][ss[1]-'0']=1;
		dfs(ss[0],ss[1],0);
		printf("To get from %s to %s takes %d knight moves.\n",ss,ts,minstep);
	}
	return 0;
}
