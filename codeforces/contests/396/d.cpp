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
	int n,m,q;
	cin>>n>>m>>q;
	map<char*,int>M;

	char a[29][100023];
	char b[100023];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		M[a[i]]=3;
	}
	int t;
	for(int i=0;i<m;i++)
	{
		cin>>t;
		cin>>b;
		int no=0;
		if(M[b]==3)
			M[b]=t;
		else {no=1;cout<<M[b]<<endl;}
		cin>>b;
		if(M[b]==3)
			M[b]=t;
		else no=1;
		if(no)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	for(int i=0;i<q;i++)
	{
		cin>>b;
//		int A=M[b];
		cin>>b;
//		int B=M[b];
//		if(A==3 || B==3)
//			cout<<3<<endl;
//		else if(A!=B) cout<<2<<endl;
//		else cout<<1<<endl;
	}
	return 0;
}

