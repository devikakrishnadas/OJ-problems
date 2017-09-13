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
	ll n,a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if(a>b)
			swap(a,b);
		if((a%2)==(b%2) && (a+2)==b)
		{
			cout<<"YES"<<endl;
		}
		else if((a-1)/2 == (b-2)/2 && ((a-1)%2)==0 && ((b-2)%2)==0)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}

