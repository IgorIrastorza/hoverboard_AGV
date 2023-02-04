#include <Arduino_LSM9DS1.h> 
#include <Arduino_LPS22HB.h> 

void setup(){
  Serial.begin(9600); //Serial Monitor para desplegar los valores medidos
  while (!Serial) {
    ; //Espera hasta que el monitor conecte
  }
  // Inicializar IMU
  if (!IMU.begin()) { 
   Serial.println("Fallo al inicializar IMU!");
   while (1);
  }
  
  //Inicializar el sensor de presión
  if (!BARO.begin()) { 
   Serial.println("Fallo al iniciar el sensor de presión!");
   while (1);
  }

 }

float accel_x, accel_y, accel_z;
float gyro_x, gyro_y, gyro_z;
float mag_x, mag_y, mag_z;
float Pressure;
int Proximity;

void loop() {
  // Valores captados por el acelerometro
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(accel_x, accel_y, accel_z);
  }

  // Valores captados por el giroscopio
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(gyro_x, gyro_y, gyro_z);
  }

  // Valores captados por el magnetometro
  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(mag_x, mag_y, mag_z);
    
  }

  // Valores captados por el sensor de presión
  Pressure = BARO.readPressure();

  // Impresión de valores en monitor
  Serial.print(accel_x); 
  Serial.print(","); 
  Serial.print(accel_y); 
  Serial.print(","); 
  Serial.print(accel_z); 
  Serial.print(","); 
  Serial.print(gyro_x); 
  Serial.print(","); 
  Serial.print(gyro_y);
  Serial.print(","); 
  Serial.print(gyro_z); 
  Serial.print(","); 
  Serial.print(mag_x); 
  Serial.print(","); 
  Serial.print(mag_y); 
  Serial.print(","); 
  Serial.print(mag_z); 
  Serial.print(","); 
  Serial.print(Pressure); 
  Serial.println(";");
  
  delay(1000);
}