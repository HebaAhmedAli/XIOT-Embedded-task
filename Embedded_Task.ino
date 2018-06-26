const byte ledPin = 13;
const byte interruptPin = 2;
const byte tempSensorPin = 0; //analog pin 0
const int interval=3000;
volatile byte switch_state = LOW;
volatile bool toggle = false;
bool old_toggle = false;
int prev_time = 0;
float temp;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), change_in_state, CHANGE);
}

void loop() {
  digitalWrite(ledPin, switch_state);
  
  // this function is to check if the switch state changed to print the required data on the serial monitor
  check_for_change_state();

  //this function to read the temrature value every 3 seconds and send it to serial monitor
  read_temp_perodically();
}
void change_in_state() {
  switch_state = !switch_state;
  toggle = !toggle;
}
void check_for_change_state() {
  if (toggle != old_toggle) { //then there is a change in the switch state
    old_toggle = toggle;

    if (switch_state == HIGH) {
      // send “pressed” to the serial monitor only one time
      Serial.println("pressed");
      // also send the LED states ”ON” only one time
      Serial.println("ON");
    } else {
      // send the LED states ”OFF” only one time
      Serial.println("OFF");
    }
  }
}
void read_temp_perodically() {
  if (millis() - prev_time >= interval) {
    prev_time = millis();
    temp = analogRead(tempSensorPin);
    temp = temp * 0.48828125;
    /* this is how 0.48828125 calculated
    to  mv => (temp/1024.0)*5000; 
    to cel => mv/10;
    */
    Serial.print("TEMPRATURE = ");
    Serial.print(temp);
    Serial.print("*C");
    Serial.println();
  }
}
