#define histeresis 15

uint16_t ejeX, ejeY, lastX, lastY;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ejeX = analogRead(A0);
  ejeY = analogRead(A1);

  if( ((ejeX >  lastX + histeresis) | (ejeX <  lastX - histeresis) )| ( (ejeY >  lastY + histeresis) | (ejeY <  lastY - histeresis)) ){
    //Serial.print("Eje X = "); Serial.print(ejeX); Serial.print("   "); Serial.print("Eje Y = "); Serial.println(ejeY); //For human read
    Serial.print(ejeX); Serial.print(",");Serial.println(ejeY); // For arduino serial plotter 
    lastX = ejeX;
    lastY = ejeY;
  }
 delay(100);
}
