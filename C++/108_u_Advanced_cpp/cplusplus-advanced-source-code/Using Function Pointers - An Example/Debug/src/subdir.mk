################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Using\ Function\ Pointers\ -\ An\ Example.cpp 

OBJS += \
./src/Using\ Function\ Pointers\ -\ An\ Example.o 

CPP_DEPS += \
./src/Using\ Function\ Pointers\ -\ An\ Example.d 


# Each subdirectory must supply rules for building sources it contributes
src/Using\ Function\ Pointers\ -\ An\ Example.o: ../src/Using\ Function\ Pointers\ -\ An\ Example.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Using Function Pointers - An Example.d" -MT"src/Using\ Function\ Pointers\ -\ An\ Example.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


