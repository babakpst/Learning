from timeit import default_timer as timer
start=timer()

for i in range(pow(2,15)):
  a = i

readend=timer()
print("time:",readend-start)
