import matplotlib.pyplot as plt
from datetime import datetime
from matplotlib import pyplot
from matplotlib.animation import FuncAnimation
from random import randrange
import serial
import time

ard = serial.Serial('COM4', 9600)

while 1:
  datos = ard.readline()
  print(datos)