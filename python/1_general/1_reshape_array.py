

import numpy as np

a = np.random.randn(4,3)
print(" a shape: {}".format(a.shape))
print(" a: \n {}".format(a))


a=a.reshape(-1,1)
print(" a shape: {}".format(a.shape))
print(" a: \n {}".format(a))
