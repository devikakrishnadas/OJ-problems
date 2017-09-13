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

vi FailureFunction(vc pat,int n)
{
        int j=0;
        vi F(n);
        F[0]=0;
        for(int i=1;i<n;i++)
        {
                if(pat[i]==pat[j])
                {
                        j++;
                        F[i]=j;
                }
                else
                {while(pat[i]!=pat[j] && j)
                {
                        j=F[j-1];
                }
                if(pat[i]==pat[j])
                        F[i]=F[j]+1;
                else
                        F[i]=0;
                }
                cout<<F[i]<<" ";
        }
        cout<<endl;
        return F;
}
int main()
{
	char A[100023];
	cin>>A;
	int n=strlen(A);
	vc text;
	for(int i=0;i<n;i++)
	{
		text.pb(A[i]);
	}
	vi F=FailureFunction(text,n);
	return 0;
}

