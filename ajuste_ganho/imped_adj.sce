//Cálculo de impedâncias de entrada e saída do bloco de ajuste de ganho

j = %i;
f = 112.5;

w = 2*%pi*f;

Ro = 10;
R1 = 220e3;
Rf = 56e3;
Radj = 1e6;
C1 = 100e-9;

Xc1 = 1/(j*w*C1);

Zin_max = R1 + Xc1 + Radj + Rf + Ro;

Zin_min = R1 + Xc1 + Rf + Ro;

Zout = Ro;
