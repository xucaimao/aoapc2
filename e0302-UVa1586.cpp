//�㷨�������ž���ڶ��� e0302.cpp UVa1586������
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
			switch(s[i]){ //���Ҹ�Ԫ�صķ�����
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
			i++;//������һ���ַ�
			//�����ԭ�ӵ�����n>=2,n<=99
			//Ҳ����˵��Ԫ�ط��ź�����Ը��Ŷ�λ�����ַ�
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