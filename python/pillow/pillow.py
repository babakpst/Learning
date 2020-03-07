
# Image processing library
# Check how pillow library works

# Babak Poursartip
# 02/01/2020
from PIL import Image, ImageOps, ImageFilter
import numpy as np

def main():

  print("{}".format(" pillow image processing code starts ..."))

  print("{}".format(" reading images ..."))
  Image1 = Image.open("fig1_2x1BasicProblem01/1.png")
  Image2 = Image.open("fig1_2x1BasicProblem01/6.png")
  Image1.show()
  Image2.show()  
  
  print("{}".format(" convert the image to an array ... "))

  Image1_ar_int = np.array(Image1, dtype=np.int16)
  Image2_ar_int = np.array(Image2, dtype=np.int16)
  
  print("{} {}".format("size of matrix:", Image1_ar_int.shape))
  print("{} {}".format("size of matrix:", Image2_ar_int.shape))


  w, h = 512, 512
  data = np.zeros((h, w, 3), dtype=np.uint8)
  data[0:256, 0:256] = [255, 0, 0] # red patch in upper left
  img = Image.fromarray(data, 'RGB')
  img.show()


  #Image.fromarray(Image1_ar_int).convert("L").show()
  #wait = input("PRESS ENter")

  #Im_n1 = Image1_ar_int  - Image2_ar_int
  #Im_n2 = Image2_ar_int  - Image1_ar_int

  #Image.fromarray(Im_n1).convert("L").show()
  #wait = input("PRESS ENter")  
  #Image.fromarray(Im_n2).convert("L").show()
  #wait = input("PRESS ENter")


  #res_1 = Image.fromarray(Im_n1)
  #res_2 = Image.fromarray(Im_n2)
  #res_1.show()
  #res_2.show()

  Image1_ar = np.array(Image1)
  Image2_ar = np.array(Image2)
  print("{} {}".format("size of matrix:", Image1_ar.shape))
  print("{} {}".format("size of matrix:", Image2_ar.shape))


  # convert back to image:  Image.fromarray(im2arr)


  check = np.zeros((5,3))
  print(check.size, check.shape)

  print("{}".format(" End of the code successfully."))


if __name__ == "__main__":
  main()
