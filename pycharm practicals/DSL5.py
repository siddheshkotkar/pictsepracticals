class sort_functions:
    def insertionsort(self,percentage):
        for i in range(1, len(percentage)):
            j = i
            while (percentage[j - 1] > percentage[j]) and j > 0:
                percentage[j - 1], percentage[j] = percentage[j], percentage[j - 1]
                j -= 1
        return percentage


    def shellsort(self,percentage):
        size = len(percentage)
        gap = size // 2

        while gap > 0:
            for i in range(gap, size):
                anchor = percentage[i]
                j = i
                while j >= gap and percentage[j - gap] > anchor:  # sorting done using insertion sort
                    percentage[j] = percentage[j - gap]
                    j -= gap
                percentage[j] = anchor
            gap = gap // 2
        return percentage

sorting = sort_functions()
option=0
n = int(input("Enter total number of students:"))
percentage = []
i = 0
while i < n:
    per = float(input("Enter percentage:"))
    if per >= 35 and per <= 100:
        percentage.append(per)
        i += 1
    else:
        print("Enter valid percentage!!")
while(option!=3):

    print("MENU")
    print("1.Insertion sort")
    print("2.Shell sort")
    print("3.Exit")
    option = int(input("Enter your choice:"))


    # for i in range(n):
    #     x = float(input("Enter percentage:"))
    #     percentage.append(x)
    if option == 1:

        sorting.insertionsort(percentage)
        print("Following are the sorted percentages:")
        print(percentage)
        print("Top 5 among them are:")
        print(percentage[-1:-6:-1])

    elif option == 2:
        sorting.shellsort(percentage)
        print("Following are the sorted percentages:")
        print(percentage)
        print("Top 5 among them are:")
        print(percentage[-1:-6:-1])
