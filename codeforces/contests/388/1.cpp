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
	int a=n/2;
	cout<<a<<endl;
	for(int i=1;i<a;i++)
	{
		cout<<2<<" ";
	}
	if(n%2) cout<<3<<endl;
	else cout<<2<<endl;
	
	return 0;
}

