#display_libraries

import Adafruit_Nokia_LCD as LCD
import Adafruit_GPIO.SPI as SPI

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

#camera_libraries

import face_recognition
import picamera
import numpy as np
import RPi.GPIO as gpio
import time

#camera

#import time



gpio.setmode(gpio.BCM)

gpio.setwarnings(False)
gpio.setup(16, gpio.OUT)
gpio.setwarnings(False)
gpio.setup(25, gpio.OUT)
gpio.setwarnings(False)
gpio.setup(17, gpio.OUT)
gpio.setwarnings(False)
gpio.setup(20, gpio.IN, gpio.PUD_DOWN)

# Get a reference to the Raspberry Pi camera.
# If this fails, make sure you have a camera connected to the RPi and that you
# enabled your camera in raspi-config and rebooted first.
camera = picamera.PiCamera()
camera.resolution = (320, 240)
output = np.empty((240, 320, 3), dtype=np.uint8)

DC = 23
RST = 24
SPI_PORT = 0
SPI_DEVICE = 0

disp = LCD.PCD8544(DC, RST, spi=SPI.SpiDev(SPI_PORT, SPI_DEVICE, max_speed_hz=4000000))

disp.begin(contrast=60)

disp.clear()
disp.display()

#DEFINIÇÃO DOS OBJETOS DE IMAGEM

image = Image.new('1', (LCD.LCDWIDTH, LCD.LCDHEIGHT))
image2 = Image.new('1', (LCD.LCDWIDTH, LCD.LCDHEIGHT))
image3 = Image.new('1', (LCD.LCDWIDTH, LCD.LCDHEIGHT))
image4 = Image.new('1', (LCD.LCDWIDTH, LCD.LCDHEIGHT))
image5 = Image.new('1', (LCD.LCDWIDTH, LCD.LCDHEIGHT))
image6 = Image.new('1', (LCD.LCDWIDTH, LCD.LCDHEIGHT))
image7 = Image.new('1', (LCD.LCDWIDTH, LCD.LCDHEIGHT))



draw = ImageDraw.Draw(image)
draw2 = ImageDraw.Draw(image2)
draw3 = ImageDraw.Draw(image3)
draw4 = ImageDraw.Draw(image4)
draw5 = ImageDraw.Draw(image5)
draw6 = ImageDraw.Draw(image6)
draw7 = ImageDraw.Draw(image7)


draw.rectangle((0,0,LCD.LCDWIDTH,LCD.LCDHEIGHT), outline=255, fill=255)
draw2.rectangle((0,0,LCD.LCDWIDTH,LCD.LCDHEIGHT), outline=255, fill=255)
draw3.rectangle((0,0,LCD.LCDWIDTH,LCD.LCDHEIGHT), outline=255, fill=255)
draw4.rectangle((0,0,LCD.LCDWIDTH,LCD.LCDHEIGHT), outline=255, fill=255)
draw5.rectangle((0,0,LCD.LCDWIDTH,LCD.LCDHEIGHT), outline=255, fill=255)
draw6.rectangle((0,0,LCD.LCDWIDTH,LCD.LCDHEIGHT), outline=255, fill=255)
draw7.rectangle((0,0,LCD.LCDWIDTH,LCD.LCDHEIGHT), outline=255, fill=255)

#FIM DOS OBJETOS DE IMAGEM

font = ImageFont.load_default()

# Load a sample picture and learn how to recognize it.
draw.text((2,10), 'Iniciando', font=font)
draw.text((7,30), 'Sistema', font=font)

# Display image.
disp.image(image)
disp.display()

print("Iniciando Sistema")
vinicius_image = face_recognition.load_image_file("vinicius.jpg")
vinicius_face_encoding = face_recognition.face_encodings(vinicius_image)[0]
# Initialize some variables
face_locations = []
face_encodings = []

time.sleep(1)

disp.clear()
disp.display()

time.sleep(0.5)

   
while True:
  

    
    if gpio.input(20) == gpio.LOW:
      
        
        draw2.text((2,10), 'aguardando', font=font)
        draw2.text((7,30), 'consulta', font=font)
        print("Aguardando Consulta")
        
        # Display image.
        disp.image(image2)
        disp.display()
        
        time.sleep(1)

        disp.clear()
        disp.display()

        time.sleep(0.5)

        gpio.output(16, gpio.LOW)
        gpio.output(25, gpio.LOW)
        time.sleep(0.5)
        
    else:
        gpio.input(20) == gpio.HIGH
        
        draw3.text((2,10), 'Capturando', font=font)
        draw3.text((7,30), 'imagem', font=font)
        print("Capturando imagem")
        gpio.output(17, gpio.HIGH)
        time.sleep(1)
        gpio.output(17, gpio.LOW)
        
        # Display image.
        disp.image(image3)
        disp.display()
        
        time.sleep(0.5)

        disp.clear()
        disp.display()

        time.sleep(0.5)
        
        # Grab a single frame of video from the RPi camera as a numpy array
        camera.capture(output, format="rgb")

                    # Find all the faces and face encodings in the current frame of video
        face_locations = face_recognition.face_locations(output)
        
        
        
        print("Checando banco de dados.".format(len(face_locations)))
        
        draw4.text((2,10), 'checando', font=font)
        draw4.text((7,30), 'banco', font=font)
         # Display image.
        disp.image(image4)
        disp.display()
        
        
        time.sleep(0.5)

        #disp.clear()
        #disp.display()

        #time.sleep(1)
        
        face_encodings = face_recognition.face_encodings(output, face_locations)
        
       

                    # Loop over each face found in the frame to see if it's someone we know.
        for face_encoding in face_encodings:
                            # See if the face is a match for the known face(s)
            match = face_recognition.compare_faces([vinicius_face_encoding], face_encoding)
            # name = "Pessoa Desconhecida"
                        

            if match[0]:
                
                name = "Vinicius Ferreira Ribeiro"
                name1 = 'Vinicius Ferreira Ribeiro'
                gpio.output(16, gpio.HIGH)
                
                
            else:
               
                name = "Nao Consta no banco de dados."
                name1 = 'Nao Consta'
                gpio.output(25, gpio.HIGH)
                
                
                
            draw7.text((2,10), 'procurado:', font=font)
            draw7.text((7,30),format(name1), font=font)
            disp.image(image7)
            disp.display()
            
            print("Procurado:{}".format(name))
            #gpio.output(16, gpio.HIGH)
            time.sleep(2)
