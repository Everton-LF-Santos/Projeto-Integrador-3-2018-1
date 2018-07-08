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
