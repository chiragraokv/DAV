`timescale 1ns/1ps
`include "full_adder.v"
`include "four_bit.v"

module four_bit_tb;
    reg [3:0] a_t, b_t;
    reg cin_t;
    wire [3:0] sum_t;
    wire cout_t;

    // Instantiate the DUT (Device Under Test)
    four_bit uut(a_t, b_t, cin_t, sum_t, cout_t);

    initial begin
        $dumpfile("four_bit.vcd");   // name it cleanly
        $dumpvars(0, four_bit_tb);

        a_t = 4'b0000; b_t = 4'b0000; cin_t = 0; #10;
        a_t = 4'b0101; b_t = 4'b0011; cin_t = 0; #10;
        a_t = 4'b1111; b_t = 4'b0001; cin_t = 0; #10;
        a_t = 4'b1010; b_t = 4'b0110; cin_t = 1; #10;

        $finish;
    end
endmodule
