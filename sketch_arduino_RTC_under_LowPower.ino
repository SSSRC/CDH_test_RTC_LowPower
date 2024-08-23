//RTCがColdSleep状態やDeepSleep状態でも動き続けるかどうかを検証するためのプログラム。
//それぞれの状態を経た後、RTCが５秒ほど進んでいたら、そのスリープ状態下でもRTCが動き続けていたことになる。

#include <LowPower.h>
#include <RTC.h>

void setup() {
  // put your setup code here, to run once:
}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
  LowPower.begin();
  RTC.begin();
  RtcTime time_before_deep_sleep, time_after_deep_sleep, time_before_cold_sleep, time_after_cold_sleep;

  Serial.print("DeepSleepでのRTCの検証をはじめます\n");
  Serial.print("DeepSleep後、5秒後にsleep解除します\n");
  time_before_deep_sleep = RTC.getTime();
  Serial.print("DeepSleep前のRTC時刻:");
  Serial.print(time_before_deep_sleep);
  Serial.print("\n");
  Serial.print("DeepSleepにはいります\n");
  LowPower.deepSleep(5);
  Serial.print("DeepSleep解除しました\n");
  time_after_deep_sleep = RTC.getTime();
  Serial.print("DeepSleep後のRTC時刻:");
  Serial.print(time_after_deep_sleep);
  Serial.print("\n");

  Serial.print("ColdSleepでのRTCの検証をはじめます\n");
  Serial.print("ColdSleep後、5秒後にsleep解除します\n");
  time_before_cold_sleep = RTC.getTime();
  Serial.print("ColdSleep前のRTC時刻:");
  Serial.print(time_before_cold_sleep);
  Serial.print("\n");
  Serial.print("ColdSleepにはいります\n");
  LowPower.coldSleep(5);
  time_after_cold_sleep = RTC.getTime();
  Serial.print("ColdSleep後のRTC時間:");
  Serial.print(time_after_cold_sleep);
  Serial.end();
  LowPower.end();
  RTC.end();
}
