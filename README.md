<h1> Sistema de aquisição de sinais elétricos musculares microcontrolado </h1>

<p>Repositorio criado para a disciplina de Projeto Integrador 3, do curso de engenharia eletrônica do IFSC - câmpus Florianópolis. <br/>
</p>

<h2> Revisão Bibliográfica </h2>

<p> A revisão bibliográfica pode ser acessada na wiki deste projeto.</p>

<h2> Diagrama de blocos </h2>

![Figura 1 - Diagrama de blocos do projeto](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletroneuromiografia-ENMG/images/block_diagram.jpg "Diagrama de Blocos")

<p> Com a leitura das referências bilbiográficas da área feita e o diagrama de blocos definido, iniciou-se o desenvolvimento do projeto com o circuito de pré-amplificação. Foi encontrada no livro The Biomedical Engineering Book, uma topologia que junta o pré-amplificador e o filtro passa-alta no mesmo circuito. No exemplo da topologia, coincidentemente foi usado o INA118, mesmo amplificador de instrumentação disponível para o projeto. Na imagem a seguir, temos o esquemático simplificado e definição do ganho do componente.<p>
  
 ![Figura 1 - Diagrama de blocos do projeto](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/blob/Eletroneuromiografia-ENMG/images/ina118_ss_ganho.png "Esquemático simples e ganho INA118")
  
<p>Foi arbitrado um ganho de 51 para a estrutura, por resultar em um valor de 1kohm para Rg, fácil de obter, e por ser um valor na faixa aceitável de ganho para esse tipo de estrutura neste tipo de aplicação. segundo a bibliografia estudada. A frequência de corte do passa-alta foi definida como 25 Hz, pois abaixo desse valor a ruídos de movimentação mecânica, e os diagramas de energia do sinal observador nas referências mostra a concentração de energia do sinal para a faixa acima deste valor.<p>
  
<p>Todas as considerações feitas, os cálculos e simulações pertinentes foram executados. Os arquivos de ambas etapas citadas estão disponível no link.<p>

[Calculos e Simulacoes - Pre_amp e PA](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/tree/Eletroneuromiografia-ENMG/pre_amp_e_passa_alta)

<p>Com o primeiro bloco projetado, passou-se para o próximo bloco, segundo o diagrama, o filtro passa-baixa. A topologia escolhida foi o filtro ativo Multiple Feedback com aproximação Butterworth. O ganho foi escolhido para 12,5 com o intuito de deixar o ganho em cascata da estrutura na casa das unidades de centenas. A frequência de corte de 250 Hz foi escolhida baseada no estudo dos diagramas de frequência do sinal  EMG. O ampop escolhido para implementar o circuito deste bloco foi o LM324, por atender as especificações de ganho e frequência e ser um componente de fácil obtenção e barato.Com os parâmetros do bloco definidos, passou-se então para os cálculos de componentes e simulações. Os arquivos pertinentes podem ser encontrados no link a seguir.<p>
  
[Calculos e Simulacoes - Filtro Passa-Baixa](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/tree/Eletroneuromiografia-ENMG/passa_baixa)

<p> A faixa de variação da amplitude do sinal elétrico muscular pode ser consideralmente ampla, devido fatores como tipo e qualidade dos eletrodos, grupo muscular em análise, capacidade e fisiologia do individuo em análise, entre outros. Levando isso em consideração, foi desenvolvido um bloco de ajuste de ganho, para que seja possível adequar o sinal adquirido da melhor forma possível.
<p>Porém, para fazer uma adequação correta, deve se conhecer o que se têm ou onde se está, e o que se quer ou onde se quer chegar. O que temos são sinais da ordem de centenas de microvolts a unidades de milivolts.o que queremos é um sinal de saída analógico que pode ser convertido para informação digital, de preferência em um microncontrolador de baixo consumo. Estes geralmente trabalham com alimentação em 3.3 V. Logo, podemos definir que queremos um sinal de saída do módulo de aquisição que seja de 0 V a 3.3V, correspondente a sinais mioelétricos captados pelo eletrodo da ordem de 250uV até 5mV.
<p> Tendo o ponto de partida e de chegada, podemos focar esforços na construção do caminho agora. Para termos um sinal totalmente positivo na saída, é necessário que seja feito um offset DC no sinal. Para isso, foi escolhida a topologia de amplificador operacional na configuração não-inversora. Os valores de resistência do circuito foram arbitrados para não ter influencia no casamento de impedância dos blocos. A tensão de referência deste circuito (que deve ser metade da excursão do sinal de saída, logo, 3.3/2 = 1,65 V) será provida por um seguidor de tensão. Como o seguidor inverte a polaridade da tensão, o valor de -1,65V necessário é pego de um divisor resistivo entre o GND e o -5V da alimentação simétricas dos ampops.
<p> Tendo definido os parâmetros necessários, passaram-se para os demais cálculos e simulações do bloco de offset DC. Os arquivos relacionados a esta etapa podem ser encontrados no link.
  
[Calculos e Simulacoes - Somador DC](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/tree/Eletroneuromiografia-ENMG/somadorDC)

<p> Devido a configuração e valores utilizados no bloco de offset DC, o sinal de entrada deste bloco deve variar de -0,815 V a +0,815 V para que haja 0 a 3.3V na saída. Com este faixa de amplitude necessária na entrada do bloco de offset, juntamente com a faixa de amplitude do sinal mioelétrico que deseja ser captada e conhecendo o ganho dos blocos anteriores, é possível finalmente projetar o bloco de ajuste de ganho. A topologia utilizada é simples, um amplificador operacional em configuração de ganho ajustável, com um trimpot conectado ao terminal inversor e na malha de realimentação e um diodo zener de 3.3V na saída para certificar que o valor máximo não seja ultrapassado. De acordo com os cálculos feitos, que podem ser observados nos arquivos desta etapa no link abaixo, o bloco de ajuste deve variar o ganho de aproximadamente 0,25 a 5. Conhecendo as impedâncias de entrada e saída dos blocos anteriores e posteriores, foram calculados os componentes necessários para que não houvesse influência na resposta em frequência do circuito. 
  
[Calculos e Simulacoes - Ajuste de ganho](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/tree/Eletroneuromiografia-ENMG/ajuste_ganho)
  
<p> Com os quatro bloco de hardware de aquisição prontos, foi feito um protótipo para validar o funcionamento dos circuitos escolhidos. O esquemático e layout elaborados no software Altium Designer foram feitos em blocos, para garantir a validação individual de cada um, antes do teste coletivo. É possível acoplar os blocos por meio de jumpers. Após confeccionada a placa, foram feitos os testes pertinentes. Os resultados estão na apresentação de slides do link a seguir. Os outros arquivos relacionados à etapa de prototipagem e testes também podem ser encontrados no link.
  
[Protótipo  e teste do hardware de aquisição](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/tree/Eletroneuromiografia-ENMG/ajuste_ganho)

Com os resultados dos testes, foi concluído que os blocos do hardware de aquisição estavam de acordo com os requisitos necessários, porém para próxima etapa (teste IN VIVO), seria necessário que o circuito fosse alimentado de forma independente da rede elétrica. Assim, foi desenvolvida uma placa de regulação de tensão para alimentar o prototipo apartir de baterias 9 V. Os arquivos do projeto estão disponiveis no link a seguir.

[Placa de regulação de tensão](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/tree/Eletroneuromiografia-ENMG/reg_tensao)

Com a alimentação regulada das baterias e sem interferência conduzida da rede elétrica, foi feito o teste In Vivo do hardware de aquisição. Usando eletrodos de Prata/Cloreto de Prata com gel condutor e cabos blindados, foi feita leitura do sinal da musculatura do antebraço esquerdo. O sinal foi observado por meio do osciloscópio portátil Rohde & Schwarz modelo RTH1004. Os arquivos relacionados a etapa de teste in vivo pode ser acessados pelo link a seguir.

[Teste In Vivo](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/tree/Eletroneuromiografia-ENMG/teste_vivo)

Por fim, foi iniciada a etapa de conversão analógica-digital transmissão dos dados, por meio do uso de um microcontrolador. Foi escolhido o chip ATMEGA328P pela familiarização anterior. O código desenvolvido faz a conversão do sinal analógico em digital e envia o dado por meio do módulo Bluetooth HC-06. Para fins de facilitação de código, foi usada resolução de 8 bits na conversão A/D, com taxa de amostragem de 1 kHz. O uso de transmissão de dados sem fio é para garantir o isolamento galvânico do circuito de aquisição de qualquer outro equipamento eletrônico. Para visualização dos dados foi usado o software SerialPlot. Os arquivos relacionados a etapa de desenvolvimento do firmware, aquisição e visualização dos dados podem ser acessados no link a seguir.

[Teste In Vivo com aquisição de dados via Bluetooth](https://github.com/Everton-LF-Santos/Projeto-Integrador-3-2018-1/tree/Eletroneuromiografia-ENMG/firmware_bt)
