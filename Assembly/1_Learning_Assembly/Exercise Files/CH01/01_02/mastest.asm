include \masm32\include\masm32rt.inc
.data
 hello  db "Hello World!", 0
.code
start:
 invoke StdOut, addr hello
 invoke ExitProcess, 0
end start 