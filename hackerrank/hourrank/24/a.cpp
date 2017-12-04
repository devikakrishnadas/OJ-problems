#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=1,b=1,c=1,d=1,e=1;
    if(s.length()>=6) e=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a' && s[i]<='z') a=0;
        else if(s[i]>='A' && s[i]<='Z') b=0;
        else if(s[i]>='0' && s[i]<='9') c=0;
        else if(s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%'||s[i]=='^'||s[i]=='&'||s[i]=='*'||s[i]=='('||s[i]==')'||s[i]=='-'||s[i]=='+') d=0;
    }
    cout<<max(6-n,a+b+c+d)<<endl;
	return 0;
}

