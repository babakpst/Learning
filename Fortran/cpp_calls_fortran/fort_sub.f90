
! Babak Poursartip
! 03/21/2020


subroutine fortran_sub(ii,ff)
 integer ii
 real*4 ff

 write(6,100) ii, ff
 100 format('ii=',i2,' ff=',f6.3)

 return
 end subroutine fortran_sub
