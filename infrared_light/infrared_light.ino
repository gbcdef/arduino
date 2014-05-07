
#include <IRremote.h>
#include <led_action.ino>

int RECV_PIN = 11;//定义红外接收器的引脚为11
int ledPin=6;
int lumix=0;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // 初始化红外接收器
}

void loop() {
  if (irrecv.decode(&results)) {
    switch(results.value)
    {
    case 0x68733A46://button volume plus
      led_increase(50);
      break;
    case 0x83B19366://button volume minus
      led_decrease(50);
      break;
    case 0xE13DDA28://button 1
      led_blink(ledPin,5);
      break;
    case 0xF4BA2988://button open&close
      led_openbutton();
      break;
    }

    Serial.println(results.value,HEX);//以16进制换行输出接收代码
    Serial.println();//为了便于观看输出结果增加一个空行
    irrecv.resume(); // 接收下一个值
  }2
  analogWrite(ledPin,lumix);
}

