#include<bits/stdc++.h>
using namespace std;
const int M=50001;
int a[M],b[M],c[M];
int main(){
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++)
    a[s1.length()-1-i]=s1[i]-'0';
    for(int i=0;i<s2.length();i++)
    b[s2.length()-1-i]=s2[i]-'0';

    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    int sum=s1.length()+s2.length();
    while(c[sum-1]==0 && sum>1){
        sum--;
    }
    for(int i=0;i<sum;i++){
        cout<<c[sum-1-i];
    }

    return 0;
}