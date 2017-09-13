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

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int A[]={1,2,3,4,5,6,7,8,9};
	int B[]={1,2,3,4,5,6,7,8};
	int C[]={1,2,3,4,5,6,7};
	int D[]={1,2,3,4,5,6};
	int E[]={1,2,3,4,5};
	int F[]={1,2,3,4};
	int G[]={1,2,3};
	int H[]={1,2};
	vector< int>T;
	T.pb(1);
	do
	{
		int aa=0;
		for(int i=0;i<2;i++)
		{
			aa=aa*10+H[i];
		}
		T.pb(aa);
	}while(next_permutation(H,H+2));
	do
        {
		int aa=0;
                for(int i=0;i<3;i++)
                {
                        aa=aa*10+G[i];
                }
                T.pb(aa);
        }while(next_permutation(G,G+3));
	do
        {
                int aa=0;
                for(int i=0;i<4;i++)
                {
                        aa=aa*10+F[i];
                }
                T.pb(aa);
        }while(next_permutation(F,F+4));
	do
        {
                int aa=0;
                for(int i=0;i<5;i++)
                {
                        aa=aa*10+E[i];
                }
                T.pb(aa);
        }while(next_permutation(E,E+5));
	do
        {
                int aa=0;
                for(int i=0;i<6;i++)
                {
                        aa=aa*10+D[i];
                }
                T.pb(aa);
        }while(next_permutation(D,D+6));
	vi b(1000000,0);
	for(int i=0;i<T.size();i++)
	{
		b[T[i]]=1;
	}
	for(int i=1;i<=1000000;i++)
	{
		b[i]=b[i]+b[i-1];
	}
	int q;
	cin>>q;
	while(q--)
	{	
		int l,r;
		cin>>l>>r;
		if(l>r)
			swap(l,r);
		else
			cout<<b[r]-b[l-1]<<endl;
	}
		
	return 0;
}

