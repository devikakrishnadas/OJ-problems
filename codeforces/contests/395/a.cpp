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
	int n,m,z;
	cin>>n>>m>>z;
	int lcm=(n*m)/__gcd(n,m);
	int cnt=0;
	for(int i=1;lcm*i<=z;i++)
	{
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

