
import numpy as np

def main():
  print("this is the code")

  mat_size = (5,5)
  #mat = np.zeros(mat_size, dtype=float)
  #mat = np.random.randn(5,5)
  mat = np.random.rand(*mat_size)
  #mat = np.zeros(5, dtype=float)

  print(mat)
  print(mat.shape)

  serialized_size = 1
  for size in mat_size:
    serialized_size *=size

  mat=mat.reshape (-1)
  print(mat)
  print(mat.shape)

  mat=mat.reshape (mat_size)
  print(mat)
  print(mat.shape)

  mat=mat.reshape (-1, order='F')
  print(mat)
  print(mat.shape)


if __name__== "__main__":
  main()


