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
	ll n,m,k,x,y;
	cin>>n>>m>>k>>x>>y;
	ll sergei_front=m*(x-1)+y;
	ll ma=k/((n-2)*m);
	ll rem=k%((n-2)*m);
	ll mi=rem/2;
	cout<<ma<<" "<<mi<<" ";
	
	return 0;
}

