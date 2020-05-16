//  README file for bw_msposix library
//  MS C++ compatible replacements for missing POSIX functions
//  by Bill Weinman <http://bw.org/>
//  Copyright (c) 2014 The BearHeart Group LLC
//

HISTORY:

2014-05-12 BW - first public release with lynda.com Code Clinc series. 

DESCRIPTION:

These files provide standard POSIX C/C++ functions for Microsoft Visual C++. MSVC is missing a few standard functions. This provides those functions so that standard-compliant code will compile and run on MSVC. 

This code provides the following functions: 

int vasprintf(char ** ret, const char * format, va_list ap);
int snprintf(char * str, size_t size, const char * format, ...);
int setenv(const char *name, const char *value, int overwrite);

USAGE: 

Simply drop these files into your project in Visual Studio. The files must be in the same directory as your other code. Include the header file like this: 

#include "bw_msposix.h"

