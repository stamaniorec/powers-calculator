#ifndef BASEDEF_H_
#define BASEDEF_H_

#define true (!!1)
#define false (!true)

#ifndef NULL
#define NULL ((void *) 0L)
#endif

typedef void (*InterruptHandler_t)(void);

typedef unsigned char U8;
typedef unsigned short int U16;
typedef unsigned long U32;
typedef signed char S8;
typedef signed short int S16;
typedef signed long S32;
typedef U8 BOOL;
typedef float F16;
typedef double F32;
typedef long double F64;

typedef enum {
	S_OK,
	S_WAIT,
	S_INVALID_ARGUMENT,
	S_ARGUMENT_ERROR,
	S_INITIALIZED_OBJECT_EXPECTED,
	S_ARRAY_OUT_OF_BOUNDS,
	S_TIMEOUT,
	S_FUNCTION_FAILURE,
	S_DIVISION_BY_ZERO,
	S_STRUCTURE_FULL,
	S_STRUCTURE_EMPTY,
	S_STACK_OVERFLOW
} HRESULT;

#define __inline

#endif /*BASEDEF_H_*/
