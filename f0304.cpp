//算法竞赛入门经典第二版 f0304.cpp 竖式问题
//write by xucaima,20161108,12:44
//重点是sprintf、strchr两个函数的使用

#include<cstdio>
#include<cstring>

int main()
{
	char s[20],t[20];  //s存放初始字符序列，t存放竖式中的所有数字
	int num=0;
	scanf("%s",s);
	for(int abc=100;abc<=999;abc++)
		for(int de=10;de<=99;de++){
			int x=abc*(de%10),y=abc*(de/10),z=abc*de;
			sprintf(t,"%d%d%d%d%d",abc,de,x,y,z);
			int ins=1;
			for(int i=0;i<strlen(t);i++)
				if(strchr(s,t[i])==NULL) ins=0; //如果竖式有字符不在序列内，ins置0
			if(ins){ //竖式中所有的字符都在序列内
				num++;
				printf("%d\n",num);
				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
			}
		}
	printf("The number of solutions = %d\n",num);
	return 0;		
}