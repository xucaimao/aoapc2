//�㷨�������ž���ڶ��� f0305.cpp ����Ԫ
//write by xucaima,20161108,13:49
//

#include<cstdio>
int yuan[100001]={0};//�����ֵΪ�±��Ӧ������Ԫ

int main()
{
	int num,d;
	for(int n=1;n<=100000;n++){
		int t=n,sum=n;
		while(t>0){sum+=t%10;t/=10;}
		if(yuan[sum]==0 || n<yuan[sum]) yuan[sum]=n;//ֻ����С������Ԫ	
	}
	scanf("%d",&num);
	while(num--){
		scanf("%d",&d);
		printf("%d\n",yuan[d]);
	}
	return 0;
}