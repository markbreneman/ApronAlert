//Apron Alert

char inByte;             // incoming byte from serial RX
//char inString[6];           // string for incoming serial data
//int stringPos = 0;          // string index counter


void setup() {
  // configure serial communications:
  Serial.begin(9600);      

  // set XBee's destination address:
  setDestination();
}

void setDestination() {
  // put the radio in command mode:
  Serial.print("+++");
  // wait for the radio to respond with "OK\r"
  char thisByte = 0;
  while (thisByte != '\r') {
    if (Serial.available() > 0) {
      thisByte = Serial.read(); 
    }
  }

  // set the destination address, using 16-bit addressing.
  // if you're using two radios, one radio's destination 
  // should be the other radio's MY address, and vice versa:
  Serial.print("ATDH0, DL1234\r");
  // set my address using 16-bit addressing:
  Serial.print("ATMY5678\r"); 
  // set the PAN ID. If you're working in a place where many people
  // are using XBees, you should set your own PAN ID distinct
  // from other projects.
  Serial.print("ATID1111\r");
  // put the radio in data mode:
  Serial.print("ATCN\r");
}

void loop() {
  // listen for incoming serial data:
  if (Serial.available() > 0) {
    // turn on the RX LED whenever you're reading data:
//    digitalWrite(rxLed, HIGH);
//    handleSerial();
    inByte = Serial.read();
    Serial.print(inByte);
  } 
//  else {
//    // turn off the receive LED when there's no incoming data:
//    digitalWrite(rxLed, LOW); 
//  }

}
//void handleSerial() {
//  inByte = Serial.read();
//  // save only ASCII numeric characters (ASCII 0 - 9):
//  if ((inByte >= '0') && (inByte <= '9')){
//    inString[stringPos] = inByte;
//    stringPos++;
//  }
//  // if you get an ASCII carriage return:
//
//  if (inByte == '\r') {
//    // convert the string to a number:
//    int brightness = atoi(inString);
//    // set the analog output LED:
//    analogWrite(analogLed, brightness);
//
//    // put zeroes in the array
//    for (int c = 0; c < stringPos; c++) {
//      inString[c] = 0;
//    } 
//    // reset the string pointer:
//    stringPos = 0;
//  }
//}


