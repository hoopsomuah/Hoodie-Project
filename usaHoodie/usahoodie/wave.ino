

int currPixelWave =0;

void waveSetup()
{
  drawState = 0;
  currPixelWave = 0;
}

void waveDrawFrame()
{
  //wave red up
  if(drawState == 0)
  {
     strip.setPixelColor(currPixelWave, USA_RED); 
     strip.setPixelColor(LIGHT_STRIP_LED_COUNT - currPixelWave, USA_RED);
     strip.show();
     delay(25);
     
     currPixelWave++;
     if(currPixelWave > LIGHT_STRIP_LED_COUNT/2)
     {
       drawState = 1;
       currPixelWave--;
     }
  }
  //wave white down
  if(drawState == 1)
  {
    strip.setPixelColor(currPixelWave, USA_WHITE);
    strip.setPixelColor(LIGHT_STRIP_LED_COUNT - currPixelWave, USA_WHITE);
    strip.show();
    delay(25);
    
    currPixelWave--;
    if(currPixelWave < 0)
    {  
      drawState = 2;
      currPixelWave++;
    }
  }
  //wave blue up
  if(drawState == 2)
  {
    strip.setPixelColor(currPixelWave, USA_BLUE); 
     strip.setPixelColor(LIGHT_STRIP_LED_COUNT - currPixelWave, USA_BLUE);
     strip.show();
     delay(25);
     
     currPixelWave++;
     if(currPixelWave > LIGHT_STRIP_LED_COUNT/2)
     {
       drawState = 3;
       currPixelWave--;
     } 
  }
  //wave white down
  if(drawState == 3)
  {
    strip.setPixelColor(currPixelWave, USA_WHITE);
    strip.setPixelColor(LIGHT_STRIP_LED_COUNT - currPixelWave, USA_WHITE);
    strip.show();
    delay(25);
    
    currPixelWave--;
    if(currPixelWave < 0)
    {  
      drawState = 0;
      currPixelWave++;
    }
  }
   
}
