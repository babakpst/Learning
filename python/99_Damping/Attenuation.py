
####################################################################################################
# Purpose: This code computes the mass, stiffness matrix of Q4, Q8, T3, T6
#
# Developed by: Babak Poursartip
# 
# The University of Texas at Austin
#
# ================================ V E R S I O N ===================================================
# V0.0: 07/18/2019 - Class initiation.
#
####################################################################################################

# libraries
import matplotlib.pyplot as plt  # plotting library
import numpy as np # arrays and vectors
import math as m

print(" Ploting the dependency of each Q model on frequency. ")
print(" Available visco-elastic models:")
print(" Kelvin-Voigt")

## input
# Spring-dashpot system
# Kelvin-Vigt (KV)
E_KV = 25
eta_KV = 1.0


# Maxwell (M)
E_M = 25
eta_M = 1.0

# Standard Linear Solid (SLS)
E1_SLS = 1   # E
E2_SLS = 10  # E*
eta_SLS = 5

# Maxwell-Rayleigh (MR)
E_MR = 100
eta1_MR = 1  #eta*
eta2_MR = 10000

# Generalized Maxwell Body
n = 8 # number of Maxwell bodies in GMB
E_H = 1000
E_GMB = np.zeros(n, dtype = np.float64) # Elastic modulus of GMB
eta_GMB = np.zeros(n, dtype = np.float64) # Elastic modulus of GMB

for i_GMB in range(0, n-1):
  E_GMB[i_GMB] = 1000
  eta_GMB[i_GMB] = 20

# range of frequencies to be studied (Hz)
initial_freq = 0.1
final_freq = 100
inc_freq = 0.1
plot_inverse = 0 # 0 plots Q-f, 1 Q inv-f

# calculations
total_freq = (final_freq-initial_freq)/inc_freq + 1

# print info on screen
print(" Frequency range: ", initial_freq, " to ", final_freq, " at increments: ", inc_freq)
print(" Total number of frequencies: ", total_freq)

# creating arrays
freq = np.zeros(total_freq, dtype = np.float64) # holds the frequency increments
Q_KV = np.zeros(total_freq, dtype = np.float64) # holds Q from the Kelvin-Voigt visco-elastic model
Q_M = np.zeros(total_freq, dtype = np.float64) # holds Q from the Maxwell visco-elastic model
Q_SLS = np.zeros(total_freq, dtype = np.float64) # holds Q from the Standard Linear Solid visco-elastic model
Q_MR = np.zeros(total_freq, dtype = np.float64) # holds Q from the Maxwwell-Rayleigh visco-elastic model
Q_GMB = np.zeros(total_freq, dtype = np.float64) # holds Q from the Maxwwell-Rayleigh visco-elastic model

for i_freq in range(0, int(total_freq)):
  freq[i_freq] = (i_freq+1) * inc_freq
  Q_KV[i_freq] = E_KV/(freq[i_freq] * eta_KV)
  Q_M[i_freq] = (freq[i_freq] * eta_M)/E_M
  Q_SLS[i_freq] = (E2_SLS*(E1_SLS + E2_SLS) + ((freq[i_freq])**2) * (eta_SLS**2))/ (freq[i_freq]*eta_SLS*E1_SLS)
  Q_MR[i_freq] = (freq[i_freq]*E_MR * (eta2_MR**2)) / ((E_MR**2) * (eta1_MR + eta2_MR) + ((freq[i_freq])**2) * eta1_MR * eta2_MR**2 )

  numerator = 0.0
  denuminator = 0.0
  for i_GMB in range(0,n-1):
    w_l = E_GMB[i_GMB]/eta_GMB[i_GMB]
    numerator = numerator+ ( ((freq[i_freq])**2) * E_GMB[i_GMB] )/( w_l**2 + ((freq[i_freq])**2) )
    denuminator =  denuminator + ( freq[i_freq] * E_GMB[i_GMB] * w_l ) / ( w_l**2 + ((freq[i_freq])**2) )
  #print(" num: ", numerator, " denumen: ", denuminator)
  Q_GMB[i_freq] = (E_H + numerator)/denuminator


  #print(i_freq, "  ", freq[i_freq], "  ", Q_KV[i_freq], "  ", Q_M[i_freq])

if plot_inverse == 1: 
  Q_KV[:] = 1/Q_KV[:]
  Q_M[:] = 1/Q_M[:]
  Q_SLS[:] = 1/Q_SLS[:]
  Q_MR[:] = 1/Q_MR[:]
  Q_GMB[:] = 1/Q_GMB[:]

# plotting Q
fig = plt.figure()
ax = fig.add_subplot(111)
ax.grid(True, color='k')
ax.set_ylim([0,100])

ax.plot(freq, Q_KV, label='Kelvin-Voigt', color='c', linewidth=2.0)
ax.plot(freq, Q_M, label='Maxwell', color='k', linewidth=2.0)
ax.plot(freq, Q_SLS, label='SLS', color='r', linewidth=2.0)
ax.plot(freq, Q_MR, label='MR', color='b', linewidth=2.0)
ax.plot(freq, Q_GMB, label='GMB', color='y', linewidth=2.0)

plt.title(" Q factor dependency on frequency for various models.")
plt.xlabel("Frequency (Hz)", fontsize=12)
plt.ylabel("Q", fontsize=12) # modify
ax.legend()
#plt.show(block=False)
plt.show()
plt.close(fig)

print(" Successful simulation. Congrats.")
print(" End of the code!")

#EE = 100
#eta1 = 1
#eta2 = 10000
#freq = 2

#numerator = (freq * EE * eta2**2)
#denum = ((EE**2) * (eta1 + eta2) + (freq**2) * eta1 * (eta2**2))
#QN_MR = numerator / denum

#print(" Q_MR= ", QN_MR, " ", numerator, " ", denum)


#a = 40
#b=-400000
#c=-400000

#sol1 = (-b+m.sqrt(b**2-4*a*c))/(2*a)
#sol2 = (-b-m.sqrt(b**2-4*a*c))/(2*a)

#print(" solution: ", sol1, " ", sol2 )
