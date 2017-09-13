#include <bits/stdc++.h>
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

int lis(vi A,int n)
{

        vi tail(n);
	vi l_a(n);
        tail[0]=A[0];
	l_a[0]=A[0];
        int len=1;
	int pl=1;
        for(int i=1;i<A.size();i++)
        {
                if(A[i]<tail[0])//If the element is the least, replaces the first element of all lists
                {
                        tail[0]=A[i];
                }
                else if(A[i]>tail[len-1]) //If the element is greater than all other, then appends to all the list
                {
                        tail[len++]=A[i];
		//	l_a[pl++]=A[i];
                }
                else
                {
                        *lower_bound(tail.begin(),tail.begin()+len,A[i])=A[i]; //Finds the lower bound of the index and replaces it with A[i]
                }
		if(len>pl)
		{
			l_a=tail;
			pl=len;
		}
        }
        return l_a[len-1] - l_a[0];
}


int main()
{
	int n;
	int t;
	cin>>t;
	while(t--)
	{
        	cin>>n;
        	vi a;
        	int x;
        	for(int i=0;i<n;i++)
        	{
                	cin>>x;
                	a.pb(x);
        	}
        	cout<< lis(a,n) << endl;
	}
	return 0;
}

