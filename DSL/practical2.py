def max_word(array):
    maxlen=0
    maxword=""
    for i in array:
        if maxlen<len(i):
            maxword=i
            maxlen=len(maxword)
    return maxword    

def occurence(string2,chara2):
    count=0
    for i in string2:
        if i==chara2:
            count+=1
    return count

def isplaindrome(string3):
    mid=int(len(string3)/2)
    for i in range(0,mid):
        if string3[i]!=string3[len(string3)-i-1]:
            return False
        return True 

def occurence_susbstring(string4,subs):
    array3=string4.split(" ")
    for i in array3:
        if i==subs:
            return array3.index(i)

def occurence_word(string5,string6):
    count=0
    array4=string5.split(" ")
    for i in array4:
        if i==string6:
            count+=1
    return count


array=[]
isEnd = False
# for i in sentence:
#     array=sentence.split(" ")
while(isEnd!=True):

    print("MENU")
    print("1.To Display word with longest length")
    print("2.To determin freq of occurence of particular character in string")
    print("3.To check whether given string is palindrome or not")
    print("4.To display index of first appearance of substring")
    print("5.To count occurences of each word in given string")
    print("6.Exit")
    print("Select option which you want to perform:")
    option = int(input())

    if option==1:
        sentence = input("Enter a sentence to begin: ")
        array=sentence.split(" ")
        print(max_word(array))
        

    elif option==2:
        string2=input("Enter a string:")
        chara2=input("Enter a character to find its occurance:")
        print(occurence(string2,chara2))

    elif option==3:
        string3=input("Enter a string to check its palindrome or not:")
        print(isplaindrome(string3))

    elif option==4:
        string4=input("Enter a string:")
        subs=input("Enter a substring to find its index:")
        print(occurence_susbstring(string4,subs))

    elif option==5:
        string5=input("Enter a string:")
        string6=input("Enter a character to find its occurence:")
        print(occurence_word(string5,string6))
        
    else:
        isEnd=True



