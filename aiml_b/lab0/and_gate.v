module and_gate();
input a;
input b;
output y;
assign y = a&b;
	initial begin
	&display("this is and gate");
	end
endmodule
