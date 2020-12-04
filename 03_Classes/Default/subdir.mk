################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Aggregation.cpp \
../Association.cpp \
../Composition.cpp \
../Constructors.cpp \
../Inline.cpp \
../Point.cpp \
../PointB.cpp \
../enums.cpp \
../statics.cpp 

OBJS += \
./Aggregation.o \
./Association.o \
./Composition.o \
./Constructors.o \
./Inline.o \
./Point.o \
./PointB.o \
./enums.o \
./statics.o 

CPP_DEPS += \
./Aggregation.d \
./Association.d \
./Composition.d \
./Constructors.d \
./Inline.d \
./Point.d \
./PointB.d \
./enums.d \
./statics.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


