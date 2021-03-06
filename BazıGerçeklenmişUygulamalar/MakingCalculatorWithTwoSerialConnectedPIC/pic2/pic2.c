#include <main.h> // Basic Tanimlamalar

#include <lcd.c>  // Lcd Kutuphanesi

#use rs232(baud = 9600, rcv = pin_c7, parity = N, stop = 1) // RX-TX

char al;                                      //okunacak de?eri tutan degisken
float sayi1 = 0, sayi = 0, sonuc = 0;         //islemler icin gerekli degiskenler
int x=0, islem = 0, i = 0;                    //islemler icin gerekli degiskenler

islem_sec();
void sayiyap_yazdir()                    //sayi olusturma fonksyonu
{     
     al=getc();                       //diger picden veri alma
     //----------------------------------------------------------------------------------------------------------------------------------------------
 
     if(al == '7'){
      i++;
      if(i == 1){
         printf(lcd_putc,"\f");} //i bir se sf?rla
      while(al == "7");          //Tekrar bas?lana kadar bidaha d?nd?rme
      printf(lcd_putc,"7");      //bastir
      x=7;                       //x i doldur
      sayi=sayi*10 +x;           //sayiyi olustur
     }
     
     if(al=='8'){i++;if(i==1){printf(lcd_putc,"\f");} while(al == "8"); printf(lcd_putc,"8");  x=8; sayi=sayi*10 +x;}
     if(al=='9'){i++;if(i==1){printf(lcd_putc,"\f");} while(al == "9");  printf(lcd_putc,"9");  x=9; sayi=sayi*10 +x;}   
     if(al=='/'){i++;if(i==1){printf(lcd_putc,"\f");} while(al == "/"); printf(lcd_putc,"/"); sayi1=sayi;     islem=4;     sayi=0;  }   // bolme
      //----------------------------------------------------------------------------------------------------------------------------------------------
     if(al=='4'){i++;if(i==1){printf(lcd_putc,"\f");} while(al == "4"); printf(lcd_putc,"4"); x=4; sayi=sayi*10 +x; }  
     if(al=='5'){i++;if(i==1){printf(lcd_putc,"\f");} while(al == "5"); printf(lcd_putc,"5");  x=5; sayi=sayi*10 +x;}  
     if(al=='6'){i++;if(i==1){printf(lcd_putc,"\f");}while(al == "6"); printf(lcd_putc,"6");  x=6; sayi=sayi*10 +x;}  
     if(al=='*'){i++;if(i==1){printf(lcd_putc,"\f");} while(al == "*"); printf(lcd_putc,"*"); sayi1=sayi;    islem=3;   sayi=0;}  // carpma
      //-----------------------------------------------------------------------------------------------------------------------------------------------
     if(al=='1'){i++;if(i==1){printf(lcd_putc,"\f");} while(al=="1"); printf(lcd_putc,"1"); x=1; sayi=sayi*10 +x; }
     if(al=='2'){i++;if(i==1){printf(lcd_putc,"\f");} while(al=="2"); printf(lcd_putc,"2");  x=2; sayi=sayi*10 +x;}  
     if(al=='3'){i++;if(i==1){printf(lcd_putc,"\f");} while(al=="3"); printf(lcd_putc,"3");    x=3; sayi=sayi*10 +x;}
     if(al=='-'){i++;if(i==1){printf(lcd_putc,"\f");} while(al=="-"); printf(lcd_putc,"-"); sayi1=sayi;islem=2;sayi=0;} //cikarma
      //-------------------------------------------------------------------------------------------------------------------------------------------------
     if(al=='f'){ while(al =="f"); printf(lcd_putc,"\f0"); sayi1=0;sayi=0;x=0;islem=0;sonuc=0;i=0;}
     if(al=='0'){i++;if(i==1){printf(lcd_putc,"\f");} while(al=="0"); printf(lcd_putc,"0") ;  x=0; sayi=sayi*10 +x;}
     if(al=='='){i++;if(i==1){printf(lcd_putc,"\f");} while(al=="="); islem_sec();}   
     if(al=='+'){i++;if(i==1){printf(lcd_putc,"\f");} while(al=="+"); printf(lcd_putc,"+");sayi1=sayi;islem=1;sayi=0;    } // toplama
    //-------------------------------------------------------------------------------------------------------------------------------------------------------
    if(al== ' '){ while(al == " "); printf(lcd_putc,"\f");sayi1=0;sayi=0;x=0;islem=0;sonuc=0;i=0;} 
     

}

int islem_sec() //islem degiskenin degerini g?re islem secme
{ 
delay_ms(250);
printf(lcd_putc,"\f");
   if(islem==1){
    sonuc=sayi1+sayi; 
    printf(lcd_putc,"%.0f",sonuc);
    sayi1=sonuc;           // yedekle tekrar islem yapabilmek icin
    sayi=sonuc;
    x=0;islem=0;sonuc=0;//butun degerleri s?f?rla
   }
  else if(islem==2){
    sonuc=sayi1-sayi;
    printf(lcd_putc,"%.0f",sonuc);
    sayi1=sonuc;
    sayi=sonuc;
    x=0;islem=0;sonuc=0; 
  }
  else if(islem==3){
    sonuc=sayi1*sayi; 
    printf(lcd_putc,"%.0f",sonuc);
    sayi1=sonuc;
    sayi=sonuc;
    x=0;
    islem=0;
    sonuc=0;
  }
  else if(islem==4){
    sonuc=sayi1/sayi;
    printf(lcd_putc,"%.2f",sonuc);
    sayi1=sonuc;
    sayi=sonuc;                     //sayi yedekleme sonradan sonuc ?zerinden islem yapabilmek icin
    x=0;
    islem=0;
    sonuc=0;
break;
    return 0;
 } 
 islem=0;
}

void main()
{  
   lcd_init();
   while(True)
   {   
    sayiyap_yazdir();  
   }
}
