

# Index
- [Motiva��o](#motiva��o)
- [Introdu��o](#introdu��o)
	- [O Cultivo de Cogumelos](#o-cultivo-de-cogumelos)
	- [O Protocolo MQTT](#o-protocolo-mqtt)
 - [Sensoreamento](#sensoreamento)
	 - [Componentes](#componentes)
	 - [Diagrama de Blocos](#diagrama-de-blocos)
	 - [Placa de Circuito Impresso](#placa-de-circuito-impresso)
 - [Testes](#testes)
 - [Softwares](#softwares)
	 -  [Servidor MQTT](#servidor-mqtt)
	 - [Firmware do ESP8266](#firmware-do-esp8266)
- [Or�amentos](#or�amentos)
- [Montagem](#montagem)
- 

# Motiva��o

O intuito  � projetar e desenvolver uma estufa para cultuvo de cogumelos de modo descentralizado e utilizando o protocolo MQTT para comunica��o via Wi-Fi.
Inicialmente ser� feito um prot�tipo de um modelo menor e ser� deixado como uma base para se poder expandir futuramente.

# Introdu��o

## O Cultivo de Cogumelos
Hoje em dia est� tendo uma demanda crescente para o consumo de cogumelos, seja ela devido ao seu delicioso sabor, ao uso nos pratos de origem Orientais, ou ao veganismo, na qual n�o se consomem produtos de origem animal.
O cultivo de cogumelo � tido como um taboo para as pessoas. Isso pode ser devido � diferen�a dos cogumelos com os alimentos que encontramos no dia a dia. Um cogumelo n�o � uma planta e nem um animal, ele � algo pr�prio, um fungo. Um fungo quase sempre � levado para uma conota��o ruim, como o mofo ou bolor. Por�m, alguns desses fungos s�o saborosos e nutritivos e infelizmente s�o pouco comercializados.



### Est�gios de Cultivo

### Cogumelos Mais Comuns
- Cogumelo Paris ou Champignon:
<img src="https://cdn.awsli.com.br/1000x1000/334/334766/produto/18044212/17f8c200a1.jpg" width="300" />
- Shimeji: 
<img src="https://http2.mlstatic.com/cogumelo-shimeji-branco-fresco-r-3000-o-kilo-D_NQ_NP_835450-MLB26598211450_012018-F.webp" width="300" />
- Shitake:
<img src="http://www.casacamponesa.com.br/sites/default/files/produtos/cogumelo-shitake.jpg" width="300" />
- Cogumelo Salm�o ou Shimeji Rosa:
<img src="http://www.casacamponesa.com.br/sites/default/files/produtos/cogumelo-salmao.jpg" width="300" />
- Portobello:
<img src="https://static.wixstatic.com/media/9a994c_a21487f1a5af481b80e415b6e3e3525d~mv2.jpg/v1/fill/w_494,h_299,al_c,q_90/9a994c_a21487f1a5af481b80e415b6e3e3525d~mv2.webp" width="300" />

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
- **Ventila��o**: Mini Ventilador
- **Aquecimento**: Aquecedor de Aqu�rio
- **Umidifica��o**: Umidificador Ultrass�nico "Fogger"

### ESP8266
O ESP8266 � um microcontrolador de baixo custo da fabricante chin�sa Espressif que inclui capacidade de comunica��o por Wi-Fi. � um microcontrolador de 32 bits e que possui uma grande variedade de m�dulos. O m�dulo empregado para esse projeto foi o Kit de Desenvolvimento Node-MCU.

<img src="https://cdn.shopify.com/s/files/1/0672/9409/products/NodeMCU_ESP8266_development_board_1024x1024.jpg" width="200" />

### DHT22
O DHT22 � um sensor de temperatura e umidade que usa comunica��o One-Wire. Este sensor foi escolhido para o projeto por ser o sensor mais dispon�vel no mercado brasileiro.

<img src="https://uploads.filipeflop.com/2017/07/SKU031549-.2-600x600.jpg" width="200" />


### Mini Ventilador
Mini Ventiladores s�o o suficiente para promover o fluxo de ar interno e para promover a troca de ar.

<img src="https://cdn.shopify.com/s/files/1/0447/3693/products/scythe-mini-kaze-ultra-40-x-20-mm-silent-mini-fan-sy124020l-4_800x.jpeg" width="200" />

### Aquecedor de Aqu�rio
Usar um aquecedor de aqu�rio dentro de um recipiente com �gua � um m�todo simples, pr�tico, barato e replic�vel para se aquecer um ambiente.

<img src="https://http2.mlstatic.com/aquecedor-para-aquarios-sarlo-better-hot-25w-220v-D_NQ_NP_994011-MLB20453932090_102015-F.jpg" width="200" />

### Umidificador Ultrass�nico "Fogger"
O Fogger � mergulhado na �gua e ent�o ele cria uma n�voa em sua superf�cie por meio de ondas ultrass�nicas. Essa n�voa pode ser utilizada para umidificar o ar.

<img src="https://img1.wantitall.co.za/prodimages/new-ultrasonic-fogger-mist-maker-fog-water-fountain-pond-atomizer-air-humidifier__41G-NPwk1pL.jpg" width="200" />


## Diagrama de Blocos
![Diagrama de Blocos](https://raw.githubusercontent.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/Estufa-para-Cogumelos/imgs/block_diagram.jpg)

A parte do sensoreamento � formada pelo ESP8266 como unidade central e este recebe os sinais dos sensores e manda sinal para os atuadores.

## Placa de Circuito Impresso
A placa de circuito impresso foi feita no software Altium.
### Esquem�tico
![Diagrama de Blocos](https://raw.githubusercontent.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/Estufa-para-Cogumelos/imgs/schematic.jpg)


### PCB
![Diagrama de Blocos](https://raw.githubusercontent.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/Estufa-para-Cogumelos/imgs/pcb.jpg)

# Testes
## Caixa de isopor
Foi feito um teste de resfriamento da caixa de isopor e numericamente encontrado a curva resultante do comportamento dos dados:
![isopor](https://raw.githubusercontent.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/Estufa-para-Cogumelos/imgs/temperature_curve_box_cooling.png)
Podemos aproximar a fun��o da temperatura pelo tempo por T(t)=28.3+18.15\*exp(-0.001225\*t).
Com isso podemos obter a condutividade t�rmica da caixa de isopor, k = 0.001225.



# Softwares

## Servidor MQTT
Foi utilizado o servidor test.mosquitto.org como servidor MQTT. Este servidor � de livre uso utilizando a porta 1883.

## Firmware do ESP8266

O Firmware do ESP8266 foi feito utilizando a framework do Arduino.

# Or�amentos
A tabela de pre�os contem valores aproximados:

|Item						|Pre�o	|
|---------------------------|------:|
|ESP8266					| 25 R$	|
|DHT22						| 35 R$	|
|Mini Ventilador			| 6 R$	|
|Aquecedor de Aqu�rio 50W	| 30 R$	|
|Fogger						| 20 R$	|
|Caixa de Isopor 30L		| 30 R$	|
|**Total**					| 146 R$	|


# Montagem

# Manual de Uso
O ESP8266 se increver� no t�pico "/set/" do seu ID. Cada ESP8266 tem um ID, que ser� designado ESPID. 

Para iniciar, deve-se mandar "1" para o t�pico:
```
ESPID/set/state
```
Para ajustar a temperatura, deve-se mandar o valor desejado para:
```
ESPID/set/temperature
```
Para ajustar a umidade, deve-se mandar o valor desejado para:
```
ESPID/set/humidity
```
Para ajustar o tempo em que o Umidificador permanece ativo temporariamente, deve-se mandar o valor desejado, em segundos, para:
```
ESPID/set/humifer/activetime
```
Para ajustar o periodo em que o Umidificador ser� ligado, deve-se mandar o valor desejado, em minutos, para:
```
ESPID/set/humifer/period
```
\
\
O ESP8266 mandar� informa��es nos seguintes t�picos:
```
ESPID/status/temperature
ESPID/status/humidity
ESPID/status/elapsed
ESPID/status/heater
ESPID/status/humidifier
ESPID/status/fan1
ESPID/status/fan2
```