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
	vi A;
	int x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		A.pb(x);
	}
	for(int i=0 , j=n-1 ;i<n/2; i++,j-- )
	{
//		cout<<i<<" "<<j<<endl;
		if(i%2==0)
			swap(A[i],A[j]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}

