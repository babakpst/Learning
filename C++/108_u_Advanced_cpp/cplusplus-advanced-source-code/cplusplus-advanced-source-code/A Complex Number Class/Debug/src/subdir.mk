################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/A\ Complex\ Number\ Class.cpp \
../src/Complex.cpp 

OBJS += \
./src/A\ Complex\ Number\ Class.o \
./src/Complex.o 

CPP_DEPS += \
./src/A\ Complex\ Number\ Class.d \
./src/Complex.d 


# Each subdirectory must supply rules for building sources it contributes
src/A\ Complex\ Number\ Class.o: ../src/A\ Complex\ Number\ Class.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/A Complex Number Class.d" -MT"src/A\ Complex\ Number\ Class.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


