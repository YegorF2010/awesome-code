#ifndef DEBUG_H
#define	DEBUG_H

#include <stdio.h>
#define	PDEBUG(level,fmt,...)

#ifdef DEBUG
#undef PDEBUG

#define PDEBUG(level,fmt,...)\
if (level<=DEBUG) printf("%s: %d: " fmt " \n", __FUNCTIONW__, __LINE__, ## __VA_ARGS__ )


#endif	// !DEBUG
#endif // !DEBUG_H
