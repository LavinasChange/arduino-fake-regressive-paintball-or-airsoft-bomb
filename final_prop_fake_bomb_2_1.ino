/*Airsoft / Paintball TIMER Bomb
 Version 2.0
 Creators:
Roberto Santos Reis
Turned into usable code, 12/09/2013:
Aracaju/ Brazil
*/

#include <LiquidCrystal.h>
#include <PS2Keyboard.h>
#include <stdlib.h>

PS2Keyboard keyboard;
LiquidCrystal lcd(22, 25, 26, 27, 28, 29); // START LCD

// Definições
#define LED_RED 6
#define LED_GREEN 5
#define SPKRPin 2

//Strings
String key;
String password;
// Chars
char entered[15];
char confirma[1] = {};
char pwd[15] = {};
char tmp[15] = {};
char digitado[15] = {};
char startTime[15] = {};
char verifica[15] = {};
char digito;
// Ints
int i = 0;
int loops = 0;
int situacao = 0;
unsigned int timerSeconds;
const int DataPin = 4;
const int IRQpin =  3;
int currentLength = 0;
int qntErros=0;
//long
long interval=1000;
long present;
long previousMillis = 0;







void setup() {

  Serial.begin(9600);
  pinMode(45, OUTPUT); // bg display
  analogWrite(45, 100);
  lcd.begin(16, 2);
  lcd.print(">NOVO CODIGO:");
  lcd.cursor();
  lcd.setCursor(0, 1);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT); // sets the digital pin as output
  pinMode(LED_GREEN, OUTPUT); // sets the digital pin as output
  //  CONFIGURAÇÃO DO PASSWORD

  while (situacao == 0) {
    if (keyboard.available()) {
      digito = char(keyboard.read());
      pwd[i] = char(digito);


      if (digito == PS2_ENTER)
      {
        pwd[i] = '\0';
        Serial.println(pwd);
        key = String(pwd);
        Serial.println("pwd=");
        Serial.print(pwd);
        lcd.clear();
        situacao = 1;
      }
      if (digito != '13') {
        lcd.print(digito);
      }
      i++;
    }
    else {
      delay(1);
    };
  }

  lcd.noCursor();
  lcd.clear();
  lcd.print("PWD DEFINIDO");
  lcd.setCursor(0, 1);
  lcd.print(pwd);
  delay(2000);
  lcd.clear();
  lcd.print("DEFINIR MINUTOS");
  lcd.setCursor(0, 1);
  i = 0;
  //  CONFIGURAÇÃO DO TEMPO

  while (situacao == 1) {
    if (keyboard.available()) {
      digito = char(keyboard.read());
      tmp[i] = digito;
      Serial.print("tempo=");
      Serial.println(tmp[i]);

      if (digito == PS2_ENTER)
      {
        tmp[i] = '\0';
        Serial.print(tmp);
        lcd.print(tmp);
        timerSeconds = ((String(tmp).toInt()) * 60);
        lcd.clear();
        situacao = 2;
      }
      if (digito != '13') {
        lcd.print(digito);
      }
      i++;
    }
    else {
      delay(1);
    }
  }

  lcd.noCursor();
  lcd.clear();
  lcd.print("TEMPO DEFINIDO");
  lcd.setCursor(0, 1);
  lcd.print(timerSeconds / 60);
  lcd.print(" minutos");
  delay(2000);
  lcd.noCursor();
  lcd.clear();
  // Contagem Regressiva para começar o jogo
  for (loops = 5; loops > 0; loops--) {
    lcd.setCursor(0, 0);
    lcd.print("Iniciando em:");
    lcd.setCursor(14, 0);
    lcd.print(loops);
    tone(SPKRPin, 2000, 30);
    delay(1000);
    lcd.clear();
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DIGITE O CODIGO");
  lcd.cursor();
  lcd.setCursor(0, 0);
  i=0;
}
void loop() {
  if (keyboard.available()) {
      lcd.setCursor(0, 0);
      Serial.print("               ");

    digito = char(keyboard.read());
    entered[currentLength] = char(digito);

    if (digito == PS2_ENTER)    {
      entered[currentLength] = '\0';
      lcd.setCursor(0, 0);
      Serial.println(entered);
      key = entered;
      lcd.clear();
    
      if (String(entered) == String(pwd)) { // shortcut to compare an array of bytes, use memcmp(A, B, length), will return 0 if match.

        lcd.noCursor();
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("BOMBA");
        lcd.setCursor(3, 0);
        lcd.print("DESARMADA!");
        
        tone(SPKRPin, 600, 300); //
        delay(200);
        tone(SPKRPin, 1200, 500); //
        delay(200);        
        tone(SPKRPin, 2400, 700); //
        delay(200);        
        tone(SPKRPin, 600, 300); //
        delay(200);        
        tone(SPKRPin, 1200, 500); //
        delay(200);        
        tone(SPKRPin, 2400, 700); //
        delay(200);
        
        delay(10000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" [OK, BOM DIA!]");
        delay(5000);
        lcd.setCursor(0, 0 );
        lcd.print("REINICIANDO!   ");
        currentLength = 0;
        delay(1000); // hold that on screen for 2.5 seconds

        
        for (loops = 30; loops > 0; loops--) {
          lcd.setCursor(0, 0 );
          lcd.print("REINICIANDO!   ");

          lcd.setCursor(0,1);          
          lcd.print(" EM:");
          lcd.setCursor(5, 1);
          lcd.print(loops);
          tone(SPKRPin, 200, 30);
          delay(1000);
          lcd.clear();
        }
        
        lcd.clear();
        currentLength = 0;
        software_Reset();
        

      } else if (entered != pwd) {
        if(qntErros==0){
          msgErro();
          lcd.print("PENALIDADE: 50%"); // Display time penalty
          if (timerSeconds > 60) timerSeconds -= timerSeconds/2;
          else timerSeconds = 1; // will trigger BOOM next cycle
          currentLength = 0;
          delay(2500); // hold that on screen for 2.5 seconds
          lcd.clear();
          situacao = 3;
          lcd.setCursor(0,0);
          lcd.print("DIGITE O CODIGO");
          qntErros+=1;
          
        }else if(qntErros==1){
         msgErro();
         interval=50; 
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("DIGITE O CODIGO*");
         qntErros+=1;
         situacao = 3;
        }else if(qntErros==2){
          timerSeconds=1;
        }
        
      i = 0;// Reiniciando posicionamento (para o loop)
      currentLength=0; //Reiniciando a coleta de dados do teclado para a variável


      }

    }else if (digito != PS2_ENTER) {
      lcd.setCursor(i, 0);
      lcd.print("*              ");

//      lcd.print(digito);
      i++;
      currentLength++;
      tone(SPKRPin, 500,10); // play bleep for 50ms
    }

  }
 timer();
}
void msgErro(){
   lcd.noCursor();
   lcd.clear();
   lcd.print(" ERRO! ");
   tone(SPKRPin, 300, 20);
   lcd.setCursor(0, 1);
}
void presentTime(void){ // registra o tempo presente quando solicitado
    present = millis()/1000;
    return;
}

void timer() {
  long tempoAtual=millis();
  
  if(tempoAtual - previousMillis > interval) {
     previousMillis = tempoAtual; 
      
  lcd.setCursor(0, 1); // sets cursor to 2nd line
  lcd.print(" Tempo: ");
  lcd.print(timerSeconds / 60); // integer number of minutes on clock
  lcd.print("m");
  lcd.print(timerSeconds % 60); // mod 60; gives us number of seconds outside of 60sec/min
  lcd.print("s        ");
  long tempoAtual=millis();
 // delay(950); // hold us here for 0.950 seconds
  {
    digitalWrite(LED_RED, !digitalRead(LED_RED)); // toggle the green LED once a second
  }
 // tone(SPKRPin, 50, 100); // play bleep for 50ms
//  delay(5); // and there's the rest of that 1 second (not counting LCD delay)
  timerSeconds--;

  if (timerSeconds == 0) explodeBomb();
    }
}

void explodeBomb() {
  // routine for making ze BOMB GOEZ OFF!!!1 :D
  lcd.noCursor();
  lcd.clear();
  lcd.print("*-BoOo0o0o0oMm-*");
  lcd.setCursor(0, 1);
  lcd.print(" SOLDADO MORTO!");
  tone(SPKRPin, 150, 100);
  digitalWrite(LED_RED, HIGH); // sets the red LED on
  delay(500); // waits half a second
  tone(SPKRPin, 110, 100);
  delay(500); // waits half a second
  digitalWrite(LED_RED, LOW); // sets the red LED off
  digitalWrite(LED_GREEN, HIGH); // sets the green LED on
  tone(SPKRPin, 150, 100);
  delay(500); // waits half a second
  digitalWrite(LED_RED, HIGH); // sets the red LED on
  digitalWrite(LED_GREEN, LOW); // sets the green LED off
  tone(SPKRPin, 110, 100);
  delay(500); // waits half a second
  digitalWrite(LED_RED, LOW); // sets the red LED off
  digitalWrite(LED_GREEN, HIGH); // sets the green LED on
  tone(SPKRPin, 150, 100);
  delay(500); // waits half a second

  key = ""; // enter the while() loop, otherwise it'll skip. i could use do { } while();, but I'm lazy.
  {
    while (key==""){
      
      if (keyboard.available()) {

        digito = char(keyboard.read());
        
      
      if (digito==PS2_ESC)
      {
        lcd.clear();
        lcd.print("Reiniciando:");
        lcd.setCursor(6, 1);
        lcd.print("a bomba!");
        delay(3000); //  3 sec delay
        void (*softReset) (void) = 0; //declare reset function @ address 0
        softReset();
        //timerSeconds = 300; // put 5 minutes on the clock
        // and we break the loop and go back to timer.
      }
      else  key = ""; // continue looking for pound key
      }
    }
  }
}

void software_Reset() // Reinicia o software para o primeiro estágio, mas não reinicia os periféricos nem registros
{
  asm volatile ("  jmp 0");
}

void rebootMe(int tempo){
   if (keyboard.available()) {
    digito = char(keyboard.read());
 if (digito == PS2_ENTER)
    {
      verifica[i] = '\0';
      Serial.println(verifica);
      key = String(verifica);
      Serial.println("verifica=");
      Serial.println(verifica);
      lcd.clear();
      situacao = 4;

    }
}
}
void tecladoIn() {
  if (keyboard.available()) {
    digito = char(keyboard.read());
    verifica[i] = char(digito);
    Serial.print("verifica=");
    Serial.println(verifica[i]);

    if (digito == PS2_ENTER)
    {
      verifica[i] = '\0';
      Serial.println(verifica);
      key = String(verifica);
      Serial.println("verifica=");
      Serial.println(verifica);
      lcd.clear();
      situacao = 4;

    }
    if (digito != '13') {
      lcd.print(digito);
    }
    i++;
  }
}
