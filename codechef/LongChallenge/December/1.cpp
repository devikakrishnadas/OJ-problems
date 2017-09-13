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
	int t;
	cin>>t;
	char A[][5]={"SU","LB",  "MB",  "UB",  "LB",  "MB",  "UB",  "SL"};
	while(t--)
	{
		cin>>n;
		int l=n%8 ;
		int ansn;
		if(l==1||l==2||l==3)
			ansn=n+3;
		else if(l==4||l==5||l==6) ansn=n-3;
		else if(l==7) ansn=n+1;
		else if(l==0) ansn=n-1;
		cout<<ansn<<A[ansn%8]<<endl;
		
	}
	return 0;
}

