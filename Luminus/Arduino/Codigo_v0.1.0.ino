#include <Adafruit_NeoPixel.h> //
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include <SoftwareSerial.h>


#define num_pixels 60
#define EN_Bluetooth 9


SoftwareSerial BTSerial(10, 11); // RX, TX
Adafruit_NeoPixel fitaLeds = Adafruit_NeoPixel(num_pixels, 8, NEO_GRB + NEO_KHZ800);
String pacote = "";




void setup() {
  Serial.begin(9600);

  //CONFIGURACOES BLUETOOTH
  pinMode(EN_Bluetooth, OUTPUT);
  digitalWrite(EN_Bluetooth, HIGH);
  Serial.begin(9600);
  BTSerial.begin(38400);

  //CONFIGURACOES FITA DE LEDS
  fitaLeds.begin();
  fitaLeds.show();
}

void loop() {
  while (BTSerial.available()) {
    BTSerial.flush();
    pacote = Serial.readString();
    Serial.println(pacote);
    //Serial.findUntil()
  }
//    char character = BTSerial.read(); // Receive a single character from the software serial port
//    pacote.concat(character); // Add the received character to the receive buffer
//    if (character == '\n') {
//        Serial.print("Received: ");
//        Serial.println(pacote);
//        pacote = "";
//    }
//  }
  //atualizarFita();
  //intensidadeBrilho();
}

void atualizarFita(uint8_t vermelho, uint8_t verde, uint8_t azul) {
  for (int pixel = 0; pixel < num_pixels; pixel++) {
    fitaLeds.setPixelColor(pixel, vermelho, verde, azul);
  }
  fitaLeds.show();
}

void intensidadeBrilho(uint8_t brilho) {
  fitaLeds.setBrightness(brilho);
}
