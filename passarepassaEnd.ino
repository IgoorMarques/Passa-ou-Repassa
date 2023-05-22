int led_aperte = 2, led_aguarde = 3, led_p1 = 7, led_p2 = 9, led_p3 = 11;
int bt_start = 4, bt_reset = 5, bt_p1 = 6, bt_p2 = 8, bt_p3 = 10, bt_p4 = 12;

int bt_start_status, bt_reset_status;

void setup(){
  pinMode(bt_start, INPUT);
  pinMode(bt_reset, INPUT);
  pinMode(bt_p1, INPUT);
  pinMode(bt_p2, INPUT);
  pinMode(bt_p3, INPUT);
  pinMode(bt_p4, INPUT);
  pinMode(led_aperte, OUTPUT);
  pinMode(led_aguarde, OUTPUT);
  pinMode(led_p1, OUTPUT);
  pinMode(led_p2, OUTPUT);
  pinMode(led_p3, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_aguarde,LOW);
  digitalWrite(led_aperte,LOW);
  bt_start_status = digitalRead(bt_start);
  if(bt_start_status > 0){
      run();
      }
}

void run(){
    digitalWrite(led_aguarde, HIGH);
    int time = random(1000, 12000);
    delay(time);
    digitalWrite(led_aguarde, LOW);
    digitalWrite(led_aperte, HIGH);
    bt_reset_status = 0;
    while(true){
        int bt_p1_status = digitalRead(bt_p1);
        int bt_p2_status = digitalRead(bt_p2);
        int bt_p3_status = digitalRead(bt_p3);
        int bt_p4_status = digitalRead(bt_p4);
        bt_reset_status = digitalRead(bt_reset);

        if(bt_reset_status > 0){
          digitalWrite(led_p1, LOW);
          digitalWrite(led_p2, LOW);
          digitalWrite(led_p3, LOW);
          break;
        }
        if(bt_p1_status){
          Win(led_p1);
        }
        if(bt_p2_status){
          Win(led_p2);
        }
        if(bt_p3_status){
          Win(led_p3);
        }
        if(bt_p4_status){
          Win(20);
        }  
    }
}

void Win(int led){
  bt_reset_status = 0;
  int led_winner = led;
    while(bt_reset_status == 0){
      if(led_winner == 20){
        digitalWrite(led_p2, HIGH);
        digitalWrite(led_p1, LOW);
        delay(100);
        digitalWrite(led_p2, LOW);
        digitalWrite(led_p1, HIGH);
        delay(100);
      }
      else{
        digitalWrite(led_winner, HIGH);
        delay(100);
        digitalWrite(led_winner, LOW);
        delay(100);
      }
      bt_reset_status = digitalRead(bt_reset);
      }
}
