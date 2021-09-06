#pragma once

#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#if (GCC_VERSION != 90201)
#error "GCC must be version 9.2.1 => Install arm-none-eabi-gcc version 2019 Q4 major."
#endif