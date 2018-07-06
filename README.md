# Monitoramento de Nível e Vazamento de Água
## IFSC Campus Florianópolis
### Projeto-Integrador-3-2018-1

#### Equipe: Jhonatan Lang, Ian Dannapel


## Objetivo:
Monitoramento do nível de água de uma caixa d'água e verificação de vazamentos de água em pontos estratégicos no campus através de comunicação WIFI.

### MQTT
O protocolo MQTT é ideal para IOT (Internet Of Things) e será usado neste projeto. Neste protocolo o trabalho fica a cargo de um Broker, no qual um "Publisher" pública dados em um tópico no Broker e os inscritos neste tópico recebem os dados.
![alt text](https://www.cloudmqtt.com/images/publisher-subscriber.jpg "")
![alt text](https://www.cloudmqtt.com/images/cloudmqtt_overview.png "")

Afim de facilitar a visualização dos dados, optou-se por usar a plataforma IOT ThingsBoard. Na plataforma é possível criar gráficos que mostram os dados em tempo real e designar a um cliente. Para testes, usou-se a versão Demo Online.

Para receber os dados, é necessário criar um dispositivo e conectar com seu token, que é basicamente o broker nessa aplicação. A partir dos dados recebidos neste dispositivo, pode-se criar um gráfico que estará inscrito no tópico do dado:
![Flow_Teste.PNG](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Flow_Teste.PNG?raw=true)

### Componentes Principais:
1. NodeMCU V1.0 (ESP8266)
2. Sensor Ultrassônico HCSR-04
3. Sensor De Fluxo

O protótipo foi desenvolvido de maneira que o sensor de altura e sensor de fluxo possam ser utilizados individualmente ou ao mesmo tempo. Como os gráficos são individualizados, a visualização de dados também será individual.

#### NodeMCU
É um kit de desenvolvimento que combina o chip ESP8266, interface USB  e regulador de tensão. Além de ser responsável por todo processamento e leitura dos sensores, conecta ao WIFI para enviar os dados via MQTT. A programação pode ser feita pela interface do Arduino®, oferecendo bastante agilidade e praticidade, além das bibliotecas já implementadas.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Node.png?raw=true =200x200 "NodeMCU")


#### Sensor Ultrassônico
Este componente mede a distância emitindo ondas ultrassônicas e aguardando o eco. A distância será proporcional ao tempo de demora entre a onda emitida e recebida.

### Resultados
#### Limitações técnicas

### Documentação Auxiliar
#### MQTT
1. https://www.cloudmqtt.com/docs.html
2. https://thingsboard.io/docs/
#### Sensor de Fluxo
http://wiki.seeedstudio.com/G1_and_2_inch_Water_Flow_Sensor/
