
bool state = true;
void theaterChaseDuoSetup()
{
}

//Theatre-style crawling lights.
void theaterChaseDuoDrawFrame() {
  if(state)
  {
    for (int i=0; i < strip.numPixels(); i=i+2) {
          strip.setPixelColor(i, SEAHAWKS_GREEN);    //turn every other pixel to green
    }
    
    for (int i=1; i < strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, SEAHAWKS_BLUE);        //turn every other pixel o blue
    }    
  }
  else
  {
    for (int i=0; i < strip.numPixels(); i=i+2) {
          strip.setPixelColor(i, SEAHAWKS_GREEN);    //turn every other pixel to green
    }
    
    for (int i=1; i < strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, SEAHAWKS_GREEN);        //turn every other pixel o blue
    }
  }
  state = !state;
  strip.show();
  delay(100);
}

