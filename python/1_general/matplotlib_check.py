import numpy as np
import matplotlib.pyplot as plt
import math

x = np.arange(1, 10, 1)
N = len(x)
fa = np.zeros(N,dtype=int)
fb = np.zeros(N,dtype=int)
fc = np.zeros(N,dtype=int)
fd = np.zeros(N,dtype=int)
fe = np.zeros(N,dtype=int)

for i in range(N):
  fa[i] = 2**(2**x[i])
  fb[i] = 2**(x[i]**2)
  fc[i] = (x[i]**2)* math.log(x[i],2)
  fd[i] = x[i]
  fe[i] = x[i]**(2**x[i])
  print(x[i],fa[i],fb[i],fc[i],fd[i],fe[i])

fig = plt.figure()
ax = plt.subplot(111)

ax.plot(x, fa, label='a')
ax.plot(x, fb, label='b')
#ax.plot(x, fc, label='c')
#ax.plot(x, fd, label='d')
#ax.plot(x, fe, label='e')

plt.title('Legend inside')
ax.legend()
plt.show()


ax.plot(x, fa,x, fb,x, fc,x, fd,x, fe)

