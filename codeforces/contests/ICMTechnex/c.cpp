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


int getMid(int s, int e) {  return s + (e -s)/2;  }

int getSumUtil(ll *st, int ss, int se, int qs, int qe, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}

ll constructSTUtil(int arr[], int ss, int se, ll *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

ll ml=0;
ll *constructST(int arr[], int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n))); 
 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
    ml=max_size;
    // Allocate memory
    ll *st = new ll[1000000];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}


int main()
{
	vector<bool>A(2000000000,0),B(2000000000,0);
	int n,k;
	cin>>n>>k;
	ll a=1;
	for(int i=0;;i++)
	{
		a=a*k;
		if(a>1000000000)
			break;
		if(a>0)
			A[a]=1;
	}
	int arr[200012]={0};
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int cnt=0;
	ll *st = constructST(arr, n);
	for(int i=0;i<=ml;i++)
	{
		if(st[i]>0 && A[abs(st[i])]==1)
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

