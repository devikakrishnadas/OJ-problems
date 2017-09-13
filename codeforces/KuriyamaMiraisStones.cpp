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
	ll n,m;
        ll A[100023],B[100023],C[100023],D[100023];;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>A[i];
                B[i]=C[i]=D[i]=A[i];
                if(i)
                        A[i]+=A[i-1];
        }
        cin>>m;
        sort(D,D+n);
        sort(B,B+n);
        for(int i=1;i<n;i++)
        {
                B[i]+=B[i-1];
        }
        int a,l,r;
        while(m--)
        {
                cin>>a>>l>>r;
                if(a==1)
                {
                        cout<<A[r-1]-A[l-1]+C[l-1]<<endl;
                }
                else cout<<B[r-1]-B[l-1]+D[l-1]<<endl;
        }

	return 0;
}

