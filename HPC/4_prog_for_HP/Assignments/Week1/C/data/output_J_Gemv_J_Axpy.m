% number of repeats:% 3
% enter first, last, inc:% 48 480 48 
data = [
%  n          reference      |         current implementation 
%        time       GFLOPS   |    time       GFLOPS     diff 
   480 4.7868e-03 4.6207e+01    2.6025e-02 8.4990e+00 5.6214e+144
   432 2.7495e-03 5.8643e+01    1.8911e-02 8.5265e+00 1.8953e+130
   384 2.0490e-03 5.5269e+01    1.3527e-02 8.3720e+00 6.9382e+115
   336 1.4052e-03 5.3988e+01    8.8297e-03 8.5921e+00 2.4168e+101
   288 8.7342e-04 5.4699e+01    5.4591e-03 8.7515e+00 8.3927e+86
   240 4.9171e-04 5.6228e+01    3.0953e-03 8.9323e+00 3.0799e+72
   192 2.5929e-04 5.4593e+01    1.5133e-03 9.3543e+00 1.0374e+58
   144 1.1604e-04 5.1464e+01    5.8894e-04 1.0140e+01 3.7819e+43
    96 4.0490e-05 4.3701e+01    1.7528e-04 1.0095e+01 1.3288e+29
    48 8.6540e-06 2.5559e+01    2.0297e-05 1.0897e+01 4.5029e+14
];

% Maximum difference between reference and your implementation: 5.621412e+144.