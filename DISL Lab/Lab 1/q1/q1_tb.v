`timescale 1ns/1ns
`include "q1_struct.v"

module q1_tb();
reg a, b, c, d;
wire o1, o2, o3, o4, o3_, o5, o6, f;

q1_struct q1(f, a, b, c, d);
initial
begin
	$dumpfile("q1_struct.vcd");
	$dumpvars(0, q1_tb);
	
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
	
	$display("please work");
end

endmodule
		
