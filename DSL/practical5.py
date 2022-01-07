def insertionsort(percentage):
    for i in range(1,len(percentage)):
        j=i
        while(percentage[j-1]>percentage[j]) and j>0:
            percentage[j-1],percentage[j]=percentage[j],percentage[j-1]
            j-=1
    return percentage

def shellsort(percentage):
    size = len(percentage)
    gap = size//2

    while gap > 0:
        for i in range(gap,size):
            anchor = percentage[i]
            j = i
            while j>=gap and percentage[j-gap]>anchor:  #sorting done using insertion sort
                percentage[j] = percentage[j-gap]
                j -= gap
            percentage[j] = anchor
        gap = gap // 2
    return percentage


print("MENU")
print("1.Insertion sort")
print("2.Shell sort")
option=int(input("Enter your choice:"))
n=int(input("Enter total number of students:"))
percentage=[]
for i in range(n):
        x=float(input("Enter percentage:"))
        percentage.append(x)
if option==1:
    
    

    insertionsort(percentage)
    print("Following are the sorted percentages:")
    print(percentage)
    print("Top 5 among them are:")
    print(percentage[-1:-6:-1])

elif option==2:
    shellsort(percentage)
    print("Following are the sorted percentages:")
    print(percentage)
    print("Top 5 among them are:")
    print(percentage[-1:-6:-1])
