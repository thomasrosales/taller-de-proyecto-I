function z = tone_generator()

filename = 'frec_audible.ogg';
%filename = '01 Intro - Soda.mp3'
[x,fs] = audioread(filename);

%disp(fs);
n = length(x);
Ts = 1/fs; 

%calculo de potencia tiempo
Pot_x_temp=var(x)+mean(x).^2

FILTER_PB = load('FLP160.mat');
FILTER_PB = FILTER_PB.Hd;

z1 = filter(FILTER_PB, x);

Z1 = fftshift(fft(z1));
f = [(1-(1/n)*mod(n,2))*(-1/(2*Ts)):(1/n)*(1/Ts):((n-1)/n)*(1/(2*Ts))];

%calculo de potencia frequencia
Pot_Z1_freq=sum(abs(Z1).^2)/n
Pot_Z1_freq_dB=10*log10(Pot_Z1_freq)

end