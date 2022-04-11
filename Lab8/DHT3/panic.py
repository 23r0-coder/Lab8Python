import serial
import time
from matplotlib import image
from datetime import datetime
from tkinter import *
from PIL import ImageTk, Image


arduino = serial.Serial('COM4', 9600, timeout=1)
print('Conectado')


hot = 30
cold = 25

def imge():
    ventana = Tk()
    ventana.title('¡ADVERTENCIA!')

    imagen = ImageTk.PhotoImage(Image.open(r'C:\Users\User\Desktop\LabsPython\Lab8\DHT3\panic.ico').resize((500,500)))
    boton = Button(image=imagen, command=ventana.quit)
    boton.pack()
    ventana.mainloop()

while True:
    data = arduino.readline().decode().strip()
    time.sleep(1)

    if data:
        data = float(data)
        print(data)

        if data >= hot:
            print(imge())