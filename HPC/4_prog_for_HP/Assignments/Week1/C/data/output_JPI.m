% number of repeats:% 3
% enter first, last, inc:% 48 480 48 
data = [
%  n          reference      |         current implementation 
%        time       GFLOPS   |    time       GFLOPS     diff 
   480 3.9893e-03 5.5444e+01    2.5013e-02 8.8429e+00 3.5527e-13
   432 2.8209e-03 5.7160e+01    1.8280e-02 8.8206e+00 3.1264e-13
   384 1.9889e-03 5.6938e+01    1.3045e-02 8.6813e+00 1.9895e-13
   336 1.3421e-03 5.6528e+01    8.5092e-03 8.9158e+00 1.7053e-13
   288 8.6381e-04 5.5308e+01    5.3102e-03 8.9970e+00 1.1369e-13
   240 4.9542e-04 5.5808e+01    3.0190e-03 9.1579e+00 4.2633e-14
   192 2.6319e-04 5.3786e+01    1.4676e-03 9.6452e+00 2.8422e-14
   144 1.1644e-04 5.1287e+01    5.8184e-04 1.0264e+01 2.8422e-14
    96 4.0358e-05 4.3844e+01    1.7052e-04 1.0377e+01 1.4211e-14
    48 8.7780e-06 2.5198e+01    1.9962e-05 1.1080e+01 7.1054e-15
];

% Maximum difference between reference and your implementation: 3.552714e-13.