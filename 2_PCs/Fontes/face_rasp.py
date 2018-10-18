import face_recognition
import picamera
import numpy as np
import RPi.GPIO as gpio
import time


gpio.setmode(gpio.BOARD)

gpio.setwarnings(False)
gpio.setup(36, gpio.OUT)
gpio.setwarnings(False)
gpio.setup(22, gpio.OUT)
gpio.setwarnings(False)
gpio.setup(38, gpio.IN, gpio.PUD_DOWN)

# Get a reference to the Raspberry Pi camera.
# If this fails, make sure you have a camera connected to the RPi and that you
# enabled your camera in raspi-config and rebooted first.
camera = picamera.PiCamera()
camera.resolution = (320, 240)
output = np.empty((240, 320, 3), dtype=np.uint8)

# Load a sample picture and learn how to recognize it.
print("Iniciando Sistema")
vinicius_image = face_recognition.load_image_file("vinicius.jpg")
vinicius_face_encoding = face_recognition.face_encodings(vinicius_image)[0]

# Initialize some variables
face_locations = []
face_encodings = []

while True:
    
    if gpio.input(38) == gpio.LOW:
            
        print("Aguardando Consulta")
        gpio.output(36, gpio.LOW)
        gpio.output(22, gpio.LOW)
        time.sleep(0.5)
        
    else:
        gpio.input(38) == gpio.HIGH
                    
        print("Capturando imagem")
                    # Grab a single frame of video from the RPi camera as a numpy array
        camera.capture(output, format="rgb")

                    # Find all the faces and face encodings in the current frame of video
        face_locations = face_recognition.face_locations(output)
        print("Checando banco de dados.".format(len(face_locations)))
        face_encodings = face_recognition.face_encodings(output, face_locations)

                    # Loop over each face found in the frame to see if it's someone we know.
        for face_encoding in face_encodings:
                            # See if the face is a match for the known face(s)
            match = face_recognition.compare_faces([vinicius_face_encoding], face_encoding)
            # name = "Pessoa Desconhecida"
                        

            if match[0]:
                name = "Vinicius Ferreira Ribeiro"
                gpio.output(36, gpio.HIGH)
            else:
                name = "Nao Consta no banco de dados."
                gpio.output(22, gpio.HIGH)

            print("Procurado:{}".format(name))
            #gpio.output(16, gpio.HIGH)
            time.sleep(2)
