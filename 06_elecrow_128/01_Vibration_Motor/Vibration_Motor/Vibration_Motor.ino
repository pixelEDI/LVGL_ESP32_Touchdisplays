#include <Wire.h>

#define PI4IO_I2C_ADDR 0x43  // I2C address for the I/O extender

// Function to initialize the I/O extender
void init_IO_extender() {
  Wire.beginTransmission(PI4IO_I2C_ADDR);  // Start I2C transmission to the extender
  Wire.write(0x01);  // Select the test register
  Wire.endTransmission();  // End the transmission
  Wire.requestFrom(PI4IO_I2C_ADDR, 1);  // Request 1 byte from the extender
  uint8_t rxdata = Wire.read();  // Read the received data
  Serial.print("Device ID: ");
  Serial.println(rxdata, HEX);  // Print the device ID in hexadecimal

  Wire.beginTransmission(PI4IO_I2C_ADDR);  // Start I2C transmission again
  Wire.write(0x03);  // Select the I/O direction register
  Wire.write((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4));  // Set pins 0-4 as outputs
  Wire.endTransmission();  // End the transmission

  Wire.beginTransmission(PI4IO_I2C_ADDR);  // Start I2C transmission
  Wire.write(0x07);  // Select the Output Hi-Z register
  Wire.write(~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)));  // Set pins 0-4 low
  Wire.endTransmission();  // End the transmission
}

// Function to set the state of a specific pin on the I/O extender
void set_pin_io(uint8_t pin_number, bool value) {
  Wire.beginTransmission(PI4IO_I2C_ADDR);  // Start I2C transmission
  Wire.write(0x05);  // Select the test register
  Wire.endTransmission();  // End the transmission
  Wire.requestFrom(PI4IO_I2C_ADDR, 1);  // Request 1 byte from the extender
  uint8_t rxdata = Wire.read();  // Read the received data
  Serial.print("Before the change: ");
  Serial.println(rxdata, HEX);  // Print the data before change

  Wire.beginTransmission(PI4IO_I2C_ADDR);  // Start I2C transmission
  Wire.write(0x05);  // Select the Output register

  if (!value) {
    Wire.write((~(1 << pin_number)) & rxdata);  // Set the pin low
  } else {
    Wire.write((1 << pin_number) | rxdata);  // Set the pin high
  }
  Wire.endTransmission();  // End the transmission

  // Read the output state to verify the change
  Wire.beginTransmission(PI4IO_I2C_ADDR);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.requestFrom(PI4IO_I2C_ADDR, 1);
  rxdata = Wire.read();
  Serial.print("after the change: ");
  Serial.println(rxdata, HEX);  // Print the data after change
}

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate
  Wire.begin(4, 5);  // Initialize I2C bus with SDA and SCL pins
  init_IO_extender();  // Initialize the I/O extender
  delay(100);  // Short delay
}

void loop() {
  // Main code to run repeatedly
  set_pin_io(0, true);  // Set pin 0 to high
  delay(1000);  // Wait for 1000 milliseconds
  set_pin_io(0, false);  // Set pin 0 to low
  delay(1000);  // Wait for another 1000 milliseconds
}
