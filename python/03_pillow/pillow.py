
# Image processing library
# Check how pillow library works

# Babak Poursartip
# 02/01/2020
from PIL import Image, ImageOps, ImageFilter
import numpy as np

def main():

  print("{}".format(" pillow image processing code starts ..."))


  # Reading images from files ==================================================
  print("{}".format(" reading images ..."))
  Image1 = Image.open("fig2_B-10/A.png").convert("L")
  Image2 = Image.open("fig2_B-10/B.png").convert("L")
 
  # If you have an L mode image, that means it is a single channel image - normally interpreted as greyscale. The L means that is just stores the Luminance. It is very compact, but only stores a greyscale, not colour.

  print("{}".format(" convert the image to an array ... "))

  #Image1_ar_int = np.array(Image1)
  Image1_ar_int = np.array(Image1, dtype=np.uint8)
  Image2_ar_int = np.array(Image2, dtype=np.uint8)

  Image1_ar_int2 = np.array(Image1, dtype=np.int16)
  Image2_ar_int2 = np.array(Image2, dtype=np.int16)

  #Image1_ar_int[Image1_ar_int<0] = 0
  #Image1_ar_int[Image1_ar_int>255] = 255


  print("{} {}".format("size of matrix:", Image1_ar_int.shape))
  print("{} {}".format("size of matrix:", Image2_ar_int.shape))

  print("{} {}".format("size of matrix:", Image1_ar_int2.shape))
  print("{} {}".format("size of matrix:", Image2_ar_int2.shape))

  print(" arrays:")
  #print(Image1_ar_int)
  print(Image1_ar_int[100,100])
  print(Image1_ar_int2[100,100])

  print(" arrays:")
  print(Image1_ar_int2)


  # Transformations ===========================================================



  # Addition/Subtraction ======================================================
  #Image.fromarray(Image1_ar_int).convert("L").show()
  #Image.fromarray(Image1_ar_int2).show()
  #wait = input("image1")
  #Image.fromarray(Image2_ar_int).convert("L").show()
  #Image.fromarray(Image2_ar_int2).show()
  #wait = input("image2")

  Im_n1 = Image1_ar_int  - Image2_ar_int
  Im_n2 = Image2_ar_int  - Image1_ar_int

  #Image.fromarray(Im_n1).convert("L").show()
  #Image.fromarray(Im_n1).show()
  #wait = input("image1 - image 2")  
  #Image.fromarray(Im_n2).convert("L").show()
  #Image.fromarray(Im_n2).show()
  #wait = input("image2 - image1")


  # intersection and union  ===================================================
  #Image3 = Image1.open("fig2_B-10/A.png").convert("1")
  #Image4 = Image2.open("fig2_B-10/B.png").convert("1")

  image3_array = np.asarray(Image1.convert('1'), dtype=np.float32)
  image4_array = np.asarray(Image2.convert('1'), dtype=np.float32)

  union = image3_array + image4_array
  #print(union)
  union = np.where(union > 1., 1., 0)
  #print(union)
  #Image.fromarray(intersect).convert("1").show()
  Image.fromarray(union*255).show()
  #Image.fromarray(Image1_ar_int2).show()
  wait = input("union")

  intersect = image3_array + image4_array
  #print(intersect)
  intersect = np.where(intersect >= 1., 1., 0)
  #print(intersect)
  #Image.fromarray(intersect).convert("1").show()
  Image.fromarray(intersect*255).show()
  #Image.fromarray(Image1_ar_int2).show()
  wait = input("intersect")

  # union =====================================================================



  # numpy =====================================================================
  print(" NumPy: ---")
  Image1_ar1 = np.array(Image1.convert("1"), dtype=np.float32)
  Image1_ar2 = np.asarray(Image1.convert("L"), dtype=np.float32)
  
  print(" size:", Image1_ar1.shape, Image1_ar2.shape)
  print(Image1_ar1)
  print(Image1_ar2)

  check = np.zeros((5,3))
  print(check[2,2])
  print(check.size, check.shape)

  print("{}".format(" End of the code successfully."))


if __name__ == "__main__":
  main()
