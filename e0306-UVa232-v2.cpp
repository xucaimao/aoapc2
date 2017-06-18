//�㷨�������ž���ڶ���ϰ��3-6 UVa232�ݺ�����
//write by xucaima,20161114,13:00.20161115,12:47����ͨ��.
//ʱ������:3s
//ע�����ʱǰ�����ж���Ŀ��У�������������

#include<cstdio>
#include<cstring>
const int MAXN=12;
char m[MAXN][MAXN];
int mn[MAXN][MAXN];//��ʼ�����
char w[MAXN];
int row,col;

//��ʼ����ʼ�����
void initmn()
{
	int wn=0;
	for(int r=0;r<MAXN;r++)
		for(int c=0;c<MAXN;c++)
			mn[r][c]=0;
	for(int r=0;r<row;r++)
		for(int c=0;c<col;c++){
			if(m[r][c]=='*') //�˴���ʼ��д��mn[r][c]������ʱ��ĥ�������
				continue;  //��������ѭ��
			if(r-1<0 || c-1<0 || m[r-1][c]=='*' || m[r][c-1]=='*')
					{wn++;
					mn[r][c]=wn;}
		}
}

//��ӡ���򵥴�
void across1()
{
	printf("Across\n");
	int wn=0;
	for(int r=0;r<row;r++){  //���д�����
		for(int c=0;c<col;){
				int wi=0;
				int letter=0;//�µ��ʱ�־
				while(m[r][c]=='*' && c<col)
					c++;//���˵�����ǰ�˵�'*'
				wn=mn[r][c]; //��¼��ǰ���ʵ���ʼ�����
				while(m[r][c]!='*' && c<col) {//������һ�����ʵ�w
					w[wi]=m[r][c];
					wi++;
					letter=1;
					c++;
				}
				w[wi]='\0';

				if(letter)printf("%3d.%s\n",wn,w); //�������µ��ʲŴ�ӡ
		}
	}
}

//��ӡ���򵥴��°�
//������ʼ��������
void across()
{
	printf("Across\n");
	for(int r=0;r<row;++r)
		{
			int c=0;
			while(c<col)
			{
				if(mn[r][c] == 0 || m[r][c] =='*') //������ʼ��,��������ַ�
				{
					c++;
					continue;
				}
				printf("%3d.%c",mn[r][c],m[r][c]); //����ʼ�񣬴�ӡ��ʼ��������ַ�
				c++;
				while(c<col && m[r][c]!='*')//��ӡ���������ַ�ֱ������'*'
				{
					printf("%c",m[r][c]);
					c++;
				}
				printf("\n");
			}
		}

}

//��ӡ���򵥴�
//������д������ܰ�����ʼ����ŵ�˳���������Ҫ�ص㿼��˳������
//��Ȼ�����д�����������ʼ��Ĵ�С˳����д���
void down()
{
	printf("Down\n");
	for(int r=0;r<row;r++){
		for(int c=0;c<col;c++){
			if(mn[r][c]==0 || m[r][c]=='*')
				continue;
			printf("%3d.%c",mn[r][c],m[r][c]);//����ʼ�񣬴�ӡ��ʼ��������ַ�
			mn[r][c]=0;  //���������ʼ����0
			int k=r+1;
			while(k<row && m[k][c]!='*'){  //��ӡ���������ַ�ֱ������'*'
				printf("%c",m[k][c]);
				mn[k][c]=0; //���������ʼ����0
				k++;
			}
			printf("\n");
		}
	}
}

int main()
{
	//freopen("e0306.in","r",stdin);//�ض����ļ����룬�ύ����ʱ��Ҫע�͵�����
	int gn=0;
	while(scanf("%d%d",&row,&col)==2 && row!=0){
		gn++;
		if(gn>1)printf("\n");//������ǰ�����û�ж���Ŀ���,������������
		for(int r=0;r<row;r++)  //������������
			scanf("%s",&m[r]);
		printf("puzzle #%d:\n",gn);
		initmn();
		across();
		down();
	}
	return 0;
}


