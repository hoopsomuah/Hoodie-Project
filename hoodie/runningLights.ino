#define chaseLength 4

int startChase = 0;
int endChase = chaseLength;

uint32_t chaseColor = seaHawksGreen;
uint32_t baseColor = seaHawksBlue;

//state 0 = colorwipe
//state 1 = start the chase
//state 2 = continue chase
int runningLightsState = 0;

void runningLightsSetup()
{
  currPixel = 0;
  runningLightsState = 0; 
  startChase = 0;
  endChase = chaseLength;
}

void runningLightsDrawFrame()
{
  //colorwipe
  if(runningLightsState == 0)
  {
    strip.setPixelColor(currPixel, baseColor);
    strip.show();
    delay(50);
    
    currPixel++;
    if(currPixel >= LIGHT_STRIP_LED_COUNT)
    {
      runningLightsState = 1;
      currPixel = 0;
    }
  }
  
  //start the chase
  if(runningLightsState == 1)
  {
    strip.setPixelColor(currPixel, chaseColor);
    strip.show();
    delay(50);
    
    currPixel++;
    if(currPixel >= chaseLength)
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



