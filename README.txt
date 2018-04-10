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
1.	First use command "ls /usr/include/curl" to identify that /usr/include/curl/ folder exists or not.

2.	If the folder doesn.t exist. Run "sudo apt-get update" to update the application list.

3.	Run "sudo apt-get install libcurl3" to install the libcurl3.

4.	Run "sudo apt-get install libcurl4-openssl-dev" to install the development API of libcurl4.
  Use www.github.com to upload files
3.Operating instructions:
  Windows 10 64-bit Operating System, x64-based processer
  Connecting putty to PC
  Download files to raspberry Pi 3
  Run the program in raspberry and you need to make some voice to mircorephone
  and you can see the change about it
  Finally, use "ctrl + c" to shut down the program  
4.File manifest:
comm.c  project.tar  README.txt  screen.h  sound.h  testcurl
comm.h  main.c  makefile  README.md  screen.c  sound.c

5.Copyright and license:
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) <2018>  <Hu Jipan>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
6.Contact information:  
Hu Jipan
Dept. of Information technolog
Vaasa University of Applied Sciences
Woffinite 30, 65100, Vaasa, Finland
pages: www.cc.puv-fi/~e1700705
email:1448707610@qq.com
