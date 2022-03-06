#include <sonnnn.h>
#use delay(clock=20000000)
#include<lcd.c>
#include <tones.c>
#define SIZE 25

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O             
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG

void servo_90();
void servo_0();

void play();

const struct note
{
   long tone;
   long length;
} happy_bday[SIZE] = {
E_note[1],250, E_note[1],250, E_note[1],500, E_note[1],500, E_note[1],250, E_note[1],250,
E_note[1],500, G_note[1],250, C_note[1],250, D_note[1],250, E_note[1],1000, F_note[1],250,
F_note[1],250, F_note[1],250, F_note[1],250, F_note[0],250, E_note[1],250, E_note[1],250, E_note[1],250,
E_note[1],250, D_note[1],250, D_note[1],250, E_note[1],250, D_note[1],250,G_note[1],500};

void play(void)  
{
   int i;

   while(1)
   {
  
        for(i=0; i<SIZE; ++i)
      {
        
         generate_tone(happy_bday[i].tone,happy_bday[i].length);
         delay_ms(5);
         if(input(pin_c3)==0)
      {
      break;
      }
      }
       if(input(pin_c3)==0)
      {
      break;
      }
    
   }
}


void servo_90()
{
printf(lcd_putc,"\fTren Geliyor\nDurunuz");
delay_ms(100);
output_high(pin_b1);
output_low(pin_b2);
output_low(pin_b3);
}

void servo_0()
{
printf(lcd_putc,"\fTren Gidiyor\nGecebilirsiniz");
delay_ms(100);
output_high(pin_b2);
output_low(pin_b1);
output_low(pin_b3);
}

void main()
{
 int y=5;
   set_tris_d(0x00);
   set_tris_b(0x00);
   set_tris_c(0xFF);//giriþ
   output_d(0x00);
   output_b(0x00);
   lcd_init();
     
   output_low(pin_b1);
   output_low(pin_b2);
   output_high(pin_b3);
   while(TRUE)
   {
   
   if(input(pin_c3)==1 && input(pin_c4)==1)
   {
   if(y==1) printf(lcd_putc,"\fTren Gidiyor\nGecebilirsiniz");
     if(y==0) printf(lcd_putc,"\fTren Geliyor\nDurunuz");
   output_low(pin_b1);
   output_low(pin_b2);
   output_high(pin_b3);
   }
   
   if(input(pin_c3)==1 && input(pin_c4)==0)//c4==0 çalýþ  eðer c3 çalýþýrsa çýk
   {
     y=0;
    servo_90();
    play(); //þimdilik silebilirim
    
   }
 
   if(input(pin_c4)==1 && input(pin_c3)==0)//þu an 0dayýz 
   {
    y=1;
    servo_0();//çalýþýyor
      
   }
   

   
   }

 
}






/*
E_note[1],500, E_note[1],500, E_note[1],1000, E_note[1],1000, E_note[1],500, E_note[1],500,
E_note[1],1000, G_note[1],500, C_note[1],500, D_note[1],500, E_note[1],2000, F_note[1],500,
F_note[1],500, F_note[1],500, F_note[1],500, F_note[0],500, E_note[1],500, E_note[1],500, E_note[1],500,
E_note[1],500, D_note[1],500, D_note[1],500, E_note[1],500, D_note[1],500,G_note[1],1000};
*/


