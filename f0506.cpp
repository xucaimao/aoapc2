//�㷨�������ž���ڶ��� ����5-6 UVa540 ������� ���ϳ���
//write by xucaimao,20161207,16:15
//�����ϸ���ʾ����ͬ����Ա�����С�ӵı����û����ѧ�ϵ��߼���ϵ��
//���ֻ�ܲ���map���������ߵĶ�Ӧ��ϵ������Ӧ��֤��Ա��ŵ�Ψһ��

#include<cstdio>
#include<queue>
#include<map>
using namespace std;

const int maxt=1000+10;//�����1000��С��

int main(){
	freopen("f0506.in","r",stdin);
	int T,kase=1;
	while(scanf("%d",&T)==1 && T){
		printf("Scenario #%d\n",kase);
		map<int,int> team; //team[x]��ʾ���Ϊx�������ڵ�С�ӵı��
		for(int i=0;i<T;i++){ //����t��С�ӵ�����
			int n,x;
			scanf("%d",&n);
			while(n--){
				scanf("%d",&x);
				team[x]=i; //������Ա�����С�ӱ�ŵ�ӳ���ϵ
			}
		}
		
		queue<int> q_all,q_sub[maxt];//q_all��С�ӱ�ŵĶ��У�q_sub[i]��С��i��Ա�Ķ���
		for(;;){ //�ظ�ִ������
			int x;
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='S') break;
			else if(cmd[0]=='D'){//����
							int t=q_all.front();//ȡ�����ȳ��ӵ�С�ӱ��
							printf("%d\n",q_sub[t].front());//����С�ӱ���ҵ�С�������ȳ��ӵĶ�Ա���
							q_sub[t].pop();//С�Ӷ�Ա����
							if(q_sub[t].empty())//С��t��ȫ����Ա���Ѿ�����
								q_all.pop();//�ܶ��ڸ�С�ӱ�ų���
						}
						else if(cmd[0]=='E'){ //���
							scanf("%d",&x);//������Զ�Ա�ı��
							int t=team[x];//���Ҹö�Ա��С�ӱ��
							if(q_sub[t].empty())	//������С�ӵĵ�һ����Ա����
								q_all.push(t);//С�ӱ�Ž������ŶӶ���
							q_sub[t].push(x);//С�Ӷ�Ա�����Լ���С��
						}
		}
		printf("end of #%d\n",kase);
		printf("\n");	

	}
	return 0;
}