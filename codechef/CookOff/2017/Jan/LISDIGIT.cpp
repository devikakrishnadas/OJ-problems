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
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		ll a=0;
		int x;
		for(int i=0;i<n;i++)
		{
			a=a*10;
			cin>>x;
			a=a+x;
		}
		cout<<a<<endl;
	}
	return 0;
}

