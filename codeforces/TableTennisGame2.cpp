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
	ll k,a,b;
	cin>>k>>a>>b;
	if(a/k + b/k==0) cout<<-1<<endl;
	else cout<<a/k + b/k<<endl;
	return 0;
}

