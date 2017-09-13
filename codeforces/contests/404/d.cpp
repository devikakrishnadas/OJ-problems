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
	char A[200023];
	cin>>A;
	vi a,b;
	
	for(int i=0;i<strlen(A);i++)
	{
		if(A[i]=='(') a.pb(i);
		else b.pb(i);
	}
	
	return 0;
}

