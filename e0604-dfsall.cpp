//算法竞赛入门经典第二版 习题6-1 UVa439 Knight Moves 
//write by xucaimao,20171025-22:30开始编程，201710测试通过
//直接对字符进行运算，省去了来回转换的麻烦，程序更直观
//可能有多种走法，每种走法所需要的步数是不同的。所以需要判断求最小值。
#include<cstdio>

int board[8][8];
char ss[5];//初始位置
char ts[5];//目标位置
//八个方向移动，每一个方向[字母,数字]的增量值
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int minstep;

char ans[10000][2];//用数组模拟的路径记录的栈
int stop;//栈顶指针

//其实是一个dfs的过程
//入口是字母坐标和数字坐标的两个字符
void dfs(char pchr,char pnum,int step){	
	//超出棋盘范围
	if(pchr<'a' || pchr>'h' || pnum<'1' || pnum>'8') return;		//这里其实就是一个剪枝
	
	if(pchr==ts[0] && pnum==ts[1]){
		//到目的地,开始打印输出路径
		if(step==0)printf("Not to move!!\n");
		else{
			printf("Total %d steps !!!\n",step);
			for(int i=0;i<=stop;i++)printf("%c%c  ",ans[i][0],ans[i][1]);	
			printf("\n");
		}	
		return;
	}
		
	for(int i=0;i<8;i++){
		//走一步棋
		char npchr=pchr+dir[i][0];
		char npnum=pnum+dir[i][1];
		//保存数据
		stop++;
		ans[stop][0]=npchr;
		ans[stop][1]=npnum;
		dfs(npchr,npnum,step+1);
		//恢复数据的处理
		stop--;
	}
}

int main(){
	freopen("e0604.in","r",stdin);
	while( scanf("%s%s",ss,ts)==2 ){
		minstep=1000;
		//起点位置入栈
		stop=0;
		ans[stop][0]=ss[0];
		ans[stop][1]=ss[1];
		printf("The way from %s to %s are:\n",ss,ts);
		dfs(ss[0],ss[1],0);
		//printf("To get from %s to %s takes %d knight moves.\n",ss,ts,minstep);
	}
	return 0;
}
