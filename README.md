# Monitoramento de Nível e Vazamento de Água
## IFSC Campus Florianópolis
### Projeto-Integrador-3-2018-1

#### Alunos: Jhonatan Lang, Ian Dannapel


## Objetivo:
Monitoramento do nível de água de uma caixa d'água e verificação de vazamentos de água em pontos estratégicos no campus através de comunicação WIFI.

### MQTT
O protocolo MQTT é ideal para IOT (Internet Of Things) e será usado neste projeto. Neste protocolo o trabalho fica a cargo de um Broker, no qual um "Publisher" pública dados em um tópico no Broker e os inscritos neste tópico recebem os dados.
![alt text](https://www.cloudmqtt.com/images/publisher-subscriber.jpg "")
![alt text](https://www.cloudmqtt.com/images/cloudmqtt_overview.png "")


### Componentes:
#### Sensor de Nível:
1. uC ATMEGA328p
2. ESP8266-01
3. Sensor Ultrassônico HCSR-04
##### Diagrama de Blocos:
![alt text](https://raw.githubusercontent.com/Eximmius/Projeto-Integrador-3-2018-1/master/Imagens/S_Nivel.png "Diagrama Nivel")
#### Sensor de Fluxo:
1. uC ATMEGA 328p
2. ESP8266-01
3. Sensor de Efeito Hall YF-S401
##### Diagrama de Blocos:
![alt text](https://raw.githubusercontent.com/Eximmius/Projeto-Integrador-3-2018-1/master/Imagens/S_Fluxo.png "Diagrama Fluxo")

### Limitações técnicas

### Testes de Estresse

### Referências
1. https://www.cloudmqtt.com/docs.html
