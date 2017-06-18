//算法竞赛入门经典第二版 例题6-17 UVa10562 看图写树
//write by xucaimao,20170210-21:00开始编程，20170210-22:10测试通过
#include<cstdio>
#include<cstring>
#include<cctype>

const int maxn=200+10;
char tree[maxn][maxn];
int maxrow;

//递归遍历以tree[r][c]为根节点的子树
void dfs(int r,int c){
	printf("%c(",tree[r][c]);//打印根节点
	if(r+1<maxrow && tree[r+1][c]=='|'){//该节点有子树
		int i=c;
		while(i-1>=0 && tree[r+2][i-1]=='-') i--;//找左边界
		//处理一行(r+3)叶子节点
		//根据题意，叶子节点的上方一定是'-'.同时考虑行(r+3)数据输入是否结束
		while(tree[r+2][i]=='-' && tree[r+3][i]!='\0'){
			if(!isspace(tree[r+3][i])) dfs(r+3,i);
			i++;//处理右边的节点
		}
	}
	printf(")");
}

void solve(){
	maxrow=0;
	for(;;){
		fgets(tree[maxrow],maxn,stdin);//读入一行数据
		if(tree[maxrow][0]=='#')break;//数据输入结束
		else maxrow++;
	}
	
	//printf("data row is: %d\n",maxrow);
	//for(int i=0;i<maxrow;i++)
		//printf("%s",tree[i]);
	//printf("***************\n");
	
	printf("(");//行首
	if(maxrow>0){//有输入时(考虑空输入的特殊情况)
		for(int i=0;i<strlen(tree[0]);i++)
			if(tree[0][i]!=' '){dfs(0,i);break;}
	}
	printf(")\n");//行尾
}

int main(){
	freopen("f0617.in","r",stdin);
	int T;
	scanf("%d",&T);
	getchar();//读取行尾的\n
	while(T--) solve();
	return 0;
}
