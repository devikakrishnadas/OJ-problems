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
	int n,k,x;
	cin>>n>>k>>x;
	k=k%2;
	vi A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	if(k==0)
		cout<<*max_element(A.begin(),A.begin()+n)<<" "<<*min_element(A.begin(),A.begin()+n);
	else
	{
		for(int i=0;i<n;i++)
		{
			A[i]=A[i]^x;
		}
		cout<<*max_element(A.begin(),A.begin()+n)<<" "<<*min_element(A.begin(),A.begin()+n);
	}
	
	return 0;
}

