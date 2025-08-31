`timescale 1ns/1ps
`include "half_adder.v"
module half_adder_tb;
reg a_t,b_t;
wire sum_t,carry_t;
half_adder qs(a_t,b_t,sum_t,carry_t);
initial begin 
    $dumpfile("half_adder.vcd");
    $dumpvars(0,half_adder_tb);
a_t = 0; b_t = 0; #10;
a_t = 0; b_t = 1; #10;
a_t = 1; b_t = 0; #10;
a_t = 1; b_t = 1; #10;

$finish;
end
endmodule
