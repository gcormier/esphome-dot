#include "esphome.h"

#define AK5704_ADDR 0x10

class AK5704 : public Component {
 public:
  void setup() override {
    Wire.begin();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x00);
    Wire.write(0x20);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x01);
    Wire.write(0x80);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x04);
    Wire.write(0xF4);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x05);
    Wire.write(0x11);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x08);
    Wire.write(0x0A);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x0E);
    Wire.write(0x10);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x00);
    Wire.write(0x27);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x13);
    Wire.write(0x70);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x26);
    Wire.write(0x00);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x2B);
    Wire.write(0x96);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x41);
    Wire.write(0xDF);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x42);
    Wire.write(0x8E);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x01);
    Wire.write(0x8F);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x03);
    Wire.write(0x0F);
    Wire.endTransmission();

    Wire.beginTransmission(AK5704_ADDR);
    Wire.write(0x01);
    Wire.write(0xCF);
    Wire.endTransmission();

    delay(500);


  }

};