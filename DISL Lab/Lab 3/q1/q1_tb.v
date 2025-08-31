`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg A, B, C, D;
wire F;
q1 q1(F, A, B, C, D);
initial
begin
	$dumpfile("q1.vcd");
	$dumpvars(0, q1_tb);
	
	A = 1'b0; B = 1'b0; C = 1'b0; D = 1'b0;
	#20;
	A = 1'b0; B = 1'b0; C = 1'b0; D= 1'b1;
	#20;
	A = 1'b0; B = 1'b0; C = 1'b1; D = 1'b0;
	#20;
	A = 1'b0; B = 1'b0; C = 1'b1; D = 1'b1;
	#20;
	A = 1'b0; B = 1'b1; C = 1'b0; D = 1'b0;
	#20;
	A = 1'b0; B = 1'b1; C = 1'b0; D = 1'b1;
	#20;
	A = 1'b0; B = 1'b1; C = 1'b1; D = 1'b0;
	#20;
	A = 1'b0; B = 1'b1; C = 1'b1; D = 1'b1;
	#20;
	A = 1'b1; B = 1'b0; C = 1'b0; D = 1'b0;
	#20;
	A = 1'b1; B = 1'b0; C = 1'b0; D = 1'b1;
	#20;
	A = 1'b1; B = 1'b0; C = 1'b1; D = 1'b0;
	#20;
	A = 1'b1; B = 1'b0; C = 1'b1; D = 1'b1;
	#20;
	A = 1'b1; B = 1'b1; C = 1'b0; D = 1'b0;
	#20;
	A = 1'b1; B = 1'b1; C = 1'b0; D = 1'b1;
	#20;
	A = 1'b1; B = 1'b1; C = 1'b1; D = 1'b0;
	#20;
	A = 1'b1; B = 1'b1; C = 1'b1; D = 1'b1;
	#20;
	
	$display("please work");
end
endmodule
