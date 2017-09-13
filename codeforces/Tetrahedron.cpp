#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define M 1000000007
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
	//vll a(n+1,0);
	ll d=0,o=1;
	for(int i=1;i<n;i++)
	{
		ll ot=d+2*o;
		ll dt=o*3;
		d=dt%M;
		o=ot%M;
	}
	cout<<d<<endl;
	return 0;
}

