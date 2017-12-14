n = raw_input()
str_arr = raw_input().split(' ')
arr = [int(num) for num in str_arr]
n=int(n)

vals = dict()
vals[0]=0
vals[1]=0
ans = 0
for i in range(1,n) :
    vals[i] = vals[i-1] + arr[i-1] - (i)*arr[i] 
    if i >= 2 :
        vals[i] = vals[i] + (i-1)*arr[i-1] 
    ans += vals[i]
val = dict()

for i in range(0,n) :
    if arr[i] in val :
        val[arr[i]] = val[arr[i]] + 1
    else :
        val[arr[i]] = 1
    if arr[i]-1 in val :
        ans = ans + val[arr[i]-1]
    if arr[i]+1 in val :
        ans = ans - val[arr[i] + 1]
ans = -1*ans
print ans;
