`include "multi2to1.v"

module multi2to1_tb;
    reg w0, w1, s;
    wire out;

    // Instantiate the multiplexer
    multi2to1 uut (
        .s(s),
        .w0(w0),
        .w1(w1),
        .out(out)
    );

    initial begin
        // Apply test inputs
        $dumpfile("multi2to1_tb.vcd");
        $dumpvars(0,multi2to1_tb);
        w0=0; w1=0; s=0; #10;
        w0=1; w1=0; s=0; #10;
        w0=0; w1=1; s=0; #10;
        w0=1; w1=1; s=0; #10;

        w0=0; w1=0; s=1; #10;
        w0=1; w1=0; s=1; #10;
        w0=0; w1=1; s=1; #10;
        w0=1; w1=1; s=1; #10;

        $finish;
    end
endmodule
