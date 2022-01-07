class sports:
    cricket = []
    football = []
    badminton = []

    def input(self):
        n=int(input("Enter no of students who play cricket:"))
        for i in range(n):
            roll=int(input("Enter roll no:"))
            self.cricket.append(roll)

        n = int(input("Enter no of students who play football:"))
        for i in range(n):
            roll = int(input("Enter roll no:"))
            self.football.append(roll)

        n = int(input("Enter no of students who play badminton:"))
        for i in range(n):
            roll = int(input("Enter roll no:"))
            self.badminton.append(roll)

    def both(self):
        temp_list = []
        for i in self.cricket:
            if i in self.badminton:
                temp_list.append(i)
        print("Students who play both cricket and badminton are: ",temp_list)

    def either_corb(self):
        temp_list = []
        for i in self.cricket:
            if i not in self.badminton:
                temp_list.append(i)
        for i in self.badminton:
            if i not in self.cricket:
                temp_list.append(i)
        temp_list = temp_list + self.football
        print("Students who play either cricket or badminton but not both are: ",temp_list)

    def neither_corb(self):
        temp_list = []
        for i in self.football:
            if i not in self.cricket and i not in self.badminton:
                temp_list.append(i)
        print("Students who play neither cricket nor badminton are: ",temp_list)

    def candfnb(self):
        temp_list = []
        for i in self.cricket:
            if i in self.football and i not in self.badminton:
                temp_list.append(i)
        print("Students who play cricket and football but not badminton are: ",temp_list)



sp=sports()
sp.input()
op=0
while op!=5:
    print("MENU")
    print("1.Get students who play both cricket and badminton are:")
    print("2.Get Students who play either cricket or badminton but not both:")
    print("3.Get Students who play neither cricket nor badminton:")
    print("4.Get Students who play cricket and football but not badminton:")
    print("5.Exit")
    op = int(input("Enter your choice:"))
    if(op==1):
        sp.both()
    elif(op==2):
        sp.either_corb()
    elif(op==3):
        sp.neither_corb()
    elif(op==4):
        sp.candfnb()




