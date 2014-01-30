
void theaterChaseDuoSetup()
{
  colorIndex = 0;
}

//Theatre-style crawling lights.
void theaterChaseDuoDrawFrame() {
    for (int i=0; i < strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, colors[colorIndex]);    //turn every other pixel to green
    }
    
    colorIndex = (colorIndex + 1) % 2;
    
    for (int i=1; i < strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, colors[colorIndex]);        //turn every other pixel o blue
    }
    
    strip.show();
    delay(100);
}

