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

void func(vi &b, int c)
{
	int re=0;
	for(int i=0;i<b.size();i++)
	{
		int d=b[i]*c + re;
		b[i]=d%10;
		re=d/10;
	}
	while(re)
	{
		b.pb(re%10);
		re=re/10;
	}
}
int main()
{
	ll a;
	cin>>a;
	vi b;
	ll c=a;
	while(a)
	{
		b.pb(a%10);
		a=a/10;
	}
	for(int i=0;i<c-1;i++)
	{
		func(b,c);
	}
	for(int i=b.size()-1;i>=0;i--)
		cout<<b[i];
	cout<<endl;
//	cout<<27<<endl;
	return 0;
}

