**Projeto Integrador 3 | Eletrocardi�grafo**

**Introdu��o**

Um eletrocardiograma � a reprodu��o gr�fica da atividade el�trica do cora��o registrada por eletrodos posicionados em 3 regi�es do corpo tradicionalmente, sendo elas, pulso direito e esquerdo e o terceiro eletrodo na perna direita, esse sinal � filtrado e amplificado atrav�s de um eletrocardi�grafo.
O cora��o � uma bomba hidr�ulica ativada por est�mulos el�tricos com 4 cavidades e que a cada movimento, realiza uma altera��o no fluxo sangu�neo. A contra��o das fibras musculares do cora��o � controlada por uma descarga el�trica que flui atrav�s de vias el�tricas do sistema de condu��o, em uma velocidade controlada. 
A frequ�ncia card�aca gira em torno de 60 a 100 batimentos por minuto. O que no sistema Internacional de Unidades corresponde entre 1Hz a 1,67Hz. 

**Desenvolvimento**

Para o desenvolvimento do projeto foi analisado alguns pontos e seguido alguns passos importantes descritos a seguir.
Na figura a seguir observamos tr�s larguras de banda, a clinica vai de 0.05 a 100 Hz e a de monitoramento 0.5 Hz a 50 Hz, tamb�m observamos a frequ�ncia card�aca centrada em 17 Hz (TOMPKINS, 1995).

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im1.png)

Foi escolhido trabalhar com as frequ�ncias entre 0.5 Hz a 50 Hz, as mesmas utilizadas para aplica��es de monitoramento. A raz�o pela qual foi escolhido trabalhar nesta faixa, d�-se pela implementa��o do filtro passa-alta resultar em um circuito com valores elevados, e um filtro passa-baixa de 50 Hz j� excluiria a frequ�ncia da rede, entorno de 60 Hz, facilitando assim a  realiza��o do projeto pois n�o seria necess�rio utilizar um filtro notch.

Para a implementa��o desses foi utilizado dois filtro Butterwoth ordem dois de  topologia VCVS, onde os componentes podem ser calculados a partir das seguintes f�rmulas: 

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im2.png)

Para o calculo desses arbitrou-se o valor de capacit�ncia para o filtro passa baixas e passa altas, C= 1,6 uF e C = 33 nF, respectivamente, e adquiriu-se os coeficientes 'a' e 'b' da tabela de filtros butterworth. Obtendo os seguintes resultados:

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im3.png)

Na imagem abaixo � poss�vel ver a topologia dos filtros com os valores calculados e em seguida para verificar o funcionamento do filtro antes do mesmo ser implementado na pr�tica, foi tra�ada a curva de ganho pela frequ�ncia, como pode-se observar na imagem,  a banda passante dos filtros em quest�o vai de mais ou menos 250mHz a 50Hz.  

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im4.png)

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im5.png)

Ao ser implementado o fitro apresentou o comportamento da imagem a seguir.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/Magnitude_log_Filtro.png)

Ap�s a impementa��o do filtro, tamb�m foi feito algumas melhorias e adapta��es como o acrescimo de um circuito para o offset, e em seguida o circuito amplificador com acionamento na perna direita, o circuito utilizado � o mesmo que esta disponibilizado no datashet do INA118, amplificador de instrumenta��o. O ganho do INA118 � dado de acordo com a f�rmula dada abaixo.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/circuito_ina.jpg)

Este circuito foi implementado para uma aquisi��o do sinal com pouco ru�do. Como o sinal � muito baixo e h� muitas fontes de ru�dos utilizou-se o filtro passa faixa descrito. O layout da placa de capta��o do sinal e o layout da placa de filtros pode ser visto abaixo.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/filtros.png)

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/ina118.png)

Um colega se disp�s a ser volunt�rio para teste dos circuitos. O resultado obtido pode ser visto abaixo. 

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/Screenshot.png)

� interessante salientar que apesar do circuito n�o estar ligado a rede a mesma cria muito ru�do ao circuito. Para um sinal mais limpo foi necess�rio desligar as bancadas de energia e a luz do ambiente.
Utilizou-se o formato AC para a captura deste sinal com o intuito de melhor visualiza��o do mesmo. Por�m ele possui um offset de 1.5V para que o microcontrolador possa receber seu sinal sem danifica-lo.

Com o auxilio de um Atemega328p e um m�dulo bluetooth o sinal foi enviado para tela do computador e mostrado atrav�s do software *SerialPlot*.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/pi3.png)

O sinal apresentou frequ�ncia de amostragem pequena para uma boa discretiza��o do sinal. Com o intuito de deixar o sinal mais suave aumentou-se o n�mero da frequ�ncia de amostragem no c�digo, por�m n�o ouve melhora significativa. Isso deve-se ao fato do bluetooth ser lento para receber as informa��es, deixando assim a sa�da com longos intervalos de tempo entre amostras.

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/pi3_2.png)

**Refer�ncias**

TOMPKINS, W. J. Biomedical Digital Signal Processing. Upper Saddle River, New Jersey: Prentice Hall, 1995.

Por: Bruna Martini e Maria Negri
