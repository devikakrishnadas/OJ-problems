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
	int n,k;
	int A[10000]={0};
	cin>>n>>k;
	if(n>1 && k==0)
	{
		cout<<"No solution" <<endl;
		return 0;
	}	
	int sum=0;
	for(int i=0;sum!=k;i++)
	{
		A[i%n]++;
		sum++;
		if(sum==k)
			break;
	}
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<endl;
	
	return 0;
}

