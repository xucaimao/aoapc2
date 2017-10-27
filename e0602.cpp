//算法竞赛入门经典第二版 习题6-2 UVa712 S-Trees
//write by xucaimao,20171027-21:30开始编程，20171028-00:30测试通过
//题目看了好久才明白，重点是第二行的数据Xi Xj Xk 决定了第五行开始的命令序列的执行顺序
//deep>=1 deep<=7,算上最后一层叶子节点，树的实际深度应当<=8,叶子节点最大的数量应该是2^(8-1)=2^7=128
//命令序列的长度和树的深度deep相等

#include <cstdio>
#include <cstring>
#include <cmath>
char leaf[200];		//用于保存第三行(叶子)数据
char command[10];	//用于保存从第五行开始的命令序列
int ord[10];		//用于保存第二行(命令顺序)
char ans[200];		//保存答案

int main(){
	freopen("e0602.in","r",stdin);
	int deep,cnum;
	char s[5];
	int treenum=0;
	while(scanf("%d",&deep) && deep){
		memset(ans,0,sizeof(ans));
		treenum++;
		getchar();//去掉deep后面的换行
		for(int i=0;i<deep;i++){
			//读入并处理第二行数据
			scanf("%s",s);
			ord[i]=s[1]-'0'-1;			//没有减一，此处是一个坑
		}

		scanf("%s",leaf);				//读入第三行数据
		scanf("%d",&cnum);				//读入m值
		char c=getchar();//去掉cnum后面的换行

		for(int i=0;i<cnum;i++){		//处理多行命令序列
			scanf("%s",command);		//读入一行命令序列
			int p=0;					//定位到根节点
			for(int j=0;j<deep;j++){	//处理一行命令序列
				int cmd=command[ ord[j] ]-'0';	//根据顺序取得实际执行的命令
				if(cmd==0) p=p*2+1;		//往左走
				else p=p*2+2;			//往右走
			}
			//二叉树最后一层节点的序号与leaf数组下标的转换,是重点
			//乘方函数不熟悉，以及类型转换
			ans[i]=leaf[p- (int)(pow(2,deep)-1)];	
		}
		ans[cnum]='\0';		//加入结束标志
		printf("S-Tree #%d:\n",treenum );
		printf("%s\n\n", ans);
	}
	return 0;
}