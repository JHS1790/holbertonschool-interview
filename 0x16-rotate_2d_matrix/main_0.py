#!/usr/bin/python3
"""
Test 0x16 - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

def displayMatrix( mat ):
    N = len(matrix[0]) 
    for i in range(0, N):
         
        for j in range(0, N):
             
            print (mat[i][j], end = ' ')
        print ("")

if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]
    
    displayMatrix(matrix)
    print()
    rotate_2d_matrix(matrix)
    displayMatrix(matrix)

