function z = tone_generator(Fs,Frq,t)
%Esta funcion genera sonido sinusoidal puro
% Fs = frecuencia de muestreo
% Frq = frecuencia en herzios
% t = tiempo de duración segundos
%
%Fs = 44100;   % Default Sampling Frequency (Hz)
%t = 1;        % Default Time Interval
%Frq = 20;     % Tone Frequency [Hz]
%


Ts = 1/Fs;                          % Sampling Interval (s)
T = 0:Ts:t*(Fs*Ts);                 % One Second

Y = sin(2*pi*Frq*T);                % Tone
Y0 = zeros(1, Fs*2);                % Silent Interval
Ys = [repmat([Y Y0], 1, 4) Y];      % Full Tone With Silent Intervals

%Gráfico del espectro
%f1 = figure;
%plot(T,Y,'LineWidth',0.5,'color','blue');
%title('Señales Generada');
%xlabel('Tiempo(s)');
%ylabel('Y(f)');

%soundsc(Ys,Fs);                     % Play Sound
z = Y;

end