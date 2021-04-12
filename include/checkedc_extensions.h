//--------------------------------------------------------------------------//
// Additional bounds-safe interface options for functions that have         //
// different interfaces for array_ptr and nt_array_ptr args. Programmer can //
// choose to use these over the default bounds-safe interfaces.             //
//////////////////////////////////////////////////////////////////////////////

#include <stdlib_checked.h>
#include <string_checked.h>

#ifdef __checkedc

#ifndef __CHECKED_C_EXTENSIONS_H
#define __CHECKED_C_EXTENSIONS_H

#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE on

// default strncmp has a bounds-safe interface nt_array_ptr;
// this option is for array_ptr
extern inline int strncmp_array_ptr(const char *src : count(n), const char *s2 : count(n), size_t n) {
  _Unchecked { return strncmp(src, s2, n); }
}

// default snprintf assumes nt_array_ptr for bounds-safe interface
// this option is for array_ptr
_Unchecked
int snprintf_array_ptr(char * restrict s : itype(restrict _Array_ptr<char>) count(n),
                       size_t n, 
                       const char * restrict format : itype(restrict _Nt_array_ptr<const char>),
                       ...);

#pragma CHECKED_SCOPE pop

#endif // guard 
#endif // Checked C 
