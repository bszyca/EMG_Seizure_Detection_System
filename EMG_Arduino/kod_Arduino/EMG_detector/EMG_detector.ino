#include <filters.h>
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX

const float cutoff_freq   = 150.0;   //czestotliwosc graniczna 
const float sampling_time = 0.001; //probkowanie

//FILTR
Filter fhp(cutoff_freq, sampling_time, IIR::ORDER::OD2, IIR::TYPE::HIGHPASS);

unsigned long time1, time2;
float raw_volt;
float raw_sign;
float filt_sign;
int zero_counter = 0;

int i = 0;
int j = 0;

void setup(){
 Serial.begin(115200);
 BTserial.begin(9600);
 Serial.println();
 pinMode(A0, INPUT);

 noInterrupts();// wyłacza wszystkie przerwania
 TCCR1A = 0; // reset rejestru
 TCCR1B = 0; // reset rejestru
 TCNT1 = 0; 
 OCR1A = 1959; // obliczona wartosc z:  16MHz / (presclaer * freq) - 1
 TCCR1B |= (1 << WGM12); // właczenie trybu CTC 
 TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10); // preskaler = 8
 TIMSK1 |= (1 << OCIE1A); 
 interrupts();//włącza wszystkie przerwania
}

//przerwanie
ISR(TIMER1_COMPA_vect) 
{
 raw_sign = analogRead(0);
}

void loop(){

float buff[100];
raw_volt = ((raw_sign*5 /1023)-2.4)*10;

if(j<100)
 {

   filt_sign = fhp.filterIn(raw_volt);
   buff[j] = filt_sign;
   

   if (j >= 25)
      {
        if (j < 75)
        {
          buff[j] = buff[j + 25];
        }
        else
        {
          buff[j] = filt_sign;
        }
      }

      // Histereza
      if ((buff[j] > 0.035 && buff[j+1] > 0.035 )||(buff[j] < -0.35 && buff[j+1] < -0.035 ))
      {
        zero_counter += 1;
        Serial.print("Detekcja: ");
        Serial.print(zero_counter);
        Serial.print(",");
        if (zero_counter >= 10)
        {
          Serial.println("ALARM");
          BTserial.println("alarm");
        }
      }

 j+=1;
 }
 else 
 {
  j = 0;
  zero_counter = 0;
 }
}
