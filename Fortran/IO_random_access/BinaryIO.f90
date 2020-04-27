! Babak Poursartip

program binaryIO


implicit none

! variables ========================================================
integer(kind=4) :: UnFile   ! Holds Unit of a file for error message
integer(kind=4) :: IO_File  ! For IOSTAT: Input Output Status in OPEN command
integer(kind=4) :: IO_write ! Used for IOSTAT: Input/Output Status in the write command
integer(Kind=4) :: IO_read  ! Holds error of read statements


integer(kind=4) :: ii, jj   ! loop variables
integer(kind=4) :: recLength   ! record length for the direct access
integer(kind=4) :: record      ! record number


integer(kind=4), parameter :: dim = 50

real(kind=8) :: number
real(kind=8) :: num(dim, dim)
real(kind=8) :: out(dim, dim)


! code ==============================================================
! filling the array =================================================
write(*,"(a)")" code starts ..."

! generate an array to create a file
write(*,"(a, i5)")" Size of the array: ", dim
  do ii = 1, dim
    do jj = 1, dim
      num(ii,jj) = ii + 0.1*jj
    enddo
  enddo

recLength = 2 ! Specify the record length in 4-byte units, thus for real 8 we have 2


! file decimal file =============================================================
write(*,"(a)")" Opening the file ..."
open(UnFile, file="scratch.txt")

write(*,"(a)")" Writing in the file ..."
  do ii = 1, dim
    do jj = 1, dim
      record = (ii-1)*dim+jj
      write (Unit = UnFile, FMT = "(3i8, F15.5)", IOSTAT = IO_Write, ERR = 1006 ) record, ii, jj, num(ii, jj)
    enddo
  enddo

! closing the file
write(*,"(a)")" closing the file ..."
close(unit=UnFile, status="keep", err=1002, iostat=IO_File)


! fill binary file ===================================================
! open a binary file for direct access
write(*,"(a)")" Opening the file for direct/random access ..."
open(UnFile, file="scratch.bin", &
     iostat=IO_File, &
     action='write', &
     status='replace', &
     dispose = 'keep', form = 'Unformatted', access = 'direct', recl = recLength &
)

write(*,"(a)")" Writing in the binary file ..."
  do ii = 1, dim
    do jj = 1, dim
      record = (ii-1)*dim+jj
      write (Unit = UnFile, rec=record, IOSTAT = IO_Write) num(ii, jj) 
   enddo
 enddo

! closing the file
write(*,"(a)")" closing the binary file ..."
close(unit=UnFile, status="keep", iostat=IO_File)

! read binary file for the sequential access ============================================
! opeining the binary file for sequential access

write(*,"(a)")" Opening the binary file for random access ..."
open(UnFile, file="scratch.bin", &
     iostat=IO_File, &
     action='read', &
     status='old', &
     dispose = 'keep', form = 'unformatted', access='direct', recl=recLength &
)

! read from a binary file with direct access
write(*,"(a)")" Reading from the binary file with direct access ..."
  do jj = 1, dim
    do ii = 1, dim
      record = (ii-1)*dim+jj
      read(Unit = UnFile, rec=record, IOSTAT = IO_Read, ERR = 1003) number
      write(*,*)" out: ",record, ii, jj, number
    enddo
  enddo

record = 12
read(Unit = UnFile, rec=record, IOSTAT = IO_Read, ERR = 1003) number
write(*,*)" out: ",record, number

record = 13
read(Unit = UnFile, rec=record, IOSTAT = IO_Read, ERR = 1003) number
write(*,*)" out: ",record, number


record = 1000
read(Unit = UnFile, rec=record, IOSTAT = IO_Read, ERR = 1003) number
write(*,*)" out: ",record, number

record = 1321
read(Unit = UnFile, rec=record, IOSTAT = IO_Read, ERR = 1003) number
write(*,*)" out: ",record, number

record = 1
read(Unit = UnFile, rec=record, IOSTAT = IO_Read, ERR = 1003) number
write(*,*)" out: ",record, number

record = 2
read(Unit = UnFile, rec=record, IOSTAT = IO_Read, ERR = 1003) number
write(*,*)" out: ",record, number


! closing the binary file
!close(unit=UnFile, status="delete", err=1002, iostat=IO_File)
close(unit=UnFile, status="keep", err=1002, iostat=IO_File)


! %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
write(*,"(a)")" Program terminated successfully!"
stop



! Errors ==========================================================================================
! Opening statement Errors
1001 if (IO_File > 0) then
       write(*, *) UnFile, IO_File
       read(*,*); stop;
     else if ( IO_File < 0 ) then
       write(*, *) UnFile, IO_File
       read(*,*); stop;
     end if

! Close statement Errors
1002 if (IO_File > 0) then
       write(*, *) UnFile, IO_File
       read(*,*); stop;
     end if

! - Error in read statement -----------------------------------------------------------------------
1003 write(*, *) UnFile, IO_read
     read(*,*);  stop;

! - End-OF-FILE in read statement -----------------------------------------------------------------
1004 write(*, *) UnFile, IO_read
     read(*,*);  stop;

! write statement errors
1006 write(*, *) UnFile, IO_write
     read(*,*);  stop;

end program binaryIO
