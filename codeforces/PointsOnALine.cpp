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
	ll n,d;
	ll x[100023];
	cin>>n>>d;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	ll diff=x[1]-x[0];
	int j=0;
	ll cnt=0;
	for(int i=1;i<n;i++)
	{
		diff=x[i]-x[j];
		if(diff>d)
			while(diff>d)
			{
				j++;
			}
		else cnt++;
		
	}
	cout<<cnt<<endl;
	return 0;
}

