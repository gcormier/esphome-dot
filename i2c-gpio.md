# i2c gpio
i2c device is 0x08

cmos buffer gate is bottom left bin for OE

Device at 0x08
    - Registers written to: 0xF4, 0xF5, 0xF1, 0xF0
    - Registers read from: 0xF4, 0xF5, 0xF1, 0xF0


# Register 0xF1
Something to do with mute LED
0x62 when light off
0x40 when light on
bits 7 and 2 flip
One probably drives LED's, the other probably drives the output enable pin on the cmos buffer

# Register 0xF4
BITS
MSB 12345678 LSB

Bit 7 is the MUTE LED
Bit 5 is the PDN pin
W,F4,00 - this seems to bring ADC online!
W,0xf4, 04 - turns it off


# Register 0xF5
R,0xF5,1
bit 1 and 2 are related to mute
one probably controls the LED's
bit 3, far button
bit 4, is FPC button
bit 7, something has changed


RESET INPUT REGISTERS - 
Write 0D to F4, then 0C to F4
toggles LSB once which resets the registers
w,0xf4,0d
w,0xf4,0c
