# Nano-Eye
Get the raw data from OV7670 camera module using atmega328 (nano). 

### Specifications

| Component | Description | 
| --- | --- |
| Arduino Nano | Atmega328p with old bootloader is used |
| OV7670 |  [Camera module](https://www.voti.nl/docs/OV7670.pdf) |

### Pinout

OV7670 connections:
```
VSYNC - PIN2
XCLCK - PIN3
PCLCK - PIN12
SIOD - A4 (I2C data) - 10K resistor to 3.3V
SIOC - A5 (I2C clock) - 10K resistor to 3.3V
D0..D3 - A0..A3 (pixel data bits 0..3)
D4..D7 - PIN4..PIN7 (pixel data bits 4..7)
3.3V - 3.3V
RESET - 3.3V
GND - GND
PWDN - GND
```

For More Information refer to this documentation [indrekluuk](https://github.com/indrekluuk/LiveOV7670)
