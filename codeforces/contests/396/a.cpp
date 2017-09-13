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
	char A[100023],B[100023];
	cin>>A>>B;
	int n=strlen(A);
	int m=strlen(B);
	if(n==m)
	{
		int k=0;
		bool found=0;
		for(int i=0;i<n;i++)
		{
			if(A[i]==B[k] && k<m)
			{
				k++;
			}
			if(k==m)
			{
				found=1;
				break;
			}
		}
		if(found)
		{
			cout<<-1<<endl;
		}
		else cout<<n<<endl;
	}
	else
	{
		cout<<max(n,m)<<endl;
	}
	return 0;
}

