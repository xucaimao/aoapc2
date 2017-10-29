//算法竞赛入门经典第二版 习题6-3 UVa536 Tree Recovery 
//write by xucaimao,20171029开始编程，20171028-00:30测试通过
//是书上例题6-8 UVa548的变形
//关键是以什么方式来存储二叉树
//1.先采用链表来储存
//2.由题，每个二叉树的节点数不会超过26个，尝试采用静态数组来构建二叉树.输入都是大写字母，ascii值<100
//直接用ascii码作为节点的值
//本程序采用链表
//TODO

#include<cstdio>
#include<cstring>

struct Node{
	char value;
	Node *left,*right;
	Node():left(NULL),right(NULL){}
};

const int maxv=100;
char preorder[maxv],inorder[maxv];
int lch[maxv],rch[maxv];

//根据preorder[Pl..Pr] 和 inorder[Il..Ir]中的数据建成一颗二叉树，返回树的根
int build(int Pl,int Pr,int Il,int Ir){
	if(Il>Ir) return 0;
	int root=(int)preorder[Pl];//前序遍历的首字符就是根,
	int p=Il;
	while( (int)inorder[p]!=root ) p++;
	int cnt=p-Il; //左子树的节点数
	lch[root]=build(Pl+1,Pl+cnt,Il,p-1);
	rch[root]=build(Pl+cnt+1,Pr,p+1,Ir);
	return root;
}

void dfs(int n){
	if(n==0)return;
	dfs(lch[n]);
	dfs(rch[n]);
	printf("%c",(char)n);
}

int main(){
	//freopen("e0603.in","r",stdin);
	while( scanf("%s%s",preorder,inorder)==2 ){
		int n=strlen(preorder);
		build(0,n-1,0,n-1);
		dfs( (int)preorder[0] );
		printf("\n");
	}
	return 0;
}

