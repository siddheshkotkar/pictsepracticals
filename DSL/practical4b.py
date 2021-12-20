def binarysearch(roll,selection):
    first = 0
    last = len(roll)-1
    found = False
    while( first<=last and not found):
        mid = (first + last)//2
        if roll[mid] == selection :
            found = True
        else:
            if selection < roll[mid]:
                last = mid - 1
            else:
                first = mid + 1	
    return found

def fibbonaccisearch(array,selection):
    n=1
    a=0
    b=1
    fibboseries=[]
    fibboseries.append(a)
    fibboseries.append(a)
    c=0
    while(c<=len(array)):
        c=a+b
        fibboseries.append(c)
        a=b
        b=c
        n+=1
    print(fibboseries)
    offset=-1
    while(c>1):
        i=min(offset+a,n-1)
        if array[i]<selection:
            c=b
            b=a
            a=c-b
        elif array[i]>selection:
            c=a
            b=b-a
            a=c-b
        else:   
            return 1
            f=1
            break

no=int(input("Enter the number of studets you want to enter:"))
print("Enter roll numbers of students:")
roll=[]

for i in range(0,no):
    roll_no=int(input())
    roll.append(roll_no)

   

selection=int(input("Enter the roll no you want to search:"))
print("select the type of search you want to use:")
print("1.Binary Search")
print("2.Fibbonacci Search")
option=int(input())
if option==1:
    res=binarysearch(roll,selection)
    if res==True:
        print(selection," is present in the array")
    else:
        print(selection," is not present in the array")

elif option==2:
    res=fibbonaccisearch(roll,selection)
    if res==1:
        print(selection," is present")
    else:
        print(selection," is not present in array")