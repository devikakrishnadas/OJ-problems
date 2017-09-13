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
	int n;
	cin>>n;
	for(int i=1,j=n*n,k=0;k<n*n;i++,j--)
	{
		cout<<i<<" "<<j;
		k+=2;
		if(k%n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}

