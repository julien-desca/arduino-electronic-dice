#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define LED7 8
#define BUZZ 13
#define DELAY 1000
#define BUZZ_TIME 100
#define BUZZ_F 500
int random_num = 0;
int last_random = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(12, INPUT);
  randomSeed(analogRead(0));
  
  tone(BUZZ,100,BUZZ_TIME);
  delay(400);
  tone(BUZZ,100,BUZZ_TIME);
  delay(400);
  //testSequence();
}

void testSequence(){

  tone(BUZZ,100,BUZZ_TIME);
  delay(400);
  tone(BUZZ,100,BUZZ_TIME);
  delay(400);
  displayOne();
  displayTwo();
  displayThree();
  displayFour();
  displayFive();
  displaySix();
  tone(BUZZ,100,BUZZ_TIME);
  delay(400);
  tone(BUZZ,100,BUZZ_TIME);
  clearLEDS(); 
}

void loop() {
  int button = digitalRead(12);
  if(button == HIGH){
    while(digitalRead(12) == HIGH){
      roll();
      delay(100);
      clearLEDS();
    }
    dice();
  }
}

void dice(){
  int max_del = random(1000,2500);
  int del = 100;
  do{
    while(random_num == last_random){
      random_num = random(1,7);
    }
    display_int(random_num, true);  
    delay(del);
    clearLEDS();
    last_random = random_num;
    del = del * 1.35;
  }while(del < max_del);
  blink_blink(random_num);
}

void blink_blink(int number){
  clearLEDS();
  delay(450);
  display_int(number, false);
  delay(450);
  clearLEDS();
  delay(450 );
  display_int(number,false);
}

void roll(){
  while(random_num == last_random){
    random_num = random(1,7);
  }
  display_int(random_num, true);  
  last_random = random_num;
}

void display_int(int num, bool buzzing){
  switch(num){
    case 1:
      displayOne();
      break;
    case 2:
      displayTwo();
      break;
    case 3:
      displayThree();
      break;
    case 4:
      displayFour();
      break;
    case 5:
      displayFive();
      break;
    case 6:
      displaySix();
      break;
  }
  if(buzzing){
    buzz();  
  }
}

void displayOne(){
  digitalWrite(LED7, HIGH);
}

void displayTwo(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED6, HIGH);
}

void displayThree(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED7, HIGH);
  digitalWrite(LED6, HIGH);
}

void displayFour(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
}

void displayFive(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
  digitalWrite(LED7, HIGH);
}

void displaySix(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
}

void clearLEDS(){
  for(int i = LED1; i <= LED7; i++){
    digitalWrite(i,LOW);
  }
}

void buzz(){
  tone(BUZZ, BUZZ_F, BUZZ_TIME);
}
