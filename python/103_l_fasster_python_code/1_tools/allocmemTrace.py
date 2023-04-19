
 # April 13, 2023

# prints memory information
import tracemalloc

tracemalloc.start()

l1 = [i for i in range(10000)]
l2 = [i*i for i in range(10000)]
l3 = [i*i*i for i in range(10000)]

snapshot = tracemalloc.take_snapshot()

for stat in snapshot.statistics("lineno"):
    print(stat)

tracemalloc.stop()
