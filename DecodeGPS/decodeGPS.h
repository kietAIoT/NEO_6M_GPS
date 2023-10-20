
/** @author in stmm32: NguyenTuanKiet
    * @author in arduino:
    * @copyright Copyright
    * @author in
    * @version 1.0.0
    * @brief: This library for learning
    * @note if you want to use */

//#define DECODE_GPS
//#ifndef DECODE_GPS

#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "math.h"
// #include "stm32f1xx_hal.h"

#ifdef __cplusplus
    extern "C" {
#endif

typedef enum {
    DECODE_OK = 1,
    DECODE_ERROR = 0
} TypeStatusDecode_t;

typedef struct GPS_NEO_NMEA {
    uint8_t localHour;
    uint8_t localMinute;
    uint8_t localSecond;
    
    uint8_t GTMHour;
    uint8_t GTMMinute;
    uint8_t GTMSecond;

    void (*CalculateTime)(void);
    TypeStatusDecode_t (*Decode)(char *, uint8_t);
    
    char GPGGA[100];
    char TypeGP_str[7];
    char GTM_str[10];
    char Longitude_str[12];
    char Latitude_str[12];
    char CheckN_str[1];
    char CheckE_str[1];

} GPS_NEO_NMEA_t;

extern GPS_NEO_NMEA_t GPS;

void GPS_NEO_NMEA_Init();
void GPS_NEO_NMEA_GotoUpdate(char *a, uint8_t size, uint8_t flag);
TypeStatusDecode_t GPS_NEO_NMEA_Decode(char *a,  uint8_t size);
void GPS_NEO_NMEA_CalculateTime();



#ifdef __cplusplus
    }
#endif


//#endif
