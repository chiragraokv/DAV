`timescale 1ns/1ns
`include "q2_b.v"

module q2_tb();
reg A, B, C, D;
wire F;

q2_b q2(F, A, B, C, D);
initial
begin
	$dumpfile("q2_b.vcd");
	$dumpvars(0, q2_tb);
	
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

