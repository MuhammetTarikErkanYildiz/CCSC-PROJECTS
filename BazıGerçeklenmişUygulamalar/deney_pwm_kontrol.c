
#include <16F877A.h>
#device ADC=8
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                 
#use delay(crystal=20000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#define ileri pin_c3
#define geri pin_c4
#define artir pin_b1
#define azalt pin_b2
#define basla_dur pin_b3

unsigned int but_deger=0;
unsigned int pot_deger=0;
unsigned int tutucu=0,tutucu1=0;

void pwm_arranger(float d){
         set_pwm1_duty(d);
         output_high(ileri);
         output_low(geri);
         delay_us(100); 
}
void main()
{
    setup_timer_2(T2_DIV_BY_4, 255, 1);
   setup_timer_1(T1_DISABLED);
   setup_adc(adc_clock_div_16);
   setup_CCP2(CCP_OFF);
   setup_psp(PSP_DISABLED);
   setup_CCP1(CCP_PWM);

   setup_adc_ports(AN0);
   
   
   set_tris_a(0xff);
 
   set_tris_b(0xFF);
   set_tris_c(0x00);
     output_c(0X00);
   
   set_adc_channel(0);
    delay_ms(10);
     set_pwm1_duty(0);
     
      while(true)
      {
      
         if(input(pin_b3)){
            delay_us(100);
            while(true){
               pot_deger=read_adc();
               pwm_arranger(pot_deger);
               if(basla_dur)
               break;
            
            }
         
         }
         set_pwm1_duty(0);
         output_low(ileri);
         output_low(geri);
     
      }
      }
   
   
  
