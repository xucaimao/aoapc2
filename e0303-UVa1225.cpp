//�㷨�������ž���ڶ��� e0303.cpp UVa1225������
//write by xucaima,20161109,13:20
//ʱ������:3s

#include<cstdio>
#include<cstring>

int main()
{
	int ans[10];
	int n,T;
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		scanf("%d",&n);
		for(int i=0;i<=9;i++)  //��ʼ������
			ans[i]=0;
		for(int i=1;i<=n;i++){
			int t=i,d;
			while(t>0){  //ͳ��ÿһ�����������ַ��ĳ���Ƶ��
				d=t%10;
				ans[d]++;
				t=t/10;
			}
		}
		int first=1;  //���ױ�־
		for(int i=0;i<10;i++){
			if(first) first=0;
			else printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}