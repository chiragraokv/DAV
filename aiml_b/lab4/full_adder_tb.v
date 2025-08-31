`timescale 1ns/1ps
`include "full_adder.v"
module full_adder_tb;
reg a_t,b_t,c_t;
wire sum_t,carry_t;
full_adder ara(a_t,b_t,c_t,sum_t,carry_t);
initial begin 
    $dumpfile("full_adder.vcd");
    $dumpvars(0,full_adder_tb);
        a_t = 0; b_t = 0; c_t = 0; #10;
        a_t = 0; b_t = 0; c_t = 1; #10;
        a_t = 0; b_t = 1; c_t = 0; #10;
        a_t = 0; b_t = 1; c_t = 1; #10;
        a_t = 1; b_t = 0; c_t = 0; #10;
        a_t = 1; b_t = 0; c_t = 1; #10;
        a_t = 1; b_t = 1; c_t = 0; #10;
        a_t = 1; b_t = 1; c_t = 1; #10;

$finish;
end
endmodule
