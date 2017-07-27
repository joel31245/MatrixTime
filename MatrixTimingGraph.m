x = csvread("nCtr.csv");

ijk = csvread("ijk.csv");
ikj = csvread("ikj.csv");
jik = csvread("jik.csv");
jki = csvread("jki.csv");
kij = csvread("kij.csv");
kji = csvread("kji.csv");


figure(1);
hold on;
plot(x, ijk);
plot(x, ikj);
plot(x, jik);
plot(x, jki);
plot(x, kij);
plot(x, kji);
legend("ijk","ikj","jik","jki","kij","kji");
xlabel("Array Size (N)");
ylabel("Time (Amount of cycles)");
title("Core i5 Matrix Multiply Performance");
