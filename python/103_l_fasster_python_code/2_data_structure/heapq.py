
# April 24, 2023

# heapq (priority queue)

# heapify: converts a list to heap
# heappush/heappop: pushes and pops form the heap list.

#heappushpop(heap, ele):- This function combines the functioning of both push and pop operations in one statement, increasing efficiency. Heap order is maintained after this operation.

#heapreplace(heap, ele):- This function also inserts and pops elements in one statement, but it is different from the above function. In this, the element is first popped, then the element is pushed. i.e, the value larger than the pushed value can be returned. heapreplace() returns the smallest value originally in the heap regardless of the pushed element as opposed to heappushpop().

#nlargest(k, iterable, key = fun): This function is used to return the k largest elements from the iterable specified and satisfy the key if mentioned.
#nsmallest(k, iterable, key = fun): This function is used to return the k smallest elements from the iterable specified and satisfy the key if mentioned.




# importing "heapq" to implement heap queue
import heapq

# initializing list
li = [5, 7, 9, 1, 3]

print("before heapify: {}".format(li))

# using heapify to convert list into heap
heapq.heapify(li)

# printing created heap
print("The created heap is : ", end="")
print(list(li))

# using heappush() to push elements into heap
# pushes 4
heapq.heappush(li, 4)

# printing modified heap
print("The modified heap after push is : ", end="")
print(list(li))

# using heappop() to pop smallest element
print("The popped and smallest element is : ", end="")
print(heapq.heappop(li))

# using heappushpop() to push and pop items simultaneously
# pops 8
print("The popped item using heappushpop() is : ", end="")
print(heapq.heappushpop(li, 8))
print("The modified heap after push/pop is : ", end="")
print(list(li))

# using nlargest to print 3 largest numbers
# prints 10, 9 and 8
print("The 3 largest numbers in list are : ", end="")
print(heapq.nlargest(3, li))

# using nsmallest to print 3 smallest numbers
# prints 1, 3 and 4
print("The 3 smallest numbers in list are : ", end="")
print(heapq.nsmallest(3, li))
