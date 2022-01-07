class Matrix:
    def __init__(self, rows, cols):
        self.matrix = [[0 for j in range(cols)] for i in range(rows)]

    def getData(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                self.matrix[i][j] = int(input(f"Enter matrix[{i}][{j}] element : "))

    def addmatrix(self, other):
        if len(self.matrix) != len(other.matrix) or len(self.matrix[0]) != len(other.matrix[0]):
            raise ValueError("Matrix Can't be added because size is different")

        addition = Matrix(len(self.matrix), len(self.matrix[0]))
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                addition.matrix[i][j] = self.matrix[i][j] + other.matrix[i][j]
        return addition

    def submatrix(self, other):
        if len(self.matrix) != len(other.matrix) or len(self.matrix[0]) != len(other.matrix[0]):
            raise ValueError("Matrix Can't be subtracted because size is different")

        subtraction = Matrix(len(self.matrix), len(self.matrix[0]))
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                subtraction.matrix[i][j] = self.matrix[i][j] - other.matrix[i][j]
        return subtraction

    def mulmatrix(self, other):
        if len(self.matrix[0]) != len(other.matrix):
            raise ValueError("Matrix Can't be multiplied because size is different")
        multiplication = Matrix(len(self.matrix), len(other.matrix[0]))
        for i in range(len(self.matrix)):
            for j in range(len(other.matrix[0])):
                for k in range(len(self.matrix[0])):
                    multiplication.matrix[i][j] = (self.matrix[i][k] * other.matrix[k][j]) + multiplication.matrix[i][j]

        return multiplication

    def __neg__(self):
        transpose = Matrix(len(self.matrix),len(self.matrix[0]))
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                transpose.matrix[j][i] = self.matrix[i][j]
        return transpose

    def print(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                print(f"{self.matrix[i][j]} ", end="")
            print()

row=int(input("Enter number of rows you want to enter for matrix 1:"))
column=int(input("Enter number of column you want to enter for matrix 1:"))

matrix1 = Matrix(row,column)
matrix1.getData()
row=int(input("Enter number of rows you want to enter for matrix 2:"))
column=int(input("Enter number of column you want to enter for matrix 2:"))

matrix2 = Matrix(row,column)
matrix2.getData()
op=0
while(op!=5):
    print("MENU")
    print("1.Addition of matrices")
    print("2.Subtraction of matrices")
    print("3.Multiplication of matrices")
    print("4.Transpose of matrix")
    print("5.Exit")
    op=int(input("Enter your choice:"))
    if op==1:
        matrix = matrix1.addmatrix(matrix2)
        matrix.print()
    elif op==2:
        matrix = matrix1.submatrix(matrix2)
        matrix.print()
    elif op==3:
        matrix = matrix1.mulmatrix(matrix2)
        matrix.print()
    elif op==4:
        matrix_1 = -matrix1
        matrix_2 = -matrix2
        matrix_1.print()
        matrix_2.print()




# matrix = matrix1 * matrix2
# matrix.print()
# matrix = -matrix
# matrix.print()
