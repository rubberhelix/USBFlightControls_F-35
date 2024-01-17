#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-PIC18F4550_usb_hid.mk)" "nbproject/Makefile-local-PIC18F4550_usb_hid.mk"
include nbproject/Makefile-local-PIC18F4550_usb_hid.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PIC18F4550_usb_hid
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Throttle.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Throttle.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../source/usb/usb_device.c ../source/usb/usb_descriptors.c ../source/usb/usb_device_hid.c ../source/usb/usb_events.c ../source/adc.c ../source/app_device_joystick.c ../source/buttons.c ../source/main.c system.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1361295679/usb_device.p1 ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1 ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1 ${OBJECTDIR}/_ext/1361295679/usb_events.p1 ${OBJECTDIR}/_ext/812168374/adc.p1 ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1 ${OBJECTDIR}/_ext/812168374/buttons.p1 ${OBJECTDIR}/_ext/812168374/main.p1 ${OBJECTDIR}/system.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1361295679/usb_device.p1.d ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1.d ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1.d ${OBJECTDIR}/_ext/1361295679/usb_events.p1.d ${OBJECTDIR}/_ext/812168374/adc.p1.d ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1.d ${OBJECTDIR}/_ext/812168374/buttons.p1.d ${OBJECTDIR}/_ext/812168374/main.p1.d ${OBJECTDIR}/system.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1361295679/usb_device.p1 ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1 ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1 ${OBJECTDIR}/_ext/1361295679/usb_events.p1 ${OBJECTDIR}/_ext/812168374/adc.p1 ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1 ${OBJECTDIR}/_ext/812168374/buttons.p1 ${OBJECTDIR}/_ext/812168374/main.p1 ${OBJECTDIR}/system.p1

# Source Files
SOURCEFILES=../source/usb/usb_device.c ../source/usb/usb_descriptors.c ../source/usb/usb_device_hid.c ../source/usb/usb_events.c ../source/adc.c ../source/app_device_joystick.c ../source/buttons.c ../source/main.c system.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-PIC18F4550_usb_hid.mk ${DISTDIR}/Throttle.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4550
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1361295679/usb_device.p1: ../source/usb/usb_device.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1361295679" 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_device.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_device.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1361295679/usb_device.p1 ../source/usb/usb_device.c 
	@-${MV} ${OBJECTDIR}/_ext/1361295679/usb_device.d ${OBJECTDIR}/_ext/1361295679/usb_device.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1361295679/usb_device.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1: ../source/usb/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1361295679" 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1 ../source/usb/usb_descriptors.c 
	@-${MV} ${OBJECTDIR}/_ext/1361295679/usb_descriptors.d ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1: ../source/usb/usb_device_hid.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1361295679" 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1 ../source/usb/usb_device_hid.c 
	@-${MV} ${OBJECTDIR}/_ext/1361295679/usb_device_hid.d ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1361295679/usb_events.p1: ../source/usb/usb_events.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1361295679" 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_events.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_events.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1361295679/usb_events.p1 ../source/usb/usb_events.c 
	@-${MV} ${OBJECTDIR}/_ext/1361295679/usb_events.d ${OBJECTDIR}/_ext/1361295679/usb_events.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1361295679/usb_events.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/812168374/adc.p1: ../source/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/812168374" 
	@${RM} ${OBJECTDIR}/_ext/812168374/adc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/812168374/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/812168374/adc.p1 ../source/adc.c 
	@-${MV} ${OBJECTDIR}/_ext/812168374/adc.d ${OBJECTDIR}/_ext/812168374/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/812168374/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/812168374/app_device_joystick.p1: ../source/app_device_joystick.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/812168374" 
	@${RM} ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1.d 
	@${RM} ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1 ../source/app_device_joystick.c 
	@-${MV} ${OBJECTDIR}/_ext/812168374/app_device_joystick.d ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/812168374/buttons.p1: ../source/buttons.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/812168374" 
	@${RM} ${OBJECTDIR}/_ext/812168374/buttons.p1.d 
	@${RM} ${OBJECTDIR}/_ext/812168374/buttons.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/812168374/buttons.p1 ../source/buttons.c 
	@-${MV} ${OBJECTDIR}/_ext/812168374/buttons.d ${OBJECTDIR}/_ext/812168374/buttons.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/812168374/buttons.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/812168374/main.p1: ../source/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/812168374" 
	@${RM} ${OBJECTDIR}/_ext/812168374/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/812168374/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/812168374/main.p1 ../source/main.c 
	@-${MV} ${OBJECTDIR}/_ext/812168374/main.d ${OBJECTDIR}/_ext/812168374/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/812168374/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/system.p1: system.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.p1.d 
	@${RM} ${OBJECTDIR}/system.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/system.p1 system.c 
	@-${MV} ${OBJECTDIR}/system.d ${OBJECTDIR}/system.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/system.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1361295679/usb_device.p1: ../source/usb/usb_device.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1361295679" 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_device.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_device.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1361295679/usb_device.p1 ../source/usb/usb_device.c 
	@-${MV} ${OBJECTDIR}/_ext/1361295679/usb_device.d ${OBJECTDIR}/_ext/1361295679/usb_device.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1361295679/usb_device.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1: ../source/usb/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1361295679" 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1 ../source/usb/usb_descriptors.c 
	@-${MV} ${OBJECTDIR}/_ext/1361295679/usb_descriptors.d ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1361295679/usb_descriptors.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1: ../source/usb/usb_device_hid.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1361295679" 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1 ../source/usb/usb_device_hid.c 
	@-${MV} ${OBJECTDIR}/_ext/1361295679/usb_device_hid.d ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1361295679/usb_device_hid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1361295679/usb_events.p1: ../source/usb/usb_events.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1361295679" 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_events.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1361295679/usb_events.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1361295679/usb_events.p1 ../source/usb/usb_events.c 
	@-${MV} ${OBJECTDIR}/_ext/1361295679/usb_events.d ${OBJECTDIR}/_ext/1361295679/usb_events.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1361295679/usb_events.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/812168374/adc.p1: ../source/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/812168374" 
	@${RM} ${OBJECTDIR}/_ext/812168374/adc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/812168374/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/812168374/adc.p1 ../source/adc.c 
	@-${MV} ${OBJECTDIR}/_ext/812168374/adc.d ${OBJECTDIR}/_ext/812168374/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/812168374/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/812168374/app_device_joystick.p1: ../source/app_device_joystick.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/812168374" 
	@${RM} ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1.d 
	@${RM} ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1 ../source/app_device_joystick.c 
	@-${MV} ${OBJECTDIR}/_ext/812168374/app_device_joystick.d ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/812168374/app_device_joystick.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/812168374/buttons.p1: ../source/buttons.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/812168374" 
	@${RM} ${OBJECTDIR}/_ext/812168374/buttons.p1.d 
	@${RM} ${OBJECTDIR}/_ext/812168374/buttons.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/812168374/buttons.p1 ../source/buttons.c 
	@-${MV} ${OBJECTDIR}/_ext/812168374/buttons.d ${OBJECTDIR}/_ext/812168374/buttons.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/812168374/buttons.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/812168374/main.p1: ../source/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/812168374" 
	@${RM} ${OBJECTDIR}/_ext/812168374/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/812168374/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/812168374/main.p1 ../source/main.c 
	@-${MV} ${OBJECTDIR}/_ext/812168374/main.d ${OBJECTDIR}/_ext/812168374/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/812168374/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/system.p1: system.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.p1.d 
	@${RM} ${OBJECTDIR}/system.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/system.p1 system.c 
	@-${MV} ${OBJECTDIR}/system.d ${OBJECTDIR}/system.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/system.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Throttle.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Throttle.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=pickit3  -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -gdwarf-3 -mstack=compiled:auto:auto:auto     -mrom=default,-7dc0-7fff -mram=default,-3f4-3ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Throttle.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Throttle.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Throttle.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Throttle.X.${IMAGE_TYPE}.map  -DXPRJ_PIC18F4550_usb_hid=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -maddrqual=require -xassembler-with-cpp -I"." -I"../headers" -I"../source" -I"../headers/usb" -I"../source/usb" -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Throttle.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
