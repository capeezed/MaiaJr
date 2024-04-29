
  //variaveis
  #define pino1 6
  #define pino2 5
  #define ent1 13
  #define ent2 12
  #define ent3 3
  #define ent4 4
  #define trig1 10
  #define ech1 9
  #define trig2 2
  #define ech2 7
  #define trig3 8
  #define ech3 11
  int distancia_E, distancia_C, distancia_D;
  const int alertadis = 15;

  //funcoes
  int getd1();
  int getd2();
  int getd3();
  void acelerar();
  void parar();
  void re();
  void esquerda();
  void direita();

  void setup()
  {

    Serial.begin(9600);
    Serial.println("Sistemas iniciando...");
    pinMode(pino1, OUTPUT);
    pinMode(pino2, OUTPUT);
    pinMode(ent1, OUTPUT);
    pinMode(ent2, OUTPUT);
    pinMode(ent3, OUTPUT);
    pinMode(ent4, OUTPUT);
    pinMode(trig1,OUTPUT);
    pinMode(trig2, OUTPUT);
    pinMode(trig3,OUTPUT);
    pinMode(ech1,INPUT);
    pinMode(ech2,INPUT);
    pinMode(ech3,INPUT);

  }


  void loop()
  {

  distancia_E = getd1();
  distancia_C = getd2();
  distancia_D = getd3();

    if((distancia_D <= alertadis) && (distancia_D > 5)) {
          esquerda();
    }

      else if((distancia_C <= alertadis) && (distancia_C > 5)) {
          esquerda();
    }
      
        else if((distancia_E <= alertadis) && (distancia_E > 5)) {
          direita();
    }
    
        else if((distancia_E > alertadis) && (distancia_C > alertadis) && (distancia_D > alertadis) ){
          acelerar();
    }
	
  }

  int getd1()
  {
    int distancia, duration;
    digitalWrite(trig1,LOW);
    digitalWrite(trig1, HIGH);
    delayMicroseconds(2);
    digitalWrite(trig1,LOW);
    duration = pulseIn(ech1,HIGH);
    distancia = duration / 58.2;

    return distancia;
  }

  int getd2()
  {
    int distancia, duration;
    digitalWrite(trig2,LOW);
    digitalWrite(trig2, HIGH);
    delayMicroseconds(2);
    digitalWrite(trig2,LOW);
    duration = pulseIn(ech2,HIGH);
    distancia = duration / 58.2;

    return distancia;
  }

  int getd3()
  {
    int distancia, duration;
    digitalWrite(trig3,LOW);
    digitalWrite(trig3, HIGH);
    delayMicroseconds(2);
    digitalWrite(trig3,LOW);
    duration = pulseIn(ech3,HIGH);
    distancia = duration / 58.2;

    return distancia;
  }

  void acelerar()
  {
    analogWrite(pino1, 500);
    analogWrite(pino2, 500);
    digitalWrite(ent1, LOW);
    digitalWrite(ent2, HIGH);
    digitalWrite(ent3, HIGH);
    digitalWrite(ent4, LOW);

  }

  void parar()
  {

    analogWrite(pino1, 500);
    analogWrite(pino2, 500);
    digitalWrite(ent1,LOW);
    digitalWrite(ent2,LOW);
    digitalWrite(ent3,LOW);
    digitalWrite(ent4,LOW);

  }

  void re()
  {
    
    analogWrite(pino1, 500);
    analogWrite(pino2, 500);
    digitalWrite(ent1,HIGH);
    digitalWrite(ent2,LOW);
    digitalWrite(ent3,LOW);
    digitalWrite(ent4,HIGH);

  }

  void direita()
  {
    
    analogWrite(pino1, 500);
    analogWrite(pino2, 500);
    digitalWrite(ent1,LOW);
    digitalWrite(ent2,HIGH);
    digitalWrite(ent3,LOW);
    digitalWrite(ent4,LOW);

    }

  void esquerda()
  {
    
    analogWrite(pino1, 500);
    analogWrite(pino2, 500);
    digitalWrite(ent1,LOW);
    digitalWrite(ent2,LOW);
    digitalWrite(ent3,HIGH);
    digitalWrite(ent4,LOW);
      
    }
