Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@babakpst 
harrism
/
mini-nbody
2
72
26
Code
Issues
2
Pull requests
Actions
Projects
Wiki
Security
Insights
mini-nbody/timer.h
@harrism
harrism Added missing timer.h
Latest commit 38fda67 on Feb 20, 2014
 History
 1 contributor
54 lines (46 sloc)  988 Bytes
 
#ifndef TIMER_H
#define TIMER_H

#include <stdlib.h>

#ifdef WIN32
  #define WIN32_LEAN_AND_MEAN
  #include <windows.h>
#else
  #ifndef __USE_BSD
    #define __USE_BSD
  #endif
  #include <sys/time.h>
#endif

#ifdef WIN32
double PCFreq = 0.0;
__int64 timerStart = 0;
#else
struct timeval timerStart;
#endif

void StartTimer()
{
#ifdef WIN32
  LARGE_INTEGER li;
  if(!QueryPerformanceFrequency(&li))
    printf("QueryPerformanceFrequency failed!\n");

  PCFreq = (double)li.QuadPart/1000.0;

  QueryPerformanceCounter(&li);
  timerStart = li.QuadPart;
#else
  gettimeofday(&timerStart, NULL);
#endif
}

// time elapsed in ms
double GetTimer()
{
#ifdef WIN32
  LARGE_INTEGER li;
  QueryPerformanceCounter(&li);
  return (double)(li.QuadPart-timerStart)/PCFreq;
#else
  struct timeval timerStop, timerElapsed;
  gettimeofday(&timerStop, NULL);
  timersub(&timerStop, &timerStart, &timerElapsed);
    return timerElapsed.tv_sec*1000.0+timerElapsed.tv_usec/1000.0;
#endif
}

#endif // TIMER_H
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
Loading complete{"mode":"full","isActive":false}
