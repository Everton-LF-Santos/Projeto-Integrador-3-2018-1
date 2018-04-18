# Index
- [Motiva��o](#motiva��o)
- [Introdu��o](#introdu��o)
	- [O Cultivo de Cogumelos](#o-cultivo-de-cogumelos)
	- [O Protocolo MQTT](#o-protocolo-mqtt)
 
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
- ESP8266
- DHT22 (Sensor de temperatura e umidade)
- MQ135 (Sensor de G�s Carb�nico)
- Mini Ventilador (Ventila��o)
- Resistores de Pot�ncia (Aquecimento)
- Umidificador Ultrass�nico "Fogger" (Umidifica��o)
- Led 460nm (Ilumina��o)
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
Foi feito um teste de resfriamento da caixa de isopor e numericamente encntrado a curva resultante do comportamento dos dados:
![isopor](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Estufa-para-Cogumelos/imgs/temperature_curve_box_cooling.png)
Podemos aproximar a fun��o da temperatura pelo tempo por T(t)=28.3+18.15\*exp(-0.001225\*t).
Com isso podemos obter a condutividade t�rmica da caixa de isopor, k = 0.001225.

# Softwares
## Firmware do ESP8266
A placa 