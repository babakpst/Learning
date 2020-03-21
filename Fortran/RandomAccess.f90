
program binaryIO


implicit none

! variables ========================================================
integer(kind=4) :: UnFile   ! Holds Unit of a file for error message
integer(kind=4) :: IO_File  ! For IOSTAT: Input Output Status in OPEN command
integer(kind=4) :: IO_write ! Used for IOSTAT: Input/Output Status in the write command
integer(Kind=4) :: IO_read  ! Holds error of read statements


integer(kind=4) :: ii, jj   ! loop variables


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
      num(ii,jj) = ii + 0.01*jj
    enddo
  enddo

! fill binary file ===================================================
! open a file for binary write
write(*,"(a)")" Opening the file ..."
open(UnFile, file="scratch_binary.txt", &
     Err=1001, iostat=IO_File, &
     action='write', &
     status='replace', &
     asynchronous = 'no', blank = 'null', blocksize = 0, &
     dispose = 'keep', form = 'binary', position = 'asis' &
)

write(*,"(a)")" Writing in the binary file ..."
  do ii = 1, dim
    write (Unit = UnFile, ASYNCHRONOUS = 'NO', IOSTAT = IO_Write, ERR = 1006 )( num,( ii, jj ), jj = 1, dim ) ; 
  enddo

! closing the file
write(*,"(a)")" closing the binary file ..."
close(unit=UnFile, status="keep", err=1002, iostat=IO_File)

! file decimal file =============================================================
write(*,"(a)")" Opening the file ..."
open(UnFile, file="scratch.txt")
write(*,"(a)")" Writing in the file ..."
  do ii = 1, dim
    write (Unit = UnFile, FMT = "(<dim>(E31.23E3,2X) )", IOSTAT = IO_Write, ERR = 1006 )( num,( ii, jj ), jj = 1, dim ) ; 
  enddo

! closing the file
write(*,"(a)")" closing the file ..."
close(unit=UnFile, status="keep", err=1002, iostat=IO_File)

! read binary file for the sequential access ============================================
! opeining the binary file for sequential access
write(*,"(a)")" Opening the binary file for random access ..."
open(UnFile, file="scratch_binary.txt", &
     Err=1001, iostat=IO_File, &
     action='read', &
     status='old', &
     asynchronous = 'no', blank = 'null', blocksize = 0, &
     dispose = 'keep', form = 'binary', position = 'asis' &
)

! read from a binary file
write(*,"(a)")" Reading from the binary file ..."
!rewind(UnFile)
  do ii = 1, dim
      read (Unit = UnFile, ASYNCHRONOUS = 'no', IOSTAT = IO_Read, ERR = 1003, End = 1004 )( out(ii, jj), jj = 1, dim ) ;
      write(*,*)" out: ", out(ii,dim)
  enddo

! closing the binary file
!close(unit=UnFile, status="delete", err=1002, iostat=IO_File)
close(unit=UnFile, status="keep", err=1002, iostat=IO_File)

! ==================================================================================
! read binary file for the random access ============================================
! ==================================================================================
! opeining the binary file for sequential access
write(*,"(a)")" Opening the binary file for random access ..."
open(UnFile, file="scratch_binary.txt", &
     Err=1001, iostat=IO_File, &
     action='read', &
     status='old', &
     asynchronous = 'no', blank = 'null', blocksize = 0, &
     dispose = 'keep', form = 'binary', position = 'asis' &
)

! read from a binary file
write(*,"(a)")" Reading from the binary file ..."
!rewind(UnFile)
  do ii = 1, dim
      read (Unit = UnFile, ASYNCHRONOUS = 'no', IOSTAT = IO_Read, ERR = 1003, End = 1004 )( out(ii, jj), jj = 1, dim ) ;
      write(*,*)" out: ", out(ii,dim)
  enddo

! closing the binary file
!close(unit=UnFile, status="delete", err=1002, iostat=IO_File)
close(unit=UnFile, status="keep", err=1002, iostat=IO_File)

! ==================================================================================
! read binary file for the direct access ============================================
! ==================================================================================


!%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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