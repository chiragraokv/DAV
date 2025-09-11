`timescale 1ns/1ps
`include "adder_subtractor.v"

module tb_adder_subtractor;

    reg  [3:0] a, b;
    reg        subt, cin;
    wire [3:0] sum;
    wire       cout;

    // Instantiate the DUT (Device Under Test)
    adder_subtractor dut (
        .a(a),
        .b(b),
        .cin(cin),
        .subt(subt),
        .sum(sum),
        .cout(cout)
    );

    initial begin
        // Monitor signals
        $monitor("t=%0t | a=%b (%0d) b=%b (%0d) subt=%b | sum=%b (%0d) cout=%b",
                 $time, a, a, b, b, subt, sum, sum, cout);

        // Test ADDITION (subt=0)
        a = 4'b0101; b = 4'b0011; subt = 0; cin = 0; #10;  // 5 + 3 = 8
        a = 4'b1111; b = 4'b0001; subt = 0; cin = 0; #10;  // 15 + 1 = 16 (overflow)

        // Test SUBTRACTION (subt=1)
        a = 4'b1000; b = 4'b0011; subt = 1; cin = 0; #10;  // 8 - 3 = 5
        a = 4'b0110; b = 4'b1001; subt = 1; cin = 0; #10;  // 6 - 9 = -3 (two's complement)

        // Edge cases
        a = 4'b0000; b = 4'b0000; subt = 0; cin = 0; #10;  // 0 + 0
        a = 4'b0000; b = 4'b0001; subt = 1; cin = 0; #10;  // 0 - 1 = -1

        $finish;
    end

endmodule
