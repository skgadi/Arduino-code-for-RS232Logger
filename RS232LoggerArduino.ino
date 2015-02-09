void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // Initial setup to be modified by the user.
  int NoOfPorts = 12; // Type number of analog ports of the arduino
  double MaxVolAllowed = 3.3; // Type the maximum voltage accepted by the board
  double APrtResol = 1024; // Type the maximum resolution of the analog channel
  int Accuracy=4; //Accuracy required to which decimal places?
  // Do not change anything from here .......................
  if (Serial.available() > 0) {
      int Read = Serial.read();
      if (Read) {
        if (Read >= (65+0) && Read <= (64+NoOfPorts) ) {
          delay(1);
          double AValue = analogRead(Read-65)*MaxVolAllowed/(APrtResol-1);
          Serial.print(AValue,Accuracy);
          Serial.print('\n');
        }
        else {
          Serial.print("-1");
          Serial.print('\n');
        }
      }
  }
}
