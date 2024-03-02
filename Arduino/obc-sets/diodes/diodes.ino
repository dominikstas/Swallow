/*
This code was developed to serve as a lighting system for the Opium UAV.
It utilizes pin 7 for the button and pin 8 for the diodes. The diodes, a red one and a green one,
are connected to the positive terminal. When the button is pressed, both diodes start flashing,
and they won't stop until an external event interrupts their operation. 

The idea is to turn on the lights before the Opium starts, and then disconnect
the button. This way, in the event of an accident, the flashing lights will persist, providing a visual indication
of the situation.

Note: It's crucial to consider safety measures and the intended use case while implementing such features.
Resistors are cool.
*/
void setup() {
  pinMode(8, OUTPUT); //Diode
  pinMode(7, INPUT_PULLUP); //Button
  digitalWrite(8, LOW); //Turn off diode
}
 
void loop()
{
  int ON = 0;
  if (digitalRead(7) == LOW) {
    ON =1;
}
  while(ON==1){
    digitalWrite(8, HIGH);
    delay(300);
    digitalWrite(8, LOW);
    delay(300);
  }
}