//�㷨�������ž���ڶ��� ϰ��0404 UVa253 Cube painting
//write by xucaima,20161123,16:20.20161115,12:44����ͨ��.

#include<cstdio>
//#include<cstring>

bool mystrcmp(char* s){
	for(int i=1;i<=4;i++)
		if(s[i]!=s[i+6]) return false;
	return true;
}

//����cube��ת�ĺ�����ʵ�����ĸ������ݵ�˳�򽻻�
void rotate(char *s){
	char t=s[10];
	s[10]=s[9];
	s[9]=s[8];
	s[8]=s[7];
	s[7]=t;
}


int main(){
	freopen("e0404.in","r",stdin);
	char data[13];
	bool st=true;
	while(scanf("%s",data)!=EOF){
		//char s1[5],s2[5];
		//printf("%s",data);
		if(!st) printf("\n");
		bool EQ=false;
		for(int i=1;i<=3;){
			if(mystrcmp(data))
				{printf("TRUE");EQ=true;break;}
			else
				{rotate(data);i++;} //ֻ��ת����
				
		}
		if(!EQ)printf("FALSE");
		st=false;
	}
	return 0;
}