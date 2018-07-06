Projeto Integrador 3 | Eletrocardiógrafo

Introdução
Um eletrocardiograma é a reprodução gráfica da atividade elétrica do coração registrada por eletrodos posicionados em 3 regiões do corpo tradicionalmente, sendo elas, pulso direito e esquerdo e o terceiro eletrodo na perna direita, esse sinal é filtrado e amplificado através de um eletrocardiógrafo.
O coração é uma bomba hidráulica ativada por estímulos elétricos com 4 cavidades e que a cada movimento, realiza uma alteração no fluxo sanguíneo. A contração das fibras musculares do coração é controlada por uma descarga elétrica que flui através de vias elétricas do sistema de condução, em uma velocidade controlada. 
A frequência cardíaca gira em torno de 60 a 100 batimentos por minuto. O que no sistema Internacional de Unidades corresponde entre 1Hz a 1,67Hz. 

Na figura a seguir observamos três larguras de banda, a clinica vai de 0.05 a 100 Hz e a de monitoramento 0.5 Hz a 50 Hz, também observamos a frequência cardíaca centrada em 17 Hz (TOMPKINS, 1995).

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im1.png)

Foi escolhido trabalhar com as frequências entre 0.5 Hz a 50 Hz, as mesmas utilizadas para aplicações de monitoramento. A razão pela qual foi escolhido trabalhar nesta faixa, dá-se pela implementação do filtro passa-alta resultar em um circuito com valores elevados, e um filtro passa-baixa de 50 Hz já excluiria a frequência da rede, entorno de 60 Hz, facilitando assim a  realização do projeto pois não seria necessário utilizar um filtro notch.

Para a implementação desses foi utilizado dois filtro Butterwoth ordem dois de  topologia VCVS, onde os componentes podem ser calculados a partir das seguintes fórmulas: 

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/im2.png)

Filtro 

![alt text](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletrocardiografia-ECG/Magnitude_log_Filtro.png)

Por: Bruna Martini e Maria Negri
