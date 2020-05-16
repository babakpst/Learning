//  bw_msposix.h
//  MS-compatible replacements for missing POSIX functions
//  by Bill Weinman <http://bw.org/>
//  Copyright (c) 2014 The BearHeart Group LLC
//

#ifndef __BW_MSPOSIX__
#define __BW_MSPOSIX__

#define _BW_MSPOSIX_VERSION "1.0.2"

#include <cstdio>
#include <cstdlib>
#include <cstdarg>

int vasprintf(char ** ret, const char * format, va_list ap);
int snprintf(char * str, size_t size, const char * format, ...);
int setenv(const char *name, const char *value, int overwrite);

#endif // __BW_MSPOSIX__
