# **PARS: Design Space Exploration for Low-Latency Ring-LWE via HLS :tiger:**

Xilinx Open HW Design Contest 2020 Competition  project  xohw20_170

University name: Eskisehir Technical University	

## *Link to YouTube Video:* 
https://www.youtube.com/watch?v=wVZGrSAV1GI&feature=youtu.be 

## *Participant(s):*
###   Participant 1 : Adem Savaş 
###   Participant 2:  Mehmet Atakan Kalkar
###   Supervisor name: Assist. Prof. Dr. İsmail San



## *For further information please contact us:*

###  Email participant 1: adamsvs@live.com

###  Email participant 2: atakankalkar@gmail.com

###   Supervisor e-mail: isan@eskisehir.edu.tr


 
 
 ## *Which xilinx board and software we used? :thinking:*
Board used: Zynq-7000 (ZedBoard)
Software Version: Vivado 2017.4
		  Vivado HLS 2017.4

## *Project Description:*

Design space exploration of post-quantum cryptographic algorithm,Ring Learning With Errors (Ring-LWE), for low latency via HLS.
In our project, Ring-LWE Encryption/Decryption was optimized in order to obtain power-efficient, higher performance 
and reliable design with System on Chip solution.
 
## *Project Report*
 Project phases and more detail about project is shared in this repository as Pars_project_report_xohw20_170.pdf.
 
## *Ring-LWE source code link we used throughout the project:*
				
[GitHub](https://github.com/ruandc/Ring-LWE-Encryption)


## *Instructions to build and test project*


* ### **For SD card booting 1st way;**

#### Step 1: load sd_image/bootfile/boot.bin file to SD Card
#### Step 2: Open any terminal program for uart communication
#### Step 3: insert SD Card to zedboard, automatically fpga will be programmed and press any button of(T18,R18,R16,N15,P16) to start application.

* ### **For SD card booting 2nd way;**

#### Step 1: Open Vivado SDK tool
#### Step 2: Press Xilinx > create boot image from upper toolbar.
#### Step 3: Select Output BIF file path and output path wherever you want, for boot image partitions part add given files in \sd_image\Image creating files
##### FSBL.elf -> bootloader
##### design_1_wrapper.bit file and encdec.elf -> datafile
#### Step 4: press create image and load created boot.bin file to SD Card
#### Step 5:insert SD Card to zedboard, automatically fpga will be programmed and press any button of(T18,R18,R16,N15,P16) to start application.

* ### **Generate vivado project file with .tcl file for phase 5 - (same as other phases)**

#### Step 1: Open vivado tcl console
#### Step 2 :  > cd (your path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5
#### Step 3 :  > source vivado_prj.tcl
#### Step 4: After generating vivado project  generate bitstream and export hardware including bitstream then, launch sdk
#### Step 5: Open projects from file system > (your_path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5\sdk_project
#### Step 6: Program fpga with (your_path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5\hw\design_1_wrapper.bit
#### Step 7: Connect any terminal for uart communication and run the application  for example right click > run as > Launch on Hardware (GDB)


* ### **If you would like to add our accelerator to your design 1st way:**

#### Step 1: Open HLS command prompt
#### Step 2:  > cd (your path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5
#### Step 3:  > vivado_hls script.tcl
#### Step 4: produced IP core will be ready at the same directory with tcl file

* ### **If you would like to add our accelerator to your design 2nd way:**
#### Step 1 : add repository to IP catalog with referencing (your path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5\HLS_ip\ip
				


