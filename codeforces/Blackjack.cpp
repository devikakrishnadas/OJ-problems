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
	n=n-10;
	if(n<0)
	{
		cout<<0<<endl;
		return 0;
	}
	int A[]={0,4,4,4,4,4,4,4,4,4,15,4,0,0,0,0};
	cout<<A[n]<<endl;
	return 0;
}

