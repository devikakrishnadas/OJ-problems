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
	int k=-1*n;
	for(int i=0;i<2*n+1;i++)
	{
		bool enter=0;
		for(int j=0;j<2*n+1;j++)
		{
			if(k>=0)
			{
				cout<<k;
				enter=1;
			}
			else if(k<0 && !enter) cout<<"  ";
			
			
			
			if(j<n) k++;
			else k--;
			if(k>=0 && enter) cout<<" ";
		}
		k++;
		if(i<n) k++;
		else k--;
		cout<<endl;
	}
	return 0;
}

