//�㷨�������ž���ڶ��� f0304.cpp ��ʽ����
//write by xucaima,20161108,12:44
//�ص���sprintf��strchr����������ʹ��

#include<cstdio>
#include<cstring>

int main()
{
	char s[20],t[20];  //s��ų�ʼ�ַ����У�t�����ʽ�е���������
	int num=0;
	scanf("%s",s);
	for(int abc=100;abc<=999;abc++)
		for(int de=10;de<=99;de++){
			int x=abc*(de%10),y=abc*(de/10),z=abc*de;
			sprintf(t,"%d%d%d%d%d",abc,de,x,y,z);
			int ins=1;
			for(int i=0;i<strlen(t);i++)
				if(strchr(s,t[i])==NULL) ins=0; //�����ʽ���ַ����������ڣ�ins��0
			if(ins){ //��ʽ�����е��ַ�����������
				num++;
				printf("%d\n",num);
				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
			}
		}
	printf("The number of solutions = %d\n",num);
	return 0;		
}