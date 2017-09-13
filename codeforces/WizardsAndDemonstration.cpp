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
	int n,x,y;
	cin>>n>>x>>y;
	int m;
	if(((y*n)%100))
		m=(y*n)/100 + 1;
	else m=(y*n)/100;
	int a=m-x;
	if(a<=0) cout<<0<<endl;
	else cout<<a<<endl;
	
	return 0;
}

