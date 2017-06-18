//算法竞赛入门经典第二版 e0302.cpp UVa1586分子量
//write by xucaima,20161109,11:30
//

#include<cstdio>
#include<cstring>

int main()
{
	char s[81];
	
	int T;
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		scanf("%s",s);
		double mass=0;
		int len=strlen(s);
		for(int i=0;i<len;){
			int n=0;
			double t=0;
			switch(s[i]){ //查找各元素的分子量
				case'C':
					t=12.01;
					break;
				case'H':
					t=1.008;
					break;
				case'O':
					t=16.0;
					break;
				case'N':
					t=14.01;
					break;
				default:
					break;
			}
			i++;//查找下一个字符
			//计算各原子的数量n>=2,n<=99
			//也就是说，元素符号后面可以跟着多位数字字符
			while(s[i]>='0' && s[i]<='9' && i<len){ 
				n=n*10+(s[i]-'0');  
				i++;
			}
			if(n==0) n=1;
			t*=n;
			mass+=t;
		}
		printf("%.3lf\n",mass);
	}
	return 0;
}