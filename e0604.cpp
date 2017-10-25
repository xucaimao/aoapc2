//算法竞赛入门经典第二版 习题6-1 UVa439 Knight Moves 
//write by xucaimao,20171025-22:30开始编程，201710测试通过
//可能有多种走法，每种走法所需要的步数是不同的。所以需要判断求最小值。
#include<cstdio>
#include<que>

int board[8][8];
char ss[5];
char ts[5];
//八个方向移动，每一个方向[r,c]值
int dir[8][2]={{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};
int minstep;
int tr,tc;//目标位置
que<> ans;

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
		solve(nsr,nsc,step+1);
		//因为前面没有改变值，这里就不需要做恢复数据的处理
		}
}

//其实是一个dfs的过程
void solve(int sr,int sc,int step){
	if(sr==tr && sc==tc){
		//到目的地
		if(step<minstep)minstep=step;
		return;
	}
	//超出棋盘范围
	if(!isOnBoard(sr,sc)) 
		return;		//这里其实就是一个剪枝
	//步数超出既有解，不接着往下计算
	if(step>minstep) 
		return;		//这里其实就是一个剪枝
	for(int i=0;i<8;i++){
		//走一步棋,此处注意不能改变函数入口的sr,sc的值
		int nsr=sr+dir[i][0];
		int nsc=sc+dir[i][1];
		solve(nsr,nsc,step+1);
		//因为前面没有改变值，这里就不需要做恢复数据的处理
		}
}

int main(){
	freopen("e0604.in","r",stdin);
	while( scanf("%s%s",ss,ts)==2 ){
		//minstep=100000;
		//printf("Input pos is : %s and %s !!\n",ss,ts);
		int sr,sc;	//初始和目标位置
		sc=ss[0]-'a';
		sr=ss[1]-'1';
		tc=ts[0]-'a';
		tr=ts[1]-'1';
		//printf("Input pos is : r%d,c%d and r%d,c%d !!\n",sr,sc,tr,tc);
		solve(sr,sc,0);
		printf("To get from %s to %s takes %d knight moves.\n",ss,ts,minstep);
	}
	return 0;
}
