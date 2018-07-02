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

Afim de facilitar a visualização dos dados, optou-se por usar a plataforma IOT ThingsBoard. Na plataforma é possível criar gráficos que mostram os dados em tempo real e designar a um cliente. Para testes, usou-se a versão Demo Online.

Para receber os dados, é necessário criar um dispositivo e conectar com seu token, que é basicamente o broker nessa aplicação. A partir dos dados recebidos neste dispositivo, pode-se criar um gráfico que estará inscrito no tópico do dado.


### Componentes:
1. NodeMCU V1.0 (ESP8266)
2. Sensor Ultrassônico HCSR-04
3. Sensor De Fluxo Efeito Hall
O protótipo foi desenvolvido de maneira que o sensor de altura e sensor de fluxo possam ser utilizados individualmente ou ao mesmo tempo. Como os gráficos são individualizados, a visualização também sera individual.

### Limitações técnicas

### Testes de Estresse

### Resultados

### Documentação
#### MQTT
1. https://www.cloudmqtt.com/docs.html
2. https://thingsboard.io/docs/
#### Sensor de Fluxo
//http://wiki.seeedstudio.com/G1_and_2_inch_Water_Flow_Sensor/
