int currRunningLightsPixel = 0;
int chaseLength = 4;
int startChase = 0;
int endChase = chaseLength;

uint32_t chaseColor = SEAHAWKS_GREEN;
uint32_t baseColor = SEAHAWKS_BLUE;

//state 0 = colorwipe
//state 1 = start the chase
//state 2 = continue chase
int runningLightsState = 0;

void runningLightsSetup()
{
  currRunningLightsPixel = 0;
  runningLightsState = 0; 
  startChase = 0;
  endChase = chaseLength;
}

void runningLightsDrawFrame()
{
  //colorwipe
  if(runningLightsState == 0)
  {
    strip.setPixelColor(currRunningLightsPixel, baseColor);
    strip.show();
    delay(50);
    
    currRunningLightsPixel++;
    if(currRunningLightsPixel >= LED_COUNT)
    {
      runningLightsState = 1;
      currRunningLightsPixel = 0;
    }
  }
  
  //start the chase
  if(runningLightsState == 1)
  {
    strip.setPixelColor(currRunningLightsPixel, chaseColor);
    strip.show();
    delay(50);
    
    currRunningLightsPixel++;
    if(currRunningLightsPixel >= chaseLength)
    {
      runningLightsState = 2;
    }
  } 
  
  //chase lights
  if(runningLightsState == 2)
  {
    uint32_t oldStart = startChase;
    startChase = (startChase + 1) % strip.numPixels();
    endChase = (endChase + 1) % strip.numPixels();
    
    strip.setPixelColor(oldStart, baseColor);
    strip.setPixelColor(endChase, chaseColor);
    strip.show();
    delay(50);
  }
  
}

void runningLights(uint32_t base, uint32_t chase, uint32_t chaseLength, uint8_t wait){
  //set the base for the pixels
  //colorWipe(base, wait);
  int startChase = 0;
  int endChase = chaseLength;
  int steps = (strip.numPixels() * 5) - chaseLength;
 
  //start the runner
  for(int i= startChase; i<endChase; i++){
    strip.setPixelColor(i, chase);
    strip.show();
    delay(wait);
  }
 
  //run the runner around the strip
  for(int j=0; j<steps; j++){
    uint32_t oldStart = startChase;
    startChase = (startChase + 1) % strip.numPixels();
    endChase = (endChase + 1) % strip.numPixels();
    strip.setPixelColor(oldStart, base);
    strip.setPixelColor(endChase, chase);
    strip.show();
    delay(wait);
  }
  //end runner
  for(int i= startChase; i<strip.numPixels(); i++)
  {
    strip.setPixelColor(i, base);
    strip.show();
    delay(wait);
  }
}


