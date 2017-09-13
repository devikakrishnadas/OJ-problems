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
	int n,m;
	cin>>n>>m;
	int A[200025]={0};
	int P=0,V=1;
	V=min(n,m);
	P=max(n,m)-1;
	cout<<P<<" "<<V<<endl;
	return 0;
}

