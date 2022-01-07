from sys import *
class quicksortop:

    def quicksort(self,arr):
        elements = len(arr)

        # Base case
        if elements < 2:
            return arr

        current_position = 0  # Position of the partitioning element

        for i in range(1, elements):  # Partitioning loop
            if arr[i] <= arr[0]:
                current_position += 1
                temp = arr[i]
                arr[i] = arr[current_position]
                arr[current_position] = temp

        temp = arr[0]
        arr[0] = arr[current_position]
        arr[current_position] = temp  # Brings pivot to it's appropriate position

        left = self.quicksort(arr[0:current_position])  # Sorts the elements to the left of pivot
        right = self.quicksort(arr[current_position + 1:elements])  # sorts the elements to the right of pivot
        arr = left + [arr[current_position]] + right  # Merging everything together

        return arr


sortop = quicksortop()
n = int(input("Enter total number of students:"))
percentage = []
i = 1
while (i <= n):

    x = float(input("Enter percentage:"))
    if (x < 35 or x > 100):
        print("enter valid percentage")

    if (x >= 35 and x <= 100):
        percentage.append(x)
        i = i + 1
op = 0
while op!=3:
    print("MENU")
    print("1.Quick sort")

    print("2.Print top 5")
    print("3.Exit")
    op = int(input("Enter your choice:"))
    if op == 1:
        print("Sorted array is:")
        result = sortop.quicksort(percentage)
        print(result)

    elif op == 2:
        print("Top 5 among them are:")
        print(result[-1:-5:-1])





