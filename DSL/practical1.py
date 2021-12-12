cricket=[]
badminton=[]
football=[]
lst1=[]
lst2=[]
lst3=[]
lst4=[]
cricket_no=int(input("Enter no of students who play cricket:"))
for i in range(0,cricket_no):
    element=input()
    if element not in cricket:
        cricket.append(element)
badminton_no=int(input("Enter no of students who play badminton:"))
for j in range(0,badminton_no):
    element1=input()
    if element1 not in badminton:
        badminton.append(element1)
football_no=int(input("Enter no of students who play football:"))
for k in range(0,football_no):
    element2=input()
    if element not in football:
        football.append(element2)

print("students who play cricket are:")
print(cricket)
print("students who play badminton are:")
print(badminton)
print("students who play football are:")
print(football)
print("Students who play both badminton and cricket are:")
for i in cricket:
    
    if i in badminton:
        lst1.append(i)
print(lst1)
print("Students who play either cricket or badminton but not both:")
for i in cricket:
    
    if i not in badminton:
        lst2.append(i)
print(lst2)
print("Students who play neither cricket nor badminton:")
for i in football:
    
    if i not in cricket and i not in badminton:
        lst3.append(i)
print(lst3)
print("Students who play cricket and foorball but not badminton:")
for i in cricket:
    
    if i in football and i not in badminton:
        lst4.append(i)
print(lst4)






