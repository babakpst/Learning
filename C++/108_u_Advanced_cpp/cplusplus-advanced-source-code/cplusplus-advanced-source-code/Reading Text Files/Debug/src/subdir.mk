################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Reading\ Text\ Files.cpp 

OBJS += \
./src/Reading\ Text\ Files.o 

CPP_DEPS += \
./src/Reading\ Text\ Files.d 


# Each subdirectory must supply rules for building sources it contributes
src/Reading\ Text\ Files.o: ../src/Reading\ Text\ Files.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Reading Text Files.d" -MT"src/Reading\ Text\ Files.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


