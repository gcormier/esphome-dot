#include "esphome.h"
#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"

#define AK5704_ADDR 0x10
#define GPIO_ADDR 0x08

class AK5704 : public Component, public i2c::I2CDevice {
    protected:
    I2CBus *myBus;

 public:
    AK5704(I2CBus *parent) : I2CDevice() {
        myBus = parent;
    }
  void setup() override {

    set_i2c_bus(myBus);
    // Set PDN (powerdown) to false via the i2c gpio expander
    set_i2c_address(GPIO_ADDR);
    write_byte(0xF4, 0x00);

    delay(30);

    set_i2c_address(AK5704_ADDR);

    write_byte(0x00, 0x20);
    write_byte(0x01, 0x80);
    write_byte(0x04, 0xF4);
    write_byte(0x05, 0x11);

    // FS and CM
    write_byte(0x08, 0x0A);

    // PLD
    write_byte(0x0B, 0x18);

    // PLM
    write_byte(0x0D, 0x5F);
    
    write_byte(0x0E, 0x10);
    
    write_byte(0x00, 0x27);
    write_byte(0x13, 0x70);

    write_byte(0x26, 0x00);
    write_byte(0x2B, 0x96);

    write_byte(0x41, 0xDF);

    write_byte(0x42, 0x8E);
    write_byte(0x01, 0x8F);
    write_byte(0x02, 0x02);
    write_byte(0x03, 0x0F);

    write_byte(0x01, 0xCF);
    
    delay(50);

    ESP_LOGD("ak5470", "AK init complete");

  }

};