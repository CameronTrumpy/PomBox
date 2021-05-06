SerLCD lcd;
int prevPage;

void initDisp(){
  Wire.begin();

  lcd.begin(Wire); //Set up the LCD for I2C communication

  lcd.setBacklight(255, 255, 255); //Set backlight to bright white
  lcd.setContrast(5); //Set contrast. Lower to 0 for higher contrast.
  lcd.clear(); //Clear the display - this moves the cursor to home position as well

  page = MAIN_PAGE;
}


void loopDisp(){
  prevPage = page;
  switch (page){
    
    case MAIN_PAGE:
        lcd.setCursor(0, 0); //Clear the display - this moves the cursor to home position as well
        lcd.print("Welcome 2 Pombox");
        
        lcd.setCursor(0, 1);
        cycleString = String(cycles);
        lcd.print("Cycles: " + cycleString);
       
        if(confirmPressed){
          page = COUNTDOWN;
          working = true; // needs to be set true so timer does not resume break time if not finished
          startTimer();
        }
        else if(cancelPressed){
          page = SETTINGS;
        }
    break;

    
    case COUNTDOWN:
        if(working){
           lcd.setCursor(0, 0);
           lcd.print("WORK TIME      ");
        }
        else{
           lcd.setCursor(0, 0);
           lcd.print("BREAK TIME     ");
        }
        lcd.setCursor(0, 1);
        lcd.print(loopTimer());
        
        if(confirmPressed){
          //pause timer
        }
        else if(cancelPressed){
          working = false;
          page = MAIN_PAGE;
        }
        
    break;
    case SETTINGS:
           lcd.setCursor(0, 0);
           lcd.print("TIME SETTINGS  ");
          
            if(upPressed){
              workTime = workTime + 60;
            }
          
           else if(confirmPressed && (workTime >1)){
            workTime = workTime - 60;
           }
           delay(200);
           
           workString = String(workTime / 60);
           lcd.setCursor(0, 1);
           lcd.print("Work Time: " + workString  + "   ");
            
           if(cancelPressed){
            page = MAIN_PAGE;
        }
         
    break;
  }

  
  if(prevPage != page){
    lcd.clear();
  }

}
