//算法竞赛入门经典第二版 例题7-1 UVa725 除法
//write by xucaimao,20170212-20:30开始编程，20170212-21:50测试通过

#include<cstdio>
#include<cstring>

int digit[10];

//判断一个整数是多少位数，同时进行统计
int wei(int n){
	int w=0;
	while(n>0){
		w++;//位数加1
		digit[n%10]++;//相应位置1，表明此数字已经被用过
		n/=10;
	}
	return w;
}

//判断0~9是否都被使用过，且只使用过一次
bool allused(){
	for(int i=0;i<10;i++)
		if(digit[i]!=1)return false;
	return true;
}

int main(){
	freopen("f0701.in","r",stdin);
	int n;
	int T=0;
	while(scanf("%d",&n)==1 && n){
		int fz,fm;
		bool havans=false;
		if(T>0)printf("\n");//数据之间加空行
		for(fm=1;fm<50000;fm++){
			memset(digit,0,sizeof(digit));//初始化
			int sum=0;//总位数
			bool firstzero=false;
			fz=fm*n;
			if(fz>99999)break;
			sum=wei(fz)+wei(fm);
			if(sum>10)break;
			//只有9位数字且0没有被使用，则把0加到分母的首位
			if(sum==9 && digit[0]==0){digit[0]=1;sum++;firstzero=true;}
			if(sum==10 && allused() ){
				havans=true;
				printf("%d / ",fz);
				if(firstzero)printf("0");
				printf("%d = %d\n",fm,n);
			}
		}
		if(!havans)printf("There are no solutions for %d.\n",n);
		T++;
	}
}