
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

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Things.png?raw=true" />

Para receber os dados, é necessário criar um dispositivo e conectar com seu token, que é basicamente o broker nessa aplicação. A partir dos dados recebidos neste dispositivo, pode-se criar um gráfico que estará inscrito no tópico do dado:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Flow_Teste.PNG?raw=true" width="500" height="280" />

### Componentes Principais:
1. NodeMCU V1.0 (ESP8266)
2. Sensor Ultrassônico HCSR-04
3. Sensor De Fluxo

O protótipo foi desenvolvido de maneira que o sensor de altura e sensor de fluxo possam ser utilizados individualmente ou ao mesmo tempo. Como os gráficos podem ser individuais, a visualização de dados também pode ser individual.

Além disso,  é alimentado por baterias 9V com regulador StepDown LM2596, que também são monitoradas via MQTT. 

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

Internamente este sensor possui um rotor que gira proporcionalmente ao fluxo de água passa por dentro dele. O giro do rotor é captado pelo sensor de efeito hall e convertido em pulsos para sua leitura.
Os pulsos por segundo para são proporcionais ao fluxo, porém seu número exato devem ser obtidos através de ensaios empíricos.
A escolha deste sensor no projeto justifica-se no custo. O baixo orçamento destinado a este protótipo traz como consequência algumas limitações de projeto. De acordo com o datasheet do sensor, seu fluxo mínimo é de 0,5L/min, muito acima do necessário para medir pequenos vazamentos. 

As vantagens então desse sensor são seu baixo custo, baixa complexidade na utilização e grande disponibilidade. 

As desvantagens encontradas estão na necessidade de calibração das leituras e no fato deste sensor ser invasivo, logo podem ser necessário ajustes em caso de instalações já existentes. 

### Testes e Resultados
#### Estrutura de Testes
Para imitar uma situação mais próxima da realidade, usou uma caixa plástica para simular uma caixa d'água com uma saída para o sensor de fluxo de torneira em uma torneira. O sensor de altura  colado na tampa da caixa. 
Para medição de volume de água usou-se um copo medidor com resolução de 50mL.
Estrutura:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Estrutura.jpeg?raw=true" width="440" height="330" />

Suporte HCSR04:

Como é necessário que o sensor de nível seja instalado dentro da caixa d’água na qual deseja-se monitorar o volume de água, é importante preocupar-se com a isolação da parte eletrônica do sensor. A umidade dentro do recipiente é muito elevada e isso pode acelerar muito o processo de deterioração dos conectores e componentes.
Foi então criado e impresso em uma impressora 3D um case para suporte do HCSR04. O case possui aberturas especificas apenas para saída dos cabos e exposição da parte que precisa permanecer fora do case. 
Sendo o case uma parte fixa e uma tampa móvel, a tampa é colada na tampa da caixa.
As frestas foram preenchidas com cola quente para vedação.

O STL para impressão desse suporte pode ser encontrado na pasta HC_STL.

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/SuporteHC.jpeg?raw=true" width="380" height="330" />

O Software utilizado para criação do STL foi o Fusion 360, que possui uma versão acadêmica gratuita.

Link alternativo para visualização e download do STL:
https://a360.co/2Nurk7G

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/HC_STL.png?raw=true" width="380" height="220"/>

### Circuito Impresso:

A ideia do circuito é que ele seja modular e possa ser replicado para uma expansibilidade do sistema, logo a PCB integra o NodeMCU com o circuito de alimentação e  um conversor lógico para o casamento de tensões o microcontrolador e os sensores.
Sendo um circuito de baixo consumo pensado para facilidade de instalação, o mesmo pode ser alimentado por bateria ou fonte com tensões compatíveis com a entrada do regular StepDown LM2596.
Foi utilizado o ADC do NodeMCU para monitorar também o nível de carga da bateria. Calculado inicialmente para funcionar com uma bateria de 9V na alimentação, é estipulado um divisor resistivo para diminuir a tensão de entrada para 1/3 da mesma na entrada do ADC.

O esquemático apresenta a interligação dos componentes:
<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Esquem%C3%A1tico.png?raw=true"/>

Layout do circuito:

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/PCB_TopSilk.jpeg?raw=true"/>

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

Ressalta-se que para fins de estudo este é um sensor empregável, porém para uma aplicação comercial ou um estudo mais avançado é crucial a escolha de um sensor de maior sensibilidade.
 
#### Ensaio Sensor de Altura
O volume de um recipiente medido pela variação de altura depende exclusivamente do seu formato, esta razão pode ser definida empírica ou matematicamente. Neste ensaio optou-se pela maneira empírica devido a difícil aproximação matemática do recipiente. O resultado obtido está ilustrado na tabela abaixo:

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/EnsaioHC%20Tabela.png?raw=true"/>

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/EnsaioHC%20Graf.png?raw=true"/>

Da mesma maneira que o sensor de fluxo, podemos aproximar a variação do volume pela reta obtida.
#### Limitações técnicas
A limitação técnica mais agravante deste protótipo é o fato do sensor de fluxo não detectar pequenos fluxos, impossibilitando a aplicação dele para este fim. 
Além disso, a determinação do volume por variação de altura depende do formato da caixa d'água, isto pode se tornar ruim de ser determinado empiricamente devido ao fato de ser necessário medir do ponto inicial ao final, esvaziando a caixa inteiramente.
### Estruturação do Código
O código gravado no microcontrolador deve enviar os dados em no máximo a cada 5s para não sobrecarregar o servidor demo, dentro do loop principal ainda deve verificar a conexão com o servidor e obter todas as medições, inclusive a leitura analógica do pino da tensão da bateria. Por exemplo, a leitura do sensor de fluxo deve normalizar a contagem de pulsos para Hz e calcular o fluxo pela aproximação linear, a imagem abaixo mostra o processo de maneira simplificada:
```C++
  deltaT = millis() - oldTime;
  if(deltaT >= 5000){
      oldTime = millis();      
      P = (pulseCount)/(deltaT/1000.0);
      flowRate = 126.23*P+416.8;
      sendMQTT("Flow",flowRate);
}
```
O pacote de dados enviados deve ser em sintaxe Jason {"tópico",dado} para ser decodificado pelo servidor.

O código completo está na pasta SRC.

### Gráficos na Plataforma IOT
Abaixo encontram-se os gráficos obtidos na plataforma IOT. Apesar de usar uma versão de demonstração, é possível designar esses gráficos a um cliente ou deixá-los públicos. Porém na versão demo só é possível deixar 500 dados e os primeiro será deletado se surgir o 501, mesmo selecionando uma escala de tempo maior.

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Flow_teste.jpeg?raw=true"/>

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/HC_Teste.jpeg?raw=true"/>

<img src="https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Uso-Sustent%C3%A1vel-%C3%81gua/Imagens/Bat_teste.jpeg?raw=true"/>

A tensão da bateria foi colocada em percentual de carga, considerando uma bateria de 9V alcalina com 100% de carga com tensão igual a 9,3V e 0% de carga com 7,5V.

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

*Partes da estrutura como caixa plástica, torneira e encanamentos não foram inclusas neste orçamento pois não fazem parte do produto final.

### Documentação Auxiliar
#### MQTT
1. https://www.cloudmqtt.com/docs.html
2. https://thingsboard.io/docs/
#### Sensor de Fluxo
http://wiki.seeedstudio.com/G1_and_2_inch_Water_Flow_Sensor/
