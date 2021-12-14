def linearsearch(roll,selection):
    # print(roll)
    for i in roll:
        if i==selection:
            return 1
    return -1

def sentinelsearch(roll,selection,no):
    for i in roll:
        index=roll.index(i)
        last=no-1
        if index==last:
            return -1
        if i==selection:
            return 1


    

no=int(input("Enter the number of studets you want to enter:"))
print("Enter roll numbers of students:")
roll=[]

for i in range(0,no):
    roll_no=int(input())
    roll.append(roll_no)

selection=int(input("Enter the roll no you want to search:"))
print("select the type of search you want to use:")
print("1.Linear Search")
print("2.Sentinal Search")
option=int(input())
if option==1:
    res=linearsearch(roll,selection)
    if res==1:
        print(selection," is present in the array")
    else:
        print(selection," is not present in the array")

elif option==2:
    res=sentinelsearch(roll,selection,no)
    if res==1:
        print(selection," is present")
    else:
        print(selection," is not present in array")
