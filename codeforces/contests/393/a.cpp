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
	ll m,d;
	cin>>m>>d;
	int t;
	if(m==2)
	{
		t=28;
	}
	else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	{
		t=31;
	}
	else t=30;
	ll ans=0;
	int r=7-(d-1);
	r=t-r;
	ans=1+r/7;
	r=r%7;
	if(r)
		ans++;
		
	cout<<ans<<endl;
	return 0;
}

