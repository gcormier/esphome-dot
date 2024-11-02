## PLL Notes
8.8 pg 18
fMCK = 12Mhz

LRCK = 48Khz
BCLK = 32*fs = 1.536Mhz

MCKI frequency
will be 128fs, 256fs, 512fs or 1024fs from 9.3

Master clock CM bits
sample freq FS bits

Register 0x08 stock is 0x0D which is

CM = 00 = 256fs
FS = 1101 = 97kHz


try
MCKI = 9.6Mhz
fs = 48khz
PLD 000EH
PLM 005FH
FS 1010
CM 00

MCKI = 16MHz
fs = 48khz
PLD = 0018h
PLM = 005Fh
FS 1010b
CM 00b