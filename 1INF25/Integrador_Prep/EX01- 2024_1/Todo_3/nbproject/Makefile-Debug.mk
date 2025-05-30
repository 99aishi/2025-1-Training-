#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ColaPrioridadGenerica.o \
	${OBJECTDIR}/PunterosFuncion1Examen01Pregunta02.o \
	${OBJECTDIR}/PunterosFuncion1Examen01Pregunta02.h.o \
	${OBJECTDIR}/Registros.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L. liblibestaticap2.a liblibestaticap1.a libaperturadearchivosbibl.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/todo_3.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/todo_3.exe: liblibestaticap2.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/todo_3.exe: liblibestaticap1.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/todo_3.exe: libaperturadearchivosbibl.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/todo_3.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/todo_3 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ColaPrioridadGenerica.o: ColaPrioridadGenerica.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ColaPrioridadGenerica.o ColaPrioridadGenerica.cpp

${OBJECTDIR}/PunterosFuncion1Examen01Pregunta02.o: PunterosFuncion1Examen01Pregunta02.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PunterosFuncion1Examen01Pregunta02.o PunterosFuncion1Examen01Pregunta02.cpp

${OBJECTDIR}/PunterosFuncion1Examen01Pregunta02.h.o: PunterosFuncion1Examen01Pregunta02.h.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PunterosFuncion1Examen01Pregunta02.h.o PunterosFuncion1Examen01Pregunta02.h.cpp

${OBJECTDIR}/Registros.o: Registros.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Registros.o Registros.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
