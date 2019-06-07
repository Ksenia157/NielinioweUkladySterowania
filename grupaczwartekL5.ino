#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
#define X_CS_PIN         53
#endif
#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
#define Y_CS_PIN         49
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
#define Z_CS_PIN         40
#endif
#ifndef X_MAX_PIN
#define X_MAX_PIN         2
#endif

#define Y_MAX_PIN          15

#define Z_MAX_PIN          19
bool flaga = 0;
int licznik = 0;
int kierx = 0, kiery = 0, kierz = 0;
String wiadomosc;
int krokix=0, krokiy= 0, krokiz= 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, LOW);
  pinMode(X_STEP_PIN, OUTPUT);

  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, LOW);
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, LOW);
  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:


  //Serial.println(digitalRead(X_MAX_PIN));

  while(Serial.available() > 0)
  {
    wiadomosc= Serial.readStringUntil('\n');
    sscanf(wiadomosc.c_str(), "x %d y %d z %d", &krokix, &krokiy, &krokiz);
    flaga=1;
    //Serial.print(krokix); Serial.print(" ");
    //Serial.print(krokiy); Serial.print(" ");
    //Serial.print(krokiz); Serial.println("");
    
    kierx = (krokix < 0);
    digitalWrite(X_DIR_PIN, kierx);
    krokix = abs(krokix);

    kiery = krokiy < 0;
    digitalWrite(Y_DIR_PIN, kiery);
    krokiy = abs(krokiy);

    kierz = krokiz < 0;
    digitalWrite(Z_DIR_PIN, kierz);
    krokiz = abs(krokiz);
    
    
  }

  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  
  delay(1);
  if ((digitalRead(X_MAX_PIN) == 0 || kierx == 1) && krokix > 0)
  {
    digitalWrite(X_STEP_PIN, HIGH);
    krokix--;
  }
  if ((digitalRead(Y_MAX_PIN) == 0 || kiery == 1) && krokiy > 0)
  {
    digitalWrite(Y_STEP_PIN, HIGH);
    krokiy--;
  }
  if ((digitalRead(Z_MAX_PIN) == 0 || kierz == 1) && krokiz > 0)
  {
    digitalWrite(Z_STEP_PIN, HIGH);
    krokiz--;
  }
  delay(1);
  if ((krokix && krokiy && krokiz) == 0 && flaga == 1)
  
  {
   Serial.println("DONE");
    flaga=0;
      
  }

  
  //licznik++;
  //if(licznik == 200)
  //{
  //  kierunek = ! kierunek;
  //  digitalWrite(X_DIR_PIN,kierunek);
  //  digitalWrite(Y_DIR_PIN,kierunek);
  //  digitalWrite(Z_DIR_PIN,kierunek);
  //  licznik = 0;
  //}
}
