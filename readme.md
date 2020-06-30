Team number: xohw20_170

Project name: PARS: Design Space Exploration for Low-Latency Ring-LWE via HLS

Date: 30 June 2020

Version of uploaded archive: Version 1

 

University name: Eskisehir Technical University	

Supervisor name: Assist. Prof. Dr. İsmail San

Supervisor e-mail: isan@eskisehir.edu.tr

Participant(s):

Participant 1 : Adem Savaş 
Participant 2:  Mehmet Atakan Kalkar

Email participant 1: adamsvs@live.com
Email participant 2: atakankalkar@gmail.com


 

Board used: Zynq-7000 (ZedBoard)

Software Version: Vivado 2017.4
		  Vivado HLS 2017.4

Brief description of project:
Design space exploration of post-quantum cryptographic algorithm,Ring Learning With Errors (Ring-LWE), for low latency via HLS.
In our project, Ring-LWE Encryption/Decryption was optimized in order to obtain power-efficient, higher performance 
and reliable design with System on Chip solution.

Link to project repository: https://github.com/atakankalkar/pars_designspaceexp_xohw20_170

 

Description of archive (explain directory structure, documents and source files):

Instructions to build and test project

----For SD card booting 1st way;

Step 1: load sd_image/bootfile/boot.bin file to SD Card
Step 2: Open any terminal program for uart communication
Step 3: insert SD Card to zedboard, automatically fpga will be programmed
 and press any button of(T18,R18,R16,N15,P16) to start application.

----For SD card booting 2nd way;

Step 1: Open Vivado SDK tool
Step 2: Press Xilinx > create boot image from upper toolbar.
Step 3: Select Output BIF file path and output path wherever you want, for boot image partitions part
add given files in \sd_image\Image creating files
FSBL.elf -> bootloader
design_1_wrapper.bit file and encdec.elf -> datafile
Step 4: press create image and load created boot.bin file to SD Card
Step 5:insert SD Card to zedboard, automatically fpga will be programmed
 and press any button of(T18,R18,R16,N15,P16) to start application.

----Generate vivado project file with .tcl file for phase 5 - (same as other phases)

Step 1: Open vivado tcl console
step 2 :  > cd (your path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5
step 3 :  > source vivado_prj.tcl
step 4: After generating vivado project  generate bitstream and export hardware including bitstream then, launch sdk
step 5: Open projects from file system > (your_path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5\sdk_project
step 6: Program fpga with (your_path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5\hw\design_1_wrapper.bit
step 7: Connect any terminal for uart communication and run the application 
	for example right click > run as > Launch on Hardware (GDB)


----If you would like to add our accelerator to your design 1st way:

Step 1: Open HLS command prompt
Step 2:  > cd (your path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5
Step 3:  > vivado_hls script.tcl
step 4: produced IP core will be ready at the same directory with tcl file

----If you would like to add our accelerator to your design 2nd way:
step 1 : add repository to IP catalog with referencing
 				(your path)...\student_xohw20-170_san_20200630_1\Project_directory\Phase5\HLS_ip\ip

Link to YouTube Video(s): https://www.youtube.com/watch?v=wVZGrSAV1GI&feature=youtu.be