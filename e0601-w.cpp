#include<cstdio>
#include<stack>
char cor[512];
int main(){
	cor[')']='(';
	cor[']']='[';
	int n;
	scanf("%d",&n);
	gtechar();
	while(n--){
		char s[256];
		gets(s);
		stack<char> k;
		k.push(-1);
		for(int i=0;s[i];i++){
			if(cor[s[i]]==k.top()) k.pop();
			else k.push(s[i]);
		}
		if(k.size()==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}