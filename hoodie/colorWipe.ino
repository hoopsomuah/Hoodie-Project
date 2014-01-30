#define colorWipeWait 50

int currPixel = 0;
int color = SEAHAWKS_GREEN;


void colorWipeSetup()
{
  currPixel = 0;
}

void colorWipeDrawFrame(){
  
  strip.setPixelColor(currPixel, color);
  strip.show();
  delay(colorWipeWait);
  
  //if we've lit up all the pixels then change color and start again
  currPixel++;
  if(currPixel >= LIGHT_STRIP_LED_COUNT)
  {
      currPixel = 0;
      if(color == SEAHAWKS_GREEN)
      {
        color = SEAHAWKS_BLUE;
      }
      else
      {
        color = SEAHAWKS_GREEN;
      }
  }
}


