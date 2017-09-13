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

int main()
{
	ll n,a,b,c;
	cin>>n>>a>>b>>c;
	ll ans=LLONG_MAX;
	if(n%4==0)
	{
		cout<<0<<endl;
		return 0;
	}
	
	int res=n%4;
	if(res==1)
		cout<<min(c,min(a+b,min(3*a,min(c+c+a,3*(b+c)))))<<endl;
	else if(res==2)
		cout<<min(2*a,min(b,min(c+c,min(2*(a+b),2*(b+c)))))<<endl;
	else if(res==3)
		cout<<min(a,min(b+c,min(3*c,3*(a+b))))<<endl;
	return 0;
}

