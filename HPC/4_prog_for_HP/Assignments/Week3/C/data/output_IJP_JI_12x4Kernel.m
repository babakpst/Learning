% number of repeats:% 3
% enter first, last, inc:% 48 1488 48 
data = [
%  n          reference      |         current implementation 
%        time       GFLOPS   |    time       GFLOPS     diff 
  1488 1.1963e-01 5.5081e+01    1.8565e-01 3.5494e+01 2.1600e-12
  1440 1.0789e-01 5.5351e+01    1.6854e-01 3.5433e+01 2.1032e-12
  1392 9.9069e-02 5.4452e+01    1.4949e-01 3.6086e+01 1.9327e-12
  1344 8.8710e-02 5.4734e+01    1.4781e-01 3.2850e+01 1.7621e-12
  1296 8.0459e-02 5.4109e+01    1.2251e-01 3.5536e+01 1.8190e-12
  1248 6.9017e-02 5.6327e+01    1.1277e-01 3.4474e+01 1.6485e-12
  1200 6.3419e-02 5.4495e+01    9.6850e-02 3.5684e+01 1.5348e-12
  1152 5.8514e-02 5.2255e+01    9.2441e-02 3.3077e+01 1.3642e-12
  1104 4.8569e-02 5.5409e+01    7.4745e-02 3.6004e+01 1.2506e-12
  1056 4.2683e-02 5.5179e+01    6.6147e-02 3.5605e+01 1.1937e-12
  1008 3.7203e-02 5.5059e+01    5.7379e-02 3.5699e+01 1.0232e-12
   960 3.1050e-02 5.6987e+01    5.2374e-02 3.3785e+01 1.0232e-12
   912 2.7930e-02 5.4317e+01    4.1161e-02 3.6858e+01 1.0800e-12
   864 2.4103e-02 5.3518e+01    3.5845e-02 3.5987e+01 8.5265e-13
   816 1.9689e-02 5.5192e+01    2.9786e-02 3.6483e+01 8.2423e-13
   768 1.6173e-02 5.6018e+01    3.2673e-02 2.7728e+01 7.1054e-13
   720 1.3315e-02 5.6065e+01    1.9415e-02 3.8450e+01 6.8212e-13
   672 1.0706e-02 5.6689e+01    1.5978e-02 3.7985e+01 5.6843e-13
   624 8.5990e-03 5.6511e+01    1.2955e-02 3.7509e+01 5.4001e-13
   576 6.7727e-03 5.6433e+01    1.0609e-02 3.6026e+01 4.8317e-13
   528 5.3230e-03 5.5306e+01    7.6747e-03 3.8359e+01 4.2633e-13
   480 3.7878e-03 5.8393e+01    5.5289e-03 4.0005e+01 3.1264e-13
   432 2.7670e-03 5.8275e+01    3.9460e-03 4.0862e+01 2.7001e-13
   384 1.9765e-03 5.7297e+01    3.1139e-03 3.6368e+01 2.2737e-13
   336 1.3296e-03 5.7061e+01    1.8836e-03 4.0276e+01 1.7053e-13
   288 8.6121e-04 5.5475e+01    1.1917e-03 4.0091e+01 9.9476e-14
   240 4.8979e-04 5.6448e+01    6.3503e-04 4.3538e+01 4.2633e-14
   192 2.6064e-04 5.4312e+01    3.4197e-04 4.1395e+01 2.8422e-14
   144 1.1591e-04 5.1524e+01    1.3116e-04 4.5532e+01 2.8422e-14
    96 4.0824e-05 4.3344e+01    3.6650e-05 4.8280e+01 1.0658e-14
    48 8.7100e-06 2.5394e+01    4.3110e-06 5.1307e+01 5.3291e-15
];

% Maximum difference between reference and your implementation: 2.160050e-12.