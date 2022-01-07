def parseinput(val):
    return int(val)

def printmatrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            print(matrix[i][j],end=" ")
        print()

def inputmatrix(matrix,row,col):
    for i in range(row):
        a=list(map(parseinput,input().split(" ")))
        # for j in range(col):
        #     a.append(int(input()))
        matrix.append(a)
    return matrix

def addmatrices(matrix1,matrix2):
    addmatrix=[]
    for i in range(len(matrix1)):
        rowsum=[]
        for j in range(len(matrix2[0])):
            sum=matrix1[i][j]+matrix2[i][j]
            rowsum.append(sum)
        addmatrix.append(rowsum)
    return addmatrix

def submatrices(matrix1,matrix2):
    submatrix=[]
    for i in range(len(matrix1)):
        rowsub=[]
        for j in range(len(matrix1[0])):
            diff=matrix1[i][j]-matrix2[i][j]
            rowsub.append(diff)
        submatrix.append(rowsub)
    return submatrix

def mulmatrices(matrix1,matrix2):
    mulmatrix=[]
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            mul = 0
            for k in range(len(matrix2)):
                mul+=matrix1[i][k]*matrix2[k][j]
            row.append(mul)
        mulmatrix.append(row)
    return mulmatrix

def transposematrix(matrix1):
    transposed=[]
    for i in range(len(matrix1[0])):
        row=[]
        for j in range(len(matrix1)):
            # row=matrix1[j][i]
            row.append(matrix1[j][i])
        transposed.append(row)
    return transposed
# print(len(matrix1))
endlist=False
while endlist!=True:
    print("1.Addition of two matrices:")
    print("2.Subtraction of two matrices:")
    print("3.Multiplication of two matrices:")
    print("4.Transpose of a matrix:")
    print("5.Exit")
    print("Enter your option:")
    option=int(input())

    if option==1:
        print("Enter values for first matrix:")
        row=int(input("Enter no of rows you want to enter:"))
        col=int(input("Enter number of columns you want to enter:"))
        matrix1=[]
        inputmatrix(matrix1,row,col)

        print("Enter values for second matrix:")
        row1=int(input("Enter no of rows you want to enter:"))
        col1=int(input("Enter number of columns you want to enter:"))
        matrix2=[]
        inputmatrix(matrix2,row,col)
        print("Addition is:")
        addmatrix=addmatrices(matrix1,matrix2)
        printmatrix(addmatrix)
        

    elif option==2:
        print("Enter values for first matrix:")
        row=int(input("Enter no of rows you want to enter:"))
        col=int(input("Enter number of columns you want to enter:"))
        matrix1=[]
        inputmatrix(matrix1,row,col)

        print("Enter values for second matrix:")
        row1=int(input("Enter no of rows you want to enter:"))
        col1=int(input("Enter number of columns you want to enter:"))
        matrix2=[]
        inputmatrix(matrix2,row,col)

        print("Subtraction is:")
        submatrix=submatrices(matrix1,matrix2)
        printmatrix(submatrix)

    elif option==3:
        print("Enter values for first matrix:")
        row=int(input("Enter no of rows you want to enter:"))
        col=int(input("Enter number of columns you want to enter:"))
        matrix1=[]
        inputmatrix(matrix1,row,col)

        print("Enter values for second matrix:")
        row1=int(input("Enter no of rows you want to enter:"))
        col1=int(input("Enter number of columns you want to enter:"))
        matrix2=[]
        inputmatrix(matrix2,row,col)

        print("Multiplication of matrices is:")
        mulmatrix=mulmatrices(matrix1,matrix2)
        printmatrix(mulmatrix)

    elif option==4:
        print("Enter a matrix which is to be transpoesd:")
        row=int(input("Enter no of rows you want to enter:"))
        col=int(input("Enter number of columns you want to enter:"))
        matrix1=[]
        inputmatrix(matrix1,row,col)
        transposed=transposematrix(matrix1)
        printmatrix(transposed)
    
    elif option==5:
        endlist=True
