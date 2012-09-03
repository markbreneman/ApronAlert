//Apron Alert
const int Switch_pin = 10; // pin number
int Switch_val = 0;
int currentApronState = 1; // begin w/ circuit open
int previousApronState = 1;



void setup() {
  // configure serial communications:
  Serial.begin(9600);      

  // configure output pins:
  pinMode(Switch_pin, INPUT);

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
  Serial.print("ATDH0, DL5678\r");
  // set my address using 16-bit addressing:
  Serial.print("ATMY1234\r"); 
  // set the PAN ID. If you're working in a place where many people
  // are using XBees, you should set your own PAN ID distinct
  // from other projects.
  Serial.print("ATID1111\r");
  // put the radio in data mode:
  Serial.print("ATCN\r");
}


void loop() {
  Switch_val = digitalRead(Switch_pin);
//  Serial.print(Switch_val);
   if (Switch_val == 0){ // open
    currentApronState = 1;
    if (previousApronState != currentApronState){
      Serial.println("Finishing Cooking");
//      if (Serial.available()<=0) Serial.println("Starting to Cook");
//      if (Serial.available()<=0) Serial.println("Finished Cooking");
    }
  }
  if (Switch_val == 1){ // closed
    currentApronState = 2;
    if (previousApronState != currentApronState){
      Serial.println("Starting to Cook");
//      if (Serial.available()<=0) Serial.println("Starting to Cook");
//       if (Serial.available()<=0) Serial.println("Finished Cooking");
    }
  }
  previousApronState = currentApronState;
  
delay(300);
}
