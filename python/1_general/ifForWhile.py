
# Babak Poursartip

# while
a,b = 0, 1
while b < 10:
    print(b)
    a,b = b, a+b

# if condition

# python2
#y = raw_input("Pleae enter an integer: ")

# python3
y = input("Pleae enter an integer: ")

print("Th input data is: ", y)
x = int(y)

if x < 0:
    x = 0
    print("negative changed to zero")

elif x==0:
    print("Zero")
elif x==1:
    print("Single")
else:
    print("More")


# item in the list
tmpl = ['Babak', 'Shiva', 'Hedyeh', 'Shokouh', 'Mehran']

if 'Shiva' in tmpl:
    print("yes, shiva is in the list.")
else:
    tmpl.append('Shiva')
    print("Shiva added to the list")

if 'Bahram' in tmpl:
    print("Bahram is in the list.")
else:
    tmpl.append('Bahram')
    print("Bahram added to the list.")


# for loops
words = ['cat', 'window', 'defenestrate']
for w in words:
    print( w, len(w))


for i in range(10):
    print(i)

for i in range(5, 10):
    print(i)

for i in range(0, 10, 3):
    print(i)


for i in range(5, 10):
    print(i)

for i in range(-10, -100, -30):
    print(i)


a = ['Mary', 'had', 'a', 'little', 'lamb']
for i in range(len(a)):
     print(i, a[i])

for n in range(2, 10):
     for x in range(2, n):
         if n % x == 0:
             print( n, 'equals', x, '*', n/x)
             break
     else:
         # loop fell through without finding a factor
         print (n, 'is a prime number')

