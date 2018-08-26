#include <Arduino.h>
#include <Esp.h>
int freq_of_intrpt=1; // 1= 1 HZ 
int set = 0;
void ICACHE_RAM_ATTR tim()
{
    set =set+ 1;
}

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    timer1_isr_init();
    timer1_attachInterrupt(tim);
    timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP);
    timer1_write(5000000/freq_of_intrpt);
}

void loop()
{
    if (set==500)
    {
        
    Serial.println(millis());
    set=0;
    }
}