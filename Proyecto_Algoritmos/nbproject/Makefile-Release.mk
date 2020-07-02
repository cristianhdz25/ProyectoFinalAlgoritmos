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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ActualizarVuelo.o \
	${OBJECTDIR}/Aerolinea.o \
	${OBJECTDIR}/AerolineaBusiness.o \
	${OBJECTDIR}/AerolineaData.o \
	${OBJECTDIR}/Arista.o \
	${OBJECTDIR}/Avion.o \
	${OBJECTDIR}/ClaseGrande.o \
	${OBJECTDIR}/Client.o \
	${OBJECTDIR}/Compra.o \
	${OBJECTDIR}/Drawing.o \
	${OBJECTDIR}/Grafo.o \
	${OBJECTDIR}/Itinerario.o \
	${OBJECTDIR}/Main.o \
	${OBJECTDIR}/Pais.o \
	${OBJECTDIR}/UsuarioAdministrador.o \
	${OBJECTDIR}/UsuarioAdministradorBusiness.o \
	${OBJECTDIR}/UsuarioAdministradorData.o \
	${OBJECTDIR}/Validaciones.o \
	${OBJECTDIR}/VentanaAdmin.o \
	${OBJECTDIR}/VentanaDibujo.o \
	${OBJECTDIR}/VentanaGestionar.o \
	${OBJECTDIR}/VentanaItinerarios.o \
	${OBJECTDIR}/VentanaPrincipal.o \
	${OBJECTDIR}/VentanaRegistrar.o \
	${OBJECTDIR}/VentanaReservar.o \
	${OBJECTDIR}/Vertice.o \
	${OBJECTDIR}/WindowAddNewAirline.o \
	${OBJECTDIR}/WindowConfig.o \
	${OBJECTDIR}/WindowDelete.o \
	${OBJECTDIR}/WindowFlights.o \
	${OBJECTDIR}/WindowLogin.o \
	${OBJECTDIR}/WindowUpdateAirlane.o \
	${OBJECTDIR}/WindowUpdateItinerarie.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyecto_algoritmos

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyecto_algoritmos: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyecto_algoritmos ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ActualizarVuelo.o: ActualizarVuelo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ActualizarVuelo.o ActualizarVuelo.cpp

${OBJECTDIR}/Aerolinea.o: Aerolinea.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Aerolinea.o Aerolinea.cpp

${OBJECTDIR}/AerolineaBusiness.o: AerolineaBusiness.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AerolineaBusiness.o AerolineaBusiness.cpp

${OBJECTDIR}/AerolineaData.o: AerolineaData.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AerolineaData.o AerolineaData.cpp

${OBJECTDIR}/Arista.o: Arista.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arista.o Arista.cpp

${OBJECTDIR}/Avion.o: Avion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Avion.o Avion.cpp

${OBJECTDIR}/ClaseGrande.o: ClaseGrande.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ClaseGrande.o ClaseGrande.cpp

${OBJECTDIR}/Client.o: Client.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Client.o Client.cpp

${OBJECTDIR}/Compra.o: Compra.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Compra.o Compra.cpp

${OBJECTDIR}/Drawing.o: Drawing.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drawing.o Drawing.cpp

${OBJECTDIR}/Grafo.o: Grafo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grafo.o Grafo.cpp

${OBJECTDIR}/Itinerario.o: Itinerario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Itinerario.o Itinerario.cpp

${OBJECTDIR}/Main.o: Main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/Pais.o: Pais.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pais.o Pais.cpp

${OBJECTDIR}/UsuarioAdministrador.o: UsuarioAdministrador.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/UsuarioAdministrador.o UsuarioAdministrador.cpp

${OBJECTDIR}/UsuarioAdministradorBusiness.o: UsuarioAdministradorBusiness.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/UsuarioAdministradorBusiness.o UsuarioAdministradorBusiness.cpp

${OBJECTDIR}/UsuarioAdministradorData.o: UsuarioAdministradorData.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/UsuarioAdministradorData.o UsuarioAdministradorData.cpp

${OBJECTDIR}/Validaciones.o: Validaciones.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Validaciones.o Validaciones.cpp

${OBJECTDIR}/VentanaAdmin.o: VentanaAdmin.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaAdmin.o VentanaAdmin.cpp

${OBJECTDIR}/VentanaDibujo.o: VentanaDibujo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaDibujo.o VentanaDibujo.cpp

${OBJECTDIR}/VentanaGestionar.o: VentanaGestionar.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaGestionar.o VentanaGestionar.cpp

${OBJECTDIR}/VentanaItinerarios.o: VentanaItinerarios.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaItinerarios.o VentanaItinerarios.cpp

${OBJECTDIR}/VentanaPrincipal.o: VentanaPrincipal.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaPrincipal.o VentanaPrincipal.cpp

${OBJECTDIR}/VentanaRegistrar.o: VentanaRegistrar.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaRegistrar.o VentanaRegistrar.cpp

${OBJECTDIR}/VentanaReservar.o: VentanaReservar.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaReservar.o VentanaReservar.cpp

${OBJECTDIR}/Vertice.o: Vertice.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vertice.o Vertice.cpp

${OBJECTDIR}/WindowAddNewAirline.o: WindowAddNewAirline.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WindowAddNewAirline.o WindowAddNewAirline.cpp

${OBJECTDIR}/WindowConfig.o: WindowConfig.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WindowConfig.o WindowConfig.cpp

${OBJECTDIR}/WindowDelete.o: WindowDelete.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WindowDelete.o WindowDelete.cpp

${OBJECTDIR}/WindowFlights.o: WindowFlights.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WindowFlights.o WindowFlights.cpp

${OBJECTDIR}/WindowLogin.o: WindowLogin.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WindowLogin.o WindowLogin.cpp

${OBJECTDIR}/WindowUpdateAirlane.o: WindowUpdateAirlane.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WindowUpdateAirlane.o WindowUpdateAirlane.cpp

${OBJECTDIR}/WindowUpdateItinerarie.o: WindowUpdateItinerarie.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WindowUpdateItinerarie.o WindowUpdateItinerarie.cpp

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
