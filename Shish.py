import sounddevice as sd
import numpy as np
import matplotlib
import matplotlib.pyplot as plt

duration = 0.3  # длительность сигнала в секундах
amplitude = 0.5  # амплитуда  (в пределах: +-1.0)
frequency = 293.6648  # частота сигнала в [Гц]
# т.к. невозможно программно организовать аналоговый сигнал, необходимо обозначить
fs = 80000 # 80 тыс. временных отсчетов в 1 секунду количество временных отчетов, т.е. частоту дискретизации (об этом чуть позже)


timeSamples = np.arange(np.ceil(duration * fs)) / fs
timeSamples

signal2 = amplitude * np.sin(2 * np.pi * 155.560 * timeSamples)
signal3 = amplitude * np.sin(2 * np.pi * 185 * timeSamples)
signal4 = amplitude * np.sin(2 * np.pi * 174.610 * timeSamples)
signal5 = amplitude * np.sin(2 * np.pi * 146.830 * timeSamples)
signalSumm = signal2 + signal3 + signal4 + signal5

for i  in range(0, 4):
    sd.play(signal2, fs, None, 1)
sd.play(signal3, fs, None, 1)
sd.play(signal2, fs, None, 1)
sd.play(signal3, fs, None, 1)
sd.play(signal4, fs, None, 1)
sd.play(signal2, fs, None, 1)
sd.play(signal4, fs, None, 1)
for i  in range(0, 7):
    sd.play(signal5, fs, None, 1)

plt.plot(timeSamples[:2000] * 1000, signalSumm[:2000])
plt.title("sine tone")
plt.xlabel("time / milliseconds")