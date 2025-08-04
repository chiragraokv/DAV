`timescale 1ns/1ps
`include "q1.v"

module q1_tb;
    reg a_t, b_t, c_t, d_t;
    wire f_t;


    q1 q1 (a_t, b_t,c_t,d_t,f_t);

    initial begin
        $dumpfile("q1_tb.vcd");
        $dumpvars(0, q1_tb);
a_t=0; b_t=0; c_t=0; d_t=0; #5;
a_t=0; b_t=0; c_t=0; d_t=1; #5;
a_t=0; b_t=0; c_t=1; d_t=0; #5;
a_t=0; b_t=0; c_t=1; d_t=1; #5;
a_t=0; b_t=1; c_t=0; d_t=0; #5;
a_t=0; b_t=1; c_t=0; d_t=1; #5;
a_t=0; b_t=1; c_t=1; d_t=0; #5;
a_t=0; b_t=1; c_t=1; d_t=1; #5;
a_t=1; b_t=0; c_t=0; d_t=0; #5;
a_t=1; b_t=0; c_t=0; d_t=1; #5;
a_t=1; b_t=0; c_t=1; d_t=0; #5;
a_t=1; b_t=0; c_t=1; d_t=1; #5;
a_t=1; b_t=1; c_t=0; d_t=0; #5;
a_t=1; b_t=1; c_t=0; d_t=1; #5;
a_t=1; b_t=1; c_t=1; d_t=0; #5;
a_t=1; b_t=1; c_t=1; d_t=1; #5;

        $display("Test complete");
        $finish;
    end
endmodule
