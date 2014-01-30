#define colorWipeWait 50

int currPixel = 0;
bool turn = false;


void colorWipeSetup()
{
  currPixel = 0;
}

void colorWipeDrawFrame(){
  if(turn)
  {
    strip.setPixelColor(currPixel, SEAHAWKS_BLUE);
  } else { 
    strip.setPixelColor(currPixel, SEAHAWKS_GREEN);
  }
  strip.show();
  delay(colorWipeWait);
  
  //if we've lit up all the pixels then change color and start again
  currPixel++;
  if(currPixel >= LIGHT_STRIP_LED_COUNT)
  {
      currPixel = 0;
      turn = !turn;
  }
}



