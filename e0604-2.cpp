//算法竞赛入门经典第二版 习题6-1 UVa439 Knight Moves 
//write by xucaimao,20171025-22:30开始编程，201710测试通过
//可能有多种走法，每种走法所需要的步数是不同的。所以需要判断求最小值。
#include<cstdio>

int board[8][8];
char ss[5];
char ts[5];
//八个方向移动，每一个方向[r,c]值
int dir[8][2]={{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};
int minstep;
int tr,tc;//目标位置
char ans[10000][2];//用数组模拟的路径记录的栈
int stop;//栈顶指针

//判断棋子是否在棋盘上
bool isOnBoard(int row,int col){
	if(row<0 || row>7 || col<0 || col>7)
		return false;
	else 
		return true;
}

//修改成打印所有解的程序
void dfsAll(int sr,int sc,int step){
	if(sr==tr && sc==tc){
		//到目的地,打印一种解
		for(int i=0;i<=stop;i++)
			printf("%c%c ",ans[i][0],ans[i][1]);
		printf("\n");
		return;
	}
	//超出棋盘范围
	if(!isOnBoard(sr,sc)) 
		return;		//这里其实就是一个剪枝
	//步数超出既有解，不接着往下计算
	//if(step>minstep) return;		//要求所有解，这里就不能剪枝
	for(int i=0;i<8;i++){
		//走一步棋,此处注意不能改变函数入口的sr,sc的值
		int nsr=sr+dir[i][0];
		int nsc=sc+dir[i][1];
		stop++;
		ans[stop][0]=nsr+'a';
		ans[stop][1]=nsr+'1';
		dfsAll(nsr,nsc,step+1);
		stop--;
		//因为前面没有改变值，这里就不需要做恢复数据的处理
		}
}


int main(){
	freopen("e0604-2.in","r",stdin);
	while( scanf("%s%s",ss,ts)==2 ){
		printf("Input pos is : %s and %s !!\n",ss,ts);
		stop=0;
		int sr,sc;	//初始和目标位置
		sc=ss[0]-'a';
		sr=ss[1]-'1';
		tc=ts[0]-'a';
		tr=ts[1]-'1';
		ans[0][0]=ss[0];
		ans[0][1]=ss[1];
		printf("The path is : \n");
		dfsAll(sr,sc,0);
		
	}
	return 0;
}
