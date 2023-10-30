#include <Arduino.h>
const byte PinDeInterrupcion = 13;
volatile byte ContadorDeInterrupciones = 0;
int NumeroDeInterrupciones = 0;

void ICACHE_RAM_ATTR InterrupcionExterna();

void InterrupcionExterna()
{
  ContadorDeInterrupciones++;
}

void setup()
{
  Serial.begin(115200);
  //pinMode(PinDeInterrupcion, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PinDeInterrupcion), InterrupcionExterna, RISING);
}

void loop()
{
  if (ContadorDeInterrupciones > 0)
  {
    ContadorDeInterrupciones--;
    NumeroDeInterrupciones++;
    Serial.print("Numero de interrupciones: ");
    Serial.println(NumeroDeInterrupciones);
  }
}