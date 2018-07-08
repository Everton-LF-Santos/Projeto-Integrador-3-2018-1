**Projeto Integrador 3 | Eletrocardiógrafo**

**Introdução**

Um eletrocardiograma é a reprodução gráfica da atividade elétrica do coração registrada por eletrodos posicionados em 3 regiões do corpo tradicionalmente, sendo elas, pulso direito e esquerdo e o terceiro eletrodo na perna direita, esse sinal é filtrado e amplificado através de um eletrocardiógrafo.
O coração é uma bomba hidráulica ativada por estímulos elétricos com 4 cavidades e que a cada movimento, realiza uma alteração no fluxo sanguíneo. A contração das fibras musculares do coração é controlada por uma descarga elétrica que flui através de vias elétricas do sistema de condução, em uma velocidade controlada. 
A frequência cardíaca gira em torno de 60 a 100 batimentos por minuto. O que no sistema Internacional de Unidades corresponde entre 1Hz a 1,67Hz. 

**Desenvolvimento**

Para o desenvolvimento do projeto foi analisado alguns pontos e seguido alguns passos importantes descritos a seguir.
Na figura a seguir observamos três larguras de banda, a clinica vai de 0.05 a 100 Hz e a de monitoramento 0.5 Hz a 50 Hz, também observamos a frequência cardíaca centrada em 17 Hz (TOMPKINS, 1995).

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im1.png)

Foi escolhido trabalhar com as frequências entre 0.5 Hz a 50 Hz, as mesmas utilizadas para aplicações de monitoramento. A razão pela qual foi escolhido trabalhar nesta faixa, dá-se pela implementação do filtro passa-alta resultar em um circuito com valores elevados, e um filtro passa-baixa de 50 Hz já excluiria a frequência da rede, entorno de 60 Hz, facilitando assim a  realização do projeto pois não seria necessário utilizar um filtro notch.

Para a implementação desses foi utilizado dois filtro Butterwoth ordem dois de  topologia VCVS, onde os componentes podem ser calculados a partir das seguintes fórmulas: 

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im2.png)

Para o calculo desses arbitrou-se o valor de capacitância para o filtro passa baixas e passa altas, C= 1,6 uF e C = 33 nF, respectivamente, e adquiriu-se os coeficientes 'a' e 'b' da tabela de filtros butterworth. Obtendo os seguintes resultados:

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im3.png)

Na imagem abaixo é possível ver a topologia dos filtros com os valores calculados e em seguida para verificar o funcionamento do filtro antes do mesmo ser implementado na prática, foi traçada a curva de ganho pela frequência, como pode-se observar na imagem,  a banda passante dos filtros em questão vai de mais ou menos 250mHz a 50Hz.  

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im4.png)

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im5.png)

Ao ser implementado o fitro apresentou o comportamento da imagem a seguir.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/Magnitude_log_Filtro.png)

Após a impementação do filtro, também foi feito algumas melhorias e adaptações como o acrescimo de um circuito para o offset, e em seguida o circuito amplificador com acionamento na perna direita, o circuito utilizado é o mesmo que esta disponibilizado no datashet do INA118, amplificador de instrumentação. O ganho do INA118 é dado de acordo com a fórmula dada abaixo.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/circuito_ina.jpg)

Este circuito foi implementado para uma aquisição do sinal com pouco ruído. Como o sinal é muito baixo e há muitas fontes de ruídos utilizou-se o filtro passa faixa descrito. O layout da placa de captação do sinal e o layout da placa de filtros pode ser visto abaixo.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/filtros.png)

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/ina118.png)

Um colega se dispôs a ser voluntário para teste dos circuitos. O resultado obtido pode ser visto abaixo. 

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/Screenshot.png)

É interessante salientar que apesar do circuito não estar ligado a rede a mesma cria muito ruído ao circuito. Para um sinal mais limpo foi necessário desligar as bancadas de energia e a luz do ambiente.
Utilizou-se o formato AC para a captura deste sinal com o intuito de melhor visualização do mesmo. Porém ele possui um offset de 1.5V para que o microcontrolador possa receber seu sinal sem danifica-lo.

Com o auxilio de um Atemega328p e um módulo bluetooth o sinal foi enviado para tela do computador e mostrado através do software *SerialPlot*.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/pi3.png)

O sinal apresentou frequência de amostragem pequena para uma boa discretização do sinal. Com o intuito de deixar o sinal mais suave aumentou-se o número da frequência de amostragem no código, porém não ouve melhora significativa. Isso deve-se ao fato do bluetooth ser lento para receber as informações, deixando assim a saída com longos intervalos de tempo entre amostras.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/pi3_2.png)

**Referências**

TOMPKINS, W. J. Biomedical Digital Signal Processing. Upper Saddle River, New Jersey: Prentice Hall, 1995.

Por: Bruna Martini e Maria Negri
