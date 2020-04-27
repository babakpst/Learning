! Babak Poursartip
! Date: 03/21/2020 Happy Norouz


subroutine test_for(i,x,y,ny)

implicit none

integer :: i, ny
double precision :: x
double precision :: y(ny)

print *, "This is in the Fortran subroutine ..."
print *, "i = ", i, ", x = ", x
print *, "y = ", y(1:ny)

end subroutine test_for

