//算法竞赛入门经典第二版 习题6-1 UVa439 Knight Moves 
//write by xucaimao,20171025-22:30开始编程，201710测试通过
//直接对字符进行运算，省去了来回转换的麻烦，程序更直观
//可能有多种走法，每种走法所需要的步数是不同的。所以需要判断求最小值。
#include<cstdio>
#include<cstring>

int vis[8][8];//走过点的状态数组
char ss[5];//初始位置
char ts[5];//目标位置
//八个方向移动，每一个方向[字母,数字]的增量值
short int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int minstep;
int maxstep;
long int ansnum=0;//实现本目标，所有的走法的数量
//棋盘8x8，最多走64步
char ans[100][2];//用数组模拟的栈，记录走过的路径
char minans[100][2];//记录最短路径
int stop;//栈顶指针

//本函数求从一点到达另一点的所有可以的走法。但走法太多，不具有实际意义
//并可以输出走棋的过程
//入口是字母坐标和数字坐标的两个字符
void dfsall(char pchr,char pnum,int step){	
	//超出棋盘范围
	if(pchr<'a' || pchr>'h' || pnum<'1' || pnum>'8') return;		//这里其实就是一个剪枝
	
	if(pchr==ts[0] && pnum==ts[1]){
		ansnum++;
		//记录最大最小走法
		if(step>maxstep)maxstep=step;
		if(step<minstep){
			minstep=step;
			memcpy(minans,ans,sizeof(ans));
		}
		return;
	}
		
	for(int i=0;i<8;i++){
		//走一步棋
		char npchr=pchr+dir[i][0];
		char npnum=pnum+dir[i][1];
		//此语句一定要加上，否则会出现又回到前面已经走过的点，从而陷入死循环
		//e8 c7是个特例，调试中发现的奇葩
		if(vis[npchr-'a'][npnum-'0']) continue;
		//保存数据
		vis[npchr-'a'][npnum-'0']=1;
		stop++;
		ans[stop][0]=npchr;
		ans[stop][1]=npnum;
		dfsall(npchr,npnum,step+1);
		//恢复数据的处理
		vis[npchr-'a'][npnum-'0']=0;
		ans[stop][0]='\0';
		ans[stop][1]='\0';
		stop--;
	}
}

int main(){
	freopen("e0604.in","r",stdin);
	while( scanf("%s%s",ss,ts)==2 ){
		minstep=1000;
		maxstep=-1;
		memset(vis,0,sizeof(vis));
		vis[ss[0]-'a'][ss[1]-'0']=1;
		//起点位置入栈
		stop=0;
		ans[stop][0]=ss[0];
		ans[stop][1]=ss[1];

		dfsall(ss[0],ss[1],0);
		printf("The are %ld ways from %s to %s !!!\n",ansnum,ss,ts);
		printf("The are %d steps in max way!!\n ",maxstep);
		printf("The are %d steps in min way!!\n ",minstep);
		printf("The min way is: \n");
		for(int j=0;j<minstep;j++)printf("%c%c  ",minans[j][0],minans[j][1]);	
		printf("\n");
	}
	return 0;
}
