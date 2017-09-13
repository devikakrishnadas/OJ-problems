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
	vll A(n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	sort(A.begin(),A.begin()+n);
	int cnt=0;
	for(int i=2;i<n;i++)
	{
		if(A[i]<A[i-1]+A[i-2])
		{
			cout<<"YES"<<endl;
			return 0;
		}
	
	}
	
	cout<<"NO"<<endl;
	return 0;
}

