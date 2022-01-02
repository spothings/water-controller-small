// variable relay/selenoid
int waiting_on = 0;
int waiting_off = 0;
const int selenoidPin = 26; //
bool selenoid_status = false;
String selenoidString;

void setup_selenoid(){
  // set pin selenoid as output
  pinMode(selenoidPin, OUTPUT);
}

String loop_selenoid(){
  if(distance > box_high){
    if(waiting_on >= 5){
      selenoid_status = true;
      digitalWrite(selenoidPin, HIGH);
    }
    waiting_on += 1;
    waiting_off = 0;
  }else{
    if(waiting_off >= 5){
      selenoid_status = false;
      digitalWrite(selenoidPin, LOW);
    }
    waiting_on = 0;
    waiting_off += 1;
  }
  if(selenoid_status){
    selenoidString = "On";
  } else {
    selenoidString = "Off";
  }
  return selenoidString;
}
