//�㷨�������ž���ڶ��� ϰ��3-9 UVa10340 ������
//write by xucaima,��ʼ��20161117,23:00.2016118,14:14����ͨ��.
//ʱ������:3s
//���鿪С��Ҳ�����RE����

#include<cstdio>
#include<cstring>
const int MAXN=100002; //���鿪С��Ҳ�����RE����
char s[MAXN],t[MAXN];

bool judge(char * s,char * t)
{
    int ls=strlen(s);
    int lt=strlen(t);
    if(ls>lt) return false;//s����t������ֱ�ӷ���false
    int i,j;
    for(i=0,j=0;i<ls && j<lt;){
        if(s[i]==t[j]){i++;j++;} //��t�����ҵ�s[i]��ͬ���ַ���������һ��s[i]
        else
        	while(s[i]!=t[j] && j<lt) //��t��������s[i]��ͬ���ַ�
        		j++;
		}
    if(i==ls)return true;//s�����ַ�����������ϣ�û�г����쳣���
    else return false;
}

int main()
{
	freopen("e0309.in","r",stdin);
	while((scanf("%s%s",s,t))==2){
        if(judge(s,t)) printf("Yes\n");
        else  printf("No\n");
	}

	return 0;
}
