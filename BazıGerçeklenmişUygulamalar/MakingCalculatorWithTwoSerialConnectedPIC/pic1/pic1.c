#include <main.h>
#use rs232(baud = 9600, xmit = pin_c6, parity = N, stop = 1)

int i=0;

#int_ext
void b0_kesmesi(){
i++;
if(i==2) i=0;

}


void oku()
{
     output_high(pin_d0);
     if(input(pin_d4)){ while(input(pin_d4)); puts("7"); }  // 7
     if(input(pin_d5)){ while(input(pin_d5)); puts("8"); }   // 8
     if(input(pin_d6)){ while(input(pin_d6)); puts("9"); }   // 9
     if(input(pin_d7)){ while(input(pin_d7)); puts("/"); }  
     output_low(pin_d0);
        //---------------------------------------------------------------------
     output_high(pin_d1);
     if(input(pin_d4)){ while(input(pin_d4)); puts("4"); }  // 4
     if(input(pin_d5)){ while(input(pin_d5)); puts("5"); }   // 5
     if(input(pin_d6)){ while(input(pin_d6)); puts("6"); }   //6
     if(input(pin_d7)){ while(input(pin_d7)); puts("*"); }  // �arpma
     output_low(pin_d1);
        //---------------------------------------------------------------------
     output_high(pin_d2);
     if(input(pin_d4)){ while(input(pin_d4)); puts("1"); } // 1
     if(input(pin_d5)){ while(input(pin_d5)); puts("2"); }  //2
     if(input(pin_d6)){ while(input(pin_d6)); puts("3"); } //3
     if(input(pin_d7)){ while(input(pin_d7)); puts("-"); } //- ��karma
     output_low(pin_d2);
     //---------------------------------------------------------------------
     output_high(pin_d3);
     if(input(pin_d4)){ while(input(pin_d4)); puts("f"); }//   ON/OFF
     if(input(pin_d5)){ while(input(pin_d5)); puts("0"); }//   0
     if(input(pin_d6)){ while(input(pin_d6)); puts("="); }//   =    
     if(input(pin_d7)){ while(input(pin_d7)); puts("+"); }//  toplama
     output_low(pin_d3);
}

void main()
{  
   set_tris_b(0xFF);
   set_tris_d(0xF0); 
   ext_int_edge(L_TO_H); // basildigi anda kesme aktif
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   set_tris_b(0xFF);
   set_tris_d(0xF0); 

   while(TRUE)
   {  
      puts(" ");
      delay_ms(250);
      if(i==1)
      {
      puts("f");
      delay_ms(100);
      while(TRUE)
         {
            oku();
            if(i==0)
            {  
               delay_ms(250);
               break;
            }
         }

      }
   }
}
