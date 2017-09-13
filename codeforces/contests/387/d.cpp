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
	int A[200023];
	int tire=1;//0 -> winter 1->summer
	cin>>n>>k;
	int ans=0;
	int l=0;
	int lcnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		if(A[i]<0){ l=i; lcnt++;}
	}
	if(lcnt>k)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(A[i]<0  && tire==1)
		{
			ans++;
			tire=0;
		}
		else if(A[i]>=0 && ((l-i+1)>k || k==0)  && tire==0)
		{
			ans++;
			tire=1;
		}
		if(tire==0) k--;
	}
	cout<<ans<<endl;
	return 0;
}
