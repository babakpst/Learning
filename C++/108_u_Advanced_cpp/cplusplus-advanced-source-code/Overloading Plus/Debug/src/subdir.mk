################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Complex.cpp \
../src/Overloading\ Plus.cpp 

OBJS += \
./src/Complex.o \
./src/Overloading\ Plus.o 

CPP_DEPS += \
./src/Complex.d \
./src/Overloading\ Plus.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Overloading\ Plus.o: ../src/Overloading\ Plus.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Overloading Plus.d" -MT"src/Overloading\ Plus.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


