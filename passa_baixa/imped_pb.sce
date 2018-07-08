//Cálculo de impedâncias de entrada e saída do bloco filtro PB
j = %i;
f = 112.5;

w = 2*%pi*f;

Ro = 10;
R1 = 18e3;
R2 = 22e4;
R3 = 39e3;
C1 = 1.2e-9;
C2 = 39e-3;

Xc1 = 1/(j*w*C1);
Xc2 = 1/(j*w*C2);

Zeq1 = 1/((1/(R3+Xc1)) + (1/(R2)));
Zeq2 = Zeq1 + Ro;
Zeq3 = 1/((1/(Xc2))+(1/(Zeq2)));
Zin = R1 + Zeq1 + Ro;

Zeq4 = Zeq1 + Ro;
Zout = 1/((1/(Xc2))+(1/(Zeq4)));
