#pragma once

#if (defined (__cplusplus))
	extern "C" {
#endif

#include <bool.h>
#include <unicorn/unicorn.h>
//#include "/root/Projects/unicorn/include/uc_priv.h"


//int const uc_cpu_reg_usr_get (struct uc_engine * const, unsigned int const * const/* regs*/, void * const * const/* vals*/, int const/* count*/);
//int const uc_cpu_reg_usr_set (struct uc_engine * const, unsigned int const * const/* regs*/, void * const * const/* vals*/, int const/* count*/);


UNICORN_EXPORT
uc_err const uc_cpu_reg_usr_get (uc_engine * const, int const/* reg*/, void * const/* val*/);

UNICORN_EXPORT
uc_err const uc_cpu_reg_usr_set (uc_engine * const, int const/* reg*/, void * const/* val*/);


#if (defined (__cplusplus))
	}
#endif
