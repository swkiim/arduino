# arduino
수업에서 활용했던 것들

  - bluetooth : 블루투스 연결을 통해 13번 led 제어
  - led_pwm : 아날로그 타입으로 led밝기 조절
  - bt_led_strange : 블루투스로 연결 후 원격으로 led제어 및 버튼스위치 상태에 따른 데이터 변화 확인
  - fnd_loop : FND를 0부터 9까지 1초의 delay를 가지고 무한으로 출력하는 루프
  - fnd_Serial : Serial통신으로 시리얼 모니터에 입력한 값을 FND로 출력
  - BT_FND : 블루투스 통신으로 아두이노와 모바일 앱에 연결 후 모바일 앱에서 입력한 값을 FND로 출력
  - pc_to_phone : pc(아두이노)와 휴대폰의 블루투스 통신 (문자열을 주고받을 수 있는 코드)
  - lcd : lcd를 사용하기 위한 테스트
  - lcd_BT : 특정 숫자 또는 문자를 블루투스로 입력받았을 때 lcd에서 그에 맞는 문자열 출력
  - lcd_String : 특정 숫자가 아닌 전송하고자 하는 문구를 블루투스로 전송하고 lcd에서 해당 문자열을 출력
  - DC_Motor_control : DC모터 동작 소스
  - DC_Motor_Serial_Monitor : 시리얼 모니터에서 DC모터를 제어하는 소스
  - DC_Motor_BT : DC모터를 제어하는 소스를 블루투스와 연결하여 구성
  - DC_Motor_Speed_Hold : DC모터가 일정한 속도를 유지하며 동작하게 하는 소스
  - step_motor : stepper.h 라이브러리 없이 Binary 코드 배열로 스텝모터 동작
  - step_control : Serial Monitor에서 값을 입력 후 입력받은 값에 따라 시계방향과 반시계방향으로 스텝모터가 회전
  - dht11 : 라이브러리를 사용하지 않고 dht11 온습도 센서를 작동하는 코드
  - dht11_lib : dht11 온습도 센서 라이브러리를 활용한 코드
  - dht11_lcd : 라이브러리 없는 dht11 센서와 lcd를 사용한 코드
  - dht11_lcd_lib : 라이브러리를 사용해 dht11과 lcd를 활용한 코드
  - dht11_lcd_lib_bt : dht11과 lcd, 블루투스를 활용해 모바일에서도 센서 측정 값 확인 가능한 코드
## arduino project(smart-home)
  - 회로도

![Smart Home Circuit Diagram](https://user-images.githubusercontent.com/87691039/170607961-f90bcd82-f1a5-4a9d-af8c-a71d14ee0fde.png)
  
  - 4x4 키패드

![4x4 Keypad List](https://user-images.githubusercontent.com/87691039/170608035-6fd56463-b080-4f49-adbe-a9cfb7297ea4.png)
