#include <Arduino.h>
#include <WiFi.h>

#include <AudioOutputI2S.h>
#include <AudioGeneratorMIDI.h>
#include "AudioFileSourcePROGMEM.h"

#include "sf2.h"

#include "yixiaojianghu.h"
#include "youhebuke.h"
#include "flowerdance.h"
#include "mid.h"
#include "lemontree.h"
#include "tiantiande.h"
#include "mid_gaobai.h"
#include "mid_alice.h"

#include  "readfile.h"
#include "String.h"
#include <Ticker.h>
#include "I2S.h"


Ticker runner;
AudioFileSourcePROGMEM *sf2;
AudioFileSourcePROGMEM *mid;

AudioOutputI2S *dac;
AudioGeneratorMIDI *midi;

int A;

// 告白气球：25050
// 有何不可：16000
// 致爱丽丝：12000
// 其他都是：22050
const int frequency_Do = 261.6;    // frequency of square wave in Hz
const int frequency_Ri = 293.6;    // frequency of square wave in Hz
const int frequency_Mi = 329.6;    // frequency of square wave in Hz
const int frequency_Fa = 349.2;    // frequency of square wave in Hz
const int frequency_So = 392;    // frequency of square wave in Hz
const int frequency_La = 440;    // frequency of square wave in Hz
const int frequency_Xi = 493.8;    // frequency of square wave in Hz
const int frequency_Do2 = 600;    // frequency of square wave in Hz
const int amplitude = 300;    // amplitude of square wave
const int sampleRate = 16000; // sample rate in Hz

int32_t sample = amplitude;  // current sample value
int count = 0;
int32_t sample_recall= 0;
int  halfWavelength = 0;
int  frequency_recall = 0;

void run(){

  midi->loop();
}


void setup()
{
  


  Serial.begin(115200);
  //读取目前的乐曲库序号
  if (!LittleFS.begin(true, "/lfs2", 5, "spiffs")) {
    Serial.println("Mount Failed");
    return;
  }
  A = readFile(LittleFS, "/numofmusic.txt");
  Serial.println(A);

  if (A == 48){
    mid = new AudioFileSourcePROGMEM(mid_alice, sizeof(mid_alice));
  WiFi.mode(WIFI_OFF); 
  Serial.println("Starting up...\n");
  pinMode(3,INPUT);pinMode(10,INPUT);
  pinMode(20,OUTPUT);
  digitalWrite(20,LOW);
  audioLogger = &Serial;
  sf2 = new AudioFileSourcePROGMEM(sf2_h, sizeof(sf2_h));

  dac = new AudioOutputI2S();
  midi = new AudioGeneratorMIDI();
  midi->SetSoundfont(sf2);
  midi->SetSampleRate(22050);
  Serial.printf("BEGIN...\n");
  midi->begin(mid, dac);
  runner.attach_ms(0.1,run);  

  }
  else if(A==49){

    mid = new AudioFileSourcePROGMEM(yixiaojianghu_h, sizeof(yixiaojianghu_h));
    WiFi.mode(WIFI_OFF); 
  Serial.println("Starting up...\n");
  pinMode(3,INPUT);pinMode(10,INPUT);
  pinMode(20,OUTPUT);
  digitalWrite(20,LOW);
  audioLogger = &Serial;
  sf2 = new AudioFileSourcePROGMEM(sf2_h, sizeof(sf2_h));

  dac = new AudioOutputI2S();
  midi = new AudioGeneratorMIDI();
  midi->SetSoundfont(sf2);
  midi->SetSampleRate(22050);
  Serial.printf("BEGIN...\n");
  midi->begin(mid, dac);
  runner.attach_ms(0.1,run);
  }
  else if (A==50){

    mid = new AudioFileSourcePROGMEM(flowerdance_h, sizeof(flowerdance_h));
  WiFi.mode(WIFI_OFF); 
  Serial.println("Starting up...\n");
  pinMode(3,INPUT);pinMode(10,INPUT);
  pinMode(20,OUTPUT);
  digitalWrite(20,LOW);
  audioLogger = &Serial;
  sf2 = new AudioFileSourcePROGMEM(sf2_h, sizeof(sf2_h));

  dac = new AudioOutputI2S();
  midi = new AudioGeneratorMIDI();
  midi->SetSoundfont(sf2);
  midi->SetSampleRate(22050);
  Serial.printf("BEGIN...\n");
  midi->begin(mid, dac);
  runner.attach_ms(1,run);
  }
  else if (A==51){

    mid = new AudioFileSourcePROGMEM(mid_gaobai, sizeof(mid_gaobai));
  WiFi.mode(WIFI_OFF); 
  Serial.println("Starting up...\n");
  pinMode(3,INPUT);pinMode(10,INPUT);
  pinMode(20,OUTPUT);
  digitalWrite(20,LOW);
  audioLogger = &Serial;
  sf2 = new AudioFileSourcePROGMEM(sf2_h, sizeof(sf2_h));

  dac = new AudioOutputI2S();
  midi = new AudioGeneratorMIDI();
  midi->SetSoundfont(sf2);
  midi->SetSampleRate(25050);
  Serial.printf("BEGIN...\n");
  midi->begin(mid, dac);
  runner.attach_ms(1,run);
  }
  else if (A==52){

   mid = new AudioFileSourcePROGMEM(youhebuke_h, sizeof(youhebuke_h));
  WiFi.mode(WIFI_OFF); 
  Serial.println("Starting up...\n");
  pinMode(3,INPUT);pinMode(10,INPUT);
  pinMode(20,OUTPUT);
  digitalWrite(20,LOW);
  audioLogger = &Serial;
  sf2 = new AudioFileSourcePROGMEM(sf2_h, sizeof(sf2_h));

  dac = new AudioOutputI2S();
  midi = new AudioGeneratorMIDI();
  midi->SetSoundfont(sf2);
  midi->SetSampleRate(16000);
  Serial.printf("BEGIN...\n");
  midi->begin(mid, dac);
  runner.attach_ms(0.1,run);
  }
  else if (A==53){

   mid = new AudioFileSourcePROGMEM(tiantiande_h, sizeof(tiantiande_h));
  WiFi.mode(WIFI_OFF); 
  Serial.println("Starting up...\n");
  pinMode(3,INPUT);pinMode(10,INPUT);
  pinMode(20,OUTPUT);
  digitalWrite(20,LOW);
  audioLogger = &Serial;
  sf2 = new AudioFileSourcePROGMEM(sf2_h, sizeof(sf2_h));

  dac = new AudioOutputI2S();
  midi = new AudioGeneratorMIDI();
  midi->SetSoundfont(sf2);
  midi->SetSampleRate(22050);
  Serial.printf("BEGIN...\n");
  midi->begin(mid, dac);
  runner.attach_ms(0.1,run);
  }
  else if (A==54){

   mid = new AudioFileSourcePROGMEM(lemontree_h, sizeof(lemontree_h));
  WiFi.mode(WIFI_OFF); 
  Serial.println("Starting up...\n");
  pinMode(3,INPUT);pinMode(10,INPUT);
  pinMode(20,OUTPUT);
  digitalWrite(20,LOW);
  audioLogger = &Serial;
  sf2 = new AudioFileSourcePROGMEM(sf2_h, sizeof(sf2_h));

  dac = new AudioOutputI2S();
  midi = new AudioGeneratorMIDI();
  midi->SetSoundfont(sf2);
  midi->SetSampleRate(30000);
  Serial.printf("BEGIN...\n");
  midi->begin(mid, dac);
  runner.attach_ms(0.1,run);
  }
  else if (A==55){

   mid = new AudioFileSourcePROGMEM(mid_h, sizeof(mid_h));
  WiFi.mode(WIFI_OFF); 
  Serial.println("Starting up...\n");
  pinMode(3,INPUT);pinMode(10,INPUT);
  pinMode(20,OUTPUT);
  digitalWrite(20,LOW);
  audioLogger = &Serial;
  sf2 = new AudioFileSourcePROGMEM(sf2_h, sizeof(sf2_h));

  dac = new AudioOutputI2S();
  midi = new AudioGeneratorMIDI();
  midi->SetSoundfont(sf2);
  midi->SetSampleRate(22050);
  Serial.printf("BEGIN...\n");
  midi->begin(mid, dac);
  runner.attach_ms(0.1,run);
  }
  
  else if (A==56){

    

    pinMode(21,OUTPUT);
    digitalWrite(21,LOW);
    I2S.setSckPin(2);
  I2S.setFsPin(0);
  I2S.setDataPin(1);
  I2S.setSimplex();

  // start I2S at the sample rate with 16-bits per sample
  if (!I2S.begin(I2S_PHILIPS_MODE, sampleRate, 16)) {
    while (1);  // do nothing
  }

  pinMode(3,INPUT); 
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);

  }
  else{

    writeFile(LittleFS, "/numofmusic.txt","0");
    mid = new AudioFileSourcePROGMEM(mid_h, sizeof(mid_h));

  }
  
  


}


void loop()
{
  // midi->loop();
  // if (midi->isRunning()) {
  //   if (!midi->loop()) {
  //     uint32_t e = millis();
  //     midi->stop();
  //   }
  // } else {
  //   Serial.printf("MIDI done\n");
  //   delay(1000);
  // }

  if (digitalRead(3)==HIGH&&digitalRead(10)==HIGH){
    Serial.println(A);
    A = A -48 +1 ;
    if (A >8){
      A = 0;
    }
    Serial.println(A);
    const char* ch = (String(A).c_str());
    Serial.println(String(A).c_str());
    writeFile(LittleFS, "/numofmusic.txt",String(A).c_str());
    ESP.restart(); 
  }
  
  if (A==56){
  int frequency = 0;
  int time =0;
  int x = 0;
  if (digitalRead(3) == HIGH){
     frequency = frequency + frequency_Do;
     time++;
  }



  if (digitalRead(4) == HIGH){
     frequency = frequency + frequency_Ri;
     time++;
  }

  if (digitalRead(5) == HIGH){
     frequency = frequency + frequency_Mi;
     time++;
  }


  if (digitalRead(6) == HIGH){
     frequency = frequency + frequency_Fa;
     time++;
  }


  if (digitalRead(7) == HIGH){
     frequency = frequency + frequency_So;
     time++;
  }


  if (digitalRead(8) == LOW){
     frequency = frequency + frequency_La;
     time++;
  }



  if (digitalRead(9) == HIGH){
     frequency = frequency + frequency_Xi;
     time++;
  }


  if (digitalRead(10) == HIGH){
     frequency = frequency + frequency_Do2;
     time++;
  }


  if (frequency != 0) {
      frequency = frequency / time;
      halfWavelength = (sampleRate / frequency);

      if (count % halfWavelength == 0) {
    // invert the sample every half wavelength count multiple to generate square wave
      sample = -1 *sample;
      }
      I2S.write(sample);  // Left channel
      I2S.write(sample);  // Right channel
      sample_recall = sample;
      frequency_recall = frequency;
  }else{
      if (sample_recall >0){
        sample_recall = sample_recall-0.0001;
        }
        else{
          sample_recall =0;
        }
    halfWavelength = (sampleRate / frequency_recall);
    if (count % halfWavelength == 0) {
      
    // invert the sample every half wavelength count multiple to generate square wave
      sample_recall = -1 *sample_recall;
      }
      I2S.write(sample_recall);  // Left channel
      I2S.write(sample_recall);  // Right channel
    

  }

    
    count++;
  }

}
