
# These symbols are the same in c language

# Symbol	Operator
# &	bitwise AND
# |	bitwise inclusive OR
# ^	bitwise XOR (exclusive OR)
# <<	left shift
# >>	right shift
# ~	bitwise NOT (one's complement) (unary)

a = 60            # 60 = 0011 1100
b = 13            # 13 = 0000 1101
c = 0


# 	bitwise AND
c = a & b;        # 12 = 0000 1100
print("Line 1 - Value of c is ", c)

# bitwise OR
c = a | b;        # 61 = 0011 1101
print("Line 2 - Value of c is ", c)

# ^	bitwise XOR (exclusive OR)
c = a ^ b;        # 49 = 0011 0001
print("Line 3 - Value of c is ", c)

# ~	bitwise NOT (one's complement) (unary)
c = ~a;           # -61 = 1100 0011
print("Line 4 - Value of c is ", c)

# <<	left shift
c = a << 2;       # 240 = 1111 0000
print("Line 5 - Value of c is ", c)

# >>	right shift
c = a >> 2;       # 15 = 0000 1111
print("Line 6 - Value of c is ", c)


