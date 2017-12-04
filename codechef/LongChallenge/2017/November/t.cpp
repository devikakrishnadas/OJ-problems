#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;
int longestPalSubstr(vc &str)
{
    int maxLength = 1;  // The result (length of LPS)
 
    int start = 0;
    int len = str.size();
 
    int low, high;
 
    // One by one consider every character as center point of 
    // even and length palindromes
    for (int i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        // as i-1 and i.  
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
 
        // Find the longest odd length palindrome with center 
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
 
//    printf("Longest palindrome substring is: ");
  //  printSubStr(str, start, start + maxLength - 1);
 
    return maxLength;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    //vc a;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int maxl=INT_MAX;
        vc tt,a;
        //a.clear();
        for(int j=1;j<=i;j++)
        {
            a.pb('a');
        }
        for(int j=i+1;j<=n;j++)
        {
            a.pb('b');
        }
        do
        {
            int l=longestPalSubstr(a);
            if(l<maxl)
            {
                tt=a;
                l=maxl;
            }
        }while(next_permutation(all(a)));
        cout<<maxl<<endl;
    }
	return 0;
}

