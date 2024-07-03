#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32 test");
  Serial.println("ESP32 Bluetooth Ready to Use");
}

void loop() {

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }

  if (SerialBT.available()) {
    //data stream
    String dataStream = generateDataStream();
    Serial.println(dataStream);
    SerialBT.println(dataStream);
    delay(2000);

    //data result
    String dataResult = generateDataResult();
    Serial.println(dataResult);
    SerialBT.println(dataResult);
    delay(2000);

    //error result
    String errorResult = generateErrorResult();
    Serial.println(errorResult);
    SerialBT.println(errorResult);
  }
  delay(2000);
}

String generateDataStream() {
  int day = 1;
  int month = 3;
  int year = 24;
  static int hour = 7;
  static int minute = 0;
  static int init = 0;
  static int adapt = 0;
  static int batt = 0;
  static float senssRaw =0;
  static float senss =0;
  static int pwmValue =0;
  static int deflectRate =0;
  static float heartRate =0;
  static int iRH =0;
  static int beats =0;

  minute++;
  if (minute > 59) {
    minute = 0;
    hour++;
    if (hour > 23) {
      hour = 0;
    }
  }

  init = random(0,2);
  adapt= random(0,2);
  batt = random(0,2);
  senssRaw = random(10, 1000) / 888.9;
  senss = random(0, 100);
  pwmValue = random(0, 256);
  deflectRate = 0;
  heartRate = random(0, 100);
  iRH = random(0,2);
  beats = random(0, 2);

  return "DAT," + String(hour) + ":" + String(minute) + " " + String(day) + "/" + String(month) + 
  "/" + String(year) + "," + String(init) + "," + String(adapt) + "," + String(batt) + "," + String(senssRaw) + 
  "," + String(senss) + "," + String(pwmValue) + "," + String(deflectRate) + "," + String(heartRate) + "," + 
  String(iRH) + "," + String(beats) +",TAD";
}

String generateDataResult() {
  static float sys = 0;
  static float dia = 0;
  static int map = 0;
  static float hr = 0;
  static int ihb = 0;
  static int tPump = 0;
  static int dPump = 0;
  static int sPump = 0;
  
  sys = random(0, 100);
  dia = random(0, 100);
  map = 0;
  hr = random(0, 100);
  ihb = random(0, 10);
  tPump = random(0, 10);
  dPump = random(0, 30);
  sPump = random(0, 30);

  return "vin,sys:" + String(sys) + ",dia:" + String(dia) + ",map:" + String(map) +
         ",hr:" + String(hr) + ",ihb:" + String(ihb) + ",t_pump:" + String(tPump) +
         ",d_pump:" + String(dPump) + ",s_pump:" + String(sPump) + ",niv";
}

String generateErrorResult() {
  static int errorCode = 0;
  
  errorCode = random(0, 8);

  return "vin,err " + String(errorCode) + ",niv";
}

