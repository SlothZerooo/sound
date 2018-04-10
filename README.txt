# ---------------------- Sound Level Sensor ---------------------------
Sound level meter project made by Hu Jipan, Feb.2018.

This progect uses a Raspberry Pi 3 Mode B as a sound sensor. A USB sound card
with microphone and a RJ45 cable are needed as peripheral. The application runs
periodically every second and take record from microphone at a sample rate of 
as a bar chart on termial screen. If commmunication is ended (conditional
complication), the second will be re-calculated into 8 pieces of Fast Level data
and sent out a PHP server program.
List Contents
1.Configuration instructions
2.Installation instructions
3.Operating instructions
4.File manifest
5.Copyright and license
6.Contact information

1.Configuration instructions:  
  Software: PUTTY
  Hardware: USB Sound Card, RJ45 Cable, Raspberry Pi 3, microphone 
2.Installation instructions:
  Use www.github.com to upload files
3.Operating instructions:

4.File manifest:
comm.c  comm.o  main.o    project.tar  README.txt  screen.h  sound.a  sound.h  testcurl
comm.h  main.c  makefile  README.md    screen.c    screen.o  sound.c  sound.o  test.wav

5.Copyright and license:
Reference to Wikipedia
6.Contact information:  
ALL
Hu Jipan
Dept. of Information technolog
Vaasa University of Applied Sciences
Woffinite 30, 65100, Vaasa, Finland
pages: www.cc.puv-fi/~e1700705
email:1448707610@qq.com
