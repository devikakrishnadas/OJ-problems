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

/* The Function creates a failure table for every PATTERN and returns it */
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
		{
			while(pat[i]!=pat[j] && j)
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

/* The function acctepts the pattern and text and their respective sizes as the input.
	It finds the occurances of the pattern in the text and saves them in the vector "ans".
	Returns the vector ans.  */
vi compare(vi F,vc pat, vc text, int m,int n)
{
	vi ans;
	int j=0;
	for(int i=0;i<m;i++)
        {
                if(text[i]==pat[j])
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
                if(pat[j]==text[i]) j++;
                if(j==n)
                {
                        if(j)
                                j=F[j-1];
                        else j=0;
                        if(i-(n-1)>=0)
                        ans.pb(i-(n-1));
                }
        }
	return ans;

}
int main()
{
	vc pat;//Pattern
	int n;
	char x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		pat.pb(x);
	}
	vi F=FailureFunction(pat,n); /* Creates the failure table of KMP */
	
	int m;
	cin>>m;
	vc text;
	for(int i=0;i<m;i++)
	{
		cin>>x;
		text.pb(x);
	}
	vi ans=compare(F,pat,text,m,n);/* Compares the given pattern to the text and returns the starting point of the matches */
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
