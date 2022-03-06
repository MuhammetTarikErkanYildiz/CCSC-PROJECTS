#include <16F877A.h>
#device ADC=8
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

                   
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG
int kume[]={63,6,91,79,102,109,125,7,127,111,111};
unsigned int pot_deger=0;
unsigned int but_deger=100;
unsigned int tutucu=0;
void durdur(){
         set_pwm1_duty(0);
         output_high(pin_c3);
         output_low(pin_c4);
         delay_ms(100);
          output_d(kume[0]);
}
void pot_oku(){

         if(input(pin_b3)){
          output_d(kume[0]);
            break;
            }
        
         set_pwm1_duty(pot_deger);
         delay_ms(20);
         tutucu=pot_deger;
          output_d(kume[pot_deger/25]);
}


void but_oku(){
    
            if(input(pin_b3)){
             delay_ms(30);
            output_d(kume[0]);
            break;
            }
    
    if(input(PIN_B1)){            // If RB1 button pressed
         delay_ms(50);
         if(but_deger> 220){
        but_deger = 254;
        }
        else{
           but_deger+=25;
   
           }// Increment i by 1 (i = i + 1)
              output_d(kume[ but_deger/25]);
      
         output_high(pin_c3);
         output_low(pin_c4);

      set_pwm1_duty( but_deger);  // Duty cycle change in tenths %
      delay_ms(100);
        
      }           
    if(input(PIN_B2)){            // If RB2 button pressed
      delay_ms(100);
                           // Decrement i by 1 (i = i - 1)
      if(but_deger < 25)
        but_deger=10;
        else
         but_deger-=25; 
         
         output_high(pin_c3);
         output_low(pin_c4);
      output_d(kume[but_deger/25]);
      set_pwm1_duty(but_deger);  // Duty cycle change in tenths %
      delay_ms(100);// Wait 100ms
      } 
 

}
void main()
{  
   setup_timer_2(T2_DIV_BY_4,255,1);
   setup_CCP1(CCP_PWM);
   setup_adc(adc_clock_div_16);
   setup_adc_ports(AN0);
   
   set_tris_a(0x01);
   
   set_tris_b(0xFF);
   output_b(0x00);

   set_tris_d(0x00);
   output_c(0x00);
   
   set_tris_c(0x00);
   output_c(0x00);
   
   set_adc_channel(0);
   delay_us(20);
   
   set_pwm1_duty(0);
   delay_us(20); 
   while(TRUE)
   {  
       pot_deger=read_adc();
       tutucu=pot_deger;
   if(input(pin_b3)){
      delay_ms(300);
       while(TRUE) {
       if(input(pin_b3)){
            break;
            }
       pot_deger=read_adc();
       delay_us(20);
         if((tutucu-10)>pot_deger||(tutucu+10)<pot_deger){
            delay_us(20);
           if(pot_deger<10)
            set_pwm1_duty(9);
            else
            pot_oku();
         }
         but_oku();
       
       
       }
      
   }
      
   durdur();   
   }
   }
