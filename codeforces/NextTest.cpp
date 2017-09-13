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
	int x;
	bool A[100023]={0};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		A[x]=1;
	}
	for(int i=1;;i++)
	{
		if(A[i]==0)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}

