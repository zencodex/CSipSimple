************************************************************************
Fixed Point SILK SDK 1.0.9 MIPS source code package
Copyright 2012 (c), Skype Limited
https://developer.skype.com/silk/
************************************************************************

Date: 03/08/2012 (Format: DD/MM/YYYY)

I. Description

This package contains files for compilation and evaluation of the fixed
point SILK SDK library. The following is included in this package:

    o Source code for the fixed point SILK SDK library
    o Source code for creating encoder and decoder executables
    o Test vectors
    o Comparison tool
    o Microsoft Visual Studio solutions and project files
    o Makefile for GNU C-compiler (GCC)
    
II. Files and Folders

    o doc/          - contains more information about the SILK SDK
    o interface/    - contains API header files
    o src/          - contains all SILK SDK library source files
    o test/         - contains source files for testing the SILK SDK
    o test_vectors/ - contains test vectors   
    o Makefile      - Makefile for compiling with GCC
    o readme.txt    - this file
    o Silk_SDK.sln  - Visual Studio 2010 solution for all SILK SDK code
    o Silk_SDK_VS2005.sln - Visual Studio 2005 solution for all SILK SDK code

III. How to use the Makefile

    1. How to clean and compile the SILK SDK library:
      	  
       make clean lib
 
    2. How to compile an encoder executable:

       make encoder 

    3. How to compile a decoder executable:

       make decoder 

    4. How to compile the comparison tool:

       make signalcompare 

    5. How to clean and compile all of the above:

       make clean all 

    6. How to clean and compile for MIPS based device using a cross compiler:

       make clean all TOOLCHAIN_PREFIX=(1)

       (1) Compiler toolchain prefix, most cross-compilers do need to specify that.

    7. How to build for MIPS big endian or little endian CPU's

       - for big endian:     make clean all MIPS=yes
       - for little endian:  make clean all MIPSEL=yes
       
       Note that the 16 bit input and output from the test programs will have the upper and lower bytes swapped between little and big endian. 

    8. How to build native C code on MIPS target (no assembly code)

       make clean all MIPS[EL]=yes ADDED_DEFINES+=NO_ASM 

    9. How to use the comparison tool:

       See 'How to use the test vectors.txt' in the test_vectors folder.     	

IV. History

    Version 1.0.9 - Added 64-bit support. Added iOS LLVM compiler support. Lowered DTX mode bitrate. Bugfixes for ARM builds. Various other small fixes.
    Version 1.0.8 - Improved noise shaping, various other improvements, and various bugfixes. Added a MIPS version
    Version 1.0.7 - Updated with bugfixes for LBRR and pitch estimator. SignalCompare updated
    Version 1.0.6 - Updated with bugfixes for ARM builds
    Version 1.0.5 - Updated with bugfixes for ARM builds
    Version 1.0.4 - Updated with various bugfixes and improvements, including some API changes
                    Added support for big endian platforms
                    Added resampler support for additional API sample rates
    Version 1.0.3 - Updated with various bugfixes and improvements 
    Version 1.0.2 - Updated with various bugfixes and improvements
    Version 1.0.1 - First beta source code release
    
V. Compatibility

    This package has been tested on the following platforms:

    Windows 7 Professional,  32-bit version, Intel Core i7 CPU
    Windows 7 Professional,  64-bit version, Intel Core i7 CPU
    Mac OS X Version 10.7.4, 64-bit version, Intel Core i7 CPU
    Ubuntu Linux 10.04 LTS,  32-bit version, Intel Core i7 CPU
    Ubuntu Linux 12.04 LTS,  64-bit version, Intel Core 2 Duo CPU
	
    MIPS:
    Qemu mips/mipsel emulation platform

VI. Known Issues

    None

VII. Additional Resources

    For more information, visit the SILK SDK web site at:

    <https://developer.skype.com/silk/>
