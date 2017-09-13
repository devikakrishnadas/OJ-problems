#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;
vi dp2(n,0);
vi dp3(n,0);
void dp(int n, char S[10023])
{
	int a=dp(n-2,S);
	int c=dp(n-2,S);
	int b=((S[n-3]!=S[n-1] || S[n-1]!=S[n]) && c)
	dp2[n]=a||b;
	
}


int main()
{
	char S[20000];
	cin>>S;
	int n=strlen(S);
	if(n==5 || n==6)
	{
		cout<<0<<endl;
		return 0;
	}
	reverse(S,S+n);
	return 0;
}
