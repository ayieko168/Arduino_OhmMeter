int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float R1 = 470;  /*Change to the known resistor value*/
float R2 = 0;
float buffer = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  raw = analogRead(analogPin);
  if (raw)
  {
    buffer = raw * Vin;
    Vout = (buffer) / 1024.0;
    buffer = (Vin / Vout) - 1;
    R2 = R1 * buffer;
    
    Serial.print("Resistor: ");
    Serial.print(R2);
    Serial.println(" Ohms");

    delay(250);

  }
}
