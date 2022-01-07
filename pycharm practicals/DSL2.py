class stringop:
    str=""
    def inputstring(self):
        self.str = input("Enter a string:")

    def longestlen(self):
        temp_list = list(self.str.split(" "))
        # print(self.str)
        maxlen = 0
        maxword = ""
        # length=0
        for i in temp_list:
            length = len(i)
            if length > maxlen:
                maxlen = length
                maxword = i
        print(maxword, " is the word with longest length in string")

    def occurencechar(self):
        find=input("Enter a character to get its occurence:")
        count = 0
        for i in self.str:
            if i == find:
                count += 1

        print("Occurence of character ", find, " is ", count, " times")


    def ispalindrome(self):
        string = input("Enter a word to check whether it is palindrome or not:")
        length = len(string)
        mid = int(length/2)
        for i in range(0 , mid):
            if string[i] != string[length-i-1]:
                return 0
            return 1

    def substringappearance(self):
        substr = input("Enter the substring to be checked:")
        temp_list = list(self.str.split(" "))
        for i in temp_list:
            if i == substr:
                index = temp_list.index(i)
                print(substr, "is found at index ",index+1)
                break
            if substr not in temp_list:
                print("Substring not found!!")
                break

    def stringoccurence(self):

        words = {}
        temp_list = list(self.str.split(" "))
        for i in temp_list:
            if i in words.keys():
                words[i] += 1
            else:
                words[i] = 1
        print(words)



str = stringop()
op=0
str.inputstring()
while(op!=6):
    print("MENU")
    print("1.Get word with longest length:")
    print("2.Get occurence of character:")
    print("3.check whether string is palindrome or not:")
    print("4.Get first occurence of substring:")
    print("5.Get substring occurences")
    print("6.Exit")
    op=int(input("Enter your choice:"))
    if op==1:
        str.longestlen()
    elif op==2:
        str.occurencechar()
    elif op==3:
        if str.ispalindrome() == 1:
            print("String is palindrome")
        else:
            print("String is not palindrome")
    elif op==4:
        str.substringappearance()
    elif op==5:
        str.stringoccurence()
