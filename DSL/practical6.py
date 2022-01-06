from sys import *
def quicksort(arr):
    elements = len(arr)
    
    #Base case
    if elements < 2:
        return arr
    
    current_position = 0 #Position of the partitioning element

    for i in range(1, elements): #Partitioning loop
         if arr[i] <= arr[0]:
              current_position += 1
              temp = arr[i]
              arr[i] = arr[current_position]
              arr[current_position] = temp

    temp = arr[0]
    arr[0] = arr[current_position] 
    arr[current_position] = temp #Brings pivot to it's appropriate position
    
    left = quicksort(arr[0:current_position]) #Sorts the elements to the left of pivot
    right =quicksort(arr[current_position+1:elements]) #sorts the elements to the right of pivot
    arr = left + [arr[current_position]] + right #Merging everything together
    
    return arr
    



# setrecursionlimit()
print("MENU")
print("Quick sort")
# option=int(input("Enter your choice:"))
n=int(input("Enter total number of students:"))
percentage=[]
i=1
while(i<=n):

        x=float(input("Enter percentage:"))
        if(x<35 or x>100):
            print("enter valid percentage")
           
        if(x>=35 and x<=100):
            percentage.append(x)
            i=i+1
print("Sorted array is:")
result=quicksort(percentage)
print(result)

print("Top 5 among them are:")
print(result[-1:-5:-1])



