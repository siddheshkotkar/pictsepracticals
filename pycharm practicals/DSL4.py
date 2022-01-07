class randomsearch:
    def linear_search(self,arr,key):
        res=False
        for i in arr:
            if i==key:
                res=i
            else:
                res=-1
        return res

    def sentinel_search(self,arr,key):
        res=False
        arr.append(key)
        for i in arr:
            index = arr.index(i)
            last = len(arr)-1
            if index == last:
                res = -1
                return res
            if i == key:
                res = index
                return res

    def binary_search(self,arr,key):
        first=0
        last=len(arr)-1
        found = False
        while(first <= last and not found):
            mid = (first+last)//2
            if arr[mid] == key:
                found = True
                print(key," found at index ",mid)
                return
            elif key<arr[mid]:
                last = mid-1
            else:
                first = mid+1
        print(key, "not found!!")

    def fibbonacci_search(self,arr,key):
            a = 0
            b = 1
            fibboseries = []
            fibboseries.append(a)
            fibboseries.append(b)
            c = 0
            while (c < len(arr)):
                c = a + b
                fibboseries.append(c)
                a = b
                b = c

            # print(fibboseries)
            n = len(arr)-1
            m = len(fibboseries) - 1
            ofs = -1
            i = min((ofs + fibboseries[m - 2]), n)
            while m > 0:
                if arr[i] == key:
                    print("Element Found at index: ", i)
                    return
                elif key > arr[i]:
                    ofs = i


                m -= 1
                i = min((ofs + fibboseries[m - 2]), n)
            print("Element Not Found")


randobj = randomsearch()
n=int(input("enter number of roll no you want to enter:"))
list1=[]
for i in range(0,n):
    roll = int(input("Enter roll number:"))
    list1.append(roll)
sortedlist = []
sortedlist = sorted(list1)
# print(sortedlist)

op=0
while(op!=5):
    print("MENU")
    print("1.Linear search")
    print("2.Sentinel search")
    print("3.Binary Search")
    print("4.Fibbonacci Search")
    print("5.Exit")
    op = int(input("Enter your choice:"))
    if op == 1:
        if sortedlist == list1:
            print("Please enter random list or use binary or fibbonacci search!!")
        else:
            key = int(input("Enter key element to be searched:"))
            answer = randobj.linear_search(list1, key)
            if answer == -1:
                print("roll number not found in the list")
            else:
                print("roll no found at ",answer)

    elif op == 2:
        if sortedlist == list1:
            print("Please enter random list or use binary or fibbonacci search!!")
        else:
            key = int(input("Enter key element to be searched:"))
            answer = randobj.sentinel_search(list1, key)
            if answer == -1:
                print("roll number not found in the list")
            else:
                print("roll no found at ", answer)

    elif op == 3:
        if sortedlist == list1:
            key = int(input("Enter key element to be searched:"))
            randobj.binary_search(list1, key)

        else:
            print("Your list is sorted please enter random list or use linear or sentinel search")



    elif op == 4:
        if sortedlist == list1:
            key = int(input("Enter key element to be searched:"))
            randobj.fibbonacci_search(list1, key)

        else:
            print("Your list is sorted please enter random list or use linear or sentinel search")




