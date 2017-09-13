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
	int n,a,b;
	cin>>n>>a>>b;
	

	cout<<min(n-a,n-(n-b-1))<<endl;
	return 0;
}

