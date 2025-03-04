C='BABAB'
print(len(C), C)
ret = ''
for i in range (len(C)):
    print(C[i])
    ret+= 'A' if C[i] == 'B' else 'B'
print(ret)

