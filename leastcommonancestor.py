
mylist=[[3,2],[1,2],[2,9],[6,9],[6,10],[4,6],[4,7],[4,8],[5,8],[7,11],[8,11],[8,12]]
mydict={}
for i in range (0,len(mylist)):
   templist=[mylist[i][1]]
   if mylist[i][0] not in mydict.keys():
       mydict.update({mylist[i][0]:templist})
   else:
        templist=mydict[mylist[i][0]]
        templist.append(mylist[i][1])
        mydict[mylist[i][0]]=(templist)

print(mylist)
print(mydict)
mflag=0
n1=input('Enter 1st num: ')
n2=input('Enter 2nd num: ')
temp1=int(n1);
temp2=int(n2);

for k, v in mydict.items():
            if temp1 == v or isinstance(v, list) and temp1 in v:
                #print ('Parent: ', k, 'Child: ', temp1)
                if(temp2==k):
                    mflag=1

for k, v in mydict.items():
            if temp2 == v or isinstance(v, list) and temp2 in v:
                #print ('Parent: ', k, 'Child: ', temp2)
                if(temp1==k):
                    mflag=1

if(mflag==1):
    print('No common ancestor')


x=[]
for i in range (0, len(mylist)):
  for j in range (0,2):
      x.append(mylist[i][j])

flag=2
for i in range (0, len(x)):
    if (temp1==x[i]):
        flag=0
        break
count=0
if(flag==0):
    #print('n1 node is present in a graph')
    count=0
else:
    count=1
    #print('n1 node is absent from a graph')

flag=2
for i in range (0, len(x)):
    if (temp2==x[i]):
        flag=1

if(flag==1):
    #print('n2 node is present in a graph')
    count=0
else:
    count=2
    #print('n2 node is absent from a graph')


if(count==1 or count==2):
    print('No common ancestor of ', n1, ' and ', n2)
    exit
else:
    list1=[temp1]
    list2=[temp2]
    mykcount=0
    k1=0
    k2=0
    myk11=0
    myk22=0
    for k, v in mydict.items():
            if temp1 == v or isinstance(v, list) and temp1 in v:
                #print ('Parent: ', k, 'Child: ', temp1)
                k1=k
                list1.append(k1)
                mykcount=0
                break
            else:
                mykcount=1

    for k, v in mydict.items():
            if temp2 == v or isinstance(v, list) and temp2 in v:
                #print ('Parent: ', k, 'Child: ', temp2)
                k2=k
                list2.append(k2)
                mykcount=0
                break
            else:
                mykcount=2
    myk11=k1
    myk22=k2

    def myk1(k1):
        for k, v in mydict.items():
            if k1 == v or isinstance(v, list) and k1 in v:
                #print ('Parent: ', k, 'Child: ', k1)
                k1=k
                list1.append(k1)
                mykcount=0
                break
            else:
                mykcount=1

        if(mykcount==1):
            #print ('Parent: No ancestor', 'Child: ', k1)
            k1=0
        else:
            myk1(k1)

    def myk2(k2):
        for k, v in mydict.items():
            if k2 == v or isinstance(v, list) and k2 in v:
                #print ('Parent: ', k, 'Child: ', k2)
                k2=k
                list2.append(k2)
                mykcount=0
                break
            else:
                mykcount=2

        if(mykcount==2):
            #print ('Parent: No ancestor', 'Child: ', k2)
            k2=0
        else:
            myk2(k2)

    myk1(k1)
    myk2(k2)
    mlist1=[]
    mlist2=[]
    k1=0
    k2=0
    flist1=[]
    flist2=[]

    for k, v in mydict.items():
          if temp1 == v or isinstance(v, list) and temp1 in v:
                    #print ('Parent: ', k, 'Child: ', temp1)
                    myzk1=k
                    mlist1.append(myzk1)
    for k, v in mydict.items():
           if temp2 == v or isinstance(v, list) and temp2 in v:
                    #print ('Parent: ', k, 'Child: ', temp2)
                    myzk2=k
                    mlist2.append(myzk2)

    for i in range(0, len(mlist1)):
         if(myk11!=int(mlist1[i])):
               flist1.append(list1)
               k1=mlist1[i]
               list1=[temp1,k1]
               myk1(k1)

    for i in range(0, len(mlist2)):
         if(myk22!=int(mlist2[i])):
                flist2.append(list2)
                k2=mlist2[i]
                list2=[temp2,k2]
                myk2(k2)

    if(list1!=[temp1]):
      flist1.append(list1)
      list1=[temp1]

    if(list2!=[temp2]):
      flist2.append(list2)
      list2=[temp2]

    fcount=0
    c=0

    myflist=[]


    for i in flist1:
            xcount=0
            fy=i
            for z in range (0,len(fy)):
                xlist1=fy[z]
                for j in flist2:
                    fx=j
                    for z1 in range (0,len(fx)):
                        ylist2=fx[z1]
                        if(xlist1==ylist2):

                            xcount=xcount+1
                            if(xcount>fcount):
                                fcount=xcount

                                myflist=[xlist1]


    if(mflag!=1):
        if(myflist==[]):
            print('No Common Ancestor')
        else:
            pos=0
            pos=len(myflist)-fcount
            print('Least Common Ancestor: ',myflist[pos-1])
