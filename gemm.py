'''
    Scripts creates matrices in c format and prints the reference result
    of General Matrix Multiplication
    
    usage: python gemm.py <SIZE> <RANGE> <ALPHA> <BETA>
'''

from pprint import pprint
import numpy as np
import sys
import os

SIZE  = 16
RANGE = 100
ALPHA = 1
BETA  = 2

def print_Cformat(A, name="a"):
    print("mat_t " + name + "[SIZE][SIZE] = ", end="")
    print("{", end="")
    for i in range(0, A.shape[0]):
        print("{", end="")
        for j in range(0, A.shape[1]):
            if j != A.shape[1] - 1:
                print(f"{A[i][j]}, ", end = "")
            else:
                print(A[i][-1], end="")
        if i != A.shape[0] - 1:
            print("},")
        else:
            print("}", end="")
    print("};")
    print()
        
def cls():
    os.system('cls' if os.name=='nt' else 'clear')

def gemm(a, b, c, a1, b1):
    tmp = np.matmul(a,b)
    tmp = a1 * tmp
    c = b1 * c
    return tmp + c

if __name__ == "__main__":
    if len(sys.argv) == 5:
        SIZE  = int(sys.argv[1])
        RANGE = int(sys.argv[2])
        ALPHA = int(sys.argv[3])
        BETA  = int(sys.argv[4])

    # now, to clear the screen
    cls()

    a = np.random.randint(0, RANGE, size=(SIZE,SIZE))
    b = np.random.randint(0, RANGE, size=(SIZE,SIZE))
    c = np.zeros((SIZE, SIZE))

    a1 = ALPHA
    b1 = BETA

    print_Cformat(a, name="a")
    print_Cformat(b, name="b")
    print_Cformat(c, name="c")
    print(f"mat_t a1 = {a1};")
    print(f"mat_t b1 = {b1};")
    ref = gemm(a, b, c, a1, b1)
    print_Cformat(ref, name="ref")












    