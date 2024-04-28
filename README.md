# PRACTICA 8: BUCLE DE COMUNICACIÓ UART2
### Autor: Tomàs Lloret
L'objectiu d'aquesta pràctica és realitzar un bucle de comunicació de forma que les dades que s'enviin per el terminal RXD0 es redirigeixin a la UART2 TXD2, que reenviarà les dades un altre cop a la sortida TXD0 per a que apareixin per terminal.

## Part A: Bucle de comunicació UART2
Comencem la pràctica incloent l'única llibreria necessària i definint els pins a utilitzar.
```c
#include <Arduino.h>

#define RXD0 34
#define TXD0 35
#define TXD2 28
```

En el setup, definim la velocitat de comunicació i connectem el port RXD0 amb el TXD2 i el port TXD2 amb el TXD0 a través del SERIAL_8N1.
```c
void setup() {
  Serial.begin(4000);
  Serial1.begin(4000, SERIAL_8N1, RXD0, TXD2);
  Serial2.begin(4000, SERIAL_8N1, TXD2, TXD0);
}
```

En el loop es fan dos ifs, un d'ells mirarà si el canal Serial està disponible. Si ho està, les dades d'aquest s'escriuràn en el Serial1. El segon, de la mateixa manera, mirarà si el Serial1 està disponible i, de ser així, escriurà les dades d'aquest en el Serial2, que anirà al terminal acompanyat d'un printf "test".
```c
void loop() {
  // Serial.printf("A");
  if(Serial.available())
  {
    Serial1.write(Serial.read());  
  }
  if(Serial1.available())
  {
    Serial2.write(Serial1.read());
    Serial.printf("Test");
  }
  delay(10);
}
```

### Part A: Codi complet
```c
#include <Arduino.h>

#define RXD0 34
#define TXD0 35
#define TXD2 28

void setup() {
  Serial.begin(4000);
  Serial1.begin(4000, SERIAL_8N1, RXD0, TXD2);
  Serial2.begin(4000, SERIAL_8N1, TXD2, TXD0);
}

void loop() {
  // Serial.printf("A");
  if(Serial.available())
  {
    Serial1.write(Serial.read());  
  }
  if(Serial1.available())
  {
    Serial2.write(Serial1.read());
    Serial.printf("Test");
  }
  delay(10);
}
```