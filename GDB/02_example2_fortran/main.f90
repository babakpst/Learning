

! Babak Poursartip
! 07/16/2020

! check the gdb with a fortran code.

subroutine sum_factors(n, sum_fac)

implicit none

integer, intent(in)  :: n
integer, intent(out) :: sum_fac

integer :: i
sum_fac = 0

  do i =1, n
    if (mod(n,i)==0) then
      sum_fac = sum_fac + i 
    end if
  end do

return
end subroutine sum_factors



program main

implicit none

integer :: n = 60
integer :: sum_fac


write(*,*)" code starts ..."

call sum_factors(n, sum_fac)

write(*,"(' sum of factor of ', I3, ' is: ', I3)") n, sum_fac

write(*,*)" end of the code."
stop
end program main
