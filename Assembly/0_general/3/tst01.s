.data 
wcount  dq 0
hello   db 'Hello 64 World (from GoAsm)'

.code 
start:
arg    -11              
invoke GetStdHandle  
arg    0,addr wcount, 27
arg    addr hello,rax
invoke WriteFile
xor    rax,rax 
ret
