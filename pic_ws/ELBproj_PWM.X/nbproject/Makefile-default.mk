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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_PWM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_PWM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ELB_OSC.c ELB_PWM.c ELBv21_HardwareConfig.c Main.c ELB_Timer.c ELB_LCD.c ELB_I2C.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ELB_OSC.o ${OBJECTDIR}/ELB_PWM.o ${OBJECTDIR}/ELBv21_HardwareConfig.o ${OBJECTDIR}/Main.o ${OBJECTDIR}/ELB_Timer.o ${OBJECTDIR}/ELB_LCD.o ${OBJECTDIR}/ELB_I2C.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ELB_OSC.o.d ${OBJECTDIR}/ELB_PWM.o.d ${OBJECTDIR}/ELBv21_HardwareConfig.o.d ${OBJECTDIR}/Main.o.d ${OBJECTDIR}/ELB_Timer.o.d ${OBJECTDIR}/ELB_LCD.o.d ${OBJECTDIR}/ELB_I2C.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ELB_OSC.o ${OBJECTDIR}/ELB_PWM.o ${OBJECTDIR}/ELBv21_HardwareConfig.o ${OBJECTDIR}/Main.o ${OBJECTDIR}/ELB_Timer.o ${OBJECTDIR}/ELB_LCD.o ${OBJECTDIR}/ELB_I2C.o

# Source Files
SOURCEFILES=ELB_OSC.c ELB_PWM.c ELBv21_HardwareConfig.c Main.c ELB_Timer.c ELB_LCD.c ELB_I2C.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_PWM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256GB206
MP_LINKER_FILE_OPTION=,-Tp24FJ256GB206.gld
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ELB_OSC.o: ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/ELB_OSC.o.ok ${OBJECTDIR}/ELB_OSC.o.err 
	@${RM} ${OBJECTDIR}/ELB_OSC.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_OSC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_OSC.o.d" -o ${OBJECTDIR}/ELB_OSC.o ELB_OSC.c    
	
${OBJECTDIR}/ELB_PWM.o: ELB_PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_PWM.o.d 
	@${RM} ${OBJECTDIR}/ELB_PWM.o.ok ${OBJECTDIR}/ELB_PWM.o.err 
	@${RM} ${OBJECTDIR}/ELB_PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_PWM.o.d" -o ${OBJECTDIR}/ELB_PWM.o ELB_PWM.c    
	
${OBJECTDIR}/ELBv21_HardwareConfig.o: ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o.ok ${OBJECTDIR}/ELBv21_HardwareConfig.o.err 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/ELBv21_HardwareConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELBv21_HardwareConfig.o.d" -o ${OBJECTDIR}/ELBv21_HardwareConfig.o ELBv21_HardwareConfig.c    
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o.ok ${OBJECTDIR}/Main.o.err 
	@${RM} ${OBJECTDIR}/Main.o 
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d" -o ${OBJECTDIR}/Main.o Main.c    
	
${OBJECTDIR}/ELB_Timer.o: ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/ELB_Timer.o.ok ${OBJECTDIR}/ELB_Timer.o.err 
	@${RM} ${OBJECTDIR}/ELB_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_Timer.o.d" -o ${OBJECTDIR}/ELB_Timer.o ELB_Timer.c    
	
${OBJECTDIR}/ELB_LCD.o: ELB_LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_LCD.o.d 
	@${RM} ${OBJECTDIR}/ELB_LCD.o.ok ${OBJECTDIR}/ELB_LCD.o.err 
	@${RM} ${OBJECTDIR}/ELB_LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_LCD.o.d" -o ${OBJECTDIR}/ELB_LCD.o ELB_LCD.c    
	
${OBJECTDIR}/ELB_I2C.o: ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/ELB_I2C.o.ok ${OBJECTDIR}/ELB_I2C.o.err 
	@${RM} ${OBJECTDIR}/ELB_I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_I2C.o.d" -o ${OBJECTDIR}/ELB_I2C.o ELB_I2C.c    
	
else
${OBJECTDIR}/ELB_OSC.o: ELB_OSC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_OSC.o.d 
	@${RM} ${OBJECTDIR}/ELB_OSC.o.ok ${OBJECTDIR}/ELB_OSC.o.err 
	@${RM} ${OBJECTDIR}/ELB_OSC.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_OSC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_OSC.o.d" -o ${OBJECTDIR}/ELB_OSC.o ELB_OSC.c    
	
${OBJECTDIR}/ELB_PWM.o: ELB_PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_PWM.o.d 
	@${RM} ${OBJECTDIR}/ELB_PWM.o.ok ${OBJECTDIR}/ELB_PWM.o.err 
	@${RM} ${OBJECTDIR}/ELB_PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_PWM.o.d" -o ${OBJECTDIR}/ELB_PWM.o ELB_PWM.c    
	
${OBJECTDIR}/ELBv21_HardwareConfig.o: ELBv21_HardwareConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o.d 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o.ok ${OBJECTDIR}/ELBv21_HardwareConfig.o.err 
	@${RM} ${OBJECTDIR}/ELBv21_HardwareConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/ELBv21_HardwareConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELBv21_HardwareConfig.o.d" -o ${OBJECTDIR}/ELBv21_HardwareConfig.o ELBv21_HardwareConfig.c    
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o.ok ${OBJECTDIR}/Main.o.err 
	@${RM} ${OBJECTDIR}/Main.o 
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d" -o ${OBJECTDIR}/Main.o Main.c    
	
${OBJECTDIR}/ELB_Timer.o: ELB_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_Timer.o.d 
	@${RM} ${OBJECTDIR}/ELB_Timer.o.ok ${OBJECTDIR}/ELB_Timer.o.err 
	@${RM} ${OBJECTDIR}/ELB_Timer.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_Timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_Timer.o.d" -o ${OBJECTDIR}/ELB_Timer.o ELB_Timer.c    
	
${OBJECTDIR}/ELB_LCD.o: ELB_LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_LCD.o.d 
	@${RM} ${OBJECTDIR}/ELB_LCD.o.ok ${OBJECTDIR}/ELB_LCD.o.err 
	@${RM} ${OBJECTDIR}/ELB_LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_LCD.o.d" -o ${OBJECTDIR}/ELB_LCD.o ELB_LCD.c    
	
${OBJECTDIR}/ELB_I2C.o: ELB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ELB_I2C.o.d 
	@${RM} ${OBJECTDIR}/ELB_I2C.o.ok ${OBJECTDIR}/ELB_I2C.o.err 
	@${RM} ${OBJECTDIR}/ELB_I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/ELB_I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ELB_I2C.o.d" -o ${OBJECTDIR}/ELB_I2C.o ELB_I2C.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_PWM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_PWM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_PWM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_PWM.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/ELBproj_PWM.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
