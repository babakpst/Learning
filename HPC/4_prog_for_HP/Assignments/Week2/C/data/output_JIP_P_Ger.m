% number of repeats:% 3
% enter first, last, inc:% 48 480 48 
data = [
%  n          reference      |         current implementation 
%        time       GFLOPS   |    time       GFLOPS     diff 
   480 6.1341e-03 3.6058e+01    2.4641e-02 8.9761e+00 3.5527e-13
   432 2.7297e-03 5.9069e+01    1.7721e-02 9.0989e+00 3.1264e-13
   384 1.9449e-03 5.8226e+01    1.3346e-02 8.4855e+00 1.9895e-13
   336 1.3141e-03 5.7733e+01    8.0955e-03 9.3714e+00 1.7053e-13
   288 8.5097e-04 5.6143e+01    5.1947e-03 9.1970e+00 1.1369e-13
   240 4.8648e-04 5.6833e+01    2.7736e-03 9.9682e+00 4.2633e-14
   192 2.5809e-04 5.4849e+01    1.4521e-03 9.7483e+00 2.8422e-14
   144 1.1511e-04 5.1881e+01    6.1555e-04 9.7019e+00 2.8422e-14
    96 4.0212e-05 4.4004e+01    1.6261e-04 1.0882e+01 1.4211e-14
    48 8.5230e-06 2.5951e+01    1.8398e-05 1.2022e+01 7.1054e-15
];

% Maximum difference between reference and your implementation: 3.552714e-13.