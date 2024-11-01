# i2c

## What we want
1. Set DMIC1 DMIC2 to 1
1. Set MONON to 1 and PMDM1B to 1, PMDM1A to 0
2. 0x0e - Set audio format to is2, mono, 16-bit


## Our Sequence
1. Set 0x00 to 00100000 (Set MSN to 1)
1. Set 0x01 to 0x80 (VCOM powerup via PMVCM)

1. Set 0x04 to 0xF4 (MONON set, rest stock)
1. Set 0x05 to 0x11 (MIC gain, stock)
1. Don't touch 0x07 based on stock
1. Set 0x08 to 00 00 1010
1. Do something with PLL's on 0x0A B C D!
1. Set 0x0E to 0x10 (i2s, 16-bit, stereo)
1. Set 0x00 to 0x27
1. Set 0x13 to 0x70 (highpass filter, stock)
1. Set 0x26 to 0x00 (ALC1, stock)
1. Set 0x2B to 0x96 (volume, stock)
1. Set 0x41 to 0xDF (stock)
1. Set 0x42 to 0x8E (stock)

1. Set 0x01 to 0x8F (Bring up all MIC POWER)
1. Set 0x02 to 0x02 (Power only 1B analog mic)
1. Set 0x03 to 0x0F (Match stock init, filters on)
1. Set 0x01 to 0xCF (Bring up PLL)

## Power-on sequence
Here's what happens when the power is turned on for the AK5407
```
(register) (data)
0x26 0x00 # ALC1 
0x13 0x70 # ADC high pass
0x41 0xDF 
0x42 0x8E 
0x01 0x80 #power management
0x04 0xF0 #mic input

0x00 0x20 # flow control (MSN = 1)
0x0E 0x45 # AUDIO FORMAT pg85 = 0100 0101
            = 24-bit data length
            = page 38, Mode 13
            = MSB justified :()

0x00 0x21 # flow control
0x00 0x23 # flow control
 # flow control
0x0E 0x65 # AUDIO FORMAT AGAIN
            Changing data length to be 32-bit length
0x05 0x61 # mic1 amp gain
0x05 0x11 # more amp gain
0x06 0x61 # more amp gain
0x06 0x11 # mic2 amp gain
0x27 0x96 #volume
0x28 0x96 #volume 
0x2B 0x96 #vol
0x2C 0x96 #vol

0x08 0x0D # CLOCK MODE 
            = 25fs
            = 96kHz
0x0B 0x27 # pll
           
0x0D 0x63 # pll
0x01 0x8F # power mgmt
0x02 0x0F # power mgmt 2
0x03 0x0F # power mgmt 3
0x01 0xCF # power mgmt
```
