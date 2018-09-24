#pragma once

#if (defined (__cplusplus))
	extern "C" {
#endif


#include <bool.h>
#include <unicorn/unicorn.h>
//#include "/root/Projects/unicorn/qemu/include/exec/hwaddr.h"
//#include "/root/Projects/unicorn/qemu/include/exec/memory.h"


//// return true on success, false on failure
//bool const uc_store_usr_get (AddressSpace * const, hwaddr const/* addr*/, uint8_t * const/* buffer*/, int const/* size*/);
//bool const uc_store_usr_set (AddressSpace * const, hwaddr const/* addr*/, uint8_t const * const/* buffer*/, int const/* size*/);


UNICORN_EXPORT
uc_err const uc_store_usr_get (uc_engine * const, uint64_t const/* addr*/, void * const/* bytes*/, size_t const/* size*/);

UNICORN_EXPORT
uc_err const uc_store_usr_set (uc_engine * const, uint64_t const/* addr*/, void * const/* bytes*/, size_t const/* size*/);


#if (defined (__cplusplus))
	}
#endif
