#ifndef I2C_H_
#define I2C_H_

#include "FreeRTOS.h"
#include "semphr.h"

typedef struct i2c_chip_mapping {
    uint8_t chip_id;
    uint8_t bus_id;
    uint8_t i2c_address;
} i2c_chip_mapping_t;

typedef struct i2c_bus_mapping {
    uint8_t bus_id;
    I2C_ID_T i2c_interface;
    int8_t mux_bus;
    uint8_t enabled;
} i2c_bus_mapping_t;

typedef struct i2c_mux_state {
    I2C_ID_T i2c_interface;
    int8_t state;
    SemaphoreHandle_t semaphore;
} i2c_mux_state_t;

void i2c_init( void );
Bool i2c_mux_bus( uint8_t bus_id, i2c_mux_state_t *i2c_mux, int8_t new_state );
Bool i2c_take_by_busid( uint8_t bus_id, uint8_t *i2c_interface, uint32_t timeout );
Bool i2c_take_by_chipid(uint8_t chip_id, uint8_t *i2c_address, uint8_t * i2c_interface,  TickType_t timeout);
void i2c_give(I2C_ID_T i2c_interface);

#endif
