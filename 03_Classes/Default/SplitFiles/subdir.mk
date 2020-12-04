################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SplitFiles/Point.cpp \
../SplitFiles/Test.cpp 

OBJS += \
./SplitFiles/Point.o \
./SplitFiles/Test.o 

CPP_DEPS += \
./SplitFiles/Point.d \
./SplitFiles/Test.d 


# Each subdirectory must supply rules for building sources it contributes
SplitFiles/%.o: ../SplitFiles/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


