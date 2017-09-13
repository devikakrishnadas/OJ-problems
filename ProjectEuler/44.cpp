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

//ll A[100000]={0};
//bool A[1000000000]={0};
map<ll,ll>A;
int main()
{

	for(int i=1;i<=100000;i++)
	{
		A[(i*(3*i-1))/2]=1;
	}
	for(int i=2;i<=100000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			ll ai=(i*(3*i-1))/2;
			ll aj=(j*(3*j-1))/2;
			if(A[ai+aj] && A[abs(ai-aj)])
				cout<<abs(ai-aj)<<endl;
		}
	}
	return 0;
}

