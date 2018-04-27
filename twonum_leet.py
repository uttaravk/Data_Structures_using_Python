nums=[3,2,3]
target=6
x=target-nums[0]
mydict={x:0}
val1=0;
val2=0;
for i in range(1, len(nums)):
    x=target-nums[i]
    print('x: ',x, ' i: ',i)
    print('key: ',mydict.keys())
    if nums[i] in mydict.keys():
        val1=i
        val2=mydict[nums[i]]
        break
    else:
        mydict.update({x:i})
rtype=[val2,val1]
print (rtype)
