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
CND_PLATFORM=Cygwin-Windows
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
	${OBJECTDIR}/data.o \
	${OBJECTDIR}/equipments.o \
	${OBJECTDIR}/input.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/maintenances.o \
	${OBJECTDIR}/menus.o \
	${OBJECTDIR}/users.o \
	${OBJECTDIR}/utilities.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trabalho_recurso.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trabalho_recurso.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trabalho_recurso ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/data.o: data.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/data.o data.c

${OBJECTDIR}/equipments.o: equipments.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/equipments.o equipments.c

${OBJECTDIR}/input.o: input.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/input.o input.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/maintenances.o: maintenances.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/maintenances.o maintenances.c

${OBJECTDIR}/menus.o: menus.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menus.o menus.c

${OBJECTDIR}/users.o: users.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/users.o users.c

${OBJECTDIR}/utilities.o: utilities.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utilities.o utilities.c

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
