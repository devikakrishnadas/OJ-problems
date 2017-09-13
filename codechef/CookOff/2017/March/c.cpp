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
	int t;
	cin>>t;	
	while(t--)
	{
		double r,b,p;
		cin>>r>>b>>p;
		double ans=(p*r + (r+b-p)*b)/(r+b);
		cout<<fixed<<setprecision(9)<<ans<<endl;
	}
	return 0;
}

