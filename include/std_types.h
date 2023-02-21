#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

#define ZERO_INiT 0
#define ZERO 0

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

typedef enum RET_STATUS
{
    R_NOK,
    R_OK,
} ret_status_t;

#endif