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
	if(n==0) cout<<1<<endl;
	else if(n%4==1) cout<<8<<endl;
	else if(n%4==2) cout<<4<<endl;
	else if(n%4==3) cout<<2<<endl;
	else if(n%4==0) cout<<6<<endl;
	return 0;
}

