//�㷨�������ž���ڶ���ϰ��3-7 UVa1368 DNA����
//write by xucaima,20161117,17:00.20161117,21:17����ͨ��.
//ʱ������:3s

#include<cstdio>
#include<cstring>

char dna[50][1010];//�洢DNA����

struct Dna{  //�м����Ľṹ��,���ڲ���ѭ���������ַ����в���
const char d;
int ham;
};

struct Ans{  //�������Ľṹ��
char d[1010];//ÿ�еļ�����
int ham[1010];//ÿ�е�hammingֵ
int hamtotal;//�ܵ�hammingֵ
};

//��Ҫ����
Ans hamm(int m,int n)
{
	Ans ans;
    for(int c=0;c<n;c++){ //���н��в���
        Dna dd[4]={{'A',0},{'C',0},{'G',0},{'T',0}};//�����м�������ʼ�������ֵ�˳������
        for(int i=0;i<4;i++){ //�ֱ���ACGT�ĸ����ţ���ÿһ���ַ���hammingֵ���ۼӺ�
            int ham=0;
            for(int r=0;r<m;r++)
                if(dna[r][c]!=dd[i].d) ham++;
            dd[i].ham=ham;
        }
        ans.d[c]=dd[0].d;//�Ȱ�'A'����hammingֵ��Ϊ��Сֵ
        ans.ham[c]=dd[0].ham;
        for(int i=1;i<4;i++)
            if(dd[i].ham<ans.ham[c]){ //����Сֵ������Сֵһ��ʱ����������ֵ�˳��С���Ǹ�ֵ
            ans.ham[c]=dd[i].ham;
            ans.d[c]=dd[i].d;
        }

    }
    ans.d[n]='\0';//�����ַ���β��־
    ans.hamtotal=0;
    for(int i=0;i<n;i++)  //�ۼ��ܵ�hammingֵ
        ans.hamtotal+=ans.ham[i];
	return ans;
}

int main()
{
	int m,n,tt;
	//freopen("e0307.in","r",stdin);//�ض����ļ����룬�ύ����ʱ��Ҫע�͵�����
	scanf("%d",&tt);  //�����������������

	for(int t=0;t<tt;t++){
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
			scanf("%s",dna[i]);//����DNA����

        Ans answer=hamm(m,n);
		//��ӡ��Ӧ��DNA���м�hammingֵ
		printf("%s\n",answer.d);
		//for(int i=0;i<n;i++) printf("%d ",answer.ham[i]);
		//printf("\n");
		printf("%d\n",answer.hamtotal);

	}
	return 0;
}


