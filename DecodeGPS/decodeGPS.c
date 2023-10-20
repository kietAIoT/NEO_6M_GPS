#include "decodeGPS.h"


char GPGGA[100] = "$GPGGA,010244.00,1052.92019,N,10648.54956,E,1,05,3.24,33.9,M,-2.3,M,,*7F";


void GPS_NEO_NMEA_Init() {
    GPS.CalculateTime = GPS_NEO_NMEA_CalculateTime;
    GPS.Decode = GPS_NEO_NMEA_Decode;
    GPS.localHour = 0;
    GPS.localMinute = 0;
    GPS.localSecond = 0;

    GPS.GTMHour = 0;
    GPS.GTMMinute = 0;
    GPS.GTMSecond = 0;
}

TypeStatusDecode_t GPS_NEO_NMEA_Decode(char *GPGGA_, uint8_t size) {
    strcpy(GPS.GPGGA, GPGGA_);
    uint8_t _position = 0;
    char temp[15];
    uint8_t flag = 0;
    uint8_t temp_size = 0;
    while (_position<size) {
        if (GPS.GPGGA[_position] == ',') {
            temp[temp_size] = '\0';
            GPS_NEO_NMEA_GotoUpdate(temp, temp_size+1, flag);
            temp_size = 0;
            flag++;
        } else {
            temp[temp_size] = GPS.GPGGA[_position];
            temp_size++;
        }
        _position++;
    }
    if (strlen(GPS.Latitude_str)==0 | strlen(GPS.Longitude_str)==0 | strlen(GPS.Latitude_str)==0 | GPS.CheckE_str!='E' | GPS.CheckN_str!='N') {
        printf("Error! Can't decode, you should check data input\n");
        return DECODE_ERROR;
    } else 
    return DECODE_OK;
}

void GPS_NEO_NMEA_GotoUpdate(char *a, uint8_t size, uint8_t flag) {
    switch (flag) {
        case 0:
            strncpy(GPS.TypeGP_str, a, size);
            break;
        case 1:
            strncpy(GPS.GTM_str, a, size);
            break;
        case 2:
            strncpy(GPS.Longitude_str, a, size);
            break;
        case 3:
        	strncpy(GPS.CheckN_str, a, size);
        	break;
        case 4:
            strncpy(GPS.Latitude_str, a, size);
            break;
        case 5:
        	strncpy(GPS.CheckE_str, a, size);
        	break;
        default:
            break;
    }
}

void GPS_NEO_NMEA_CalculateTime() {
    char *Latitude_img = (char *)malloc(sizeof(GPS.Latitude_str));
    strncpy(Latitude_img, GPS.Latitude_str, sizeof(GPS.Latitude_str));
    char *token;
    token = strtok(Latitude_img,".");
    int latitude_int = atoi(token);
    uint8_t Muigio = round(latitude_int/1500);
    GPS.GTMHour   = (GPS.GTM_str[0]-0x30)*10 + (GPS.GTM_str[1]-0x30);
    GPS.GTMMinute = (GPS.GTM_str[2]-0x30)*10 + (GPS.GTM_str[3]-0x30);
    GPS.GTMSecond = (GPS.GTM_str[4]-0x30)*10 + (GPS.GTM_str[5]-0x30);
    printf("%d,%d,%d", GPS.GTMHour, GPS.GTMMinute, GPS.GTMSecond);
}


// int main() {
//     uint8_t Data[100] = "GPS,010244.00,1052.92019,N,10648.54956,E,1,05,3.24,33.9,M,-2.3,M,,*7F";
//     GPS_NEO_NMEA_Init();
//     printf("HELLO");
//     if (GPS.Decode(Data, sizeof(Data))) {
//         printf("DECODE_OKE");
//     } else printf("DECODE_ERROR");
//     printf("%d",strlen(GPS.TypeGP_str));
//     printf("Type: %s\n", GPS.TypeGP_str);
//     printf("Time %s\n", GPS.GTM_str);
//     printf("Longitude: %s\n", GPS.Longitude_str);
//     printf("Latitide: %s\n", GPS.Latitude_str);


//     return 0;
// }
