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

vi FailureFunction(vc pat,int n) //Builds the KMP array
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
//                cout<<F[i]<<" ";
        }
//        cout<<endl;
        return F;
}

int main()
{
	 vc A;
        int n;
        char x;
	char t[100023],p[100023];
	cin>>p;
        n=strlen(p);
        for(int i=0;i<n;i++)
        {
                x=p[i];
                A.pb(x);
        }
        vi F=FailureFunction(A,n);

        int m;
        cin>>t;
	m=strlen(t);
        vc text;
        vi ans;
        int j=0;
        for(int i=0;i<m;i++)
        {
                x=t[i];
                text.pb(x);
                if(text[i]==A[j])
                {
                        j++;
                }
                else
                {
                        if(j)
                                j=F[j-1];
                        else
                                j=0;
                }
                if(A[j]==text[i]) j++;
                if(j==n)
                {
                        if(j)
                                j=F[j-1];
                        else j=0;
                        if(i-(n-1)>=0)
                        ans.pb(i-(n-1));
                }
        }
        cout<<ans.size()<<endl;

	return 0;
}

