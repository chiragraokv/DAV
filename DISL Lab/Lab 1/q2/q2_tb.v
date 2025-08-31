`timescale 1ns/1ns
`include "q2_struct.v"

module q2_tb();
reg a, b, c, d;
wire f, g;

q2_struct q2(f, g, a, b, c, d);
initial
begin
	$dumpfile("q2_struct.vcd");
	$dumpvars(0, q2_tb);
	
	a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b0;
	#20;
	a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b1;
	#20;
	a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b0;
	#20;
	a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b1;
	#20;
	a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b0;
	#20;
	a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b1;
	#20;
	a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b0;
	#20;
	a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b1;
	#20;
	a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b0;
	#20;
	a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b1;
	#20;
	a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b0;
	#20;
	a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b1;
	#20;
	a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0;
	#20;
	a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b1;
	#20;
	a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b0;
	#20;
	a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b1;
	#20;
end
endmodule
