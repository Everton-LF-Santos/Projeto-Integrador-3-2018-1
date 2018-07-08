//Cálculo de impedâncias de entrada e saída do bloco de offset DC;

j = %i;
f = 112.5;

w = 2*%pi*f;

Ro = 10;
Rin_AOP = 10e12;

Zin_min = R1 + Xc1 + Rf + Ro;

Zout = Ro;
