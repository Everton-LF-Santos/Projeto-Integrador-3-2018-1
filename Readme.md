# Index
- [Motiva��o](#motiva��o)
- [Introdu��o](#introdu��o)
	- [O Cultivo de Cogumelos](#o-cultivo-de-cogumelos)
	- [O Protocolo MQTT](#o-protocolo-mqtt)
 - [Sensoreamento](#sensoreamento)
 - 
 - [Testes](#testes)
 - [Softwares](#softwares)
	 - [Firmware do ESP8266](#firmware-do-esp8266)
# Motiva��o

O intuito  � projetar e desenvolver uma estufa para cultuvo de cogumelos de modo descentralizado e utilizando o protocolo MQTT para comunica��o via Wi-Fi.
Inicialmente ser� feito um prot�tipo de um modelo menor e ser� deixado como uma base para se poder expandir futuramente.

# Introdu��o

## O Cultivo de Cogumelos

## O Protocolo MQTT
**MQTT**, acr�nimo de Message Queuing Telemetry Transport (anteriormente conhecido como _MQ Telemetry Transport_), � um protocolo de mensagens leve para sensores e pequenos dispositivos m�veis otimizado para redes TCP/IP n�o confi�veis ou de alta lat�ncia. O esquema de troca de mensagens � fundamentado no modelo de publica��o e assinatura.

O MQTT � um protocolo de rede leve e flex�vel que oferece o equil�brio ideal para os desenvolvedores de IoT. O protocolo leve permite a implementa��o em hardware de dispositivo altamente restringido e em redes de largura da banda limitada e de alta lat�ncia e sua flexibilidade possibilita o suporte a diversos cen�rios de aplicativo para dispositivos e servi�os de IoT.

O protocolo MQTT define dois tipos de entidades na rede: um message broker e in�meros clientes. O broker � um servidor que recebe todas as mensagens dos clientes e, em seguida, roteia essas mensagens para os clientes de destino relevantes. Um cliente � qualquer coisa que possa interagir com o broker e receber mensagens. Um cliente pode ser um sensor de IoT em campo ou um aplicativo em um data center que processa dados de IoT.

1.  O cliente conecta-se ao broker. Ele pode assinar qualquer "t�pico" de mensagem no broker. Essa conex�o pode ser uma conex�o TCP/IP simples ou uma conex�o TLS criptografada para mensagens sens�veis.
2.  O cliente publica as mensagens em um t�pico, enviando a mensagem e o t�pico ao broker.
3.  Em seguida, o broker encaminha a mensagem a todos os clientes que assinam esse t�pico. 

![mqtt1](https://www.ibm.com/developerworks/library/iot-mqtt-why-good-for-iot/image1.png)
[[Source]](https://www.ibm.com/developerworks/br/library/iot-mqtt-why-good-for-iot/)

# Sensoreamento
## Componentes
- **Micrcontrolador**: ESP8266
- **Sensor de temperatura**: DHT22 
- **Sensor de umidade**: DHT22 
- **Sensor de G�s Carb�nico**: MQ135
- **Ventila��o**: Mini Ventilador
- **Aquecimento**: Resistores de Pot�ncia
- **Umidifica��o**: Umidificador Ultrass�nico "Fogger"
- **Ilumina��o**: Led 460nm

### ESP8266
O ESP8266 � um microcontrolador de baixo custo da fabricante chin�sa Espressif que inclui capacidade de comunica��o por Wi-Fi. � um microcontrolador de 32 bits e que possui uma grande variedade de m�dulos. O m�dulo empregado para esse projeto foi o Kit de Desenvolvimento Node-MCU.

<img src="https://cdn.shopify.com/s/files/1/0672/9409/products/NodeMCU_ESP8266_development_board_1024x1024.jpg" width="200" />

### DHT22
O DHT22 � um sensor de temperatura e umidade que usa comunica��o One-Wire. Este sensor foi escolhido para o projeto por ter uma precis�o maior nas regi�es de satura��o da umidade.

<img src="https://makertree.azurewebsites.net/168/18/dht22-digital-temperature-and-humidity-sensor-7036.jpg" width="200" />

### MQ135
Este � o sensor de di�xido de carbono mais dispon�vel no mercado.

<img src="https://potentiallabs.com/cart/image/cache/catalog/New%20Components-17/Mq-135-800x800.jpg" width="200" />

### Mini Ventilador
Mini Ventiladores s�o o suficiente para promover o fluxo de ar interno e para promover a troca de ar.

<img src="https://cdn.shopify.com/s/files/1/0447/3693/products/scythe-mini-kaze-ultra-40-x-20-mm-silent-mini-fan-sy124020l-4_800x.jpeg" width="200" />

### Resistores de Pot�ncia
Resistores de Pot�ncia aquecem quando uma corrente relativamente alta passa por eles. Fazendo um arranjo de resistores de pot�ncia podemos criar um aquecedor b�sico e simples.

<img src="http://www.eletrodex.com.br/media/catalog/product/cache/1/image/800x/9df78eab33525d08d6e5fb8d27136e95/r/e/resistor_10w_2.jpg" width="200" />

### Umidificador Ultrass�nico "Fogger"
O Fogger � mergulhado na �gua e ent�o ele cria uma n�voa em sua superf�cie por meio de ondas ultrass�nicas. Essa n�voa pode ser utilizada para umidificar o ar.

<img src="https://img1.wantitall.co.za/prodimages/new-ultrasonic-fogger-mist-maker-fog-water-fountain-pond-atomizer-air-humidifier__41G-NPwk1pL.jpg" width="200" />

### Led 460nm
Led de freq�ncia espec�fica azul. Apenas essa faixa de freq�ncia � necess�ria para o cultivo.

<img src="https://www.digibay.in/image/cache/data/se/171-a-1w-high-power-white-led-80-lumen-3v-350ma-600x600.jpg" width="200" />

## Diagrama de Blocos
![Diagrama de Blocos](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Estufa-para-Cogumelos/imgs/block_diagram.jpg)

A parte do sensoreamento � formada pelo ESP8266 como unidade central e este recebe os sinais dos sensores e manda sinal para os atuadores.

## Atuadores

### Circuito Atuador Geral
![Diagrama de Blocos](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Estufa-para-Cogumelos/imgs/actuator_1.jpg)

### Circuito Atuador do Aquecedor
![Diagrama de Blocos](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Estufa-para-Cogumelos/imgs/actuator_2.jpg)

# Testes
## Caixa de isopor
Foi feito um teste de resfriamento da caixa de isopor e numericamente encontrado a curva resultante do comportamento dos dados:
![isopor](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Estufa-para-Cogumelos/imgs/temperature_curve_box_cooling.png)
Podemos aproximar a fun��o da temperatura pelo tempo por T(t)=28.3+18.15\*exp(-0.001225\*t).
Com isso podemos obter a condutividade t�rmica da caixa de isopor, k = 0.001225.

# Softwares
## Firmware do ESP8266

```C++
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* SSID = "batata"; //Seu SSID da Rede WIFI
const char* PASSWORD = "12344321"; // A Senha da Rede WIFI
const char* USER = "rtsukiae";
const char* USER_PASSWORD = "tJ57VNAJ_U9t";
const char* MQTT_SERVER = "m10.cloudmqtt.com";
int         PORT = 18650;


#define GPIO_PIN_HEATER     5
#define GPIO_PIN_HUMIDIFIER 4
#define GPIO_PIN_FAN1       14
#define GPIO_PIN_LIGHT      12


#define DHTPIN 2
#define DHTTYPE DHT22
#define REPORT_INTERVAL 30 // in sec

DHT dht(DHTPIN, DHTTYPE);

char espID[6];
long lastMsg = 0;
char msg[50];
char msg_buff[50];
WiFiClient CLIENT;
PubSubClient MQTT(CLIENT);


//CONFIGURA��O DA INTERFACE DE REDE
void setupWIFI() {
  WiFi.begin(SSID, PASSWORD);
  Serial.print("Conectando na rede: ");
  Serial.println(SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi connected");
}

void setup(void) {
  Serial.begin(115200);

  uint8_t temp[6];
  setupWIFI();
  WiFi.macAddress(temp);
  sprintf(espID, "%X%X%X", temp[3], temp[4], temp[5]);
  Serial.println(espID);

  MQTT.setServer(MQTT_SERVER, PORT);
  MQTT.setCallback(callback);


  setupPin();

  dht.begin();
}

void loop(void) {
  if (!MQTT.connected()) {
    reconectar();
  }
  MQTT.loop();

  delay(1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  char topic[20];
  sprintf(msg, "%.1f", t);
  sprintf(topic, "%s/temperature", espID);
  MQTT.publish(topic, msg);

  sprintf(msg, "%.1f", h);
  sprintf(topic, "%s/humidity", espID);
  MQTT.publish(topic, msg);

  Serial.print("H: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("T: ");
  Serial.println(t);

}

void reconectar() {
  while (!MQTT.connected()) {
    Serial.println("Conectando ao Broker MQTT.");
    if (MQTT.connect("ESP8266", USER, USER_PASSWORD)) {
      Serial.println("Conectado com Sucesso ao Broker");

      char topic_buff[20];
      sprintf(topic_buff, "%s/light", espID);
      MQTT.subscribe(topic_buff, 1);
      Serial.print("Subscribed to ");
      Serial.println(topic_buff);

    } else {
      Serial.print("Falha ao Conectador, rc=");
      Serial.print(MQTT.state());
      Serial.println(" tentando se reconectar...");
      delay(3000);
    }
  }
}

void setupPin() {
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
}

void callback(char* topic, byte* payload, unsigned int length) {

  for (int i = 0; i < length; i++)
    msg_buff[i] = payload[i];

  Serial.println("Received:");
  Serial.print("topic: ");
  Serial.println(topic);
  Serial.print("payload: ");
  Serial.println(msg_buff);

  char topic_buff[20];

  sprintf(topic_buff, "%s/heater", espID);
  if (strcmp(topic, topic_buff) == 0)
  {
    if (strcmp(msg_buff, "1") == 0)
    {
      digitalWrite(GPIO_PIN_HEATER, HIGH);
    }
    else
    {
      digitalWrite(GPIO_PIN_HEATER, LOW);
    }
  }

  sprintf(topic_buff, "%s/humidifier", espID);
  if (strcmp(topic, topic_buff) == 0)
  {
    if (strcmp(msg_buff, "1") == 0)
    {
      digitalWrite(GPIO_PIN_HUMIDIFIER, HIGH);
    }
    else
    {
      digitalWrite(GPIO_PIN_HUMIDIFIER, LOW);
    }
  }

  sprintf(topic_buff, "%s/fan1", espID);
  if (strcmp(topic, topic_buff) == 0)
  {
    if (strcmp(msg_buff, "1") == 0)
    {
      digitalWrite(GPIO_PIN_FAN1, HIGH);
    }
    else
    {
      digitalWrite(GPIO_PIN_FAN1, LOW);
    }
  }
  
  sprintf(topic_buff, "%s/light", espID);
  if (strcmp(topic, topic_buff) == 0)
  {
    if (strcmp(msg_buff, "1") == 0)
    {
      digitalWrite(GPIO_PIN_LIGHT, HIGH);
    }
    else
    {
      digitalWrite(GPIO_PIN_LIGHT, LOW);
    }
  }

}

```

# Or�amentos