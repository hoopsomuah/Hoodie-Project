
int waveState = 0;
int currPixelWave =0;

void waveSetup()
{
  waveState = 0;
  currPixelWave = 0;
}

void waveDrawFrame()
{
  //wave green up
  if(waveState == 0)
  {
     strip.setPixelColor(currPixelWave, seaHawksGreen); 
     strip.setPixelColor(LIGHT_STRIP_LED_COUNT - currPixelWave, seaHawksGreen);
     strip.show();
     delay(25);
     
     currPixelWave++;
     if(currPixelWave > LIGHT_STRIP_LED_COUNT/2)
     {
       waveState = 1;
       currPixelWave--;
     }
  }
  //wave blue down
  if(waveState == 1)
  {
    strip.setPixelColor(currPixelWave, seaHawksBlue);
    strip.setPixelColor(LIGHT_STRIP_LED_COUNT - currPixelWave, seaHawksBlue);
    strip.show();
    delay(25);
    
    currPixelWave--;
    if(currPixelWave < 0)
    {  
      waveState = 0;
      currPixelWave++;
    }
  }
}
