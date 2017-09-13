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
	int mi=INT_MAX;
	int mipo=0;
	int A[100023];
	cin>>n;
	map<int,int>B;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		B[A[i]]++;
		if(A[i]<mi) 
		{
			mi=A[i];
			mipo=i;
		}
	}
	if(B[mi]>1)
		cout<<"Still Rozdil"<<endl;
	else cout<<mipo+1<<endl;
	return 0;
}

