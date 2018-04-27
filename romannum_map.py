mydict={'M':1000, 'D':500, 'C':100, 'L':50, 'X':10, 'V':5, 'I':1}
s="MCMXCVI"
mysum=0
x=0
y=0
flag=0
for i in range (0, len(s)-1):
    if(flag!=1):
        x=mydict[s[i]]
        y=mydict[s[i+1]]
        if x>=y :
            mysum=mysum+x
        elif x<y :
            mysum=mysum+(y-x)
            flag=1
    else:
        flag=0
if(flag!=1):
    mysum=mysum+mydict[s[len(s)-1]]
print(mysum)
