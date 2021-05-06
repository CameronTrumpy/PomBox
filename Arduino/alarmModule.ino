void alarmMonitor() {
  // put your main code here, to run repeatedly:
  if (!triggerPressed && phoneMode && working) {
    analogWrite(alarm, 0);
    delay(100);
    analogWrite(alarm, 50);
    delay(100);
//    Serial.println("triggered");
  }
  else {
    analogWrite(alarm, 0);
//    Serial.println("no trigger");
  }
}

void quickBeep(){
  analogWrite(alarm, 0);
    delay(50);
    analogWrite(alarm, 50);
    delay(50);
    analogWrite(alarm, 0);
    delay(50);
    analogWrite(alarm, 50);
    delay(50);
    analogWrite(alarm, 0);
    delay(50);
}
