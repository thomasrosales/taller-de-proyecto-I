%%
%TEST 1

filename = 'frec_audible.ogg';
%filename = '01 Intro - Soda.mp3'
[x,fs] = audioread(filename);

%disp(fs);
n = length(x);
Ts = 1/fs; 

%calculo de potencia tiempo
Pot_x_temp=var(x)+mean(x).^2

%%
%FFT ESPECTRO EN FRECUENCIA
X = fftshift(fft(x));
f=[(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_X_freq=sum(abs(X).^2)/n


f1 = figure;
espectroX = plot(f,abs(X),'LineWidth',0.5,'color','blue');
title('Espectro de X');
xlabel('F(Hz)');
ylabel('|X|');

%%
%FILTRO PASA BANDA de 20 Hz a 160 Hz

FILTER_PB = load('FLP160b.mat');
%FILTER_PB = load('FBP160.mat');
FILTER_PB = FILTER_PB.Hd;

z1 = filter(FILTER_PB, x);

Z1 = fftshift(fft(z1));
f = [(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_Z1_freq=sum(abs(Z1).^2)/n
Pot_Z1_freq_dB=10*log10(Pot_Z1_freq)

f2 = figure;
plot(f,abs(Z1),'LineWidth',0.5,'color','blue');
title('Señal x filtrada');
xlabel('F(Hz)');
ylabel('Z1[f]')

sound(z1,fs);


%%
%FILTRO PASA BANDA de 160 Hz a 300 Hz

FILTER_PB = load('FBP300.mat');
FILTER_PB = FILTER_PB.Hd;

z2 = filter(FILTER_PB, x);

Z2 = fftshift(fft(z2));
f = [(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_Z2_freq=sum(abs(Z2).^2)/n
Pot_Z2_freq_dB=10*log10(Pot_Z2_freq)

f3 = figure;
plot(f,abs(Z2),'LineWidth',0.5,'color','blue');
title('Señal x filtrada');
xlabel('F(Hz)');
ylabel('Z1[f]')

sound(z2,fs);


%%
%FILTRO PASA BANDA de 300 Hz a 600 Hz


FILTER_PB = load('FBP600.mat');
FILTER_PB = FILTER_PB.Hd;

z3 = filter(FILTER_PB, x);

Z3 = fftshift(fft(z3));
f = [(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_Z3_freq=sum(abs(Z3).^2)/n
Pot_Z3_freq_dB=10*log10(Pot_Z3_freq)

f4 = figure;
plot(f,abs(Z3),'LineWidth',0.5,'color','blue');
title('Señal x filtrada');
xlabel('F(Hz)');
ylabel('Z1[f]')

sound(z3,fs);

%%
%FILTRO PASA BANDA de 600 Hz a 1200 Hz


FILTER_PB = load('FBP1200.mat');
FILTER_PB = FILTER_PB.Hd;

z4= filter(FILTER_PB, x);

Z4 = fftshift(fft(z4));
f = [(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_Z4_freq=sum(abs(Z4).^2)/n
Pot_Z4_freq_dB=10*log10(Pot_Z4_freq)

f5 = figure;
plot(f,abs(Z4),'LineWidth',0.5,'color','blue');
title('Señal x filtrada');
xlabel('F(Hz)');
ylabel('Z1[f]')

sound(z4,fs);


%%
%FILTRO PASA BANDA de 1200 Hz a 2400 Hz


FILTER_PB = load('FBP2400.mat');
FILTER_PB = FILTER_PB.Hd;

z5= filter(FILTER_PB, x);

Z5 = fftshift(fft(z5));
f = [(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_Z5_freq=sum(abs(Z5).^2)/n
Pot_Z5_freq_dB=10*log10(Pot_Z5_freq)

f6 = figure;
plot(f,abs(Z5),'LineWidth',0.5,'color','blue');
title('Señal x filtrada');
xlabel('F(Hz)');
ylabel('Z1[f]')

sound(z5,fs);

%%
%FILTRO PASA BANDA de 2400 Hz a 5000 Hz


FILTER_PB = load('FBP5000.mat');
FILTER_PB = FILTER_PB.Hd;

z6= filter(FILTER_PB, x);

Z6 = fftshift(fft(z6));
f = [(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_Z6_freq=sum(abs(Z6).^2)/n
Pot_Z6_freq_dB=10*log10(Pot_Z6_freq)

f7 = figure;
plot(f,abs(Z6),'LineWidth',0.5,'color','blue');
title('Señal x filtrada');
xlabel('F(Hz)');
ylabel('Z1[f]')

sound(z6,fs);

%%
%FILTRO PASA BANDA de 5000 Hz a 10000 Hz


FILTER_PB = load('FBP10000.mat');
FILTER_PB = FILTER_PB.Hd;

z7= filter(FILTER_PB, x);

Z7 = fftshift(fft(z7));
f = [(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_Z7_freq=sum(abs(Z7).^2)/n
Pot_Z7_freq_dB=10*log10(Pot_Z7_freq)

f8 = figure;
plot(f,abs(Z7),'LineWidth',0.5,'color','blue');
title('Señal x filtrada');
xlabel('F(Hz)');
ylabel('Z1[f]')

sound(z7,fs);

%%
%FILTRO PASA BANDA de 10000 Hz a 20000 Hz


FILTER_PB = load('FBP20000.mat');
FILTER_PB = FILTER_PB.Hd;

z8= filter(FILTER_PB, x);

Z8 = fftshift(fft(z8));
f = [(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_Z8_freq=sum(abs(Z8).^2)/n
Pot_Z8_freq_dB=10*log10(Pot_Z8_freq)

f9 = figure;
plot(f,abs(Z8),'LineWidth',0.5,'color','blue');
title('Señal x filtrada');
xlabel('F(Hz)');
ylabel('Z1[f]')

sound(z8,fs);

%%

%filename = 'frec_audible.ogg';
%[y,fs] = audioread(filename);

%'La frecuenca de muestreo es:
%disp(fs); %44100

%n = length(x);
%ts = 1/fs;






