#define colorWipeWait 25

int currPixel = 0;
bool turn = false;


void colorWipeSetup()
{
  currPixel = 0;
  drawState = 0;
}

void colorWipeDrawFrame(){
  if(drawState == 0)
  {
    strip.setPixelColor(currPixel, USA_RED);
  } 
  else if(drawState == 1) { 
    strip.setPixelColor(currPixel, USA_WHITE);
  }
  else if(drawState == 2){
    strip.setPixelColor(currPixel, USA_BLUE);
  }
  strip.show();
  delay(colorWipeWait);
  
  //if we've lit up all the pixels then change color and start again
  currPixel++;
  if(currPixel >= LIGHT_STRIP_LED_COUNT)
  {
      currPixel = 0;
      drawState = (drawState +1) % 3;
  }
}



