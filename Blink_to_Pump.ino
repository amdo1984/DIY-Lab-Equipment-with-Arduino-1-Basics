
int sensor = 0;

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
String message = "";

void setup() {

  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  
}


void loop() {
  // sensor = digitalRead(12);
  // if (sensor == 1) {
    
  //   digitalWrite(13, HIGH);
  //   SerialBT.println("Pump is ON");
  // } else {
    
  //   digitalWrite(13, LOW);
  //   SerialBT.println("Pump is OFF");
  // }
  if (SerialBT.available())
  {
    message = SerialBT.readString();
    if (message == "ON")
    {
      digitalWrite(13, HIGH);
    }

    if (message == "OFF")
    {
      digitalWrite(13, LOW);
    }
    
  }

  delay(200);
  
}
