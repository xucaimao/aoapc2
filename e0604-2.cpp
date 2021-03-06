//算法竞赛入门经典第二版 习题6-1 UVa439 Knight Moves 
//write by xucaimao,20171025-22:30开始编程，20171026-23:00测试通过
//直接对字符进行运算，省去了来回转换的麻烦，程序更直观
//可能有多种走法，每种走法所需要的步数是不同的。所以需要判断求最小值。
#include<cstdio>
char ss[5];//初始位置
char ts[5];//目标位置
//八个方向移动，每一个方向[字母,数字]的增量值
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int minstep;

//其实是一个dfs的过程
//入口是字母坐标和数字坐标的两个字符
void dfs(char pchr,char pnum,int step){
	//printf("%c%c step=%d\n",pchr,pnum,step);
	
	//步数超出既有解，不接着往下计算
	//这个剪枝也规避了本函数隐含的bug,即本函数有可能会陷入死循环
	//没有对前面的落点进行记录和判断，后面有可能又回到前面走过的点上面
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
		//走一步棋,此处注意不能改变函数入口的sr,sc的值
		char npchr=pchr+dir[i][0];
		char npnum=pnum+dir[i][1];
		dfs(npchr,npnum,step+1);
		//因为前面没有改变值，这里就不需要做恢复数据的处理
	}
}

int main(){
	freopen("e0604.in","r",stdin);
	while( scanf("%s%s",ss,ts)==2 ){
		minstep=6;
		//printf("Input pos is : %s and %s !!\n",ss,ts);
		dfs(ss[0],ss[1],0);
		printf("To get from %s to %s takes %d knight moves.\n",ss,ts,minstep);
	}
	return 0;
}
