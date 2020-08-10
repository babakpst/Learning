
# Babak Poursartip

# plotting the logistic cost function
# 08/02/2020

import matplotlib.pyplot as plt
import numpy as np

def posCase(temp):
  return (-np.log(1.0/(1.0+np.exp(-temp))) )

def negCase(temp):
  return (-np.log(1.0-(1.0/(1.0+np.exp(-temp)))) )


def plot():
  print("{}".format(" here is the logistic costfunction"))
  z = np.arange(-3.0,3.0,0.1,dtype=np.float64)

  pfunc = np.vectorize(posCase)
  pos = pfunc(z)

  nfunc = np.vectorize(negCase)
  neg = nfunc(z)
   
  fig = plt.figure()
  ax = plt.subplot(111)
  ax.plot(z,pos,label='positive case')
  ax.plot(z,neg,label='negative case')
  ax.legend()
  plt.show()


if __name__=="__main__":
  plot()
