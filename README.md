# Monitoramento de Nível e Vazamento de Água
## IFSC Campus Florianópolis
### Projeto Integrador 3 - 2018-1

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
Para imitar uma situação mais próxima da realidade, usou uma caixa plástica para simular uma caixa d'água com uma saída para o sensor de fluxo de torneira em uma torneira. O sensor de altura possui seu próprio suporte impresso 3D que é colado na tampa da caixa. O STL para impressão desse suporte pode ser encontrado na pasta HC_STL.
Para medição de volume de água usou-se um copo medidor com resolução de 50mL.
Estrutura:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Estrutura.jpeg?raw=true" width="440" height="330" />

Suporte HCSR04:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/SuporteHC.jpeg?raw=true" width="380" height="330" />

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/HC_STL.png?raw=true" width="380" height="220"/>


Também foi elaborada uma placa de circuito impresso com todos componentes necessários para leitura dos sensores e comunicação Wifi/MQTT e alimentação por baterias 9V. O esquemático apresenta a interligação dos componentes:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Esquem%C3%A1tico.png?raw=true"/>

A máscara de corrosão está na pasta AltiumPCB.
PCB final:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/PCB_final.jpeg?raw=true" />

#### Ensaio Sensor de Fluxo
Para determinar de forma mais precisa o fluxo de água o sensor precisa ser calibrado, além disso sua frequência de pulsos não é diretamente proporcional.
Neste ensaio procurou-se deixar um fluxo constante sobre o sensor repondo água na caixa, assim cronometrou-se o tempo e mediu-se o volume no copo medidor. Dessa maneira, contando os pulsos pode se determinar a razão de pulsos para cada fluxo A tabela obtida está na figura abaixo:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Ensaio%20Fluxo.png?raw=true" />

Os pontos obtidos podem ser colocados em gráfico e aproximar por uma linha de tendência linear:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Ensaio%20Fluxo%20Grafico.png?raw=true" />

O ensaio foi realizado do fluxo mínimo detectado pelo sensor ao fluxo máximo da estrutura simuladora.

Com essa curva de aproximação pode-se agora contar os pulsos e calcular o fluxo pela reta. De fato, os testes de validação apontam erros razoáveis:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Ensaio%20Fluxo%20Validacao.png?raw=true" width="900" height="80"/>
#### Ensaio Sensor de Altura
O volume de um recipiente medido pela variação de altura depende exclusivamente do seu formato, esta razão pode ser definida empírica ou matematicamente. Neste ensaio optou-se pela maneira empírica devido a difícil aproximação matemática do recipiente. O resultado obtido está ilustrado na tabela abaixo:

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/EnsaioHC%20Tabela.png?raw=true"/>

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/EnsaioHC%20Graf.png?raw=true"/>

Da mesma maneira que o sensor de fluxo, podemos aproximar a variação do volume pela reta obtida.
#### Limitações técnicas
A limitação técnica mais agravante deste protótipo é o fato do sensor de fluxo não detectar pequenos fluxos, impossibilitando a aplicação dele para este fim. 
Além disso, a determinação do volume por variação de altura depende do formato da caixa d'água, isto pode se tornar ruim de ser determinado empiricamente devido ao fato de ser necessário medir do ponto inicial ao final, esvaziando a caixa inteiramente.
### Estruturação do Código
O código gravado no microcontrolador deve enviar os dados em no máximo a cada 5s para não sobrecarregar o servidor demo, dentro do loop principal ainda deve verificar a conexão com o servidor e obter todas as medições, inclusive a leitura analógica do pino da tensão da bateria. Por exemplo, a leitura do sensor de fluxo deve normalizar a contagem de pulsos para Hz e calcular o fluxo pela aproximação linear:
```C++
if(deltaT >= 5000){
      P = (pulseCount)/(deltaT/1000.0);
      flowRate = 126.23*P+416.8;
      sendMQTT("Flow",flowRate);
}
```
O pacote de dados enviados deve ser em sintaxe Jason {"Tópico",dado} para ser decodificado pelo servidor.
### Gráficos na Plataforma IOT
Colocar gráficos
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
| Componentes e PCB | R$ 7,00
| Total | R$ 108,00


### Documentação Auxiliar
#### MQTT
1. https://www.cloudmqtt.com/docs.html
2. https://thingsboard.io/docs/
#### Sensor de Fluxo
http://wiki.seeedstudio.com/G1_and_2_inch_Water_Flow_Sensor/
