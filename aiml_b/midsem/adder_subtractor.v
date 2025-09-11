`include "full_adder.v"
module adder_subtractor(
    input  [3:0] a, b,
    input        subt,
    output [3:0] sum,
    output       cout
);

wire [3:0] b_xor,carry;

xor(b_xor[0],subt,b[0]);
xor(b_xor[1],subt,b[1]);
xor(b_xor[2],subt,b[2]);
xor(b_xor[3],subt,b[3]);

full_adder f1(a[0],b_xor[0],subt,sum[0],carry[0]);
full_adder f2(a[1],b_xor[1],carry[0],sum[1],carry[1]);
full_adder f3(a[2],b_xor[2],carry[0],sum[2],carry[2]);
full_adder f4(a[3],b_xor[3],carry[0],sum[3],cout);

endmodule

