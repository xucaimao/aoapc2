//算法竞赛入门经典第二版 习题4-3 UVa220黑白棋
//write by xucaima,20161129,11:20开始编程.   测试通过
//输入行尾的处理，很重要。标准输入和流输入不要混用
//scanf后，行尾的\n还留在输入队列内，如果后面跟着用getchar，就需要考虑\n的处理
#include<cstdio>
#include<cstring>
char board[10][10];
struct DIRECTION{
	int dr,dc;
};
//定义八个方向的行列坐标增量，从右侧开始顺时针一圈
DIRECTION drc[8]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
void myprint(){
	for(int i=1;i<=8;i++){
		for(int j=0;j<=9;j++)
			printf("%c",board[i][j]);
		printf("\n");
	}	
}

//找到某一位置(r,c)合法走法的数量
//可以简化，当找到合法走法的时候就直接返回
int findlegal(char player,int r,int c){
	if(board[r][c]!='-')return 0;//当前位置已经有棋子了
	int result=0;
	for(int i=0;i<8;i++){ //八个方向寻找
		int dr=drc[i].dr,dc=drc[i].dc;
		int rn,cn;
		rn=r+dr;
		cn=c+dc;
		int op=0;//发现对方的棋子数
		while(rn>=1 && rn<=8 && cn>=1 && cn<=8 ){
			if(board[rn][cn]=='-') break;
			else if(board[rn][cn]!=player)//紧挨着的是对方棋子
						{op++;rn=rn+dr;cn=cn+dc;}//开始寻找下一个棋子
						else{  //发现自己棋子
							if(op>0)result++; //找到一种合法走法，可以扩展程序，记录位置
							break; //反言之，如果发现自己棋子时op=0，则说明两个本方棋子紧挨一起
						}
		}//end of while
		
	}//end of for
	return result;
}

void printlist(char player){
	int tot=0;
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++){
			int t=findlegal(player,i,j);
			tot+=t;
			if(t>0) printf("(%d,%d) ",i,j);
		}
	if(tot==0) printf("No legal move.\n");
	else printf("\n");
}

void mymove(char* order,char player){
	printf("mymove\n");
}

int main(){
	int gamenum;
	char player[10];
	char order[10];
	freopen("e0403.in","r",stdin);
	scanf("%d",&gamenum);
	for(int gn=1;gn<=gamenum;gn++){ //开始一局游戏
		memset(board,' ',sizeof(board));//初始化
		for(int i=1;i<=8;i++){  //读入棋盘
			scanf("%s",order);
			for(int j=0;j<8;j++)
				board[i][j+1]=order[j];
		}
		myprint();
		scanf("%s",player);
		printf("%s\n",player);
		
		//int a=findlegal(player[0],4,6);
		//printf("legal of (4,6) is: %d .\n",a);
		while(scanf("%s",order) && order[0]!='Q'){
			if(order[0]=='L') printlist(player[0]);
			if(order[0]=='M') mymove(order,player[0]);
		}			
	}
	return 0;
}