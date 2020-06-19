#include <LCD4Bit_mod.h> 
LCD4Bit_mod lcd = LCD4Bit_mod(2); 
char GP2D12;
char a,b;
char str1[]="Renge:";
char str2[]=" Renge Over ";
char str3[]="cm"; 
void setup()
{
lcd.init();
lcd.clear();
lcd.printIn("GP2D12 testing..."); 
} 
void loop()
{
GP2D12=read_gp2d12_range(1);
if(GP2D12>80||GP2D12<10)
{
lcd.cursorTo(2,0); 
lcd.printIn(str2); 
}
else
{
a=0x30+GP2D12/10;
b=0x30+GP2D12%10; 
lcd.cursorTo(2, 3); 
lcd.printIn(str1); 
lcd.print(a); 
lcd.print(b);
lcd.printIn(str3); 
} 
delay(50);
}

float read_gp2d12_range(byte pin)
{
int tmp;
tmp = analogRead(pin);
if (tmp < 3)return -1; 
return (6787.0 /((float)tmp - 3.0)) - 4.0;

