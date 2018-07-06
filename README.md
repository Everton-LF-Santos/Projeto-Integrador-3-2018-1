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
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Flow_Teste.PNG?raw=true" width="500" height="280" />

### Componentes Principais:
1. NodeMCU V1.0 (ESP8266)
2. Sensor Ultrassônico HCSR-04
3. Sensor De Fluxo

O protótipo foi desenvolvido de maneira que o sensor de altura e sensor de fluxo possam ser utilizados individualmente ou ao mesmo tempo. Como os gráficos podem ser individuais, a visualização de dados também pode ser individual.

Além disso,  é alimentado por baterias 9V que também são monitoradas via MQTT.
#### NodeMCU
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Node.png?raw=true" width="200" height="200" />

É um kit de desenvolvimento que combina o chip ESP8266, interface USB  e regulador de tensão. Além de ser responsável por todo processamento e leitura dos sensores, conecta ao WIFI para enviar os dados via MQTT. A programação pode ser feita pela interface do Arduino®, oferecendo bastante agilidade e praticidade, além das bibliotecas já implementadas.
#### Sensor Ultrassônico HCSR04
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/HCSR04.jpg?raw=true" width="200" height="200" />

Este componente mede a distância emitindo ondas ultrassônicas a 40KHz e aguardando o eco.
A distância medida é definida em seu datasheet como:
d(cm) = t(us)/58
onde t é o tempo em que o ECHO está em nível lógico alto. O diagrama de tempo pode ser visto abaixo:

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/TimingHC.PNG?raw=true" width="410" height="220" />

Este sensor deve ler somente uma superfície lisa e com uma área maior que 0,5m². Apesar desse sensor não aparentar ser muito resistente ao vapor de água devido a suas aberturas para emissão das ondas ultrassônicas, este sensor foi selecionado devido a:
1. Não tem contato direto com a água.
2. Precisão de acordo com o projeto.
3. Distância máxima de 4m a 5m
4. Baixo custo e alta disponibilidade no mercado
5. Fácil utilização e aplicação

#### Sensor de Fluxo de Água de Efeito Hall
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/flowsensor_LRG.jpg?raw=true" width="340" height="260" />

Internamente este sensor possui um rotor que irá girar proporcionalmente ao fluxo de água. O giro do rotor é captado pelo sensor de efeito hall e convertido em pulsos para sua leitura.
Os pulsos por segundo para são proporcionais ao fluxo, porém seu número exato devem ser obtidos através de ensaios empíricos.
Este sensor foi selecionado devido a falta de opções, pois seu fluxo mínimo em seu datasheet é de 0,5L/min. Muito acima do desejado para medir vazamentos pequenos.
As vantagens desse sensor são seu baixo custo, fácil utilização e grande disponibilidade. Porém este sensor é invasivo, logo podem ser necessário ajustes em caso de instalações já existentes.

### Testes e Resultados
#### Estrutura de Testes


#### Ensaio Sensor de Fluxo


#### Ensaio Sensor de Altura

#### Limitações técnicas


### Custo do Sensor
Abaixo estão apresentadas as estimativas de custo do protótipo completo:

| Item       | Custo
| :-----: |:-------------:| 
| NodeMCU| R$ 25,00 |
| Sensor de FLuxo  3/4" | R$ 35,00  |
| Sensor HCSR04 | R$ 13,00  |
| Bateria 9V Alcalina | R$ 14,00  |
| Regulador Step-Down | R$ 8,00
| Conversor Bid 5V-3V3 | R$ 6,00
| Componentes e PCB | 7,00
| Total | R$ 108,00


### Documentação Auxiliar
#### MQTT
1. https://www.cloudmqtt.com/docs.html
2. https://thingsboard.io/docs/
#### Sensor de Fluxo
http://wiki.seeedstudio.com/G1_and_2_inch_Water_Flow_Sensor/
