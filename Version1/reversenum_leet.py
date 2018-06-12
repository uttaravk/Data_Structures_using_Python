#Practice
# print(len(y))
#print(y)
# y=y.replace("-","")
#print(y[0])
# l=list(y)
# l[0]=""
# y="".join(l)
# print('y: ',y)
# z=''.join(reversed(y))
# print(z)

# Method 1:
x=-1234
print('Method 1')
print('Before: ', x)
y=str(x)
if y[0]=='-' :
    flag=1
y=y.replace("-","")
z=''.join(reversed(y))
if flag==1:
    z='-'+z;
print(' After: ',z)
print('\n')

#Method 2:
x=-1234
print('Method 2')
print('Before: ', x)
y=str(x)
if y[0]=='-' :
    flag=1
l=list(y)
l[0]=""
y="".join(l)
z=''.join(reversed(y))
if flag==1:
    z='-'+z;
print(' After: ',z)
print('\n')

#Method 3:
x=-1234
print('Method 3')
print('Before: ', x)
y=str(x)
if y[0]=='-' :
    flag=1
l=list(y)
del(l[0])
y="".join(l)
z=''.join(reversed(y))
if flag==1:
    z='-'+z;
print(' After: ',z)
print('\n')

#Method 4
x=-1234
print('Method 4')
print('Before: ', x)
y=list(l)
if y[0]=='-' :
    flag=1
    del(l[0])
if len(y)%2==0 :
    count=len(y)/2
else:
    count=(len(y)/2)-1

for i in range(0,int(count)):
    temp=y[i]
    y[i]=y[len(y)-i-1];
    y[len(y)-i-1]=temp;
z="".join(y)
if flag==1:
    z='-'+z;
print(' After: ',z)
print('\n')
