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
	int n,m;
	cin>>n>>m;
	//map<int,int>A;
	int x,k;
	bool ans=0;
	for(int i=0;i<m;i++)
	{
		map<int,int>A;
		cin>>k;
		bool enter =0;
		for(int j=0;j<k;j++)
		{
			cin>>x;
			A[abs(x)]++;
			if(A[abs(x)]==2)
			{
				enter=1;
				A[abs(x)]=0;
			}
		}
		if(!enter)
		{
			ans=1;
		}
		
	}
	if(ans)
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

