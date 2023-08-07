#pragma once

#include <sys/types.h>
#include <stdint.h>

#ifdef DEBUG
#define DBG_PRINTF(...) printf(__VA_ARGS__);
#else
#define DBG_PRINTF(...)
#endif