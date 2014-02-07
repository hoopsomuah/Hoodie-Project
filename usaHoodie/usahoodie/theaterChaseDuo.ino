

void theaterChaseDuoSetup()
{
  drawState = 0;
}

//Theatre-style crawling lights.
void theaterChaseDuoDrawFrame() {
  if(drawState == 0)
  {
    for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i, USA_RED);    //turn every other pixel to green
    }
    for (int i=1; i < strip.numPixels(); i=i+3) {
      strip.setPixelColor(i, USA_WHITE);        //turn every other pixel o blue
    }    
    for(int i= 2; i<strip.numPixels(); i= i+3){
      strip.setPixelColor(i, USA_BLUE);
    }
  }
  else if(drawState == 1)
  {
    for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i, USA_BLUE);    //turn every other pixel to green
    }
    for (int i=1; i < strip.numPixels(); i=i+3) {
      strip.setPixelColor(i, USA_RED);        //turn every other pixel o blue
    }    
    for(int i= 2; i<strip.numPixels(); i= i+3){
      strip.setPixelColor(i, USA_WHITE);
    }
  }
  else if(drawState == 2)
  {
    for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i, USA_WHITE);    //turn every other pixel to green
    }
    for (int i=1; i < strip.numPixels(); i=i+3) {
      strip.setPixelColor(i, USA_BLUE);        //turn every other pixel o blue
    }    
    for(int i= 2; i<strip.numPixels(); i= i+3){
      strip.setPixelColor(i, USA_RED);
    }
  }
  drawState = (drawState+1) % 3;
  strip.show();
  delay(100);
}

