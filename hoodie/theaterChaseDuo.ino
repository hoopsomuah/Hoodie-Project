
uint32_t theaterChaseColors[] = {SEAHAWKS_GREEN, SEAHAWKS_BLUE};
int theaterChaseIndex = 0;

void theaterChaseDuoSetup()
{
  theaterChaseIndex = 0;
}

//Theatre-style crawling lights.
void theaterChaseDuoDrawFrame() {
    for (int i=0; i < strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, theaterChaseColors[theaterChaseIndex]);    //turn every other pixel to green
    }
    
    theaterChaseIndex = (theaterChaseIndex + 1) % 2;
    
    for (int i=1; i < strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, theaterChaseColors[theaterChaseIndex]);        //turn every other pixel o blue
    }
    
    strip.show();
    delay(100);
}

