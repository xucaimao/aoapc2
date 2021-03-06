#include<cstdio>
#include<cstring>
const int MAXN=12;
char m[MAXN][MAXN];
int mn[MAXN][MAXN];//起始格序号
char w[MAXN];
int row,col;

//初始化起始格序号
void initmn()
{
	int wn=0;
	for(int r=0;r<MAXN;r++)
		for(int c=0;c<MAXN;c++)
			mn[r][c]=0;
	for(int r=0;r<row;r++)
		for(int c=0;c<col;c++){
			if(m[r][c]=='*') //此处开始错写成mn[r][c]，调试时折磨了我许久
				continue;  //跳出本次循环
			if(r-1<0 || c-1<0 || m[r-1][c]=='*' || m[r][c-1]=='*')
					{wn++;
					mn[r][c]=wn;}
		}
}


//打印横向单词新版
//按照起始格来处理
void across()
{
	printf("Across\n");
	for(int r=0;r<row;++r)
		{
			int c=0;
			while(c<col)
			{
				if(mn[r][c] == 0 || m[r][c] =='*') //不是起始格,处理后续字符
				{
					c++;
					continue;
				}
				printf("%3d.%c",mn[r][c],m[r][c]); //是起始格，打印起始格号与首字符
				c++;
				while(c<col && m[r][c]!='*')//打印本行其余字符直至遇到'*'
				{
					printf("%c",m[r][c]);
					c++;
				}
				printf("\n");
			}
		}

}

//打印竖向单词
//如果按列处理，不能按照起始格序号的顺序输出，需要重点考虑顺序问题
//仍然按行列处理，即按照起始格的大小顺序进行处理
void down()
{
	printf("Down\n");
	for(int r=0;r<row;r++){
		for(int c=0;c<col;c++){
			if(mn[r][c]==0 || m[r][c]=='*')
				continue;
			printf("%3d.%c",mn[r][c],m[r][c]);//是起始格，打印起始格号与首字符
			mn[r][c]=0;  //处理过的起始格置0
			int k=r+1;
			while(k<row && m[k][c]!='*'){  //打印本列其余字符直至遇到'*'
				printf("%c",m[k][c]);
				mn[k][c]=0; //处理过的起始格置0
				k++;
			}
			printf("\n");
		}
	}
}

int main()
{
	//freopen("e0306.in","r",stdin);//重定向到文件输入，提交程序时需要注释掉此行
	int gn=0;
	while(scanf("%d%d",&row,&col)==2 && row!=0){
		gn++;
		if(gn>1)printf("\n");//控制最前及最后没有多余的空行
		for(int r=0;r<row;r++)  //读入网格数据
			scanf("%s",&m[r]);
		printf("puzzle #%d:\n",gn);
		initmn();
		across();
		down();
	}
	return 0;
}


