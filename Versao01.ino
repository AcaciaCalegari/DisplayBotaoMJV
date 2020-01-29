//===============================================================
//Esse codg pertence a Empresa MJV Technology & Innovation
//https://www.mjvinnovation.com/get-in-touch/
//Desenvolvido no Rio de Janeiro para ser Executado em Portugal
//AcaciaCalegari
//16/01/2020
//===============================================================

//Ao apertar o botão aparecem ícones personalizados
//DisplayRG1602A

#include <LiquidCrystal.h>

//os pinos do Display: VSS,RW,K estão ligados no terra(GND)
//os pinos do Display : VDD, A estão ligados em 5vcc
//Ligar um resistor em 5vcc do pino digital 10 e no botão, tudo no mesmo contato

int V0 = 3; //V0 do display no pino 3 digital do arduino p controlar contrast
int RS = 4; //RS do display no pino 4 dgtal do arduino p comandos do display
int E = 5; // E do display no pino 5 dgtal do arduino, e assim sucessivamente
int D4 = 6;
int D5 = 7;
int D6 = 8;
int D7 = 9;
int buttonPin = 10; //Botão ligado ao pino 10 digital
int buttonState = 0;
int ativado = 0;

LiquidCrystal lcd(RS, E, D4, D5, D6 , D7); //pinos do lcd q ligay no arduino

//Fazer o símbolo personalizado do V de Verificado
 byte a[8] = {
  B00000,
  B00000,
  B00001,
  B00011,
  B00111,
  B01110,
  B11100,
  B11000
};

byte b[8] = {
  B11100,
  B11000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte c[8] = {
  B11000,
  B11100,
  B01110,
  B00111,
  B00011,
  B00001,
  B00000,
  B00000
};

byte d[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10001,
  B11011,
  B11111,
  B01010
};

byte e[8] = {
  B00011,
  B00111,
  B01110,
  B11100,
  B11000,
  B10000,
  B00000,
  B00000
};




void setup() {
    Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  
  
  analogWrite(V0,130);//definicao do contraste p evitar potenciometro
  lcd.begin(16, 2);//16 catacteres em 2 linhas, parte de cima e dbaixo

  lcd.setCursor(0,0); //onde comeca o texto de cima
  lcd.print("    LAVAR A"); //msg da parte de cima do display
  lcd.setCursor(0,1); //onde comeca o txt dbaixo
  lcd.write("     LOICA"); // msg da parte dbaixo do display
}


//Fica mostrando a msg acima, mas a Partir do momento que o botão é apertado aparecem ícones



void loop() {
buttonState = digitalRead(buttonPin);
Serial.println(buttonState);

  // verifica se o botão está pressionado. Se for, o buttonState é HIGH:
  if (buttonState == HIGH) {
    if(ativado == 0){
      animation();
      ativado = 1;
      }
  }
}

void animation(){
  lcd.clear();

//troca a letra dos bytes por numeros, o arduino só permite 8bytes personalizados

  lcd.createChar(0,a);
  lcd.createChar(1,b);
  lcd.createChar(2,c);
  lcd.createChar(3,d);
  lcd.createChar(4,e);
 
  lcd.setCursor(9,0);
  lcd.write(byte(0));
  lcd.setCursor(10,0);
  lcd.write(1);
  lcd.setCursor(6,1);
  lcd.write(2);
  lcd.setCursor(7,1);
  lcd.write(3);
  lcd.setCursor(8,1);
  lcd.write(4);

  

  delay(2000);
  lcd.clear();
  delay(1000);

//Fazer a Carinha Sorrindo

  byte a[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00001,
  B00001,
  B00011,
  B00011
};

byte b[8] = {
  B00000,
  B00011,
  B01111,
  B11111,
  B11111,
  B10011,
  B10011,
  B11111
};

byte c[8] = {
  B00000,
  B11000,
  B11110,
  B11111,
  B11111,
  B11001,
  B11001,
  B11111
};

byte d[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
  B10000,
  B11000,
  B11000
};

byte e[8] = {
  B00011,
  B00011,
  B00001,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000
};

byte f[8] = {
  B11111,
  B11111,
  B11011,
  B11100,
  B11111,
  B01111,
  B00011,
  B00000
};

byte g[8] = {
  B11111,
  B11111,
  B11011,
  B00111,
  B11111,
  B11110,
  B11000,
  B00000
};

byte h[8] = {
  B11000,
  B11000,
  B10000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000
};

//troca a letra dos bytes por numeros, o arduino só permite 8bytes personalizados
  lcd.createChar(0,a);
  lcd.createChar(1,b);
  lcd.createChar(2,c);
  lcd.createChar(3,d);
  lcd.createChar(4,e);
  lcd.createChar(5,f);
  lcd.createChar(6,g);
  lcd.createChar(7,h);
 
//chama os bytes para aparecerem do display RG1602A
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.setCursor(7,0);
  lcd.write(1);
  lcd.setCursor(8,0);
  lcd.write(2);
  lcd.setCursor(9,0);
  lcd.write(3);
  lcd.setCursor(6,1);
  lcd.write(4);
  lcd.setCursor(7,1);
  lcd.write(5);
  lcd.setCursor(8,1);
  lcd.write(6);
  lcd.setCursor(9,1);
  lcd.write(7);
  
  
  }
