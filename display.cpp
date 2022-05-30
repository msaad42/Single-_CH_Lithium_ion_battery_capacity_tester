#include "main.h"

int tick_blink = 0;

LiquidCrystal lcd(7,8,9,10,11,12);//rs e d4 d5 d6 d7
byte happy[8]     = { B00000, B01010, B00000, B00000, B10001, B01110, B00000 };
byte sad[8]       = { B00000, B01010, B00000, B00000, B01110, B10001, B00000 };
byte cross[8]     = { B10001, B10001, B01010, B00100, B01010, B10001, B10001 };
byte tick[8]      = { B00000, B00000, B00001, B10010, B10100, B11000, B10000 };

//*************************************************************
void display_voltage_on_lcd(void)
{
      lcd.setCursor(10, 1);
      //lcd.print("V=");
      lcd.print(voltage);
      lcd.print("V");
  }



//*************************************************************
void display_set_current_on_lcd()
{
      lcd.setCursor(0, 0);
      lcd.print(set_current);
      lcd.print("A");
  }

  
//*************************************************************
void display_measured_current_on_lcd()
{
  lcd.setCursor(0, 1);
  lcd.print(measured_current);
  lcd.print("A");
}
  

//*************************************************************
void display_set_power_on_lcd()
{
      lcd.setCursor(0, 0);
      lcd.print(set_power);
      lcd.print("W");
  }
  

//*************************************************************
void display_measured_power_on_lcd(void)
{     
      measured_power = voltage * measured_current;
      lcd.setCursor(10, 1);
      //lcd.print("");
      lcd.print("      ");
      lcd.setCursor(10, 1);
      lcd.print(measured_power);
      lcd.print("W");
  }


//*************************************************************
void display_mah_on_lcd()
{
  lcd.setCursor(0, 0);
  lcd.print((unsigned int)(mas/3600));
  lcd.setCursor(4, 0);
  lcd.print("mAh");
}


//*************************************************************
void display_time_on_lcd(void){
  char str[2];
  lcd.setCursor(8, 0);
  
  sprintf(str, "%02d", _time.h);
  lcd.print(str); 
  lcd.print(":");

  sprintf(str, "%02d", _time.m);
  lcd.print(str);
  lcd.print(":");
  
  sprintf(str, "%02d", _time.s);
  lcd.print(str);
}


//*************************************************************
void display_insert_battery(void)
{
  lcd.setCursor(0, 0);
  lcd.print(" Insert Battery ");
  //lcd.setCursor(0, 1);
  //lcd.print("Charged ");
 
  }


//*************************************************************
void display_tick_symbol(void)
{
  if(tick_blink)
  {
    lcd.setCursor(6,1);
    lcd.print('\4');//tick symbol
    lcd.print('\4');//tick symbol
    tick_blink = 0;
    }

  else
  {
    lcd.setCursor(6,1);
    lcd.print(' ');//tick symbol
    lcd.print(' ');//tick symbol
    tick_blink = 1;
  }     
}


//*************************************************************
void display_over_discharged(void)
{
    lcd.setCursor(0,0);
    lcd.print("Over Discharged");//tick symbol
  }

  
void display_int_res_mode(void)
{
    lcd.setCursor(10,0);
    lcd.print("R int");
  }
