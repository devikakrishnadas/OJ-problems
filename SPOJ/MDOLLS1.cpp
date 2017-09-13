#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()
#define ff first
#define ss second

using namespace std;


int GetCeilIndex(vector<pair<int,int> > arr, vector<int> &T, int l, int r,
				pair<int,int> key)
{
	while (r - l > 1)
	{
		int m = l + (r - l)/2;
		if (arr[T[m]].ff >= key.ff && arr[T[m]].ss>=key.ss)
			r = m;
		else
			l = m;
	}

	return r;
}

int lis(vector<pair<int,int > > arr, int n)
{
	// Add boundary case, when array n is zero
	// Depend on smart pointers

	vector<int> tailIndices(n, 0); // Initialized with 0 
	vector<int> prevIndices(n, 0); // initialized with -1

	int len = 1; // it will always point to empty location
	for (int i = 1; i < n; i++)
	{
		if (arr[i].ff < arr[tailIndices[0]].ff && arr[i].ss<arr[tailIndices[0]].ss)
		{
			// new smallest value
			tailIndices[0] = i;
		}
		else if (arr[i].ff > arr[tailIndices[len-1]].ff && arr[i].ss > arr[tailIndices[len-1]].ss)
		{
			// arr[i] wants to extend largest subsequence
			prevIndices[i] = tailIndices[len-1];
			tailIndices[len++] = i;
		}
		else
		{
			// arr[i] wants to be a potential condidate of
			// future subsequence
			// It will replace ceil value in tailIndices
			int pos = GetCeilIndex(arr, tailIndices, -1,
								len-1, arr[i]);

			prevIndices[i] = tailIndices[pos-1];
			tailIndices[pos] = i;
		}
	}

	int t[100023]={0};
	int ans=0;
    for(int i=0;i<n;i++)
	{
		t[prevIndices[i]]++;
		if(t[prevIndices[i]]==1) ans++;
		
	}
	
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,int> >A,B;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			A.pb(mp(x,y));
			B.pb(mp(y,x));
		}
		int a=lis(A,n),b=lis(B,n);
//		cout<<a<<" "<<b<<endl;
		int ans=min(a,b);
		cout<<ans<<endl;
	}
	return 0;
}

