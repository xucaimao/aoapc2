#include<iostream>  
#include<string>  
using namespace std;  
char s[100000+2],t[100000+2];  
int main()  
{  
#ifdef test  
    freopen("sample.txt","r",stdin);  
#endif  
    while(cin>>s>>t)  
    {  
        int flag=0,len_s=strlen(s),len_t=strlen(t);  
        for(int i=0; i<len_s; i++)  
            if(flag==len_s)  
                break;  
            else  if(s[flag]==t[i])  
                flag++;  
        if(flag==len_s)  
            cout<<"Yes"<<endl;  
        else  
            cout<<"No"<<endl;  
    }  
    return 0;  
}  