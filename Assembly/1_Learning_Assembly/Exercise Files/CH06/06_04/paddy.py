#!/usr/bin/env python

import os, sys, subprocess, tempfile
from ctypes import *

PAGE_SIZE = 4096

class AssemblerFunction(object):

  def __init__(self, code, ret_type, *arg_types):
    #---------------------------------------
    # Write the asm source to a temporary file
    fd, source = tempfile.mkstemp(".S", "assembly", os.getcwd())
    os.write(fd, str.encode(code))
    os.close(fd)
    #---------------------------------------
    # Call nasm to assemble it
    target = os.path.splitext(source)[0]
    subprocess.check_call(["nasm",source])
    os.unlink(source)
    #---------------------------------------
    # Read in the nasm assembled code
    binary = open(target,"rb").read()
    os.unlink(target)
    bin_len = len(binary)
    #---------------------------------------
    # align our code on page boundary.
    self.code_buffer = create_string_buffer(PAGE_SIZE*2+bin_len)
    addr = (addressof(self.code_buffer) + PAGE_SIZE) & (~(PAGE_SIZE-1))
    memmove(addr, binary, bin_len)
    #---------------------------------------
    # Change memory protection
    self.mprotect = cdll.LoadLibrary("libc.so.6").mprotect
    mp_ret = self.mprotect(addr, bin_len, 4)   # execute only.
    if mp_ret: raise OSError("Unable to change memory protection")
    #---------------------------------------
    # We then save the codeaddress and length
    self.func = CFUNCTYPE(ret_type, *arg_types)(addr)
    self.addr = addr
    self.bin_len = bin_len

  def __call__(self, *args):
    return self.func(*args)

  def __del__(self):
    # Revert memory protection
    if hasattr(self,"mprotect"):
      self.mprotect(self.addr, self.bin_len, 3)

if __name__ == "__main__":
  add_func = """ BITS 64
                    mov rax, rdi    ; Move the first parameter
                    add rax, rsi    ; add the second parameter
                    ret             ; rax will be returned
                    """
  Add = AssemblerFunction(add_func, c_int, c_int, c_int)
  print("17 plus 45 is ", Add(17,45))
  print(sys.argv[1]+" plus "+sys.argv[2]+" is "+str(Add(int(sys.argv[1]),int(sys.argv[2]))))
  