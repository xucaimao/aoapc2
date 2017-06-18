//算法竞赛入门经典第二版习题3-7 UVa1368 DNA序列
//write by xucaima,20161117,17:00.20161117,21:17测试通过.
//时间限制:3s

#include<cstdio>
#include<cstring>

char dna[50][1010];//存储DNA序列

struct Dna{  //中间结果的结构体,便于采用循环对四种字符进行测试
const char d;
int ham;
};

struct Ans{  //计算结果的结构体
char d[1010];//每列的计算结果
int ham[1010];//每列的hamming值
int hamtotal;//总的hamming值
};

//主要函数
Ans hamm(int m,int n)
{
	Ans ans;
    for(int c=0;c<n;c++){ //对列进行操作
        Dna dd[4]={{'A',0},{'C',0},{'G',0},{'T',0}};//定义中间结果并初始化，按字典顺序排列
        for(int i=0;i<4;i++){ //分别求ACGT四个符号，对每一列字符的hamming值的累加和
            int ham=0;
            for(int r=0;r<m;r++)
                if(dna[r][c]!=dd[i].d) ham++;
            dd[i].ham=ham;
        }
        ans.d[c]=dd[0].d;//先把'A'及其hamming值作为最小值
        ans.ham[c]=dd[0].ham;
        for(int i=1;i<4;i++)
            if(dd[i].ham<ans.ham[c]){ //求最小值，当最小值一样时，输出的是字典顺序小的那个值
            ans.ham[c]=dd[i].ham;
            ans.d[c]=dd[i].d;
        }

    }
    ans.d[n]='\0';//设置字符串尾标志
    ans.hamtotal=0;
    for(int i=0;i<n;i++)  //累加总的hamming值
        ans.hamtotal+=ans.ham[i];
	return ans;
}

int main()
{
	int m,n,tt;
	//freopen("e0307.in","r",stdin);//重定向到文件输入，提交程序时需要注释掉此行
	scanf("%d",&tt);  //读入测试数据总数量

	for(int t=0;t<tt;t++){
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
			scanf("%s",dna[i]);//读入DNA序列

        Ans answer=hamm(m,n);
		//打印相应的DNA序列及hamming值
		printf("%s\n",answer.d);
		//for(int i=0;i<n;i++) printf("%d ",answer.ham[i]);
		//printf("\n");
		printf("%d\n",answer.hamtotal);

	}
	return 0;
}


