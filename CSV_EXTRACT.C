#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct {
    char customerId[10];
    float latitude;
    float longitude;
    char direction;
    float accelerometerX;
    float accelerometerY;
    int day;
    int month;
    int year;
    char time[10];
    char am_pm[3];
    char data_type;
} Data;

void parseData(char *buffer, Data *data) {
    sscanf(buffer, "#%9[^,],%f, %f, %c, %f, %f, %d,%d,%d,%9[^,],%2s,%c#", data->customerId,
        &data->latitude, &data->longitude, &data->direction, &data->accelerometerX,
        &data->accelerometerY, &data->day, &data->month, &data->year, data->time,
        data->am_pm, &data->data_type);
}

int main() {
    char buffer[BUFFER_SIZE] = "#123456UNI,123.456, 342.785, E, 12.5, 34.6, 01,01,983,01:23:34,AM,H#";
    Data data;
    parseData(buffer, &data);

    printf("Customer ID: %s\n", data.customerId);
    printf("Latitude: %f\n", data.latitude);
    printf("Longitude: %f\n", data.longitude);
    printf("Direction: %c\n", data.direction);
    printf("AccelerometerX: %f\n", data.accelerometerX);
    printf("AccelerometerY: %f\n", data.accelerometerY);
    printf("Day: %d\n", data.day);
    printf("Month: %d\n", data.month);
    printf("Year: %d\n", data.year);
    printf("Time: %s\n", data.time);
    printf("AM/PM: %s\n", data.am_pm);
    printf("Data Type: %c\n", data.data_type);

    return 0;
}
