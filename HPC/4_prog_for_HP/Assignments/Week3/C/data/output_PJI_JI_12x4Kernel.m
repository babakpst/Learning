% number of repeats:% 3
% enter first, last, inc:% 48 1488 48 
data = [
%  n          reference      |         current implementation 
%        time       GFLOPS   |    time       GFLOPS     diff 
  1488 1.1457e-01 5.7513e+01    1.7816e-01 3.6985e+01 2.1600e-12
  1440 1.0510e-01 5.6820e+01    1.6095e-01 3.7104e+01 2.1032e-12
  1392 9.5118e-02 5.6714e+01    1.4439e-01 3.7361e+01 1.9327e-12
  1344 8.5588e-02 5.6730e+01    1.4174e-01 3.4255e+01 1.7621e-12
  1296 7.7139e-02 5.6438e+01    1.1682e-01 3.7267e+01 1.8190e-12
  1248 6.7293e-02 5.7770e+01    1.0550e-01 3.6850e+01 1.6485e-12
  1200 6.0016e-02 5.7584e+01    9.1313e-02 3.7848e+01 1.5348e-12
  1152 5.3244e-02 5.7427e+01    9.0337e-02 3.3847e+01 1.3642e-12
  1104 4.7422e-02 5.6749e+01    7.1817e-02 3.7472e+01 1.2506e-12
  1056 4.1524e-02 5.6719e+01    6.4210e-02 3.6679e+01 1.1937e-12
  1008 3.5775e-02 5.7258e+01    5.4318e-02 3.7711e+01 1.0232e-12
   960 3.0983e-02 5.7110e+01    5.0470e-02 3.5060e+01 1.0232e-12
   912 2.6629e-02 5.6971e+01    4.0710e-02 3.7266e+01 1.0800e-12
   864 2.2605e-02 5.7065e+01    3.4129e-02 3.7796e+01 8.5265e-13
   816 1.9281e-02 5.6361e+01    2.8241e-02 3.8478e+01 8.2423e-13
   768 1.5809e-02 5.7306e+01    3.2038e-02 2.8278e+01 7.1054e-13
   720 1.3205e-02 5.6532e+01    1.9594e-02 3.8097e+01 6.8212e-13
   672 1.0682e-02 5.6818e+01    1.5874e-02 3.8233e+01 5.6843e-13
   624 8.6602e-03 5.6112e+01    1.2597e-02 3.8577e+01 5.4001e-13
   576 6.8640e-03 5.5683e+01    1.0746e-02 3.5569e+01 4.8317e-13
   528 5.2807e-03 5.5749e+01    7.4583e-03 3.9472e+01 4.2633e-13
   480 3.7913e-03 5.8339e+01    5.6226e-03 3.9338e+01 3.1264e-13
   432 2.7695e-03 5.8222e+01    3.8887e-03 4.1464e+01 2.7001e-13
   384 1.9970e-03 5.6707e+01    3.0875e-03 3.6679e+01 2.2737e-13
   336 1.3409e-03 5.6577e+01    1.8282e-03 4.1497e+01 1.7053e-13
   288 8.5672e-04 5.5766e+01    1.1106e-03 4.3019e+01 9.9476e-14
   240 4.9381e-04 5.5989e+01    6.0384e-04 4.5787e+01 4.2633e-14
   192 2.6054e-04 5.4333e+01    3.3301e-04 4.2508e+01 2.8422e-14
   144 1.1598e-04 5.1493e+01    1.2271e-04 4.8667e+01 2.8422e-14
    96 4.0117e-05 4.4108e+01    3.5083e-05 5.0437e+01 1.0658e-14
    48 8.5750e-06 2.5794e+01    4.2520e-06 5.2019e+01 5.3291e-15
];

% Maximum difference between reference and your implementation: 2.160050e-12.