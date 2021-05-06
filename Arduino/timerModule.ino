int getCurrSeconds(){
 return (millis() / 1000);
}

//changes defaut times to input times
void changeTimer(int newWork, int newBreak){
  workTime = (newWork * 60);
  breakTime = (newBreak * 60);
}


void startTimer(){
  initTime = getCurrSeconds();
  if(triggerPressed){
    phoneMode = true;
  }
  else{
    phoneMode = false;
  }
}

String loopTimer(){
  if(working){
     currTime = workTime - (getCurrSeconds() - initTime);
     if(currTime == 0){ //if working timer has run to 0, set working to false, and reset timer
      cycles = cycles + 1;
      working = false;
      quickBeep();
      startTimer();
     }
  }
  else{
     currTime = breakTime - (getCurrSeconds() - initTime);
     if(currTime == 0){ //if break timer has run to 0, set working to true, and reset timer
      working = true;
      quickBeep();
      startTimer();
     }
  }
  

  
  String mins = String(currTime/60);
  String secs = String(currTime%60);
  
  if(currTime%60>9){
    return (mins + ":" + secs + "  ");  
  }
  else{
     return (mins + ":0" + secs  + "  "); 
  }
  
}
