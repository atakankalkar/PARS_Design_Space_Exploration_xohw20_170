This file contains each project phase's source files. 
1 Project was added for each phases.
Project Phases was described in Project report as follows;

PHASE 1: Implementation and profiling Ring-LWE algorithm as pure software on ZedBoard 
only by using Zynq Processing System.

(Elapsed time and amount of clock cycles for pure software rlwe implementation.)

PHASE 2: Implementation of encryption, decryption functions and their sub-functions
on programmable logic side without any optimization.

(RLWE_enc2 function IP core is produced with old versions of clz and mod function)

PHASE 3: Optimization and substitution the functions which are called so many times
based on profiling and HLS compatibility.

(RLWE_enc2 function IP core is produced with new versions of clz and mod function)

PHASE 4: Experimenting HLS configurations and optimization directives to obtain best
efficiency in terms of latency and utilization.

(encdec(rlwe_enc2 + rlwe_dec2) function produced without data transfer optimization with master
port)

PHASE 5: Data transfer optimization in terms of latency from programmable logic side to
Processing System side by using High Performance port.

(encdec(rlwe_enc2 + rlwe_Dec2) function produced with data transfer optimization for PL to PS)
!! Final Version of our project !!




-- In phase 1 ;
   just contains sdk_project files because pure software implementation of Ring LWE can be experimented with any bitstream file with any vivado project by creating
sdk project with given sdk_project file. 

--In other phases; (Phase 2,3,4,5)
	script.tcl - script file for synthesize and export RTL
	vivado_prj.tcl - script file for generating vivado project with our block design
	hdl - contains system_wrapper.vhd file for helping the tcl file to generating vivado project with block design
	HLS_ip -  This file helps tcl file to create block design with our accelerator. Also, Includes necessary files for adding
	repository to IP Catalog (ip file, vhdl and verilog files)
	HLS_source - includes HLS source files which are used for producing our accelerator in script.tcl
	hw- includes bitstream file ( .bit file for programming fpga)
	sdk_project - includes necessary sdk project file and bsp file . Also it includes necessary header and .c files to build a 
	project in Vivado SDK
	



