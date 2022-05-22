import numpy as np
import matplotlib.pyplot as plt

duration = 1  # длительность сигнала в секундах
amplitude = 0.1  # амплитуда  (в пределах: +-1.0)

fs = 44000 # частота дискретизации

timeSamples = np.arange(np.ceil(duration * fs)) / fs

signal2 = amplitude * np.sin(2 * np.pi * 155.560 * timeSamples)
signal3 = amplitude * np.sin(2 * np.pi * 185 * timeSamples)
signal4 = amplitude * np.sin(2 * np.pi * 174.610 * timeSamples)
signal5 = amplitude * np.sin(2 * np.pi * 146.830 * timeSamples)

signalSumm = signal2 + signal3 + signal4 + signal5

plt.plot(signalSumm[:500])
plt.title("sine tone")
plt.xlabel("time / milliseconds")

N = duration * fs

spector = np.fft.rfft(signalSumm)
x_axis = np.fft.rfftfreq(N, 1/fs)

plt.plot(x_axis, np.abs(spector))
plt.show()

new_sig = np.fft.irfft(spector)
plt.plot(new_sig[:500])
plt.show()






