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
	char A[1023],B[1023];
	int n;
	cin>>n;
	cin>>A>>B;
	sort(A,A+n);
	sort(B,B+n);
	int mi=0;
	int k=0;
	for(int i=0;i<n;i++)
	{
		while(B[k]<A[i] && k<n)
		{
			k++;
		}
		if(k==n) break;
		else {k++; mi++;}
//		cout<<mi<<" "<<k<<endl;
	}
		
	reverse(A,A+n);
	reverse(B,B+n);
	k=0;
	int ma=0;
	for(int i=0;i<n;i++)
	{
		while(B[i]<=A[k] && k<n)
		{
			k++;
		}
		if(k==n) break;
		else {k++;ma++;}
			
	}
	cout<<n-mi<<endl<<ma<<endl;
	return 0;
}

