read -p "Please put ESP32 into flash mode manually and press Enter to continue..."
esptool.py --chip esp32s3 --port /dev/ttyACM0 erase_flash

read -p "Please reset ESP32 and press Enter to continue..."
esptool.py --chip esp32s3 --port /dev/ttyACM0 write_flash -fm dio -z 0 ESP32_GENERIC_S3-20241025-v1.24.0.bin


read -p "Please reset ESP32 and press Enter to continue..."
mpremote cp main.py :main.py

echo "You must power cycle one last time to run the new firmware."