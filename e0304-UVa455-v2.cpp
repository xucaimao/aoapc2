//�㷨�������ž���ڶ��� e0304.cpp UVa455���ڴ�
//write by xucaima,20161109,15:00.20161115,12:44����ͨ��.
//ʱ������:3s
//�������ݣ���һ������N��˵���ж������������
//�����ÿһ�����ݶ���һ�����У��ټ�һ�в������ո��С�ڵ���80���ַ����ַ���
//û���Ӵ�������"abcdefga",Ӧ�����ַ����ܳ���������ӵĲ�ǳ�����������

#include<cstdio>
#include<cstring>

//�˺��������ύͨ����
int judge2(char* s)
{
	int len=strlen(s);
	int k;
	for(k=1;k<=len/2;k++){ //ע��˴���<=;���ڼ��˵����ơ�abcdeabcde����
		bool EQ=true;
		for(int i=k;i+k<=len;i+=k)//�ж�s[0]���Ժ���k�������ַ��Ƿ����
			if(s[0]!=s[i])
				{EQ=false;break;}//�������ȣ�����ѭ����k��1�ٴ�ѭ��ִ���ж�
		if(EQ)return k;//һ��ѭ������û�г��ֲ���ȵ�������򷵻�k
	}
	return len;//û���Ӵ�������"abcdefga"�����ַ����ܳ�
}

int judge(char* s)
{
	int len=strlen(s);
	int k;
	for(k=1;k<=len/2;k++){ //ע��˴���<=;���ڼ��˵����ơ�abcdeabcde����
		bool EQ=true;
		if(len%k==0){//���жϺܺ�
			int t=len/k; //��t��������ȵ��Ӵ�
			for(int i=0;i<k;i++)//���Ӵ��ڵ�ÿ���ַ��������ж�
				for(int j=1;j<t;j++)//ִ��t-1���ж�
					if(s[i]!=s[j*k+i]){EQ=false;break;}//�������ȣ�����ѭ����k��1�ٴ�ѭ��ִ���ж�
			if(EQ) return k;//ѭ������û�г��ֲ���ȵ�������򷵻�k
		}
	}
	return len;//û���Ӵ�������"abcdefga"�����ַ����ܳ�
}

int main()
{
	char ss[81];
	int N;
	//freopen("e0304.in","r",stdin);
	scanf("%d",&N);
	for(int n=1;n<=N;n++){
		getchar();//�������
		scanf("%s",ss);//�����ַ�����
		int kk=judge(ss);
		if(n>1)printf("\n");//����ͷβ���ֶ���Ŀ���
		printf("%d\n",kk);
	}	
	return 0;
}