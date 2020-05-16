//  bw_msposix.cpp
//  MS-compatible replacements for missing POSIX functions
//  by Bill Weinman <http://bw.org/>
//  Copyright (c) 2014 The BearHeart Group LLC
//

#include "bw_msposix.h"

int vasprintf(char ** ret, const char * format, va_list ap)
{
    int len;
    char *buffer;

    len = _vscprintf(format, ap) + 1;
    buffer = (char *) malloc(len * sizeof(char));
    if (!buffer) return 0;
    vsprintf_s(buffer, len, format, ap);
    *ret = buffer;
    return len -1;
}

int snprintf(char * str, size_t size, const char * format, ...)
{
    va_list args;
    size_t len;

    va_start(args, format);
    len = _vscprintf(format, args) + 1;
    if (len > size) len = size;
    vsprintf_s(str, len, format, args);
    return len - 1;
}

int setenv(const char *name, const char *value, int overwrite)
{
    int errcode = 0;
    if(!overwrite) {
        size_t envsize = 0;
        errcode = getenv_s(&envsize, NULL, 0, name);
        if(errcode || envsize) return errcode;
    }
    return _putenv_s(name, value);
}
