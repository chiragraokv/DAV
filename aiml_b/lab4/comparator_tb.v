`timescale 1ns/1ps
`include "comparator.v"

module comparator_tb;
    reg [3:0] a, b;
    wire lt, gt, eq;

    // Instantiate DUT
    comparator uut (a, b, lt, gt, eq);

    initial begin
        $dumpfile("comparator_tb.vcd");
        $dumpvars(0, comparator_tb);  

        a = 4'b0101; b = 4'b0011; #10;  // a > b
        a = 4'b0010; b = 4'b0110; #10;  // a < b
        a = 4'b1010; b = 4'b1010; #10;  // a == b

        $finish;
    end
endmodule
