#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;  // crea el objeto BMP280

void setup() {
    Serial.begin(9600);
    if (!bmp.begin(0x76)) {  // intenta inicializar en la dirección 0x76
        Serial.println("No se pudo encontrar el BMP280 en 0x76");
        if (!bmp.begin(0x77)) {  // intenta inicializar en la dirección 0x77
            Serial.println("No se pudo encontrar el BMP280 en 0x77");
            while (1);  // detiene el programa si no se encuentra el sensor
        }
    }
}

void loop() {
    Serial.print("\nTemperatura: ");
    Serial.print(bmp.readTemperature());
    Serial.print(" C\tPresion: ");
    Serial.print(bmp.readPressure() / 100.0F);
    Serial.println(" hPa");

    //código sensor de humedad HL-69
  #define VALORMAXHUM 261
  #define VALORMINHUM 661
  //int valorMaxHum = 300;
  //int valorMinHum = 100;
  int lectura = analogRead(A0);
  Serial.println("Valor leído:");
  Serial.print(lectura);
  delay(1000);
  int lecturaPorcentaje = map(lectura, VALORMAXHUM, 0, 0, VALORMINHUM);
  Serial.print("\nLa humedad es del: ");
  Serial.print(lecturaPorcentaje);
  Serial.print("%");
  delay(2000); 
}
