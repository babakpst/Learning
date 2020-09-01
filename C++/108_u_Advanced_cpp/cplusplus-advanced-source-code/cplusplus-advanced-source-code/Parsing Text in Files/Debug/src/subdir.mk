################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Parsing\ Text\ in\ Files.cpp 

OBJS += \
./src/Parsing\ Text\ in\ Files.o 

CPP_DEPS += \
./src/Parsing\ Text\ in\ Files.d 


# Each subdirectory must supply rules for building sources it contributes
src/Parsing\ Text\ in\ Files.o: ../src/Parsing\ Text\ in\ Files.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Parsing Text in Files.d" -MT"src/Parsing\ Text\ in\ Files.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


